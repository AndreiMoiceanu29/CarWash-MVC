#ifndef H_VALIDATOR
#define H_VALIDATOR
#include "Car.h"
#include <vector>
#include <string>
#include "CarWash.h"
class Validator
{
private:
	bool hasSpecifiedLength(std::string,unsigned int,unsigned int);
	bool hasNoSpecialCharacters(std::string);
	void validPlateNumber(std::string,std::vector<std::string>&);
public:
	Validator();
	void validateCar(Car&, std::vector<Car>);
	void validateCarWash(CarWash&, std::vector<CarWash>);
	void validateIdForCar(int, std::vector<Car>);
	void validateIdForCarWash(int, std::vector<CarWash>);

	
	
};
#endif