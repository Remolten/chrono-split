#include "../Entity/sprite.cpp"
#pragma once

namespace entity
{
	struct Entity
	{
		//Variables
		int centerX;
		int centerY;
		int centerVelocityX;
		int centerVelocityY;
		entity::Sprite *parts;

		//Constructors
		Entity(entity::Sprite Sprites[])
		{
			centerX = 0;
			centerY = 0;
			centerVelocityX = 0;
			centerVelocityY = 0;
			parts = Sprites;
		}

		Entity()
		{
			centerX = 0;
			centerY = 0;
			centerVelocityX = 0;
			centerVelocityY = 0;
		}

		// Return the entity's array of sprites as a pointer value
		entity::Sprite *getSprites()
		{
			return parts;
		}
	};
}