#include "../incl/Repository.h"
#include <string>
#include <vector>
template <class T>
T Repository::getEntity(int id){ return this->database[id];}
T Repository::addEntity(T& entity){ this->database.push_back(entity); }
T Repository::deleteEntity(int id){
	for(int i = 0; i < this->database.size();i++){
		if(this->database[i].getId() == id){
			T entity = this->database[i];
			this->database.erase(this->database.begin() + i);
			return entity;
		}
	}
}
T Repository::updateEntity(T& oldEntity, T& newEntity){
	for(int i = 0; i < this->database.size();i++){
		if(this->database[i].getId() == oldEntity.getId()){
			this->database[i] = newEntity;
			return newEntity;
		}
	}
}

T Repository::getAllEntities(){
	return this->database;
}