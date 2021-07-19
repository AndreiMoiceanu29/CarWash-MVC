#include "Car.h"
#include "Entity.h"
#include <string>
Car::Car(){}
Car::Car(std::string name, std::string owner,std::string plateNumber, int id){
	this->name = name;
	this->owner = owner;
	this->plateNumber = plateNumber;
	this->carId = id;
	this->carWashId = -1;
}

std::string Car::getName(){ return this->name; }
void Car::setName(std::string name){ this->name = name;}

std::string Car::getOwner(){ return this->owner;}
void Car::setOwner(std::string owner){ this->owner = owner;}

std::string Car::getPlateNumber(){ return this->plateNumber;}
void Car::setPlateNumber(std::string plateNumber){ this->plateNumber = plateNumber;}

int Car::getId(){ return this->carId; }
void Car::setId(int carId){ this->carId = carId; }



Car::~Car(){}