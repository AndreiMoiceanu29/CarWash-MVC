#ifndef H_CAR_WASH
#define H_CAR_WASH

#include <string>
#include <vector>
#include "Entity.h"
#include "IObserver.h"

class CarWash: public Entity, public IObserver
{
	std::string name;
	std::string owner;
	
	std::vector<int> carIds;
public:
	CarWash();
	CarWash(std::string, std::string, int);

	std::string getName();
	void setName(std::string);
	std::string getOwner();
	void setOwner(std::string);
	
	std::vector<int> getCarIds();
	void setCarIds(std::vector<int>);
	void update(int);
	~CarWash();

	
	
};

#endif