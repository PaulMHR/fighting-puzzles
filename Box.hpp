#pragma once

#include "Utils.hpp"
#include "RenderObject.hpp"
#include <SFML/Graphics.hpp>

class Box: public RenderObject {
    public:
        static const int RENDER_SIZE = 46;
        static const int RENDER_OFFSET = 2;
        Coord coord = Coord(0 ,0, 0);
        Colour colour = GREEN;

        Box();
        ~Box();
        void draw(sf::RenderWindow&);

    private:
        static const int RENDER_SPACE = RENDER_SIZE + (RENDER_OFFSET * 2);
        static const int PLAYING_SPACE_X = RENDER_SPACE * 6;
        static const int PLAYING_SPACE_Y = RENDER_SPACE * 12;
};
