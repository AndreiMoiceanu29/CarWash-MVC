#ifndef H_REPOSITORY
#define H_REPOSITORY


#include <vector>
#include <string>

template <class T>
class Repository{
	std::vector<T> database;

public:
	T getEntity(int);
	T addEntity(T&);
	T deleteEntity(int);
	T updateEntity(T&,T&);
	std::vector<T> getAllEntities();
};

#include "../Repository/Repository.cpp"

#endif