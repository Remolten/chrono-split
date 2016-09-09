//Project: Chrono Split
//Authors: Remington, Lucas, and Thomas Queenan
//Written: 09/07/16 to ??/??/??

//Discription:
// An arena based fighting game in c++ and Lua 

//Include Their Files
#include <iostream> //input output
#include <chrono> //high-res timer (chrono::high_resolution_clock::timepoint & chrono::high_resolution_clock::now())

// Include SFML Window module
#include <SFML/Graphics.hpp>

//Include Our files
#include "../C++/Sprites/sprite.cpp"
#include "../C++/Render/render.cpp"
#include "../C++/Physics/physics.cpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    
    // Creates a new window object stored in the "window" variable
    sf::RenderWindow window(sf::VideoMode(800, 600), "Chrono Split");
	cout << ": Window initilized" << endl;

	// Limit the FPS to 60
	window.setFramerateLimit(60);

    // Create an instance of the render engine
    Render::render_engine renderer;
	cout << ": Renderer initilized" << endl;
    
    // Run the program as long as the window is open
    while (window.isOpen())
    { 
        // Check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "Close Requested" event: Close the window
            if (event.type == sf::Event::Closed)
                window.close();
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
