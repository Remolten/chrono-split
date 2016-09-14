#include "../Entity/sprite.cpp"
#include <string>
#pragma once

namespace entity
{
	struct Entity
	{
		// Variables
		int centerX;
		int centerY;
		int centerVelocityX;
		int centerVelocityY;
		entity::Sprite *parts;
        
        // Constructor
        // Takes an array of arrays of the form [[texture_file_path, texture_name], ...]
		Entity(std::string texture_names[], sf::Texture *textures[], unsigned int number_of_sprites)
		{
            // Basic stuff
            centerX = 0;
			centerY = 0;
			centerVelocityX = 0;
			centerVelocityY = 0;
            
            // Make the sprite container
            parts = new entity::Sprite[number_of_sprites];
            
			// Make the sprite and textures and store in the Entity container
            for (unsigned int i = 0; i < number_of_sprites; i++)
            {
                entity::Sprite sprite;
                sprite.addImage(texture_names[i], textures[i]);
                sprite.switchTextureTo(texture_names[i]);
                parts[i] = sprite;
            }
		}
        
        // Destructor
        ~Entity()
        {
            // Explicitly delete parts when finished to avoid memory corruption
            delete [] parts;
        }

		// Return the entity's array of sprites as a pointer value
		entity::Sprite *getSprites()
		{
			return parts;
		}
	};
}