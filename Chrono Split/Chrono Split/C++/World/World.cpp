#include "../World/Map.cpp"
#include <string>

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
	};
}