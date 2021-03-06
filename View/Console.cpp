#include "Car.h"
#include "CarWash.h"
#include "Service.h"
#include "Console.h"
#include <iostream>
#include <string>
#include <cstdio>

Console::Console(Service serv){
	this->service = serv;
}

void Console::run(){
	bool hasExited = false;
	int option;
	while(!hasExited){
		printMenu();
		std::cin >> option;
		switch(option){
			case 0: hasExited = true; 
			break;
			case 1: handleAddCar();
			break;
			case 2: handleReadCar();
			break;
			case 3: handleUpdateCar();
			break;
			case 4: handleDeleteCar();
			break;
			case 5: handleAddCarWash();
			break;
			case 6: handleReadCarWash();
			break;
			case 7: handleUpdateCarWash();
			break;
			case 8: handleDeleteCarWash();
			break;
			case 9: handleMakeReservation();
			break;
			case 10: displayAllCars();
			break;
			case 11: displayAllCarWash();
			break;
			default: std::cout << "Wrong option please try again !" << std::endl;
		}
	}
}

void Console::displayAllCars(){
	std::vector<Car> cars = this->service.getAllCars();
	std::vector<CarWash> carWashes = this->service.getAllCarWashes();
	std::cout << "Toate masinile" << std::endl;
	for(auto car: cars){
		displayCar(car);
	}
	
}

void Console::printMenu(){
	std::cout << "******************" << std::endl;
	std::cout << "Car Wash Dashboard" << std::endl;
	std::cout << "******************" << std::endl;
	std::cout << "Press one of the options bellow:" << std::endl;
	std::cout << "0) Exit" << std::endl;
	std::cout << "1) Add a Car" << std::endl;
	std::cout << "2) Display Car info" << std::endl;
	std::cout << "3) Update Car info" << std::endl;
	std::cout << "5) Add Car Wash" << std::endl;
	std::cout << "6) Display Car Wash info" << std::endl;
	std::cout << "7) Update Car Wash info" << std::endl;
	std::cout << "8) Delete Car Wash" << std::endl;
	std::cout << "9) Make a reservation" << std::endl;
	std::cout << "11) Display all cars" << std::endl;
	std::cout << "12) Display all car washes" << std::endl;
}

void Console::handleAddCar(){
	Car car;
	std::cout << "Please enter car's data:" << std::endl;
	car = readCar();
	try{
		this->service.createCar(car);
	}catch (std::vector<std::string> msgs){
		for(auto msg : msgs){
			std::cout << msg << std::endl;
		}
	}
}

void Console::handleReadCar(){
	int id;
	Car car;
	std::cout << "Please enter the car ID:" << std::endl;
	std::cin >> id;
	try{
		car = this->service.readCar(id);
	}catch(std::vector<std::string> msgs){
		for(auto msg: msgs){
			std::cout << msg << std::endl;
		}
	}
	
	displayCar(car);
}

void  Console::handleUpdateCar(){
	int id;
	Car oldCar;
	Car newCar;
	std::cout << "Please enter the old car's ID:" << std::endl;
	std::cin >> id;
	try{
		oldCar = this->service.readCar(id);
	}catch(std::vector<std::string> msgs){
		for(auto msg : msgs){
			std::cout << msg << std::endl;
		}
	}
	
	std::cout << "Please enter the new car's data:" << std::endl;
	newCar = readCar();
	try{
		newCar = this->service.updateCar(oldCar,newCar);
	}catch(std::vector<std::string> msgs){
		for(auto msg : msgs){
			std::cout << msg << std::endl;
		}
	}
	

}

void Console::handleDeleteCar(){
	int id;
	Car deletedCar;
	std::cout << "Please enter the ID of the car you wish to delete" << std::endl;
	std::cin >> id;
	try{
		deletedCar = this->service.deleteCar(id);
	}catch(std::vector<std::string> msgs){
		for(auto msg : msgs){
			std::cout << msg << std::endl;
		}
	}
	
}

void Console::handleAddCarWash(){
	CarWash carWash;
	std::cout << "Please enter the car wash data:" << std::endl;
	carWash = readCarWash();
	try{
		this->service.createCarWash(carWash);
	}catch(std::vector<std::string> msgs){
		for(auto msg : msgs){
			std::cout << msg << std::endl;
		}
	}
	
}

void Console::handleReadCarWash(){
	int id;
	CarWash carWash;
	std::cout << "Please enter the car wash's ID:" << std::endl;
	std::cin >> id;
	try{
		carWash = this->service.readCarWash(id);
		displayCarWash(carWash);
	}catch(std::vector<std::string> msgs){
		for(auto msg : msgs){
			std::cout << msg << std::endl;
		}
	}
	
	
}

void Console::handleUpdateCarWash(){
	int id;
	CarWash oldCarWash;
	CarWash newCarWash;
	std::cout << "Please enter the id of the old car wash" << std::endl;
	std::cin >> id;
	try{
		oldCarWash = this->service.readCarWash(id);	
	}catch(std::vector<std::string> msgs){
		for(auto msg : msgs){
			std::cout << msg << std::endl;
		}
	}
	
	std::cout << "Please enter the new car wash data" << std::endl;
	newCarWash = readCarWash();
	try{
		this->service.updateCarWash(oldCarWash,newCarWash);
	}catch(std::vector<std::string> msgs){
		for(auto msg : msgs){
			std::cout << msg << std::endl;
		}
	}
	

}

void Console::handleDeleteCarWash(){
	int id;
	CarWash deletedCarWash;
	std::cout << "Please enter the ID of the CarWash you want to delete" << std::endl;
	std::cin >> id;
	try{
		this->service.deleteCarWash(id);
	}catch(std::vector<std::string> msgs){
		for(auto msg : msgs){
			std::cout << msg << std::endl;
		}
	}
	
}

void Console::handleMakeReservation(){
	int carId;
	int carWashId;
	std::cout << "Please enter the id of your car" << std::endl;
	std::cin >> carId;
	std::cout << "Please choose where you want to wash your car" << std::endl;
	displayAllCarWash();
	std::cin >> carWashId;
	try{
		this->service.makeReservation(carId,carWashId);
	}catch(std::vector<std::string> msgs){
		for(auto msg : msgs){
			std::cout << msg << std::endl;
		}
	}
	
}


Car Console::readCar(){
	std::string name;
	std::string owner;
	std::string plateNumber;
	int id;
	
	std::cout << "Enter the Car's name:" << std::endl;
	std::cin.ignore();
	std::getline(std::cin,name,'\n');

	std::cout << "Enter the Car's owner:" << std::endl;
	//std::cin.ignore();

	std::getline(std::cin,owner,'\n');
	std::cout << "Enter the Car's plate number:" << std::endl;
	//std::cin.ignore();
	std::getline(std::cin,plateNumber,'\n');
	std::cout << "Enter the Car's id" << std::endl;
	std::cin >> id;
	Car car(name,owner,plateNumber,id);
	return car;
}

void Console::displayCar(Car& car){
	std::cout << "Name:" << car.getName() << std::endl;
	std::cout << "Owner:" << car.getOwner() << std::endl;
	std::cout << "Plate nr:" << car.getPlateNumber() << std::endl;
	std::cout << "Car's ID:" << car.getId() << std::endl;
}

CarWash Console::readCarWash(){
	std::string name;
	std::string owner;
	int id;

	std::cout << "Enter the name of your Car Wash:" << std::endl;
	std::cin.ignore();
	std::getline(std::cin,name,'\n');
	std::cout << "Enter the owner of the car wash:" << std::endl;
	
	std::getline(std::cin,owner,'\n');
	std::cout << "Enter a uniquie ID:" << std::endl;
	std::cin >> id;

	CarWash carWash(name,owner,id);
	return carWash;

}

void Console::displayCarWash(CarWash& carWash){
	Car temp;
	std::cout << "Name:" << carWash.getName() << std::endl;
	std::cout << "Owner:" << carWash.getOwner() << std::endl;
	std::vector<int> ids = carWash.getCarIds();
	std::cout <<"Cars with reservation:" << std::endl;
	for(auto id: ids){
		try{
			temp = this->service.readCar(id);	
		}catch(std::vector<std::string> msgs){
		for(auto msg : msgs){
			std::cout << msg << std::endl;
		}
	}
		
		displayCar(temp);
	}
}

void Console::displayAllCarWash(){
	std::vector<CarWash> carWashes = this->service.getAllCarWashes();
	for(auto carWash: carWashes){
		std::cout << "ID: " << carWash.getId() << " Name: " << carWash.getName() << std::endl;
	}
}



