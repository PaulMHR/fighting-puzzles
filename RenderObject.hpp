#include <memory>
#include <SFML/Graphics.hpp>

class RenderObject {
public:
    virtual void draw(sf::RenderWindow& window) = 0;
};

typedef std::shared_ptr<RenderObject> ROPtr;
