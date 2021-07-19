#include "Repository.h"
#include "Service.h"
#include "Console.h"
#include "Car.h"
#include "CarWash.h"

int main(){
	Repository<Car> carRepo = Repository<Car>();
	Repository<CarWash> carWashRepo = Repository<CarWash>();
	Service service = Service(carRepo,carWashRepo);
	Console console = Console(service);
	console.run();
}