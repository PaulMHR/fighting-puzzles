#pragma once

enum Colour {
    GREEN,
    BLUE,
    RED,
    YELLOW
};

class Coord {
    public:
        int x;
        int y;
        int f;
        Coord();
        Coord(int, int, int);
};
