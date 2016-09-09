#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

#include <iostream>

namespace Render {
    struct render_engine
    {
        // Declare variables here that you want to access throughout the struct
        sf::CircleShape shape;
        
        // This is the constructor function
        // Declare any variables that need to be accessed by the render engine
        render_engine()
        {
            // Create a circle of size 100 and color green to be drawn
            shape.setRadius(100.f);
            shape.setFillColor(sf::Color::Green);
        }
        
        // Draws a green circle to the screen every frame
        int draw(sf::RenderWindow *window)
        {
            // Clear the screen to black
            window->clear(sf::Color::Black);
            
            // Draws a green circle
            window->draw(shape);
            
            // Pushes the draw updates to the display (so they actually show up)
            window->display();
            
            return 0;
        }
	};
}