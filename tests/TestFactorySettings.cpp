#include "TestFactorySettings.h"
#include "FactorySettings.h"

TestFactorySettings::TestFactorySettings(){}

void TestFactorySettings::TestAll(){
	this->TestConstructor();
	this->TestGetAndSetRepoType();
	this->TestGetAndSetFilePath();
}

void TestFactorySettings::TestConstructor(){
	FactorySettings factorySettings(FileRepoType::file,"db.csv");
	FactorySettings factorySettingsMemory(FileRepoType::memory);
	assert(factorySettings.getRepoType() == FileRepoType::file && factorySettingsMemory.getFilePath() == "db.csv");
	assert(factorySettingsMemory.getRepoType() == FileRepoType::memory);

}

void FactorySettings::TestGetAndSetRepoType(){
	FactorySettings factorySettings;
	factorySettings.setRepoType(FileRepoType::memory);
	assert(factorySettings.getRepoType() == FileRepoType::memory);
}

void FactorySettings::TestGetAndSetFilePath(){
	FactorySettings factorySettings;
	factorySettings.setFilePath("db.csv");
	assert(factorySettings.getFilePath() == "db.csv");
}