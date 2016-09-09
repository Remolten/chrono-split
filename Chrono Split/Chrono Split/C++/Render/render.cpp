#include <SFML/Graphics.hpp>

// Get the type of our sprites
#include "../Sprites/sprite.cpp"

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
        
        int clear(sf::RenderWindow *window)
        {
            window->clear(sf::Color::Black);
            
            return 0;
        }
        
        int display(sf::RenderWindow *window)
        {
            window->display();
        }
        
        // Draws a green circle to the screen every frame
        int draw(sf::RenderWindow *window, Sprites::sprite sprite)
        {
            window->draw(sprite);
            
            return 0;
        }
        
        int draw_list(sf::RenderWindow *window, Sprites::sprite sprites[])
        {
            for (unsigned int i = 0; i < sizeof(sprites) / sizeof(sprites[0]); i++)
            {
                window->draw(sprites[i]);
            }
            
            return 0;
        }
        
        int draw_green_circle(sf::RenderWindow *window)
        {
            window->draw(shape);
            
            return 0;
        }
	};
}