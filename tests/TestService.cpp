#include "tests/TestService.h"
#include "Service.h"
#include "Car.h"
#include "CarWash.h"
#include <assert.h>
#include <vector>
#include "Repository.h"
TestService::TestService(){}

void TestService::TestAll(){
	this->TestCreateAndReadCar();
	this->TestUpdateCar();
	this->TestDeleteCar();
	this->TestCreateAndReadCarwash();
	this->TestUpdateCarwash();
	this->TestDeleteCarwash();
	this->TestMakeReservation();
	this->TestGetAllCarWashes();
}

void TestService::TestCreateAndReadCar(){
	Repository<Car> carRepo;
	Repository<CarWash> carWashRepo;
	Service service(carRepo,carWashRepo);
	Car car("Dacia","Andrei","AG00AAA",1);
	service.createCar(car);
	Car carB = service.readCar(1);
	assert(car.getId() == carB.getId());
}

void TestService::TestUpdateCar(){
	Repository<Car> carRepo;
	Repository<CarWash> carWashRepo;
	Service service(carRepo,carWashRepo);
	Car car("Dacia","Andrei","AG00AAA",1);
	service.createCar(car);
	Car newCar("BMW","Andrei","AG29MSE",2);
	service.updateCar(car,newCar);
	Car carB = service.readCar(2);
	assert(carB.getId() == newCar.getId());
}

void TestService::TestDeleteCar(){
	Repository<Car> carRepo;
	Repository<CarWash> carWashRepo;
	Service service(carRepo,carWashRepo);
	Car car("Dacia","Andrei","AG00AAA",1);
	service.createCar(car);
	Car deletedCar = service.deleteCar(1);
	assert(car.getId() == deletedCar.getId());
}

void TestService::TestCreateAndReadCarwash(){
	Repository<Car> carRepo;
	Repository<CarWash> carWashRepo;
	Service service(carRepo,carWashRepo);
	CarWash carWash("Self","Moiceanu Andrei",22);
	service.createCarWash(carWash);
	CarWash addedCarWash = service.readCarWash(22);
	assert(addedCarWash.getId() == carWash.getId());
}

void TestService::TestUpdateCarwash(){
	Repository<Car> carRepo;
	Repository<CarWash> carWashRepo;
	Service service(carRepo,carWashRepo);
	CarWash carWash("Self","Moiceanu Andrei",22);
	service.createCarWash(carWash);
	CarWash newCarWash("Oxi","Moiceanu Andrei",33);
	CarWash updatedCarWash = service.updateCarWash(carWash,newCarWash);
	assert(updatedCarWash.getId() == newCarWash.getId());
}

void TestService::TestDeleteCarwash(){
	Repository<Car> carRepo;
	Repository<CarWash> carWashRepo;
	Service service(carRepo,carWashRepo);
	CarWash carWash("Self","Moiceanu Andrei",22);
	service.createCarWash(carWash);
	CarWash deletedCarWash = service.deleteCarWash(22);
	assert(deletedCarWash.getId() == carWash.getId());
}

void TestService::TestMakeReservation(){
	Repository<Car> carRepo;
	Repository<CarWash> carWashRepo;
	Service service(carRepo,carWashRepo);
	CarWash carWash("Self","Moiceanu Andrei",22);
	service.createCarWash(carWash);
	Car car("Dacia Sandero","Moiceanu Andrei","AG06DGA",2);
	service.createCar(car);
	service.makeReservation(2,22);
	std::vector<int> carIds = service.readCarWash(22).getCarIds();
	bool isInRange = false;


	for(int i=0;i<carIds.size();i++){
				if(carIds[i] == 2){
			isInRange = true;
		}
	}
	assert(isInRange == true);
}

void TestService::TestGetAllCarWashes(){
	Service servA;
	Repository<Car> carRepo;
	Repository<CarWash> carWashRepo;
	Service service(carRepo,carWashRepo);
	CarWash carWash("Self","Moiceanu Andrei",22);
	CarWash carB("Oxi","Moiceanu Andrei",33);
	std::vector<CarWash> washes;
	washes.push_back(carWash);
	washes.push_back(carB);
	service.createCarWash(carWash);
	service.createCarWash(carB);
	std::vector<CarWash> servWashes = service.getAllCarWashes();
	for(int i=0; i<servWashes.size();i++){
		assert(servWashes[i].getId() == washes[i].getId());
	}
}