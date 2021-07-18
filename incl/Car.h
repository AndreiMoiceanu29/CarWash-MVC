#ifndef H_CAR
#define H_CAR

#include<string>
class Car
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
	int getCarId();
	void setCarId(int);
	int getCarWashId();
	void setCarWashId(int);

	
	
};



#endif