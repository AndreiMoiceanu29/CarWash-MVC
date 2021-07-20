#ifndef H_SERVICE
#define H_SERVICE

#include "CarWash.h"
#include "Car.h"
#include "MemoryRepository.h"
#include "Validator.h"

class Service
{
	IRepository<Car>* carRepo;
	IRepository<CarWash>* carWashRepo;
	Validator dataValidator;
public:
	Service();
	Service(IRepository<Car>*, IRepository<CarWash>*);
	Service(Validator, IRepository<Car>*, IRepository<CarWash>*);
	
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