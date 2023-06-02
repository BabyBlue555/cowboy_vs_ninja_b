#include "Character.hpp"
#include <iostream>

#include <cmath>
using namespace std;
namespace ariel{


	Character::Character(string name, Point location, int health_points) : _name(name), _location(location), _hp(health_points), _inteam(false) {}


	bool Character::isAlive() const{
		 return this->_hp > 0;
	}


	double Character::distance(Character *other) const
	{
		if (other == nullptr)
			throw invalid_argument("Other character is null");
		return this->_location.distance(other->getLocation());
	}

	void Character::hit(int power)
	{
		if(power<0){
			throw invalid_argument("Power cannot be negative!");
		}
		if(_hp==0){
			cout<<"character is already dead, can't hit";
			return;
		}
		_hp -= power;
	}

	string Character::getName() const
	{
		return this->_name;
	}

	void Character::setName(string name){
		this->_name=name;
	}

	const Point Character::getLocation() const
	{
		return this->_location;
	}

	void Character::setLocation(Point location){
		this->_location = location;
	}

	bool Character::isInTeam() const{
		return this->_inteam;
	}

	void Character::setInTeam(bool in_team)
	{
		this->_inteam=in_team;
	}

	int Character::getHP() const
	{
		return _hp;
	}
};


 
