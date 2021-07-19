#ifndef H_REPOSITORY
#define H_REPOSITORY


#include <vector>


template <class T>
class Repository{
	std::vector<T> database;

public:
	T getEntity(int id){
		T entity;
		for(auto item: database){
			if(item.getId() == id){
				entity = item;
				break;
			}
		}
		return entity;
	}
	void addEntity(T& entity) { this->database.push_back(entity);}
	T deleteEntity(int id){
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
	T updateEntity(T& oldEntity,T& newEntity){
	oldEntity = deleteEntity(oldEntity.getId());
	addEntity(newEntity);
	return newEntity;
}
	std::vector<T> getAllEntities(){return this->database;}
};


#endif