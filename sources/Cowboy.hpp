#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"

namespace ariel
{

	class Cowboy : public Character
	{
	
		private:
			/*
			* @brief The number of bullets the cowboy has.
			*/
			int _bullets;

		public:
			/*
			* @brief Construct a new Cowboy object.
			* @param name The name of the cowboy.
			* @param location The starting location of the cowboy.
			*/
			Cowboy(std::string name,Point location);

			
		
			/*
			* @brief Shoots another character.
			* @param other The other character.
			* @return void
			* @note If the other character is alive and the distance between the two characters is less than or equal to 10, the other character is hit.
			*/
			void shoot(Character *other);

			/*
			* @brief Checks if the cowboy has bullets.
			* @return True if the cowboy has bullets, false otherwise.
			*/
			bool hasboolets() const;

			/*
			* @brief Reloads the cowboy's gun back to 6 bullets.
			* @return void
			*/
			void reload();

			/*@brief get the current number of bullets the cowboy has
			* @return int number of bullets 
			*/
			int getNumBullets() const;
			/*
			* @brief Prints the cowboy.
			* @return string
			*/
			std::string print() const override;

	};
};
#endif