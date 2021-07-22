#include "tests/TestMemoryRepository.h"
#include "MemoryRepository.h"
#include <vector>
#include <assert.h>

#include "Car.h"
#include "CarWash.h"
#include "Entity.h"
TestMemoryRepository::TestMemoryRepository(){}

void TestMemoryRepository::TestAll(){
	this->TestGetAndAddEntity();
	this->TestUpdateEntity();
	this->TestGetAllEntities();
	this->TestDeleteEntity();
}


void TestMemoryRepository::TestGetAndAddEntity(){
	MemoryRepository<Car*> carRepo;
	Car* entityA = new Car("Dacia","Andrei","AG06DGA",1);
	carRepo.addEntity(entityA);
	assert(carRepo.getEntity(1)->getName() == entityA->getName() && carRepo.getEntity(1)->getOwner() == entityA->getOwner() && carRepo.getEntity(1)->getId() == entityA->getId());

	MemoryRepository<CarWash*> carWashRepo;
    CarWash* carWash = new CarWash("Self","Moiceanu Andrei",2);
    carWashRepo.addEntity(carWash);
    assert(carWashRepo.getEntity(2)->getName() == carWash->getName() && carWashRepo.getEntity(2)->getOwner() == carWash->getOwner());
    assert(carWashRepo.getEntity(222) == NULL);

}


void TestMemoryRepository::TestUpdateEntity(){
	MemoryRepository<Entity*> repo;
	Entity* firstEntity = new Entity();
	Entity* secondEntity = new Entity();
	firstEntity->setId(1);
	secondEntity->setId(2);
    repo.addEntity(firstEntity);
    repo.updateEntity(firstEntity,secondEntity);
    assert(repo.getEntity(2)->getId() == 2);
}

void TestMemoryRepository::TestDeleteEntity(){
	MemoryRepository<Entity*> repo;
	Entity* firstEntity = new Entity();
	firstEntity->setId(1);
	repo.addEntity(firstEntity);
	Entity* deletedEntity = repo.deleteEntity(1);
	assert(deletedEntity->getId() == firstEntity->getId());
}

void TestMemoryRepository::TestGetAllEntities(){
	MemoryRepository<Car*> carRepo;
	std::list<Car*> cars;
	cars.push_back(new Car("Dacia","Andrei","AG06DGA",1));
	cars.push_back(new Car("BMW","Andrei","AG29MSE",2));
	cars.push_back(new Car("Mercedes","Andrei","B829AXM",3));
	for(auto car : cars){
		carRepo.addEntity(car);
	}
	std::list<Car*> entities = carRepo.getAllEntities();
	auto carIt = cars.begin();
	auto entityIt = entities.begin();
	for(; carIt != cars.end() && entityIt != entities.end();++carIt,++entityIt){
		assert((*carIt)->getId() == (*entityIt)->getId());
	}
}