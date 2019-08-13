#pragma once

class Colour {
    public:
        char c[20];
};

class Coord {
    public:
        int x;
        int y;
        int f;
        Coord();
        Coord(int, int, int);
};
