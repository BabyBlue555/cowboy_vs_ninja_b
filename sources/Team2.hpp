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
class Team2 : public Team{
		public:
			/*
			* @brief Construct a new Team2 object.
			* @param leader A pointer to the leader of the team.
			*/
			Team2(Character *leader);

			/*
			* @brief Find a victim to attack.
			* @param other A pointer to the other team.
			* @return A pointer to the victim, or nullptr if there is no victim.
			* @note the preference to ninja or cowboy in the order
			*/
			Character* find_victim(Team *other, Character* leader);

			/* @brief Choose another leader in case the current one is dead
			* @param leader a pointer to the current leader
			* @note the preference to ninja or cowboy in the order
			*/
			void choose_leader(Character* leader);

			/*
			* @brief Attack the other team
			* @param other A pointer to the other team
			*/
			void attack(Team *other) ;

		
	};
};


