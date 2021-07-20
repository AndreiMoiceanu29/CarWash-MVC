#include "tests/TestRepository.h"
#include "Repository.h"
#include <vector>
#include <assert.h>

#include "Car.h"
#include "CarWash.h"
#include "Entity.h"
TestRepository::TestRepository(){}

void TestRepository::TestAll(){
	this->TestGetAndAddEntity();
	this->TestUpdateEntity();
	this->TestGetAllEntities();
	this->TestDeleteEntity();
}


void TestRepository::TestGetAndAddEntity(){
	Repository<Car> carRepo;
	Car entityA("Dacia","Andrei","AG06DGA",1);
	carRepo.addEntity(entityA);
	assert(carRepo.getEntity(1).getName() == entityA.getName() && carRepo.getEntity(1).getOwner() == entityA.getOwner() && carRepo.getEntity(1).getId() == entityA.getId());

	Repository<CarWash> carWashRepo;
    CarWash carWash("Self","Moiceanu Andrei",2);
    carWashRepo.addEntity(carWash);
    assert(carWashRepo.getEntity(2).getName() == carWash.getName() && carWashRepo.getEntity(2).getOwner() == carWash.getOwner());

}


void TestRepository::TestUpdateEntity(){
	Repository<Entity> repo;
	Entity firstEntity;
	Entity secondEntity;
	firstEntity.setId(1);
	secondEntity.setId(2);
    repo.addEntity(firstEntity);
    repo.updateEntity(firstEntity,secondEntity);
    assert(repo.getEntity(2).getId() == 2);
}

void TestRepository::TestDeleteEntity(){
	Repository<Entity> repo;
	Entity firstEntity;
	firstEntity.setId(1);
	repo.addEntity(firstEntity);
	Entity deletedEntity = repo.deleteEntity(1);
	assert(deletedEntity.getId() == firstEntity.getId());
}

void TestRepository::TestGetAllEntities(){
	Repository<Car> carRepo;
	std::vector<Car> cars;
	cars.push_back(Car("Dacia","Andrei","AG06DGA",1));
	cars.push_back(Car("BMW","Andrei","AG29MSE",2));
	cars.push_back(Car("Mercedes","Andrei","B829AXM",3));
	for(auto car : cars){
		carRepo.addEntity(car);
	}
	std::vector<Car> entities = carRepo.getAllEntities();
	for(int i=0;i<cars.size();i++){
		assert(cars[i].getId() == entities[i].getId() && cars[i].getName() == entities[i].getName() && cars[i].getOwner() == entities[i].getOwner());
	}
}