#include "Validator.h"
#include <string>
#include <vector>

Validator::Validator(){}

void Validator::validateCar(Car& car){
	std::vector<std::string> messages;
	if(car.getPlateNumber().size() != 7){
		messages.push_back("Registration plate does not have 7 characters.");
	}
	if(messages.size() > 0){
		throw messages;
	}
}