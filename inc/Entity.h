
#ifndef H_ENTITY
#define H_ENTITY
class Entity
{
protected:
	int id;
public:
	Entity();
	int getId();
	//Seteaza un id. Acesta trebuie sa fie pozitiv. Pentru id < 0 => id = 0
	void setId(int);
	~Entity();
	
};
#endif