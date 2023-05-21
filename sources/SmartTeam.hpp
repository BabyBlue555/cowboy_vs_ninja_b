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

			/*
			* @brief Attack the other team
			* @param other A pointer to the other team
			*/
			void attack(Team *other) override;

			/*
			* @brief Print the team members
			*/
			void print() const override;
	};
};