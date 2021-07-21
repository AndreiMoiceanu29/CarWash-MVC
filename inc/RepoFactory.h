#ifndef H_FACTORY_REPO
#define H_FACTORY_REPO
#include <string>
#include "FileRepository.h"
template <class T>
class RepoFactory
{
private:
	static RepoFactory<T>* instance;
	RepoFactory(){}
public:
	
	
	IRepository<T>* createRepository(std::string type){
		if(type == "file"){
			return new FileRepository<T>();
		}else if(type == "memory"){
			return new MemoryRepository<T>();
		}
		return NULL;
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