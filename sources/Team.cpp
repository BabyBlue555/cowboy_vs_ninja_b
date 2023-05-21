#include "Team.hpp"
#include <iostream>

using namespace std;
namespace ariel{

	Character* Team::find_victim(Team *other, Character* leader)
	{
		return nullptr;
	}

	Character* Team::choose_leader(Team *other, Character* leader){
		return nullptr;
	}

	Team::Team(Character *leader){
		if(leader->isInTeam()){
			throw runtime_error("in team!");
		}
		this->_leader = leader;
		this->add(leader);
		this->_leader->setInTeam(true);

	}

	Team::~Team()
	{
		
		for (Character* character: this->getMembers()){
				delete character;
		}

	}

	void Team::add(Character *member)
	{
		if(_members.size()==10){
			throw runtime_error("team is full!");
		}
		if(member->isInTeam()){
			throw runtime_error("character already in team");
		}
		_members.push_back(member);
		
		
	}

	void Team::attack(Team *other)
	{
		if(other==nullptr){
			throw runtime_error("nullptr");
		}

	}

	int Team::stillAlive() const
	{
		return _members.size();
	}

	vector<Character*> Team::getMembers(){
		return this->_members;
	}

	void Team::setLeader(Character* leader){
		this->_leader = leader;
	}


	vector<Character*> Team::getTeam() const{
		return this->_members;
	}

	void Team::print() const
	{
		return;
	}
};

