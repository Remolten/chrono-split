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

		//Constructor
		Entity(entity::Sprite Sprites[])
		{
			centerX = 0;
			centerY = 0;
			centerVelocityX = 0;
			centerVelocityY = 0;
			parts = Sprites;
		}

		//Return array of Sprites
        // Note: this doesn't work atm
		entity::Sprite getSprites()
		{
			return *parts;
		}
	};
}