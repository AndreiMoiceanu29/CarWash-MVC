#ifndef H_TEST_FILE_REPO
#define H_TEST_FILE_REPO


class TestCSVFileRepository
{
private:
	void TestLoadAndStoreFromFile();
	void TestLoadAndStoreCarWash();
	void TestUpdate();
	void TestDelete();

public:
	TestCSVFileRepository();
	void TestAll();
	
};
#endif