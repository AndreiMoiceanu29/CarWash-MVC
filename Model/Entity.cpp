#include "Entity.h"

Entity::Entity(){}

int Entity::getId(){ return this->id; }
void Entity::setId(int entityId){ 
	if(entityId < 0){
		entityId = 0;
	}
	this->id = entityId; 
}


Entity::~Entity(){}