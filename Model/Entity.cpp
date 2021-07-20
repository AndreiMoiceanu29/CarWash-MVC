#include "Entity.h"

Entity::Entity(){}

int Entity::getId(){ return this->id; }
void Entity::setId(int entityId){ 
	
	this->id = entityId; 
}


Entity::~Entity(){}