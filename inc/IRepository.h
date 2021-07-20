#ifndef H_IREPO
#define H_IREPO
#include <vector>
template <class T>
class IRepository
 {
 public:
 	virtual T getEntity(int) = 0;
 	virtual void addEntity(T&) = 0;
 	virtual T deleteEntity(int) = 0;
 	virtual T updateEntity(T&,T&) = 0;
 	virtual std::vector<T> getAllEntities() = 0;
 	
 }; 
#endif