#include "../Entity/sprite.cpp"

namespace entity
{
	struct Entity
	{
		int centerX = 0;
		int centerY = 0;
		int centerVelocityX = 0;
		int centerVelocityY = 0;

		entity::Sprite *parts;

		Entity(entity::Sprite Sprites[])
		{
			parts = Sprites;
		}

		entity::Sprite getSprites()
		{
			return *parts;
		}
	};
}