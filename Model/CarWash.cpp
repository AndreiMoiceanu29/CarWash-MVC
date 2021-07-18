#include "../incl/CarWash.h"
#include <vector>
#include <string>
CarWash::CarWash(){}
CarWash::CarWash(std::string name, std::string owner, int id){
	this->name = name;
	this->owner = owner;
	this->id = id;
}

std::string CarWash::getName(){ return this->name; }
void CarWash::setName(std::string name){ this->name = name; }

std::string CarWash::getOwner(){ return this->owner; }
void CarWash::setOwner(std::string owner){ this->owner = owner; }

int CarWash::getId(){ return this->id; }
void CarWash::setId(int id){ this->id = id;}

std::vector<int> CarWash::getCarIds(){ return this->carIds; }
void CarWash::setCarIds(std::vector<int> carIds){ this->carIds = carIds; }
