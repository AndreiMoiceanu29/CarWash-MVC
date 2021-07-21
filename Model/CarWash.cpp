#include "CarWash.h"
#include <vector>
#include <string>
CarWash::CarWash(){}
CarWash::CarWash(std::string carWashName, std::string carWashOwner, int carWashId){
	this->name = carWashName;
	this->owner = carWashOwner;
	this->id = carWashId;
}

std::string CarWash::getName(){ return this->name; }
void CarWash::setName(std::string carWashName){ this->name = carWashName; }

std::string CarWash::getOwner(){ return this->owner; }
void CarWash::setOwner(std::string carWashOwner){ this->owner = carWashOwner; }



std::vector<int> CarWash::getCarIds(){ return this->carIds; }
void CarWash::setCarIds(std::vector<int> carIdsList){ this->carIds = carIdsList; }

void CarWash::update(int carId){
	for(unsigned int i=0;i<this->carIds.size();i++){
		if(carIds[i] == carId){
			carIds.erase(carIds.begin() + i);
			break;
		}
	}
}

CarWash::~CarWash(){}