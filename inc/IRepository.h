#ifndef H_IREPO
#define H_IREPO
#include <list>
template <class T>
class IRepository
 {
 public:
 	virtual T getEntity(int) = 0;
 	virtual void addEntity(T&) = 0;
 	virtual T deleteEntity(int) = 0;
 	virtual T updateEntity(T&,T&) = 0;
 	virtual std::list<T> getAllEntities() = 0;
    virtual ~IRepository(){};
 	
 }; 
#endif