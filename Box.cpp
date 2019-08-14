#include "Box.hpp"

Box::Box(){}

Box::~Box(){}

void Box::draw(sf::RenderWindow& window){

    float side_len = RENDER_SPACE + RENDER_OFFSET*2;
    
    sf::RectangleShape cube(sf::Vector2f(side_len, side_len));

    cube.setOutlineThickness(2.5);
    cube.setOutlineColor(sf::Color(200, 200, 200));

    switch(colour){
        case GREEN:
            cube.setFillColor(sf::Color(100, 250, 50));
            break;
        case RED:
            cube.setFillColor(sf::Color(250, 0, 0));
            break;
        case YELLOW:
            cube.setFillColor(sf::Color(250, 250, 0));
            break;
        case BLUE:
            cube.setFillColor(sf::Color(0, 0, 250));
    }

    cube.setPosition((float)this->coord.x, (float)this->coord.y);

    window.draw(cube);
}
