#include "Service.h"
#include <vector>
Service::Service(){}

Service::Service(Validator dataVal, IRepository<Car> *carRepository, IRepository<CarWash> *carWashRepository){
	this->carRepo = carRepository;
	this->carWashRepo = carWashRepository;
	this->dataValidator = dataVal;
}
Service::Service(IRepository<Car> *carRepository, IRepository<CarWash> *carWashRepository){
	this->carWashRepo = carWashRepository;
	this->carRepo = carRepository;
}
void Service::createCar(Car& car){
	this->dataValidator.validateCar(car,this->carRepo->getAllEntities());
	this->carRepo->addEntity(car);
}
Car Service::readCar(int id){
	this->dataValidator.validateIdForCar(id,this->carRepo->getAllEntities());
	Car car = this->carRepo->getEntity(id);
	return car;
}

Car Service::updateCar(Car& oldCar, Car& newCar){
	this->dataValidator.validateCar(newCar,this->carRepo->getAllEntities());
	Car updatedCar = this->carRepo->updateEntity(oldCar, newCar);

	return updatedCar;
}

Car Service::deleteCar(int id){
	this->dataValidator.validateIdForCar(id, this->carRepo->getAllEntities());
	Car deletedCar = this->carRepo->deleteEntity(id);
	deletedCar.notify();
	return deletedCar;
}

void Service::createCarWash(CarWash& carWash){

	this->dataValidator.validateCarWash(carWash,this->carWashRepo->getAllEntities());
	this->carWashRepo->addEntity(carWash);
}

CarWash Service::readCarWash(int id){
	this->dataValidator.validateIdForCarWash(id, this->carWashRepo->getAllEntities());
	CarWash carWash = this->carWashRepo->getEntity(id);
	return carWash;
}

CarWash Service::updateCarWash(CarWash& oldCarWash, CarWash& newCarWash){
	this->dataValidator.validateCarWash(newCarWash,this->carWashRepo->getAllEntities());
	newCarWash.setCarIds(oldCarWash.getCarIds());
	CarWash updatedCarWash = this->carWashRepo->updateEntity(oldCarWash, newCarWash);
	return updatedCarWash;
}


CarWash Service::deleteCarWash(int id){
	this->dataValidator.validateIdForCarWash(id,this->carWashRepo->getAllEntities());
	CarWash deletedCarWash = this->carWashRepo->deleteEntity(id);
	
	return deletedCarWash;
}

void Service::makeReservation(int carId, int carWashId){
	this->dataValidator.validateIdForCar(carId,this->carRepo->getAllEntities());
	this->dataValidator.validateIdForCarWash(carWashId,this->carWashRepo->getAllEntities());
	std::vector<int> carIds = this->carWashRepo->getEntity(carWashId).getCarIds();

	carIds.push_back(carId);
	CarWash oldWash = this->carWashRepo->getEntity(carWashId);
	CarWash newWash = this->carWashRepo->getEntity(carWashId);
	newWash.setCarIds(carIds);
	this->carWashRepo->updateEntity(oldWash,newWash);
}

std::vector<CarWash> Service::getAllCarWashes(){
	return this->carWashRepo->getAllEntities();
}

