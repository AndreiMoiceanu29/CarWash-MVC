#ifndef H_FILE_REPO
#define H_FILE_REPO
#include "MemoryRepository.h"
#include "Car.h"
#include "CarWash.h"
#include <fstream>
#include <iostream>
#include "Utilities.h"


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
		T *object_type = new T;
		std::ifstream ifs(this->fileName);
		
		if(Utilities::instanceof<Car>(*object_type)) {
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
				Car *car = new Car(name,owner,plateNumber,std::stoi(id));

				T *entity =  static_cast<T*>(static_cast<void*>(&car));

				this->addEntity(*entity);

			}
		} else if(Utilities::instanceof<CarWash>(*object_type)){
			while(!ifs.eof()){
				std::string name;
				std::string id;
				std::string owner;
				std::string carIdsUntokenized;
				std::getline(ifs,id,',');
				std::getline(ifs,name,',');
				std::getline(ifs,owner,',');
				std::getline(ifs,carIdsUntokenized,'\n');
				std::vector<std::string> carIds = Utilities::split(carIdsUntokenized.c_str(),':');
				std::vector<int> ids;
				for(auto carId: carIds){
					if(carId.size() != 0){
						//Adauga carWash la masina;

						ids.push_back(stoi(carId));
					}
				}

				if(ifs.eof()) break;
				CarWash* carWash = new CarWash(name,owner,std::stoi(id));
				carWash->setCarIds(ids);
				T *entity =  static_cast<T*>(static_cast<void*>(&carWash));

				this->addEntity(*entity);
			}
		}
		ifs.close();
		
	}
	void storeToFile(){
		T *object_type = new T;
		std::ofstream ofs(this->fileName);

		for(auto obj: this->database){

			if(Utilities::instanceof<Car>(*object_type)){

				Car *car = static_cast<Car*>(static_cast<void*>(obj));
				
				ofs << car->getId() << ",";
				ofs << car->getName() << ",";
				ofs << car->getPlateNumber() << ",";
				ofs << car->getOwner() << std::endl;
			} else if(Utilities::instanceof<CarWash>(*object_type)) {
				CarWash *carWash = static_cast<CarWash*>(static_cast<void*>(obj));
				std::vector<int> carIds = carWash->getCarIds();

				ofs << carWash->getId() << ",";
				ofs << carWash->getName() << ",";
				ofs << carWash->getOwner() << ",";
				for(auto id : carIds){
					ofs << id << ":";
				}
				ofs << std::endl;

			}
		}
		ofs.close();
	}
	
	
};
#endif