#include "MemoryRepository.h"
#include "FileRepository.h"
#include "Service.h"
#include "Console.h"
#include "Car.h"
#include "CarWash.h"

int main(){
	FileRepository<Car> carRepo = FileRepository<Car>("car_database.csv");
	FileRepository<CarWash> carWashRepo = FileRepository<CarWash>("carwash_database.csv");
//	MemoryRepository<CarWash> carWashRepo = MemoryRepository<CarWash>();

	Validator validator = Validator();
	Service service = Service(validator, &carRepo, &carWashRepo);
	Console console = Console(service);
	console.run();
}