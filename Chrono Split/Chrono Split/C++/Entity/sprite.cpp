#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

#pragma once

namespace entity
{
	struct Sprite : sf::Sprite
	{
		//Unique Data
		int velocityX;
		int velocityY;

		//Stores an images with string name to a map
		std::unordered_map<std::string, sf::Texture> images;
        
		Sprite()
		{
			velocityX = 0;
			velocityY = 0;
		}

		//Adds an image with a name to the map
		void addImage(std::string name, sf::Texture picture)
		{
			images[name] = picture;
		}

		//Retrive image by name
		sf::Texture getImage(std::string name)
		{
			return images[name];
		}

		//Change current texture, return false if dosn't texture exists
		bool switchTextureTo(std::string name)
		{
			try //Just in case name doesn't exist in the map
			{
				images.at(name);
				setTexture(images[name]);
			}
			catch(const std::exception&)
			{
				return false;
			}
			return false;
		}
	};
}