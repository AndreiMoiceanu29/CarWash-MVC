#ifndef H_MemoryRepository
#define H_MemoryRepository


#include <vector>
#include "IRepository.h"

template <class T> 
class MemoryRepository: public IRepository<T>{
protected:
	std::vector<T> database;

public:
	virtual T getEntity(int id){
		T entity;
		for(auto item: database){
			if(item.getId() == id){
				entity = item;
				break;
			}
		}
		return entity;
	}
	virtual void addEntity(T& entity) { this->database.push_back(entity);}
	virtual T deleteEntity(int id){
		T entity;
	for(unsigned int i = 0; i < this->database.size();i++){
		if(this->database[i].getId() == id){
			entity = this->database[i];
			this->database.erase(this->database.begin() + i);
			break;
		}
	}
	return entity;
}
	virtual T updateEntity(T& oldEntity,T& newEntity){
	oldEntity = deleteEntity(oldEntity.getId());
	addEntity(newEntity);
	return newEntity;
}
	std::vector<T> getAllEntities(){return this->database;}
};


#endif