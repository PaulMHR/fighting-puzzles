

#include "GameObject.hpp"
#include "Input.hpp"
#include "Utils.hpp"

class Box: public GameObject{
    public:
        static const int RENDER_SIZE = 46;
        static const int RENDER_OFFSET = 2;
        Coord coord = Coord(0 ,0, 0);

        void update(int);
        // void draw(void);

    private:

        Colour colour = Colour("green");
        static const int RENDER_SPACE = RENDER_SIZE + (RENDER_OFFSET * 2);
        static const int PLAYING_SPACE_X = RENDER_SPACE * 6;
        static const int PLAYING_SPACE_Y = RENDER_SPACE * 12;
        static const int MS_PER_BLOCK = 700;

};

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

// void Box::draw(void){
//     this->ctx.fillStyle = this->color.c;
//     int x = this->coord.x * this->RENDER_SPACE + this->RENDER_OFFSET;
//     int y = this->PLAYING_SPACE_Y - (this->coord.y * this->RENDER_SPACE + this->coord.f + this->RENDER_OFFSET);
//     this->ctx.fillRect(x, y, this->RENDER_SIZE, this->RENDER_SIZE);
// }
