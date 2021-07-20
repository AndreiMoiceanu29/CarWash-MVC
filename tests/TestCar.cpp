#include <assert.h>
#include "Car.h"
#include "tests/TestCar.h"

TestCar::TestCar(){}

void TestCar::TestAll(){
	this->TestGetNameAndSetName();
	this->TestGetOwnerAndSetOwner();
	this->TestGetPlateAndSetPlate();
	this->TestConstructor();
}

void TestCar::TestGetNameAndSetName(){
	Car car = Car();
	car.setName("Basic Name");
	assert(car.getName() == "Basic Name");
	assert(car.getName() != "alskfdjal");
	car.setName("SpecialCase\n\n");
	assert(car.getName() == "SpecialCase\n\n"); 
}

void TestCar::TestGetOwnerAndSetOwner(){
	Car car = Car();
	car.setOwner("Josh");
	assert(car.getOwner() == "Josh");
	car.setOwner("   ");
	assert(car.getOwner() == "   ");
}

void TestCar::TestGetPlateAndSetPlate(){
	Car car = Car();
	car.setPlateNumber("AG00AAA");
	assert(car.getPlateNumber() == "AG00AAA");
	car.setPlateNumber("");
	assert(car.getPlateNumber() == ""); 
}

void TestCar::TestConstructor(){
	Car car("Dacia Sandero","Moiceanu Andrei","AG06DGA",1);
	assert(car.getName() == "Dacia Sandero" && car.getOwner() == "Moiceanu Andrei" && car.getPlateNumber() == "AG06DGA" && car.getId() == 1);
}