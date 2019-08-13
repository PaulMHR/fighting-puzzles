#include <memory>
#include <SFML/Graphics.hpp>

class GameObject {
    public:
        bool enabled;
        virtual void draw(sf::RenderWindow& window) = 0;
        virtual void update(float deltaTime) = 0;
};

typedef std::unique_ptr<GameObject> GOPtr;
