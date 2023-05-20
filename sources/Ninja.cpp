#include "Ninja.hpp"

using namespace std;
using namespace ariel;

Ninja::Ninja(string name, Point location, int health_points, int speed) : Character(name, location, health_points), _speed(speed) {}

// Ninja::~Ninja(){
// 	delete this;
// }

void Ninja::move(Character *other)
{
	return;
}

void Ninja::slash(Character *other)
{
	return;
}

string Ninja::print() const
{
	return "";
}

