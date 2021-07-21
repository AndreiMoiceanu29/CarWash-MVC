#ifndef H_MemoryRepository
#define H_MemoryRepository


#include <list>
#include "IRepository.h"
#include <iostream>
template <class T> 
class MemoryRepository: public IRepository<T>{
protected:
	std::list<T> database;

public:
	virtual T getEntity(int id){
		for(auto item: database){
			if(item->getId() == id)
				return item;
		}
		return NULL;
	}
	
	virtual void addEntity(T& entity) { this->database.push_back(entity);}
	
	virtual T deleteEntity(int id){
		T entity = this->getEntity(id);
		this->database.remove(entity);
		
		return entity;
	}

	virtual T updateEntity(T& oldEntity,T& newEntity){
		oldEntity = deleteEntity(oldEntity->getId());
		addEntity(newEntity);
		
		return oldEntity;
	}

	std::list<T> getAllEntities(){return this->database;}
	virtual ~MemoryRepository(){
		for(auto entity: this->database){
			delete entity;
		}
	}
};


#endif