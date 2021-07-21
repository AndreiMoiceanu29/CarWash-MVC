#include "tests/TestCar.h"
#include "tests/TestCarWash.h"
#include "tests/TestEntity.h"
#include "tests/TestMemoryRepository.h"
#include "tests/TestService.h"
#include "tests/TestValidator.h"
#include "tests/TestCSVFileRepository.h"
int main(int argc, char const *argv[])
{
	/* code */
	TestCar().TestAll();
	TestCarWash().TestAll();
	TestEntity().TestAll();
	TestMemoryRepository().TestAll();
	TestService().TestAll();
	TestValidator().TestAll();
	//TestCSVFileRepository().TestAll();
	return 0;
}