#include "SmartTeam.hpp"

using namespace std;
namespace ariel
{

	SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

	// helping function for find_victim
	//  counts the number of ninjas that can slash the character from the attacked team
	int SmartTeam::count_close_ninjas(Character *attacked)
	{
		int num_close_ninjas = 0;
		for (Character *attacker : this->getMembers())
		{
			if (attacker != nullptr && attacker->isAlive())
			{
				Ninja *ninja = dynamic_cast<Ninja *>(attacker);
				if (ninja == nullptr)
				{
					continue;
				}
				else if (ninja != nullptr && ninja->isAlive())
				{
					if (ninja->distance(attacked) <= 1)
					{
						num_close_ninjas++;
					}
				}
			}
		}
		return num_close_ninjas;
	}

	// algorithm:
	// 1. iterate on the other team and find the character (cowboy or ninja) that has the the biggest number of ninjas (from attacking team) that can slash it
	// i.e, ninjas that are in <=1 distance to the character
	// that means that the character that will be chosen as victim doesn't necessary have the least HP's.
	// i chose this algorithm since i think it's more efficient to pick the victim that loses the most points (ninjas slash is more deadly than a cowboys shoot, and cowboys shoot each character the same hp's )
	// instead of picking the victim that has the least points.
	// but i also think it's important to consider in the calculation the number of HP's , so i chose to combine the two elements (Hp's and number of ninjas around) for optimal solution.
	Character *SmartTeam::find_victim(Team *other, Character *leader)
	{
		Character *curr_victim = nullptr;
		if (other == nullptr)
		{
			throw invalid_argument("other team is null");
		}
		// iterating on the other team, no preference to cowboy/ninja
		for (Character *character : other->getMembers())
		{
			if (character != nullptr && character->isAlive())
			{
				if (curr_victim == nullptr)
				{
					curr_victim = character;
				}
				else
				{

					if (character->getHP()-40 * count_close_ninjas(character) < curr_victim->getHP()-40 * count_close_ninjas(curr_victim))
					{
						curr_victim = character;
					}
				}
			}
		}
		return curr_victim;
	}
	void SmartTeam::choose_leader(Character *leader)
	{
		// add impl!!!!!!!!!!!1
		//dfg
		return;
	}

	// algorithm:
	// 1. iterate on all the ninjas that their distance from the victim is <=1
	// 2. iterate on all the cowboys that don't need to reload
	// 3. iterate on all the ninjas that their distance from the victim is >1  all the cowboys that need to reload

	void SmartTeam::attack(Team *other)
	{
		if (other == nullptr)
		{
			throw invalid_argument("can't attack an empty group/empty group can't attack");
		}
		if (!other->stillAlive())
		{
			throw runtime_error("can't attack a team with all dead people/can't attack when all people in team are dead");
		}
		if (this->getLeader() == nullptr)
		{
			throw invalid_argument("leader is null");
		}
		// define whos the leader and whos the victim
		if (!this->getLeader()->isAlive())
		{
			choose_leader(this->getLeader());
			if (this->getLeader() == nullptr)
			{
				return;
			}
		}

		Character *victim = find_victim(other, this->getLeader());
		if (victim == nullptr)
		{
			return;
		}

		// 1. iterate on all the ninjas that their distance from the victim is <=1
		for (Character *character : this->getMembers())
		{
			// choose new victim in case the current one is dead
			if (!victim->isAlive())
			{
				victim = find_victim(other, this->getLeader());
				if (victim == nullptr)
				{ // if we haven't found a new victim, the attack is over
					return;
				}
			}

			if (character != nullptr && character->isAlive())
			{
				Ninja *ninja = dynamic_cast<Ninja *>(character);
				if (ninja == nullptr)
				{
					continue;
				}
				else if (ninja != nullptr && ninja->isAlive())
				{
					if (ninja->distance(victim) > 1)
					{
						continue;
					}
					else
					{
						ninja->slash(victim);
					}
				}
			}
		} // end-for-loop

		// 2. iterate on all the cowboys that don't need to reload
		for (Character *character : this->getMembers())
		{
			// choose new victim in case the current one is dead
			if (!victim->isAlive())
			{
				victim = find_victim(other, this->getLeader());
				if (victim == nullptr)
				{ // if we haven't found a new victim, the attack is over
					return;
				}
			}

			if (character != nullptr && character->isAlive())
			{
				Cowboy *cowboy = dynamic_cast<Cowboy *>(character);
				if (cowboy == nullptr)
				{
					continue;
				}
				else if (cowboy != nullptr && cowboy->isAlive())
				{
					if (!cowboy->hasboolets())
					{
						continue;
					}
					else
					{
						cowboy->shoot(victim);
					}
				}
			}
		}

		// 3. iterate on all the ninjas that their distance from the victim is >1
		for (Character *character : this->getMembers())
		{
			// choose new victim in case the current one is dead
			if (!victim->isAlive())
			{
				victim = find_victim(other, this->getLeader());
				if (victim == nullptr)
				{ // if we haven't found a new victim, the attack is over
					return;
				}
			}

			if (character != nullptr && character->isAlive())
			{
				Ninja *ninja = dynamic_cast<Ninja *>(character);
				if (ninja == nullptr)
				{
					Cowboy *cowboy = dynamic_cast<Cowboy *>(character);
					if (cowboy != nullptr && cowboy->isAlive())
					{
						if (!cowboy->hasboolets())
						{
							cowboy->reload();
						}
					}
				}
				else if (ninja->isAlive())
				{
					if (ninja->distance(victim) > 1)
					{
						ninja->move(victim);
					}
				}
			}
		}
	}
};