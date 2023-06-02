#pragma once

#include <vector>
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "Character.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Team.hpp"

namespace ariel
{
class SmartTeam : public Team
	{
		public:
			/*
			* @brief Construct a new SmartTeam object.
			* @param leader A pointer to the leader of the team.
			*/
			SmartTeam(Character *leader);

			int count_close_ninjas(Character *attacked);
			
			/*
			* @brief Find a victim to attack.
			* @param other A pointer to the other team.
			* @return A pointer to the victim, or nullptr if there is no victim.
			*/
			Character* find_victim(Team *other, Character* leader);


			/* @brief Choose another leader in case the current one is dead
			* @param leader a pointer to the current leader
			*/
			void choose_leader(Character* leader);

			/*
			* @brief Attack the other team
			* @param other A pointer to the other team
			*/
			void attack(Team *other) ;
	};
};