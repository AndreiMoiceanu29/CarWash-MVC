#ifndef H_CAR
#define H_CAR

#include <string>
#include "Entity.h"
class Car: public Entity
{
private:
	std::string name;
	std::string owner;
	std::string plateNumber;
	int carId;
	int carWashId;
public:
	Car();
	Car(std::string,std::string,std::string,int);

	std::string getName();
	void setName(std::string);
	std::string getOwner();
	void setOwner(std::string);
	std::string getPlateNumber();
	void setPlateNumber(std::string);
	int getId();
	void setId(int);
	

	~Car();

	
	
};



#endif