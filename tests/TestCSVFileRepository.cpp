#include "tests/TestCSVFileRepository.h"
#include "Car.h"
#include <assert.h>
#include "FileRepository.h"

TestCSVFileRepository::TestCSVFileRepository(){}

void TestCSVFileRepository::TestAll(){
	this->TestLoadAndStoreFromFile();
}

void TestCSVFileRepository::TestLoadAndStoreFromFile(){
	FileRepository<Car*> csvRepo("database.csv");
	Car* car = new Car("Dacia Sandero","Moiceanu Andrei","AG06DGA",1);
	csvRepo.addEntity(car);
	csvRepo.storeToFile();
	csvRepo.deleteEntity(1);
	csvRepo.loadFromFile();
	Car* myCar = csvRepo.getEntity(1);
	assert(myCar->getName() == car->getName());
	assert(myCar->getOwner() == car->getOwner());
	assert(myCar->getPlateNumber() == car->getPlateNumber());
	assert(myCar->getId() == car->getId());
}