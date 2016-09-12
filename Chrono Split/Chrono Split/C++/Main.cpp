//Project: Chrono Split
//Authors: Remington, Lucas, and Thomas Queenan
//Written: 09/07/16 to ??/??/16

//Discription:
// An arena based fighting game in c++ and Lua 

#include <iostream> //input output
#include <chrono> //high-res timer (chrono::high_resolution_clock::timepoint & chrono::high_resolution_clock::now())
#include <cmath> //c-math
#include <string> //strings
#include <sstream> //string building
#include <SFML/Graphics.hpp>// Include SFML Window module
#include <SFML/Graphics/Texture.hpp>

//Include Our files
#include "../C++/Render/render.cpp"
#include "../C++/World/World.cpp"

using std::cout;
using std::cin;
using std::endl;

// Records the start time of the program for console messages
std::chrono::high_resolution_clock::time_point ProgStartTime = std::chrono::high_resolution_clock::now();

//timer for debug console messages
//use for time since program start
//example:
// cout << Time() << {Message} << endl;

std::string Time()
{
	using namespace std::chrono; //for easy code
	using namespace std; 

	high_resolution_clock::time_point now = high_resolution_clock::now(); // records now
	duration<double> time = duration_cast<duration <double> >(now - ProgStartTime); // finds change in time

	double times = time.count();

	//parse into string
	int units[4] = { (int)trunc((times / (3600))),(int)trunc(((times)-(3600 * units[0])) / (60)),(int)trunc((times - ((3600 * units[0]) + (60 * units[1])))),(int)trunc((times - trunc(times)) * 1000) };

	stringstream str; //creates a string stream for string building
	str << units[0] << ":" << units[1] << ":" << units[2] << "." << units[3] << " :: "; //format data into string

	return str.str(); //returns time string
}

int main()
{
	// Creates a new window object stored in the "window" variable
	sf::RenderWindow window(sf::VideoMode(800, 600), "Chrono Split");
	cout << Time() << "Window initilized" << endl;

	// Limit the FPS to 60
	window.setFramerateLimit(60);

	// Create an instance of the render engine
	render::render_engine renderer;
	cout << Time() << "Render initilized" << endl;

	// Create a clock which gives the delta time of each frame
	sf::Clock clock;
	cout << Time() << "Timer  initilized" << endl;

	// Store the delta time
	// Pass this to any function handling movement/time
	sf::Time delta_time;

	// Don't do this code in Main
	// Define a new sprite + entity container for testing
	sf::Texture texture;
	texture.loadFromFile("../Chrono Split/Assets/enemyBlue3.png");
	entity::Sprite sprite = entity::Sprite(); //removed texture constructor due to commpile error
	sprite.addImage("basic", texture); 
	sprite.setTexture(texture); //sets texture
	entity::Sprite sprites[1] = { sprite };
	entity::Entity entity(sprites);
	//

	// Run the program as long as the window is open
	while (window.isOpen())
	{
		// Restart the clock and store the delta time
		delta_time = clock.restart();

		// Check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "Close Requested" event: Close the window
			if (event.type == sf::Event::Closed)
				window.close();

			// Process any key down events from the keyboard
			if (event.type == sf::Event::KeyPressed)
			{
				cout << Time() << "Keypress: " << event.key.code << endl; //log keys

				//Game input should not be handled in main
				//Send the input to the World class later
				/*
				if (event.key.code == sf::Keyboard::W)
				{
					// Set the move up flag
				}

				if (event.key.code == sf::Keyboard::S)
				{
					// Set the move down flag
				}

				if (event.key.code == sf::Keyboard::A)
				{
					// Set the move left flag
				}

				if (event.key.code == sf::Keyboard::D)
				{
					// Set the move right flag
				}
				// Process any key up events from the keyboard
				if (event.type == sf::Event::KeyReleased)
				{
					if (event.key.code == sf::Keyboard::W)
					{
						// Unset the move up flag
					}

					if (event.key.code == sf::Keyboard::S)
					{
						// Unset the move down flag
					}

					if (event.key.code == sf::Keyboard::A)
					{
						// Unset the move left flag
					}

					if (event.key.code == sf::Keyboard::D)
					{
						// Unset the move right flag
					}
				}
				*/
			}

			// Clear the screen each frame
			renderer.clear(window);

			//Doesn't work
			renderer.draw_list(window, entity.parts, 1);
			//

			// Draw stuff with the render engine
			// render.draw(window, sprite);
			// or
			// renderer.draw_list(window, sprites_list, sprites_list_length);

			// Draw a green circle and red rect
			//renderer.draw_green_circle(window);

			// Actually push all draw calls to the display
			renderer.display(window);
		}
	}
	return 0;
}
