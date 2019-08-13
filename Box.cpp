#include "Box.hpp"

Box::Box(){}

Box::~Box(){}

void Box::update(int delta){
    this->coord.f -= (delta / this->MS_PER_BLOCK) * this->RENDER_SPACE;
    while(this->coord.f < 0){
        this->coord.y--;
        this->coord.f += this->RENDER_SPACE;
    }
    if (this->coord.y <= 0) {
        this->coord.f = 0;
        this->coord.y = 0;
        this->enabled = false;
    }
}

void Box::draw(sf::RenderWindow& window){

    float side_len = this->RENDER_SPACE + this->RENDER_OFFSET*2;
    
    sf::RectangleShape cube(sf::Vector2f(side_len, side_len));

    cube.setOutlineThickness(2.5);
    cube.setOutlineColor(sf::Color(200, 200, 200));

    switch(this->colour){
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
    // this->ctx.fillStyle = this->color.c;
    // int x = this->coord.x * this->RENDER_SPACE + this->RENDER_OFFSET;
    // int y = this->PLAYING_SPACE_Y - (this->coord.y * this->RENDER_SPACE + this->coord.f + this->RENDER_OFFSET);
    // this->ctx.fillRect(x, y, this->RENDER_SIZE, this->RENDER_SIZE);
}
