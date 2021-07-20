#include "Repository.h"
#include "Service.h"
#include "Console.h"
#include "Car.h"
#include "CarWash.h"

int main(){
	Repository<Car> carRepo = Repository<Car>();
	Repository<CarWash> carWashRepo = Repository<CarWash>();
	Validator validator = Validator();
	Service service = Service(validator, carRepo, carWashRepo);
	Console console = Console(service);
	console.run();
}