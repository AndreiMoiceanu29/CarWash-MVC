#include "tests/TestCar.h"
#include "tests/TestCarWash.h"
#include "tests/TestEntity.h"

int main(int argc, char const *argv[])
{
	/* code */
	TestCar().TestAll();
	TestCarWash().TestAll();
	TestEntity().TestAll();
	return 0;
}