#include "Utils.hpp"
#include "RenderObject.hpp"
#include <SFML/Graphics.hpp>

class Box: public RenderObject{
    public:
        static const int RENDER_SIZE = 46;
        static const int RENDER_OFFSET = 2;
        Coord coord = Coord(0 ,0, 0);

        Box();
        ~Box();
        void update(int);
        void draw(sf::RenderWindow&);

    private:

        Colour colour = GREEN;
        static const int RENDER_SPACE = RENDER_SIZE + (RENDER_OFFSET * 2);
        static const int PLAYING_SPACE_X = RENDER_SPACE * 6;
        static const int PLAYING_SPACE_Y = RENDER_SPACE * 12;
        static const int MS_PER_BLOCK = 700;
        bool enabled = true;

};

//  In Box.cpp
// void Box::update(int delta){
//     this->coord.f -= (delta / this->MS_PER_BLOCK) * this->RENDER_SPACE;
//     while(this->coord.f < 0){
//         this->coord.y--;
//         this->coord.f += this->RENDER_SPACE;
//     }
//     if (this->coord.y <= 0) {
//         this->coord.f = 0;
//         this->coord.y = 0;
//         this->enabled = false;
//     }
// }
//
// void Box::draw(sf::RenderWindow window){
//
//     float side_len = this->RENDER_SPACE + this->RENDER_OFFSET*2;
//     sf::RectangleShape cube(sf::Vector2f(side_len, side_len));
//
//     cube.setOutlineThichness(2.5);
//     cube.setOutlineColor(sf::Color(200, 200, 200));
//
//     switch (this->colour.c){
//         case "green": cube.setFillColor(sf::Color(100, 250, 50));
//             break;
//     }
//
//     cube.setPosition((float)this->coord.x, (float)this->coord.y);
//
//     window.draw(cube);
//     // this->ctx.fillStyle = this->color.c;
//     // int x = this->coord.x * this->RENDER_SPACE + this->RENDER_OFFSET;
//     // int y = this->PLAYING_SPACE_Y - (this->coord.y * this->RENDER_SPACE + this->coord.f + this->RENDER_OFFSET);
//     // this->ctx.fillRect(x, y, this->RENDER_SIZE, this->RENDER_SIZE);
// }
