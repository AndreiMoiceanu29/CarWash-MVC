#include "Service.h"

class TestService
{
private:
	void TestCreateAndReadCar();
	void TestUpdateCar();
	void TestDeleteCar();
	void TestCreateAndReadCarwash();
	void TestUpdateCarwash();
	void TestDeleteCarwash();
	void TestMakeReservation();
	void TestGetAllCarWashes();
public:
	TestService();
	void TestAll();
	
};