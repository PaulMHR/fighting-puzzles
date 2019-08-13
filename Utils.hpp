//  Previous typescript code
// export interface Colour {
//     c : string,
// }
//
// export interface Coord {
//     x : number,
//     y : number,
//     f : number,
// }
using namespace std;

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
