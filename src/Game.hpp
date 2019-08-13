//import { GameObject } from './GameObject';
//import { Box } from './Box';
//import { Input } from './Input';
//import { EnumFlags } from './Utils';

#include <vector>

class Game {
    static std::vector<int> gameObjects; //Should be GameObject
    static std::vector<int> enabled;
    static int lastFrameTimeMs;
    static const int maxFPS = 60;
    //static Box b;
    //static input : EnumFlags<Input> = new EnumFlags<Input>();

    static void run();

    static void registerGameObject(int o);

    static void handleInput();

    static void update(int delta);

    static void draw(int timestamp);
};
