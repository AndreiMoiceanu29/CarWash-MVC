#include "tests/TestCSVFileRepository.h"
#include "Car.h"
#include <assert.h>
#include "FileRepository.h"
#include <CarWash.h>
#include <iostream>
TestCSVFileRepository::TestCSVFileRepository(){}

void TestCSVFileRepository::TestAll(){
	this->TestLoadAndStoreFromFile();
	this->TestLoadAndStoreCarWash();
	this->TestUpdate();
	this->TestDelete();
}

void TestCSVFileRepository::TestLoadAndStoreFromFile(){
	FileRepository<Car*>* csvRepo = new FileRepository<Car*>("car_db_test.csv");
	Car* car = new Car("Dacia Sandero","Moiceanu Andrei","AG06DGA",1);
	csvRepo->addEntity(car);
	
	//csvRepo.deleteEntity(1);
	//delete csvRepo;
	FileRepository<Car*> *newRepo = new FileRepository<Car*>("car_db_test.csv");
	
	Car* myCar = newRepo->getEntity(1);
	
	assert(myCar->getName() == car->getName());
	assert(myCar->getOwner() == car->getOwner());
	assert(myCar->getPlateNumber() == car->getPlateNumber());
	assert(myCar->getId() == car->getId());
	delete newRepo;
}

void TestCSVFileRepository::TestLoadAndStoreCarWash(){
	FileRepository<CarWash*> *csvRepo = new FileRepository<CarWash*>("carwash_db_test.csv");
	CarWash* wash = new CarWash("Self","Moiceanu Andrei",11);
	std::vector<int> ids;
	for(int i=1;i<=4;i++){
		ids.push_back(i);
	}

	wash->setCarIds(ids);

	csvRepo->addEntity(wash);

	//delete csvRepo;

	FileRepository<CarWash*>* washRepo = new FileRepository<CarWash*>("carwash_db_test.csv");

	CarWash* newWash = washRepo->getEntity(11);

	assert(newWash->getName() == wash->getName());
	assert(newWash->getOwner() == wash->getOwner());
	assert(newWash->getId() == wash->getId());

	assert(newWash->getCarIds().size() == wash->getCarIds().size());
	//std::cout << newWash->getId()<< std::endl;
	//delete newWash;
	//delete washRepo;
}

void TestCSVFileRepository::TestUpdate(){
	FileRepository<Car*> *csvRepo = new FileRepository<Car*>("car_db_test.csv");
	Car *oldCar = new Car("Dacia","Andrei","AG06DGA",1);
	csvRepo->addEntity(oldCar);
	Car *newCar = new Car("BMW","Andrei","AG29MSE",2);
	csvRepo->updateEntity(oldCar,newCar);
	Car *testCar = csvRepo->getEntity(2);
	assert(testCar->getId() == newCar->getId());


}


void TestCSVFileRepository::TestDelete(){
	FileRepository<Car*> *csvRepo = new FileRepository<Car*>("car_db_test.csv");
	Car *oldCar = new Car("Dacia","Andrei","AG06DGA",4);
	csvRepo->addEntity(oldCar);
	
	csvRepo->deleteEntity(4);
	Car *testCar = csvRepo->getEntity(4);
	assert(testCar == NULL);
}