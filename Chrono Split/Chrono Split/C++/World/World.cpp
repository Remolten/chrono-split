#include "../World/Map.cpp"
#include "../Entity/Entity.cpp"
#include "../Render/render.cpp"
#include "../Physics/physics.cpp"

#include <iostream> //input output
#include <chrono> //high-res timer (chrono::high_resolution_clock::timepoint & chrono::high_resolution_clock::now())
#include <cmath> //c-math
#include <string> //strings
#include <sstream> //string building
#include <SFML/Graphics.hpp>// Include SFML Window module

using std::cout;
using std::cin;
using std::endl;

namespace world
{

	struct World
	{
		//Variables
		sf::Vector2f gravity = sf::Vector2f(0.f, 1.f); //default no gravity

		std::chrono::high_resolution_clock::time_point ProgStartTime = std::chrono::high_resolution_clock::now();

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

		void setGravity(sf::Vector2f Gravity) //Sets gravity to a vector (x,y)
		{
			gravity = Gravity;
		}

		//Constructor
		World()
		{
        }
        
        void run()
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
			
            /*
            //
            //
            //
            // Below is the process of properly creating an entity
			// Create textures we need
            sf::Texture test_texture;
            test_texture.loadFromFile("../Chrono Split/Assets/enemyBlue3.png");
            // Make 2 arrays
            // 1 with the names of the parts
            std::string texture_names[1] = {"Body"};
            // The other with pointers to the textures
            sf::Texture *textures[1] = {&test_texture};
            // Then create our actual entity object
            // Note: last argument is the size of the 2 arrays (they must be same size obviously)
			entity::Entity entity(texture_names, textures, 1);
            //
            //
            //
            */
			
			// Define Outer Part (Un colored)
			sf::Texture enemyLightTexture;
			enemyLightTexture.loadFromFile("../Chrono Split/Assets/enemyPartLight.png");
            sf::Texture enemyDarkTexture;
			enemyDarkTexture.loadFromFile("../Chrono Split/Assets/enemyPartDark.png");
            
            std::string texture_names[2] = {"Light", "Dark"};
            sf::Texture *textures[2] = {&enemyLightTexture, &enemyDarkTexture};
            
			// TODO create function that returns a sprite by name
			//sprite.setColor(sf::Color(250, 250, 255, 255));

			// Define Inner Part (colored)
			//sprite1.setColor(sf::Color(000, 255, 000, 255)); // color of part

			entity::Entity entity0(texture_names, textures, 2);
			entity0.setColor(sf::Color(250, 250, 255, 255), 0);
			entity0.setColor(sf::Color(255, 000, 000, 255), 1);
			entity0.setPosition(sf::Vector2f(000, 000));
			entity0.setVelocity(sf::Vector2f(0, 1));

			entity::Entity entity1(texture_names, textures, 2);
			entity1.setColor(sf::Color(250, 250, 255, 255), 0);
			entity1.setColor(sf::Color(000, 255, 000, 255), 1);
			entity1.setPosition(sf::Vector2f(000, 000));
			entity1.setVelocity(sf::Vector2f(2, 0));
			
			// attempt to make sprite #3
			entity::Entity entity2(texture_names, textures, 2);
			entity2.setColor(sf::Color(250, 250, 255, 255), 0);
			entity2.setColor(sf::Color(000, 000, 255, 255), 1);
			entity2.setPosition(sf::Vector2f(000, 000));
			entity2.setVelocity(sf::Vector2f(1, 1));

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

					// To do Set aspect ratio bassed off of window size
					if (event.type == sf::Event::Resized)
						window.setSize(window.getSize());

					// Process any key down events from the keyboard
					if (event.type == sf::Event::KeyPressed)
					{
						cout << Time() << "Keypress: " << event.key.code << endl; // log keys

						// Game input should not be handled in main
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
                        */
					}
					/*
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
				
				//move tic
				entity0.move(window, gravity);
				entity1.move(window, gravity);
				entity2.move(window, gravity);

				renderer.draw_list(window, entity0.getSprites(), 2);
				renderer.draw_list(window, entity1.getSprites(), 2);
				renderer.draw_list(window, entity2.getSprites(), 2);
				
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
	};
}