#include "../Entity/sprite.cpp"

#include <iostream>
#pragma once

namespace entity
{
	struct Entity
	{
		//Variables
		sf::Vector2f topLeft;
		sf::Vector2f size;
		entity::Sprite *parts;
		sf::Vector2f velocity;

		//Constructors
		Entity(entity::Sprite Sprites[])
		{
			topLeft = sf::Vector2f(0.f, 0.f);
			velocity = sf::Vector2f(0.f, 0.f);
			parts = Sprites;
			for(int i = 0; i < 2; ++i) //finds max size of textures
			{
				sf::Texture img = *Sprites[i].getTexture();
				sf::Vector2u localSize = img.getSize();
				if (size.x <= localSize.x)
					size.x = localSize.x;
				if (size.y <= localSize.y)
					size.y = localSize.y;
			}
		}

		Entity()
		{
			topLeft = sf::Vector2f(0.f, 0.f);
			velocity = sf::Vector2f(0.f, 0.f); 
		}

		void setPosition(sf::Vector2f position) // sets entity members position
		{
			for (int i = 0; i < 2; ++i) // needs fixed
			{
				parts[i].setPosition( position);
			}
			topLeft = position;
		}

		void setRotation(float degrees) //Sets rotation of an entity //not working
		{
			for (int i = 0; i < 2; ++i)
			{
				parts[i].setRotation(degrees);
			}
		}

		void setColor(sf::Color color, int sprite) // sets sprite color
		{
			parts[sprite].setColor(color);
		}

		void move(sf::RenderWindow &window, sf::Vector2f gravity) //Move tick for an entity
		{
			//gravity
			velocity.x = velocity.x + gravity.x; 
			velocity.y = velocity.y + gravity.y;

			//movement
			topLeft = topLeft + velocity;

			//bounds
			if (topLeft.x > window.getSize().x - size.x)
			{
				topLeft.x = window.getSize().x - size.x;
				velocity.x = -velocity.x;
			}
			else if (topLeft.x < 0.f)
			{
				topLeft.x = 0.f;
				velocity.x = -velocity.x;
			}

			if (topLeft.y > window.getSize().y - size.y)
			{
				topLeft.y = window.getSize().y - size.y;
				velocity.y = -velocity.y;
			}
			else if (topLeft.y < 0.f)
			{
				topLeft.y = 0.f;
				velocity.y = -velocity.y;
			}
			setPosition(topLeft);
		}

		void setVelocity(sf::Vector2f Velocity) //sets velocity to a vector (x,y)
		{
			velocity = Velocity;
		}

		void setVelocity(float x, float y) //sets velocity to a pair of ints (x,y)
		{
			velocity = sf::Vector2f(x, y);
		}

		// Return the entity's array of sprites as a pointer value
		entity::Sprite *getSprites()
		{
			return parts;
		}
	};
}