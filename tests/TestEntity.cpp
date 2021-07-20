#include "tests/TestEntity.h"
#include <assert.h>
#include "Entity.h"
TestEntity::TestEntity(){}

void TestEntity::TestAll(){
	this->TestGetId();
	this->TestSetId();
}

void TestEntity::TestGetId(){
	Entity entity;
	for(int i=0;i<1000;i++){
		entity.setId(i);
			assert(entity.getId() == i);
	}
}

void TestEntity::TestSetId(){
	Entity entity;
	for(int i=-20;i<1000;i++){
		entity.setId(i);
		if(i < 0){
			assert(entity.getId() == 0);
		}else{
			assert(entity.getId() == i);
		}
	}
}