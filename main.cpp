#include "Service.h"
#include "Console.h"
#include "Car.h"
#include "CarWash.h"
#include "RepoFactory.h"

int main(){
	
	RepoFactory<Car> *carFactory = carFactory->getInstance();
	RepoFactory<CarWash> *washFactory = washFactory->getInstance(); 
	IRepository<Car> *carRepo = carFactory->createRepository("file");
	IRepository<CarWash> *carWashRepo = washFactory->createRepository("memory");

	Validator validator = Validator();
	Service service = Service(validator, carRepo, carWashRepo);
	Console console = Console(service);
	console.run();
}