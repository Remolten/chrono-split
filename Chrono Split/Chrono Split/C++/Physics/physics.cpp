#include <SFML/Graphics.hpp>

namespace physics
{
    struct Physics
    {
        void collision(entity::Entity &entity1, entity::Entity &entity2)
        {
            // If all conditions are true, the two entities are colliding
            if (entity1.topLeft.x <= entity2.topLeft.x + entity2.size.x &&
                entity2.topLeft.x <= entity1.topLeft.x + entity1.size.x &&
                entity1.topLeft.y <= entity2.topLeft.y + entity2.size.y &&
                entity2.topLeft.y <= entity1.topLeft.y + entity2.size.y)
            {
                // Reverse the objects velocity if it is moving at all
                if (!(entity1.velocity.x == 0) && !(entity1.velocity.y == 0))
                {
                    entity1.velocity.x *= -1;
                    entity1.velocity.y *= -1;
                }
                // Just move the entity so it doesn't get stuck
                // Change the position so the object is not colliding with whatever anymore
                sf::Vector2f newPosition = sf::Vector2f(entity1.topLeft.x + entity1.velocity.x, entity1.topLeft.y + entity1.velocity.y);
                entity1.setPosition(newPosition);
            }
        }
    };
}