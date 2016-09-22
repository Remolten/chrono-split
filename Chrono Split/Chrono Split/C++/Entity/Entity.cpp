#include "../Entity/sprite.cpp"
#include <string>
#include <iostream>
#pragma once

namespace entity
{
	struct Entity
	{    
        // Variables
		sf::Vector2f topLeft;;
		sf::Vector2f size;
		entity::Sprite *parts;
		sf::Vector2f velocity;
		double rigidity;

        // Constructor
        // Takes an array of arrays of the form [[texture_file_path, texture_name], ...]
		Entity(std::string texture_names[], sf::Texture *textures[], unsigned int number_of_sprites)
		{
            // Variables
            topLeft = sf::Vector2f(0.f, 0.f);
			velocity = sf::Vector2f(0.f, 0.f);
            rigidity = 1;
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

		// Sets sprite color
		void setColor(sf::Color color, int sprite)
		{
			parts[sprite].setColor(color);
		}

		// Update entity each frame
		void update(sf::RenderWindow &window, sf::Vector2f gravity) 
		{
			velocity.x = velocity.x + gravity.x;
			velocity.y = velocity.y + gravity.y;
			topLeft = topLeft + velocity;

			if (topLeft.x > window.getSize().x - size.x)
			{
				topLeft.x = window.getSize().x - size.x;
				velocity.x = -velocity.x * rigidity;
			}
			else if (topLeft.x < 0.f)
			{
				topLeft.x = 0.f;
				velocity.x = -velocity.x * rigidity;
			}

			if (topLeft.y > window.getSize().y - size.y)
			{
				topLeft.y = window.getSize().y - size.y;
				velocity.y = -velocity.y * rigidity;
			}
			else if (topLeft.y < 0.f)
			{
				topLeft.y = 0.f;
				velocity.y = -velocity.y * rigidity;
			}
			setPosition(topLeft);
		}
        
        // Shift an entity and all of its parts
        void move(sf::Vector2f change)
        {
			
            setVelocity(velocity + change);
        }

		// Sets entity members position from a vector
		void setPosition(sf::Vector2f position)
		{
			for (int i = 0; i < 2; ++i) //  needs fixed
			{
				parts[i].setPosition(position);
			}
			topLeft = position;
		}

		// Overload
		// Sets entity members position from a pair of floats
		void setPosition(float x, float y)
		{
			for (int i = 0; i < 2; ++i) //  needs fixed
			{
				parts[i].setPosition(sf::Vector2f(x, y));
			}
			topLeft = sf::Vector2f(x, y);
		}

		// Sets velocity to a vector (x,y)
		void setVelocity(sf::Vector2f Velocity) 
		{
			velocity = Velocity;
		}

		//Overload
		// Sets velocity to a pair of floats (x,y)
		void setVelocity(float x, float y)
		{
			velocity = sf::Vector2f(x, y);
		}

		// Sets rotation of all an entities members
		void setRotation(float degrees) //broken Position value dose not work???
		{
			//rotate parts
			for (int i = 0; i < 2; ++i)
			{
				parts[i].setRotation(degrees);
			}
			
			sf::Vector2f temp = topLeft; //create a temp var

			//resolve points into a vector and then resolves at a degree mesure
			float vector = sqrt((int64_t(size.x - topLeft.x) ^ 2) + (int64_t(size.y - topLeft.y) ^ 2));
			topLeft.x = (vector * cos(degrees)) + topLeft.x;
			topLeft.y = (vector * sin(degrees)) + topLeft.y;
			
			//sets the entity size off vector
			size.x = (vector * cos(degrees));
			size.y = (vector * sin(degrees));

			//set position
			for (int i = 0; i < 2; ++i)
			{
				parts[i].setOrigin(topLeft);
			}
		}

		// Sets a oblject's Bouncyness (0-100)
		void setRigidity(double i)
		{
			rigidity = i/100;
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