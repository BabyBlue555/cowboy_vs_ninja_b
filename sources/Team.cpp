#include "Team.hpp"
#include <iostream>

using namespace std;
namespace ariel
{

	// helping links: 1. https://www.educative.io/answers/how-to-iterate-through-a-vector-in-cpp
	// 2. https://www.geeksforgeeks.org/dynamic-_cast-in-cpp/

	Team::Team(Character *leader) : _leader(leader), _members(0)
	{
		if (leader->isInTeam())
		{
			throw runtime_error("leader in another team!");
		}
		// this->_leader = leader;
		this->add(leader);
		// this->_leader->setInTeam(true);
	}

	Team::~Team()
	{

		for (Character *character : this->getMembers())
		{
			delete character;
		}
	}

	void Team::add(Character *member)
	{
		if (_members.size() == 10)
		{
			throw runtime_error("team is full!");
		}
		if (member->isInTeam())
		{
			throw runtime_error("character already in team");
		}
		else
		{
			_members.push_back(member);
			member->setInTeam(true);
		}
	}

	Character *Team::find_victim(Team *other, Character *leader)
	{
		Character *curr_victim = nullptr;

		// iterating only on the Cowboys, using dynamic_cast
		for (Character *character : other->getMembers())
		{
			if (character != nullptr && character->isAlive())
			{
				Cowboy *cowboy = dynamic_cast<Cowboy *>(character);
				if (cowboy == nullptr)
				{
					continue;
				}
				else
				{

					// check distance from our teams' leader
					if (curr_victim == nullptr)
					{
						curr_victim = character;
					}
					else
					{
						if (character->distance(leader) < curr_victim->distance(leader))
							curr_victim = character;
					}
					//}
				}
			}
		}

		// iterating only on the Ninjas, using dynamic_cast
		for (Character *character : other->getMembers())
		{
			if (character != nullptr && character->isAlive())
			{
				Ninja *ninja = dynamic_cast<Ninja *>(character);
				if (ninja == nullptr)
				{
					continue;
				}
				else
				{
					// if (character->isAlive())
					// {
						// check distance from our teams' leader
						if (curr_victim == nullptr)
						{
							curr_victim = character;
						}
						else
						{
							if (character->distance(leader) < curr_victim->distance(leader))
								curr_victim = character;
						}
					//}
				}
			}
		}

		return curr_victim;
	}

	void Team::choose_leader(Character *leader)
	{
		Character *new_leader = nullptr;
		//Cowboy *cowboy = nullptr;
		//Ninja *ninja = nullptr;

		// iterating only on the Cowboys in our team, using dynamic_cast
		for (Character *character : this->getMembers())
		{
			if (character != nullptr && character->isAlive())
			{

				Cowboy *cowboy= dynamic_cast<Cowboy *>(character);
				if (cowboy != nullptr && cowboy->isAlive())
				{
					// if ()
					// {
						// check distance from our teams' leader
						if (new_leader == nullptr)
						{
							new_leader = character;
						}
						else
						{
							if (character->distance(leader) < new_leader->distance(leader))
								new_leader = character;
						}
					}
				//}
			}
		}
		for (Character *character : this->getMembers())
		{
			if (character != nullptr && character->isAlive())
			{
				Ninja *ninja = dynamic_cast<Ninja *>(character);
				if (ninja != nullptr && ninja->isAlive())
				{
					// if (character->isAlive())
					// {
						// check distance from our teams' leader
						if (new_leader == nullptr)
						{
							new_leader = character;
						}
						else
						{
							if (character->distance(leader) < new_leader->distance(leader))
								new_leader = character;
						}
					}
			//	}
			}
		}
		if (new_leader == nullptr)
		{
			cout << "no leader found" << endl;
			return;
		}

		this->setLeader(new_leader);
	}

	void Team::attack(Team *other)
	{
		if (other == nullptr)
		{
			throw invalid_argument("can't attack an empty group/empty group can't attack");
		}
		if (!other->stillAlive())
		{
			throw runtime_error("can't attack a team with all dead people/can't attack when all people in team are dead");
		}

		if(this->_leader==nullptr){
			throw invalid_argument("leader is null");
		}
		// define whos the leader and whos the victim
		if (!this->_leader->isAlive())
		{
			choose_leader(this->_leader);
			if (_leader == nullptr)
			{
				return;
			}
		}
		Character *victim = find_victim(other, this->_leader);
		if (victim == nullptr)
		{
			return;
		}

		// iterating only on cowboys in our team
		// the cowboys shoot the victim
		for (Character *character : this->_members)
		{
			// choose new victim in case the current one is dead
			if (!victim->isAlive())
			{
				victim = find_victim(other, this->_leader);
				if (victim == nullptr)
				{ // if we haven't found a new victim, the attack is over
					break;
				}
			}

			if (character != nullptr && character->isAlive())
			{
				Cowboy *cowboy = dynamic_cast<Cowboy *>(character);
				// if (cowboy == nullptr)
				// {
				// 	continue;
				// }
				// else
				if (cowboy != nullptr&& cowboy->isAlive())
				{
					// if ()
					// {
						if (cowboy->hasboolets())
						{
							cowboy->shoot(victim);
						}
						else
						{
							cowboy->reload();
						}
					//}
				}
			}
		}

		// iterating only on ninjas in our team
		// the ninjas can either slash the victim, or move towards them.
		for (Character *character : this->_members)
		{
			// choose new victim in case the current one is dead
			// if (!victim->isAlive())
			// {
			victim = find_victim(other, this->_leader);
			if (victim == nullptr)
			{ // if we haven't found a new victim, the attack is over
				break;
			}
			//}

			if (character != nullptr && character->isAlive())
			{
				Ninja *ninja = dynamic_cast<Ninja *>(character);
				// if (ninja == nullptr)
				// {
				// 	continue;
				// }
				// else
				if (ninja != nullptr && ninja->isAlive())
				{
					// if ()
					// {
						if (ninja->getLocation().distance(victim->getLocation()) <= 1)
						{
							ninja->slash(victim);
						}
						else
						{
							ninja->move(victim);
						}
					}
				//}
			}
		}
	}

	int Team::stillAlive() const
	{
		int count_alive = 0;
		for (Character *character : this->_members)
		{
			if (character!=nullptr &&character->isAlive())
			{
				count_alive++;
			}
		}
		return count_alive;
	}

	vector<Character *> Team::getMembers()
	{
		return this->_members;
	}

	Character *Team::getLeader()
	{
		return _leader;
	}

	void Team::setLeader(Character *leader)
	{
		this->_leader = leader;
	}

	vector<Character *> Team::getTeam() const
	{
		return this->_members;
	}

	void Team::print() const
	{
		return;
	}
};
