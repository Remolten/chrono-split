#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

#pragma once

namespace entity
{
	struct Sprite : sf::Sprite
	{
		// Unique Data
		int velocityX;
		int velocityY;

		// Stores an images with string name to a map
		std::unordered_map<std::string, sf::Texture*> images;
        
		Sprite()
		{
			velocityX = 0;
			velocityY = 0;
		}

		// Adds an image with a name to the map
		void addImage(std::string name, sf::Texture *texture)
		{
            images[name] = texture;
		}

		// Retrieve image by name
		sf::Texture getImage(std::string name)
		{
			return *images[name];
		}

		// Change the sprite's texture
		bool switchTextureTo(std::string name)
		{
            setTexture(*images[name]);
            
            return true;
		}
	};
}