#include "tests/TestValidator.h"
#include "Validator.h"
#include "Car.h"
#include "CarWash.h"
#include <string>
#include <vector>
#include <assert.h>
#include "Entity.h"

TestValidator::TestValidator(){}

void TestValidator::TestAll(){
	this->TestValidateCar();
	this->TestValidateCarWash();
	this->TestValidateIdForCar();
	this->TestValidateIdForCarWash();
}

void TestValidator::TestValidateCar(){
	Car wrongName("a","Andrei","AG00AAA",1);
	Car wrongOwner("BMW","A@@@D","AG00AAA",2);
	Car wrongPlateA("BMW","Andrei","A222X3S",3);
	Car wrongPlateB("BMW","Andrei","AAAAAAAAAAAA",4);
	Car goodPlate("BMW","Andrei","AG06DGA",5);
	Car usedId("Dacia","Andrei","AG06DGA",2);
	Car negativeId("Dacia","Andrei","B299XCX",-2);
	Car finalCase("@@A","d","Bddd000",7);
	Validator val;
	
	std::vector<Car> carRepo;
	try{
		val.validateCar(wrongName,carRepo);
		assert(false);
	}catch(std::vector<std::string> msg){
		assert(true);
	}
	try{
		val.validateCar(finalCase,carRepo);
		assert(false);
	}catch(std::vector<std::string> msg){
		assert(true);
	}
	try{
		val.validateCar(wrongOwner,carRepo);
		assert(false);
	}catch(std::vector<std::string> msgs){
		assert(true);
	}
	try{
		val.validateCar(wrongPlateA,carRepo);
		assert(false);
	}catch(std::vector<std::string> msg){
		assert(true);
	}
	try{
		val.validateCar(wrongPlateB,carRepo);
		assert(false);
	}catch(std::vector<std::string> msg){
		assert(true);
	}
	try{
		val.validateCar(goodPlate,carRepo);
		assert(true);
	}catch(std::vector<std::string> msg){
		assert(false);
	}
	carRepo.push_back(wrongName);
	carRepo.push_back(wrongOwner);
	carRepo.push_back(wrongPlateA);
	carRepo.push_back(wrongPlateB);
	try{
		val.validateCar(usedId,carRepo);
		assert(false);
	}catch(std::vector<std::string> msg){
		assert(true);
	}
	try{
		val.validateCar(negativeId,carRepo);
		assert(false);
	}catch(std::vector<std::string> msg){
		assert(true);
	}
	
}

void TestValidator::TestValidateCarWash(){
	CarWash wrongName("@","Andrei",1);
	CarWash wrongOwner("Self","Z+333",2);
	CarWash negativeId("Self","Andrei",-4);
	CarWash usedId("Self","Andrei",2);
	CarWash validWash("Self","Andrei",7);
	CarWash finalCase("Self","d",9);
	Validator val;
	std::vector<CarWash> carWashRepo;
	
	try{
		val.validateCarWash(wrongName,carWashRepo);
		assert(false);
	}catch(std::vector<std::string> msg){
		assert(true);
	}
	try{
		val.validateCarWash(finalCase,carWashRepo);
		assert(false);
	}catch(std::vector<std::string> msg){
		assert(true);
	}
	try{
		val.validateCarWash(wrongOwner,carWashRepo);
		assert(false);
	}catch(std::vector<std::string> msg){
		assert(true);
	}
	try{
		val.validateCarWash(negativeId,carWashRepo);
		assert(false);
	}catch(std::vector<std::string> msg){
		assert(true);
	}
	carWashRepo.push_back(wrongName);
	carWashRepo.push_back(wrongOwner);
	try{
		val.validateCarWash(usedId,carWashRepo);
		assert(false);
	}catch(std::vector<std::string> msg){
		assert(true);
	}
	try{
		val.validateCarWash(validWash,carWashRepo);
		assert(true);
	}catch(std::vector<std::string> msg){
		assert(false);
	}
}

void TestValidator::TestValidateIdForCar(){
	Car a;
	Car b;

	Validator val;
	std::vector<Car> repo;
	a.setId(1);
	b.setId(2);
	repo.push_back(a);
	repo.push_back(b);
	try{
		val.validateIdForCar(3,repo);
		assert(false);
	}catch(std::vector<std::string> msg){
		assert(true);
	}
	try{
		val.validateIdForCar(-2,repo);
		assert(false);
	}catch(std::vector<std::string> msg){
		assert(true);
	}
	try{
		val.validateIdForCar(1,repo);
		assert(true);
	}catch(std::vector<std::string> msg){
		assert(false);
	}
}

void TestValidator::TestValidateIdForCarWash(){
	CarWash a;
	CarWash b;
	Validator val;
	std::vector<CarWash> repo;
	a.setId(1);
	b.setId(2);
	repo.push_back(a);
	repo.push_back(b);

	try{
		val.validateIdForCarWash(3,repo);
		assert(false);
	}catch(std::vector<std::string> msg){
		assert(true);
	}

	try{
		val.validateIdForCarWash(-2,repo);
		assert(false);
	}catch(std::vector<std::string> msg){
		assert(true);
	}

	try{
		val.validateIdForCarWash(1,repo);
		assert(true);
	}catch(std::vector<std::string> msg){
		assert(false);
	}
}