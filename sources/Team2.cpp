#include "Team2.hpp"

using namespace std;
namespace ariel
{

	Team2::Team2(Character *leader) : Team(leader) {}

	Character *Team2::find_victim(Team *other, Character *leader)
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
					if (character->distance(leader) < curr_victim->distance(leader))
					{
						curr_victim = character;
					}
				}
			}
		}

		return curr_victim;
	}

	void Team2::choose_leader(Character *leader)
	{
		Character *new_leader = nullptr;
		for (Character *character : this->getMembers())
		{
			if (character != nullptr && character->isAlive())
			{
				if (new_leader == nullptr)
				{
					new_leader = character;
				}
				else
				{
					// if (leader == nullptr)
					// { // give explanation
					// 	break;
					// }
					if (character->distance(leader) < new_leader->distance(leader))
					{
						new_leader = character;
					}
				}
			}
		}
		if (new_leader == nullptr)
		{
			cout << "no leader found" << endl;
			return;
		}

		this->setLeader(new_leader);
	}

	void Team2::attack(Team *other)
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

		// iterating on our team - no preference to cowboy/ninja
		// using dynamic cast in order to use the method of cowboy/ninja
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
				if (cowboy == nullptr) // means the original form of the character is ninja
				{
					Ninja *ninja = dynamic_cast<Ninja *>(character);
					if (ninja != nullptr && ninja->isAlive())
					{

						if (ninja->getLocation().distance(victim->getLocation()) <= 1)
						{
							ninja->slash(victim);
						}
						else
						{
							ninja->move(victim);
						}
					}
				}

				else
				{
					if (cowboy != nullptr && cowboy->isAlive())
					{
						if (cowboy->hasboolets())
						{
							cowboy->shoot(victim);
						}
						else
						{
							cowboy->reload();
						}
					}
				}
			}
		}
	}

	void Team2::print() const
	{
		return;
	}

};
