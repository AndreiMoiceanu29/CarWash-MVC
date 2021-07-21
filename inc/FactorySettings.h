#ifndef H_FACTORY_SETTINGS
#define H_FACTORY_SETTINGS
#include <string>
namespace FileRepoType {
	enum type {
		memory, file
	};	
}


class FactorySettings
{
private:
	FileRepoType::type repoType;
	std::string filePath;
public:
	FactorySettings();
	FactorySettings(FileRepoType::type);
	FactorySettings(FileRepoType::type, std::string);
	
	FileRepoType::type getRepoType();
	void setRepoType(FileRepoType::type);

	std::string getFilePath();
	void setFilePath(std::string);
	~FactorySettings();
	
};
#endif