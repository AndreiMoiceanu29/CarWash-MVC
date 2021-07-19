#ifndef H_SERVICE
#define H_SERVICE

#include "CarWash.h"
#include "Car.h"
#include "Repository.h"

class Service
{
	Repository<Car> carRepo;
	Repository<CarWash> carWashRepo;
public:
	Service();
	Service(Repository<Car>, Repository<CarWash>);
	
	void createCar(Car&);
	Car readCar(int id);
	Car updateCar(Car& oldCar, Car& newCar);
	Car deleteCar(int id);

	void createCarWash(CarWash&);
	CarWash readCarWash(int id);
	CarWash updateCarWash(CarWash& odlCarWash, CarWash& newCarWash);
	CarWash deleteCarWash(int id);

	void makeReservation(int carId, int carWashId);
	
	std::vector<CarWash> getAllCarWashes();


	
};
#endif