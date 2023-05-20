//#include "Point.hpp"

#include "Character.hpp"
#include <iostream>

#include <cmath>
using namespace std;
using namespace ariel;



Character::Character(string name, Point &location, int health_points) : _name(name), _location(location), _hp(health_points), _inteam(false) {}

// Character::~Character(){
// 	delete this;
// }

bool Character::isAlive() const{
	if(_hp>0)
		return 1;
	return 0;
}


double Character::distance(Character *other) const
{
	if (other == nullptr)
		throw invalid_argument("Other character is null");
	return this->distance(other);
}

void Character::hit(int power)
{
	if(power<0){
		throw invalid_argument("Power cannot be negative!");;
	}
	_hp -= (_hp - power < 0 ? _hp : power);

	if (_hp == 0)
		cout << _name << " died." << endl;
	// this->_hp-=power;
}

string Character::getName() const
{
	return this->_name;
}

void Character::setName(string name){
	this->_name=name;
}

const Point& Character::getLocation() const
{
	return _location;
}

void Character::setLocation(Point &location)
{
	this->_location = location;
}

bool Character::isInTeam() const
{
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

// void Character::setHP(int ){
	
// }



 