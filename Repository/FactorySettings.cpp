#include "FactorySettings.h"

FactorySettings::FactorySettings(){}

FactorySettings::FactorySettings(FileRepoType::type repositoryType){
	this->repoType = repositoryType;
}

FactorySettings::FactorySettings(FileRepoType::type repositoryType, std::string path){
	this->repoType = repositoryType;
	this->filePath = path;
}

FileRepoType::type FactorySettings::getRepoType(){ return this->repoType; }
void FactorySettings::setRepoType(FileRepoType::type repositoryType){ this->repoType = repositoryType; }

std::string FactorySettings::getFilePath(){ return this->filePath; }
void FactorySettings::setFilePath(std::string path){ this->filePath = path; }

FactorySettings::~FactorySettings(){}