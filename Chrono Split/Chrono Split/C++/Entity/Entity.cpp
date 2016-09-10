#include "../Entity/sprite.cpp"

namespace entity
{
	struct Entity
	{
		//Variables
		int centerX = 0;
		int centerY = 0;
		int centerVelocityX = 0;
		int centerVelocityY = 0;
		entity::Sprite *parts;

		//Constructor
		Entity(entity::Sprite Sprites[])
		{
			parts = Sprites;
		}

		//Return array of Sprites
		entity::Sprite getSprites()
		{
			return *parts;
		}
	};
}