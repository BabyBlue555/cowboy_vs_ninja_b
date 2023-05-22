#include "Cowboy.hpp"
#include <iostream>

using namespace std;
namespace ariel{

	 Cowboy::Cowboy(string name,Point location): Character(name, location, 110 ), _bullets(6) {}

	void Cowboy::shoot(Character *other)
	{
		if(this==other){
			throw runtime_error("No self harm, chill out men!");
		}
		if(!this->isAlive() || !other->isAlive()){
			throw runtime_error("character is dead");
		}
		if(!this->hasboolets()){
			return;
		}

		other->hit(10);
		this->_bullets-=1;
	}

	bool Cowboy::hasboolets() const
	{
		 return this->_bullets > 0;
	}

	void Cowboy::reload()
	{
		if(!this->isAlive()){
			throw runtime_error("dead cowboy can't reload");
		}

		this->_bullets = 6;
		
	}

	int Cowboy::getNumBullets() const{
		return _bullets;
	}
				

	//implement the pure virtual print() in Charachter abstract class 
	string Cowboy::print() const
	{
		if(!this->isAlive()){
			return "Cowboy";
		}
		return "(C " + this->getName() + ")";
	}
};
