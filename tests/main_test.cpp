#include "tests/TestCar.h"
#include "tests/TestCarWash.h"
#include "tests/TestEntity.h"
#include "tests/TestRepository.h"
#include "tests/TestService.h"

int main(int argc, char const *argv[])
{
	/* code */
	TestCar().TestAll();
	TestCarWash().TestAll();
	TestEntity().TestAll();
	TestRepository().TestAll();
	TestService().TestAll();
	return 0;
}