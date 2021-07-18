#include "incl/Repository.h"
#include "incl/Service.h"
#include "incl/Console.h"
#include "incl/Car.h"
#include "incl/CarWash.h"

int main(){
	Repository<Car> carRepo = Repository<Car>();
	Repository<CarWash> carWashRepo = Repository<CarWash>();
	Service service = Service(carRepo,carWashRepo);
	Console console = Console(service);
	console.run();

}