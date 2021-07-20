#include "MemoryRepository.h"
#include "Car.h"
#include "CarWash.h"
#include <fstream>
#include <iostream>

template<typename Base, typename T2>
inline bool instanceof(const T2*) {
   return std::is_base_of<Base, T2>::value;
}

template <class T>
class FileRepository: public MemoryRepository<T>
{
	std::string fileName;
public:
	FileRepository(){
		this->fileName = "database.csv";
	}

	FileRepository(std::string filePath){
		this->fileName = filePath;
		this->loadFromFile();
	}
	
	void addEntity(T& entity){
		MemoryRepository<T>::addEntity(entity);
		
		this->storeToFile();
	}

	T deleteEntity(int id){
		T entity = MemoryRepository<T>::deleteEntity(id);
		this->storeToFile();
		return entity;
	}

	T updateEntity(T& oldEntity, T& newEntity){
		T entity = MemoryRepository<T>::updateEntity(oldEntity,newEntity);
		return entity;
	}

	void loadFromFile(){
		T object_type;
		std::ifstream ifs(this->fileName);
		
		if(instanceof<Car>(&object_type)) {
			std::string name;
			std::string owner;
			std::string plateNumber;
			std::string id;
			while(!ifs.eof()){
				std::getline(ifs,id,',');
				std::getline(ifs,name,',');
				std::getline(ifs,plateNumber,',');
				std::getline(ifs,owner,'\n');
				if(ifs.eof()) break;
				Car car(name,owner,plateNumber,std::stoi(id));

				void *entity = &car;
				T *entity2 =  static_cast<T*>(entity);
				this->addEntity(*entity2);

			}
		} else if(instanceof<CarWash>(&object_type)){
			while(!ifs.eof()){
				std::string name;
				std::string id;
				std::string owner;
				std::getline(ifs,id,',');
				std::getline(ifs,name,',');
				std::getline(ifs,owner,'\n');
				if(ifs.eof()) break;
				CarWash carWash(name,owner,std::stoi(id));

				void *entity = &carWash;
				T *entity2 =  static_cast<T*>(entity);
				this->addEntity(*entity2);
			}
		}
		ifs.close();
		
	}
	void storeToFile(){
		T object_type;
		std::ofstream ofs(this->fileName);
		for(auto obj: this->database){
			if(instanceof<Car>(&object_type)){
				void *entity = &obj;
				Car *entity2 =  static_cast<Car*>(entity);
				Car car = *entity2;

				ofs << car.getId() << ",";
				ofs << car.getName() << ",";
				ofs << car.getPlateNumber() << ",";
				ofs << car.getOwner() << std::endl;
			} else if(instanceof<CarWash>(&object_type)) {
				void *entity = &obj;
				CarWash *entity2 =  static_cast<CarWash*>(entity);
				CarWash carWash = *entity2;

				ofs << carWash.getId() << ",";
				ofs << carWash.getName() << ",";
				ofs << carWash.getOwner() << std::endl;
			}
		}
		ofs.close();
	}
	
	
};