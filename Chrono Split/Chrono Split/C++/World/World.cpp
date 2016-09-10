#include "../World/Map.cpp"
#include "../Entity/Entity.cpp"
#include <string>
#include <SFML/Graphics.hpp>

namespace world
{
	struct World
	{
		//Variables
		world::Map *map;
		entity::Entity *entities;

		//Constructor
		World(std::string fileName)
		{
			map = new world::Map(fileName);
		}

		//Destructors
		~World()
		{
			delete map;
			delete entities;
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