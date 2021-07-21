#ifndef H_CONSOLE
#define H_CONSOLE

#include "Car.h"
#include "CarWash.h"
#include "Service.h"

class Console{
	Service service;
public:
	Console(Service service);

	void run();
	void printMenu();

	void handleAddCar();
	void handleReadCar();
	void handleDeleteCar();
	void handleUpdateCar();

	void handleAddCarWash();
	void handleReadCarWash();
	void handleDeleteCarWash();
	void handleUpdateCarWash();

	void handleMakeReservation();
	
	Car readCar();
	void displayCar(Car &);

	CarWash readCarWash();
	void displayCarWash(CarWash &);
	void displayAllCarWash();
	void displayAllCars();
};

#endif