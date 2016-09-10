#include "../World/Map.cpp"
#include <string>
#include <SFML/Graphics.hpp>

namespace world
{
	struct World
	{
		//Variables
		world::Map *map;

		//Constructor
		World(std::string fileName)
		{
			map = new world::Map(fileName);
		}

		//Destructors
		~World()
		{
			delete map;
		}

		//Receive keyboard input
		void keyboardInput(sf::Event event)
		{
			switch (event.key.code)
			{

			}
		}

	};
}