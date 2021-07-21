#include "Service.h"
#include <vector>
#include <iostream>
#include <list>
Service::Service(){}

Service::Service(Validator dataVal, IRepository<Car*> *carRepository, IRepository<CarWash*> *carWashRepository){
	this->carRepo = carRepository;
	this->carWashRepo = carWashRepository;
	this->dataValidator = dataVal;
}

Service::Service(IRepository<Car*> *carRepository, IRepository<CarWash*> *carWashRepository){
	this->carWashRepo = carWashRepository;
	this->carRepo = carRepository;
}

void Service::createCar(Car car){
	this->dataValidator.validateCar(car,this->getAllCars());
	Car* myCar = new Car(car.getName(),car.getOwner(),car.getPlateNumber(),car.getId());
	this->carRepo->addEntity(myCar);
}

Car Service::readCar(int id){
	this->dataValidator.validateIdForCar(id,this->getAllCars());
	Car car = *this->carRepo->getEntity(id);

	return car;
}

Car Service::updateCar(Car oldCar, Car newCar){
	Car *oldCarPtr = new Car(oldCar);
	Car *newCarPtr = new Car(newCar);
	this->dataValidator.validateCar(newCar,this->getAllCars());
	Car *updatedCarPtr = this->carRepo->updateEntity(oldCarPtr, newCarPtr);
	Car updatedCar = *updatedCarPtr;
	delete updatedCarPtr;
	return updatedCar;
}

Car Service::deleteCar(int id){
	this->dataValidator.validateIdForCar(id, this->getAllCars());
	Car* deletedCarPtr = this->carRepo->deleteEntity(id);
	Car deletedCar = *deletedCarPtr;
	deletedCarPtr->notify();
	delete deletedCarPtr;

	return deletedCar;
}

void Service::createCarWash(CarWash carWash){
	CarWash* carWashPtr = new CarWash(carWash);
	this->dataValidator.validateCarWash(carWash,this->getAllCarWashes());
	this->carWashRepo->addEntity(carWashPtr);
}

CarWash Service::readCarWash(int id){
	this->dataValidator.validateIdForCarWash(id, this->getAllCarWashes());
	CarWash carWash = *this->carWashRepo->getEntity(id);

	return carWash;
}

CarWash Service::updateCarWash(CarWash oldCarWash, CarWash newCarWash){
	CarWash* oldCarWashPtr = new CarWash(oldCarWash);
	CarWash* newCarWashPtr = new CarWash(newCarWash);
	this->dataValidator.validateCarWash(newCarWash,this->getAllCarWashes());
	newCarWashPtr->setCarIds(oldCarWashPtr->getCarIds());
	CarWash *updatedCarWashPtr = this->carWashRepo->updateEntity(oldCarWashPtr, newCarWashPtr);
	CarWash updatedCarWash = *updatedCarWashPtr;
	delete updatedCarWashPtr;

	return updatedCarWash;
}


CarWash Service::deleteCarWash(int id){
	this->dataValidator.validateIdForCarWash(id,this->getAllCarWashes());
	CarWash* deletedCarWashPtr = this->carWashRepo->deleteEntity(id);
	CarWash deletedCarWash = *deletedCarWashPtr;
	std::vector<int> carIds = deletedCarWash.getCarIds();
	for(auto carId: carIds){
		Car *car = this->carRepo->getEntity(carId);
		Car *newCar = new Car(*car);
		newCar->dettach(deletedCarWashPtr);
		car = this->carRepo->updateEntity(car,newCar);
		delete car;
	}
	delete deletedCarWashPtr;

	return deletedCarWash;
}

void Service::makeReservation(int carId, int carWashId){
	this->dataValidator.validateIdForCar(carId,this->getAllCars());
	this->dataValidator.validateIdForCarWash(carWashId,this->getAllCarWashes());

	// ADD CAR TO CARWASH
	CarWash* oldWash = this->carWashRepo->getEntity(carWashId);
	CarWash* newWash = new CarWash(*oldWash);

	std::vector<int> carIds = this->carWashRepo->getEntity(carWashId)->getCarIds();
	carIds.push_back(carId);
	newWash->setCarIds(carIds);
	oldWash = this->carWashRepo->updateEntity(oldWash, newWash);
	delete oldWash;

	// ADD CAR OBSERVABLE
	Car* oldCar = this->carRepo->getEntity(carId);
	Car* newCar = new Car(*oldCar);


	for(auto carwash: this->carWashRepo->getAllEntities()){
		if(carwash->getId() == carWashId){
			newCar->attach(carwash);
		}
	}

	oldCar = this->carRepo->updateEntity(oldCar, newCar);
	delete oldCar;
}

std::vector<CarWash> Service::getAllCarWashes(){
	std::vector<CarWash> carWashes;
	std::list<CarWash*> entities = this->carWashRepo->getAllEntities();
	for(auto entity: entities){
		carWashes.push_back(*entity);
	}
	return carWashes;
}

std::vector<Car> Service::getAllCars(){
	std::vector<Car> cars;
	std::list<Car*> entities = this->carRepo->getAllEntities();
	for(auto entity: entities){
		cars.push_back(*entity);
	}
	return cars;
}
