#include "../Entity/sprite.cpp"

namespace Entity
{
	struct Entity
	{
		int centerX = 0;
		int centerY = 0;
		int centerVelocityX = 0;
		int centerVelocityY = 0;

		Entity::Sprite *Parts;

		Entity(Entity::Sprite Sprites[])
		{
			Parts = Sprites;
		}
	};
}