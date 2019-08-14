#pragma once

#include <memory>

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
        Coord(int x, int y, int f): x(x), y(y), f(f) {}
};

template<int H, int W, class T>
class Grid {
public:
    T& get(const Coord& coord) {
        int row = coord.x;
        int col = coord.y;
        return grid[row * H + col];
    }
    void set(T&& element) {
        int row = element->coord.x;
        int col = element->coord.y;
        grid[row * H + col] = std::move(element);
    }
    Grid() {}
    virtual ~Grid() {}
    //leftOf(T&& element);
    //rightOf(T&& element);
protected:
    T grid[H * W];
};
