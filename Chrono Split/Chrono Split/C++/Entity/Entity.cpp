#include "../Entity/sprite.cpp"
#include <string>
#pragma once

namespace entity
{
	struct Entity
	{    
        // Variables
		sf::Vector2f topLeft;
		sf::Vector2f size;
		entity::Sprite *parts;
		sf::Vector2f velocity;
        
        // Constructor
        // Takes an array of arrays of the form [[texture_file_path, texture_name], ...]
		Entity(std::string texture_names[], sf::Texture *textures[], unsigned int number_of_sprites)
		{
            // Variables
            topLeft = sf::Vector2f(0.f, 0.f);
			velocity = sf::Vector2f(0.f, 0.f);
            parts = new entity::Sprite[number_of_sprites];// Make the sprite container
            
			// Make the sprite and textures and store in the Entity container
            for (unsigned int i = 0; i < number_of_sprites; i++)
            {
                //  Create sprite and assign images
                entity::Sprite sprite;
                sprite.addImage(texture_names[i], textures[i]);
                sprite.switchTextureTo(texture_names[i]);
                parts[i] = sprite;
                
                //  Set the size
                sf::Vector2u localSize = textures[i]->getSize();
                
                if (size.x <= localSize.x)
                {
                    size.x = localSize.x;
                }
                if (size.y <= localSize.y)
                {
                    size.y = localSize.y;
                }
            }
        }

		// Sets entity members position
		void setPosition(sf::Vector2f position) 
		{
			for (int i = 0; i < 2; ++i) //  needs fixed
			{
				parts[i].setPosition(position);
			}
			topLeft = position;
		}

		// Sets sprite color
		void setColor(sf::Color color, int sprite)
		{
			parts[sprite].setColor(color);
		}

		// Move tick for an entity
		void move(sf::RenderWindow &window, sf::Vector2f gravity) 
		{
			velocity.x = velocity.x + gravity.x;
			velocity.y = velocity.y + gravity.y;
			topLeft = topLeft + velocity;

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

		// Sets velocity to a vector (x,y)
		void setVelocity(sf::Vector2f Velocity) 
		{
			velocity = Velocity;
		}
            
        // Return the entity's array of sprites as a pointer value
		entity::Sprite *getSprites()
		{
			return parts;
		}
        
        // Destructor
        ~Entity()
        {
            delete[] parts;// Explicitly delete parts when finished to avoid memory corruption
        }
	};
}