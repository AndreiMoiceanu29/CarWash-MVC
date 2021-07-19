#include "Car.h"
#include "Entity.h"
#include <string>
Car::Car(){}
Car::Car(std::string carName, std::string carOwner,std::string plateNum, int carId){
	this->name = carName;
	this->owner = carOwner;
	this->plateNumber = plateNum;
	this->id = carId;

}

std::string Car::getName(){ return this->name; }
void Car::setName(std::string carName){ this->name = carName;}

std::string Car::getOwner(){ return this->owner;}
void Car::setOwner(std::string carOwner){ this->owner = carOwner;}

std::string Car::getPlateNumber(){ return this->plateNumber;}
void Car::setPlateNumber(std::string plateNum){ this->plateNumber = plateNum;}





Car::~Car(){}