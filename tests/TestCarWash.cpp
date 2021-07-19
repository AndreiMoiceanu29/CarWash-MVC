#include "tests/TestCarWash.h"
#include "CarWash.h"
#include <assert.h>
#include <vector>

TestCarWash::TestCarWash(){}

void TestCarWash::TestAll(){
	this->TestGetAndSetName();
	this->TestGetAndSetOwner();
	this->TestGetAndSetCarIds();
}

void TestCarWash::TestGetAndSetName(){
	CarWash wash;
	wash.setName("John");
	assert(wash.getName() == "John");
	wash.setName(":))");
	assert(wash.getName() == ":))");
}

void TestCarWash::TestGetAndSetOwner(){
	CarWash wash;
	wash.setOwner("aBcD");
	assert(wash.getOwner()== "aBcD");
	wash.setOwner(" c d");
	assert(wash.getOwner() == " c d");
}

void TestCarWash::TestGetAndSetCarIds(){
	std::vector<int> ids;
	std::vector<int> carIds;
	CarWash wash;
	for(int i=0; i < 100;i += 3){
		ids.push_back(i);
	}
	wash.setCarIds(ids);
	carIds = wash.getCarIds();


}