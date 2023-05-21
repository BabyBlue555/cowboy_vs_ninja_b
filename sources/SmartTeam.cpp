#include "SmartTeam.hpp"

using namespace std;
namespace ariel{

	SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

	void SmartTeam::attack(Team *other)
	{
		return;
	}

	void SmartTeam::print() const
	{
		return;
	}
};