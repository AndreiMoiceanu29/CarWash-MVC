#include "Validator.h"
#include <string>
#include <vector>
#include "CarWash.h"

Validator::Validator(){}

void Validator::validateCar(Car& car, std::vector<Car> cars){
	std::vector<std::string> messages;
	//Valideaza nume
	std::string carName = car.getName();
	std::string plateNumber = car.getPlateNumber();
	if(!this->hasSpecifiedLength(carName,3,50)){
		messages.push_back("Car's name is too long or too short.");
	}

	if(!this->hasNoSpecialCharacters(carName)){
		messages.push_back("Car's name contains special characters.");
	}
	std::string carOwner = car.getOwner();
	if(!this->hasSpecifiedLength(carOwner,3,50)){
		messages.push_back("Owner's name is too long or too short.");
	}
	if(!this->hasNoSpecialCharacters(carOwner)){
		messages.push_back("Owner's name contains special characters");
	}
	this->validPlateNumber(plateNumber,messages);
	for(auto carItem: cars){
		if(carItem.getId() == car.getId()){
			messages.push_back("This ID is not unique.");
			break;
		}
	}
	if(car.getId() < 0){
		messages.push_back("This ID is a negative number.");
	}
	if(messages.size() > 0){
		throw messages;
	}
}

void Validator::validateCarWash(CarWash& carWash, std::vector<CarWash> carWashes){
	std::string carWashName = carWash.getName();
	std::string carWashOwner = carWash.getOwner();
	std::vector<std::string> messages;
	if(!(hasSpecifiedLength(carWashName,3,50))){
		messages.push_back("Too many or too low characters in the name");
	}
	if(!(hasNoSpecialCharacters(carWashName))){
		messages.push_back("Car wash name contains special characters");
	}
	if(!(hasSpecifiedLength(carWashOwner,3,50))){
		messages.push_back("Too many or too low characters in the Owner's name");
	}
	if(!(hasNoSpecialCharacters(carWashOwner))){
		messages.push_back("Car Wash Owner's name contains special characters");
	}
	for(auto carWashEntity : carWashes){
		if(carWashEntity.getId() == carWash.getId()){
			messages.push_back("This ID already exists");
			break;
		}
	}
	if(carWash.getId() < 0){
		messages.push_back("This ID is a negative number");
	}
	if(messages.size() > 0){
		throw messages;
	}

}

void Validator::validateIdForCar(int id,std::vector<Car> entities){
	std::vector<std::string> messages;
	bool exists = false;
	if(id < 0){
		messages.push_back("ID must be positive");
	}
	for(auto entity : entities){
		if(entity.getId() == id){
			exists = true;
			break;
		}
	}
	if(!exists){
		messages.push_back("This ID does not exist");
	}
	if(messages.size() > 0){
		throw messages;
	}
}

void Validator::validateIdForCarWash(int id, std::vector<CarWash> entities){
	std::vector<std::string> messages;
	bool exists = false;
	if(id < 0){
		messages.push_back("ID must be positive");
	}
	for(auto entity : entities){
		if(entity.getId() == id){
			exists = true;
			break;
		}
	}
	if(!exists){
		messages.push_back("This ID does not exist");
	}
	if(messages.size() > 0){
		throw messages;
	}
}


bool Validator::hasSpecifiedLength(std::string str, unsigned int low,unsigned int high){
	return (str.size() >= low && str.size() <= high);
}

bool Validator::hasNoSpecialCharacters(std::string str){
	for(std::string::size_type i=0; i<str.size(); i++){
		if(!((str[i] >= 'a' && str[i] <='z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == ' ' || str[i] == '_' || str[i] == '-')){
			return false;
		}
	}
	return true;
}

void Validator::validPlateNumber(std::string plateNumber,std::vector<std::string> &messages){
	if(plateNumber[0]=='B'){
		for(int i=1;i<4;i++){
			if(!(plateNumber[i] >= '0' && plateNumber[i] <= '9')){
				messages.push_back("Invalid registration plate format.");
			}
		}
		for(unsigned int i=4;i<plateNumber.size();i++){
			if(!(plateNumber[i] >='A' && plateNumber[i] <= 'Z')){
				messages.push_back("Invalid registration plate format");
			}
		}
	}else if(plateNumber[0] != 'B' && (plateNumber[0] >= 'A' && plateNumber[0] <= 'Z')){
		for(int i=2;i<4;i++){
			if(!(plateNumber[i] >= '0' && plateNumber[i] <= '9')){
				messages.push_back("Invalid registration plate format.");
			}
		}
		for(unsigned int i=4;i<plateNumber.size();i++){
			if(!(plateNumber[i] >='A' && plateNumber[i] <= 'Z')){
				messages.push_back("Invalid registration plate format");
			}
		}
	}
	if(plateNumber.size() != 7){
		messages.push_back("Registration plate does not have 7 characters.");
	}
}