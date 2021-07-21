#include "Service.h"
#include "Console.h"
#include "Car.h"
#include "CarWash.h"
#include "RepoFactory.h"
#include "FactorySettings.h"

int main(){
	
	RepoFactory<Car*> *carFactory = carFactory->getInstance();
	RepoFactory<CarWash*> *washFactory = washFactory->getInstance(); 
	IRepository<Car*> *carRepo = carFactory->createRepository(FactorySettings(FileRepoType::file,"car_database.csv"));
	IRepository<CarWash*> *carWashRepo = washFactory->createRepository(FactorySettings(FileRepoType::file,"carwash_database.csv"));

	Validator validator = Validator();
	Service service = Service(validator, carRepo, carWashRepo);
	Console console = Console(service);
	console.run();	
	delete carRepo;
	delete carWashRepo;
	delete carFactory;
	delete washFactory;

}