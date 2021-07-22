#include "tests/TestFactorySettings.h"
#include "FactorySettings.h"
#include <assert.h>
TestFactorySettings::TestFactorySettings(){}

void TestFactorySettings::TestAll(){
	this->TestConstructor();
	this->TestGetAndSetRepoType();
	this->TestGetAndSetFilePath();
}

void TestFactorySettings::TestConstructor(){
	FactorySettings factorySettings(FileRepoType::file,"db.csv");
	FactorySettings factorySettingsMemory(FileRepoType::memory);
	assert(factorySettings.getRepoType() == FileRepoType::file && factorySettings.getFilePath() == "db.csv");
	assert(factorySettingsMemory.getRepoType() == FileRepoType::memory);

}

void TestFactorySettings::TestGetAndSetRepoType(){
	FactorySettings factorySettings;
	factorySettings.setRepoType(FileRepoType::memory);
	assert(factorySettings.getRepoType() == FileRepoType::memory);
}

void TestFactorySettings::TestGetAndSetFilePath(){
	FactorySettings factorySettings;
	factorySettings.setFilePath("db.csv");
	assert(factorySettings.getFilePath() == "db.csv");
}