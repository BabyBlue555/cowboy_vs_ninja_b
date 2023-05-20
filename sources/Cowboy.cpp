#include "Cowboy.hpp"

using namespace std;
using namespace ariel;

Cowboy::Cowboy(string name, Point location) : Character(name, location, 110) {}

// Cowboy::~Cowboy(){
// 	delete this;
// }

void Cowboy::shoot(Character *other)
{
	return;
}

bool Cowboy::hasboolets() const
{
	return false;
}

void Cowboy::reload()
{
	return;
}

int Cowboy::getNumBullets() const{
	return _bullets;
}
			

//implement the pure virtual print() in Charachter abstract class 
string Cowboy::print() const
{
	return "";
}