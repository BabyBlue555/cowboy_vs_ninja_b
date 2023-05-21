#include "Ninja.hpp"

using namespace std;
namespace ariel{

	Ninja::Ninja(string name, Point location, int health_points, int speed) : Character(name, location, health_points), _speed(speed) {}



	void Ninja::move(Character *other)
	{
		Point dest = Point::moveTowards(this->getLocation(), other->getLocation(), this->getSpeed());
		this->setLocation(dest);
	}

	void Ninja::slash(Character *other)
	{
		if(this==other){
			throw runtime_error("No self harm, chill out men!");
		}
		if(!this->isAlive() || !other->isAlive()){
			throw runtime_error("character is dead");
		}
		if(this->distance(other) > 1){
            return;
        }
        else{
            other->hit(40);
        }
	}

	string Ninja::print() const
	{
		if(!this->isAlive()){
			return "Ninja";
		}
		return "(N " + this->getName() + ")";
	}
};
