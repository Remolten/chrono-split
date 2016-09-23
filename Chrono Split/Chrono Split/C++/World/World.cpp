#include "../World/Map.cpp"
#include "../Entity/Entity.cpp"
#include "../Render/render.cpp"
#include "../Physics/physics.cpp"

#include <iostream>
#include <chrono> // High-res timer (chrono::high_resolution_clock::timepoint & chrono::high_resolution_clock::now())
#include <cmath>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>// Include SFML Window module

using std::cout;
using std::cin;
using std::endl;

namespace world
{

	struct World
	{
		// Variables
		std::chrono::high_resolution_clock::time_point ProgStartTime;
        
        sf::Vector2f gravity; // Default no gravity
        
        // Constructor
		World()
		{
            ProgStartTime = std::chrono::high_resolution_clock::now();
            gravity = sf::Vector2f(0.f, 1.f);
        }

		std::string Time()
		{
			std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now(); // Records now
			std::chrono::duration<double> time = std::chrono::duration_cast<std::chrono::duration <double> >(now - ProgStartTime); // Change in time
			double times = time.count();

			// Parse into string
			int units[4] = { (int)trunc((times / (3600))),(int)trunc(((times)-(3600 * units[0])) / (60)),(int)trunc((times - ((3600 * units[0]) + (60 * units[1])))),(int)trunc((times - trunc(times)) * 1000) };

			std::stringstream str; // Creates a string stream for string building
			str << units[0] << ":" << units[1] << ":" << units[2] << "." << units[3] << " :: "; // format data into string

			return str.str(); // Returns time string
		}

		void setGravity(sf::Vector2f Gravity) // Sets gravity to a vector (x,y)
		{
			gravity = Gravity;
		}

		//Overload
		void setGravity(float x, float y) // Sets gravity to a pair of floats (x,y)
		{
			gravity = sf::Vector2f(x, y);
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
            
            // Create an instance of the physics engine
            physics::Physics physicsEngine;
            cout << Time() << "Physics initilized" << endl;

			// Create a clock which gives the delta time of each frame
			sf::Clock clock;
			cout << Time() << "Timer initilized" << endl;

			// Store the delta time
			// Pass this to any function handling movement/time
			sf::Time delta_time;
			
			// Define Outer Part (Un colored)
			sf::Texture enemyLightTexture;
			enemyLightTexture.loadFromFile("../Chrono Split/Assets/enemyPartLight.png");
            sf::Texture enemyDarkTexture;
			enemyDarkTexture.loadFromFile("../Chrono Split/Assets/enemyPartDark.png");
            
            std::string texture_names[2] = {"Light", "Dark"};
            sf::Texture *textures[2] = {&enemyLightTexture, &enemyDarkTexture};
            
			// TODO create function that returns a sprite by name
			// sprite.setColor(sf::Color(250, 250, 255, 255));

			// Define Inner Part (colored)
			// sprite1.setColor(sf::Color(000, 255, 000, 255)); // color of part
			setGravity(0.f, 1.f);

			entity::Entity entity0(texture_names, textures, 2);
			entity0.setColor(sf::Color(250, 250, 255, 255), 0);
			entity0.setColor(sf::Color(255, 000, 000, 255), 1);
			entity0.setPosition(sf::Vector2f(001.f, 000.f));
			entity0.setVelocity(sf::Vector2f(1.f, 1.f));
			entity0.setRigidity(99);
			//entity0.setRotation(180);

			entity::Entity entity1(texture_names, textures, 2);
			entity1.setColor(sf::Color(250, 250, 255, 255), 0);
			entity1.setColor(sf::Color(000, 255, 000, 255), 1);
			entity1.setPosition(sf::Vector2f(001.f, 000.f));
			entity1.setVelocity(sf::Vector2f(2.f, 2.f));
			entity1.setRigidity(100);
			
			// attempt to make sprite #3
			entity::Entity entity2(texture_names, textures, 2);
			entity2.setColor(sf::Color(250, 250, 255, 255), 0);
			entity2.setColor(sf::Color(000, 000, 255, 255), 1);
			entity2.setPosition(sf::Vector2f(001.f, 000.f));
			entity2.setVelocity(sf::Vector2f(3.f, 3.f));
			entity2.setRigidity(100);
            
			// block 1
			sf::Texture box1;
			box1.loadFromFile("../Chrono Split/Assets/beamGrey.png");

			//sf::Texture box2;
			//box2.loadFromFile("../Chrono Split/Assets/beamGrey.png");

			std::string str[2] = { "box" , "null"};
			sf::Texture *tex[2] = { &box1 , &box1};
			entity::Entity block1(str, tex, 2);

			// box collisions
			block1.setColor(sf::Color(255, 000, 000, 255), 0);
			block1.setPosition(400, 400);
			block1.setStatic(true);

            // Set a move speed for testing
            float speed = 2;

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
                        // Changes the size of the viewport, but not the resolution
						window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));

					// Process any key down events from the keyboard
                    // Will accept multi-key input
					if (event.type == sf::Event::KeyPressed)
					{
						cout << Time() << "Keypress: " << event.key.code << endl; // log keys

                        if (event.key.code == sf::Keyboard::W)
                        {
                            entity0.changeVelocity(sf::Vector2f(0.f, -speed));
                        }

                        if (event.key.code == sf::Keyboard::S)
                        {
                            entity0.changeVelocity(sf::Vector2f(0.f, speed));
                        }

                        if (event.key.code == sf::Keyboard::A)
                        {
                            entity0.changeVelocity(sf::Vector2f(-speed, 0.f));
                        }

                        if (event.key.code == sf::Keyboard::D)
                        {
                            entity0.changeVelocity(sf::Vector2f(speed, 0.f));
                        }
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
				}

				// Clear the screen each frame
				renderer.clear(window);
				
                // Check collision between entities and block1
                // Note: Function only changes stuff in entity 1 right now
                physicsEngine.collision(entity0, block1);
                physicsEngine.collision(entity1, block1);
                physicsEngine.collision(entity2, block1);
                
				// Move tick
				entity0.update(window, gravity);
				entity1.update(window, gravity);
				entity2.update(window, gravity);

				block1.update(window, gravity);

                // Draw sprites to the screen
				renderer.draw_list(window, entity0.getSprites(), 2);
				renderer.draw_list(window, entity1.getSprites(), 2);
				renderer.draw_list(window, entity2.getSprites(), 2);

				renderer.draw_list(window, block1.getSprites(), 1);

				// Actually push all draw calls to the display
				renderer.display(window);
			}
        }
	};
}