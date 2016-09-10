//Project: Chrono Split
//Authors: Remington, Lucas, and Thomas Queenan
//Written: 09/07/16 to ??/??/??

//Discription:
// An arena based fighting game in c++ and Lua 

//Include Their Files
#include <iostream> //input output
#include <chrono> //high-res timer (chrono::high_resolution_clock::timepoint & chrono::high_resolution_clock::now())
#include <cmath> //c-math
#include <string> //strings
#include <sstream> //string building

// Include SFML Window module
#include <SFML/Graphics.hpp>

//Include Our files
#include "../C++/Entity/sprite.cpp" //To be removed later
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
	int units[4];

	units[0] = trunc( (times / (3600) ) ); //gets hours
	units[1] = trunc( ( (times) - (3600 * units[0]) ) / (60) ); //gets minuits
	units[2] = trunc( (times - ( (3600 * units[0]) + (60 * units[1]) ) ) ); //gets seconds
	units[3] = trunc( (times - trunc(times) ) * 1000); //gets parts of a sec
	
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
    Render::render_engine renderer;
	cout << Time() << "Render initilized" << endl;
    
    // Create a clock which gives the delta time of each frame
    sf::Clock clock;
	cout << Time() << "Timer  initilized" << endl;
    
    // Store the delta time
    // Pass this to any function handling movement/time
    sf::Time delta_time;
    
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
                */
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
        renderer.clear(&window);
        
        // Draw stuff with the render engine
        // render.draw(sprite);
        // or
        // renderer.draw_list(sprites_list);
        
        // Draw a green circle
        renderer.draw_green_circle(&window);
        
        // Actually push all draw calls to the display
        renderer.display(&window);
    }
    
	return 0;
}
