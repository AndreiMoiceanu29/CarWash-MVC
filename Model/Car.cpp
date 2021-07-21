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

void Car::attach(IObserver *obs){
	this->observers.push_back(obs);
}
void Car::dettach(IObserver *obs){
	this->observers.remove(obs);
}

void Car::notify(){
	std::list<IObserver *>::iterator it = this->observers.begin();
	while(it != observers.end()){
		(*it)->update(this->id);
		++it;
	}
}



Car::~Car(){
	
}