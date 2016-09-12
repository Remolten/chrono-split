#include <SFML/Graphics.hpp>
#include <iostream> // debug

// Get the type of our sprites
#include "../Entity/sprite.cpp"


namespace render {
    struct render_engine
    {
        // Declare variables here that you want to access throughout the struct
        sf::CircleShape shape;
		sf::RectangleShape rect;
        // This is the constructor function
        // Declare any variables that need to be accessed by the render engine
        render_engine()
        {
            // Create a circle of size 100 and color green to be drawn
            shape.setRadius(100.f);
            shape.setFillColor(sf::Color::Green);

			rect.setSize(sf::Vector2f(100.f, 100.f));
			rect.setFillColor(sf::Color::Red);
			rect.setPosition(200, 200);
        }
        
        // Clears the screen
        int clear(sf::RenderWindow &window)
        {
            window.clear(sf::Color::Black);
            
            return 0;
        }
        
        // Pushes all draw calls to the display
        int display(sf::RenderWindow &window)
        {
            window.display();
            
            return 0;
        }
        
        // Draws a single sprite to the screen
        int draw(sf::RenderWindow &window, entity::Sprite sprite)
        {
            window.draw(sprite);
            
            return 0;
        }
        
        // Draw a list of sprites to the screen
        int draw_list(sf::RenderWindow &window, entity::Sprite sprites[], unsigned int sprites_array_size)
        {
            for (unsigned int i = 0; i < sprites_array_size; i++)
            {
                window.draw(sprites[i]);
            }
            
            return 0;
        }
        
        // Draws a green circle and red rectangle
        int draw_green_circle(sf::RenderWindow &window)
        {
            window.draw(shape);
			window.draw(rect);

            return 0;
        }
	};
}