#ifndef H_FACTORY_REPO
#define H_FACTORY_REPO
#include <string>
#include "FileRepository.h"
#include "FactorySettings.h"
template <class T>
class RepoFactory
{
private:
	static RepoFactory<T>* instance;
	RepoFactory(){}
public:
	
	
	IRepository<T>* createRepository(FactorySettings settings){
		if(settings.getRepoType() == FileRepoType::file){
			return new FileRepository<T>(settings.getFilePath());
		}else{
			return new MemoryRepository<T>();
		}
		
	}

	static RepoFactory<T>* getInstance(){
		if(!instance)
			instance = new RepoFactory<T>;
		return instance;
		
	}
};
template <class T>
RepoFactory<T> *RepoFactory<T>::instance =0; 
#endif