#include "../incl/CarWash.h"
#include "../incl/Car.h"
#include "../incl/Service.h"
#include "../incl/Repository.h"
#include <vector>
Service::Service(Repository<Car> carRepo, Repository<CarWash> carWashRepo){
	this->carRepo = carRepo;
	this->carWashRepo = carWashRepo;
}

void Service::createCar(Car& car){
	this->carRepo.addEntity(car);
}
Car Service::readCar(int id){
	Car car = this->carRepo.getEntity(id);
	return car;
}

Car Service::updateCar(Car& oldCar, Car& newCar){
	newCar.setCarWashId(oldCar.getCarWashId());
	Car updatedCar = this->carRepo.updateEntity(oldCar, newCar);

	return updatedCar;
}

Car Service::deleteCar(int id){
	Car deletedCar = this->carRepo.deleteEntity(id);
	std::vector<int> carIds = this->carWashRepo.getEntity(deletedCar.getCarWashId()).getCarIds();
	for(int i=0; i<carIds.size();i++){
		if(carIds[i] == id){
			carIds.erase(carIds.begin() + i);
			break;
		}
	}
	this->carWashRepo.getEntity(deletedCar.getCarWashId()).setCarIds(carIds);
	return deletedCar;
}

void Service::createCarWash(Carwash& carWash){
	this->carWashRepo.addEntity(carWash);
}

CarWash Service::readCarWash(int id){
	CarWash carWash = this->carWashRepo.getEntity(id);
	return carWash;
}

CarWash Service::updateCarWash(CarWash& oldCarWash, CarWash& newCarWash){
	newCarWash.setCarIds(oldCarWash.getCarIds());
	CarWash updatedCarWash = this->carWashRepo.updateEntity(oldCarWash, newCarWash);
	return updatedCarWash;
}


CarWash Service::deletedCarWash(int id){
	CarWash deletedCarWash = this->carWashRepo.deleteEntity(id);
	std::vector<int> carIds = deletedCarWash.getCarIds();
	for(auto carId: carIds){
		if(this->carRepo.getEntity(carId).getCarWashId() == id){
			this->carRepo.getEntity(carId).setCarWashId(-1);
		}
	}
	return deletedCarWash;
}

void Service::makeReservation(int carId, int carWashId){
	if(this->carRepo.getEntity(carId).getCarWashId() != -1){
		std::vector<int> carIds = this->carWashRepo.getEntity(this->carRepo.getEntity(carId).getCarWashId()).getCarIds();
		for(int i=0;i<carIds.size();i++){
			if(carIds[i] == carId){
				carIds.erase(carIds.begin() + i);
				this->carWashRepo.getEntity(this->carRepo.getEntity(carId).getCarWashId()).setCarIds(carIds);
				break;
			}
		}
	}
	this->carRepo.getEntity(carId).setCarWashId(carWashId);
	std::vector<int> carIds = this->carWashRepo.getEntity(carWashId).getCarIds();
	carIds.push_back(carId);
	this->carWashRepo.getEntity(carWashId).setCarIds(carIds);
}

std::vector<CarWash> Service::getAllCarWashes(){
	return this->carWashRepo.getAllEntities();
}

