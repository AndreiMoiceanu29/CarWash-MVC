#ifndef H_CAR_WASH
#define H_CAR_WASH

#include <string>
#include <vector>

class CarWash
{
	std::string name;
	std::string owner;
	int id;
	std::vector<int> carIds;
public:
	CarWash();
	CarWash(std::string, std::string, int);

	std::string getName();
	void setName(std::string);
	std::string getOwner();
	void setOwner(std::string);
	int getId();
	void setId(int);
	std::vector<int> getCarIds();
	void setCarIds(std::vector<int>);

	
	
};

#endif