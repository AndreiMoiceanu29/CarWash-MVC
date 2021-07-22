#include "tests/TestRepoFactory.h"
#include "Utilities.h"
#include "Car.h"
#include "FactorySettings.h"
#include "RepoFactory.h"
#include <assert.h>
TestRepoFactory::TestRepoFactory(){}

void TestRepoFactory::TestAll(){
	this->TestCreateRepository();
	this->TestGetInstance();
}

void TestRepoFactory::TestCreateRepository(){
	RepoFactory<Car*> *carFactory = carFactory->getInstance();
	IRepository<Car*> *fileRepo = carFactory->createRepository(FactorySettings(FileRepoType::file,"database.csv"));
	IRepository<Car*> *memoryRepo = carFactory->createRepository(FactorySettings(FileRepoType::memory));
	assert(Utilities::instanceof<IRepository<Car*>>(fileRepo));
	assert(Utilities::instanceof<IRepository<Car*>>(memoryRepo));

}

void TestRepoFactory::TestGetInstance(){
	RepoFactory<Car*> *carFactory = carFactory->getInstance();
	assert(carFactory != NULL);
}



