#ifndef H_CAR
#define H_CAR

#include <string>
#include <list>
#include "IPublisher.h"
#include "Entity.h"
class Car: public Entity, public IPublisher
{
private:
	std::string name;
	std::string owner;
	std::string plateNumber;
	std::list<IObserver *> observers;
	
public:
	Car();
	Car(std::string,std::string,std::string,int);

	std::string getName();
	void setName(std::string);
	std::string getOwner();
	void setOwner(std::string);
	std::string getPlateNumber();
	void setPlateNumber(std::string);
	
	void attach(IObserver *);
	void dettach(IObserver *);
	void notify();

	~Car();

	
	
};



#endif