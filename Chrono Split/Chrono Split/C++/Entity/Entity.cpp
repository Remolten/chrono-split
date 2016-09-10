#include "../Entity/sprite.cpp"

namespace Entity
{
	struct Entity
	{
		int centerX = 0;
		int centerY = 0;
		int centerVelocityX = 0;
		int centerVelocityY = 0;

		Entity::Sprite *parts;

		Entity(Entity::Sprite Sprites[])
		{
			parts = Sprites;
		}

		Entity::Sprite getSprites()
		{
			return *parts;
		}
	};
}