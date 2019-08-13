#ifndef RENDER_OBJECT
#define RENDER_OBJECT

#include <memory>
#include <SFML/Graphics.hpp>

class RenderObject {
public:
    virtual void draw(sf::RenderWindow& window) = 0;
};

typedef std::shared_ptr<RenderObject> ROPtr;
#endif
