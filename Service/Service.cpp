#include "CarWash.h"
#include "Car.h"
#include "Service.h"
#include "Repository.h"
#include <vector>
#include <iostream>
Service::Service(){}

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
	
	Car updatedCar = this->carRepo.updateEntity(oldCar, newCar);

	return updatedCar;
}

Car Service::deleteCar(int id){

	Car deletedCar = this->carRepo.deleteEntity(id);
	
	return deletedCar;
}

void Service::createCarWash(CarWash& carWash){
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


CarWash Service::deleteCarWash(int id){
	CarWash deletedCarWash = this->carWashRepo.deleteEntity(id);
	
	return deletedCarWash;
}

void Service::makeReservation(int carId, int carWashId){

	std::vector<int> carIds = this->carWashRepo.getEntity(carWashId).getCarIds();

	carIds.push_back(carId);
	this->carWashRepo.getEntity(carWashId).setCarIds(carIds);
}

std::vector<CarWash> Service::getAllCarWashes(){
	return this->carWashRepo.getAllEntities();
}

