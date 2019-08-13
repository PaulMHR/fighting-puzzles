#include <chrono>

#include <SFML/Graphics.hpp>
#include "Game.hpp"

const float MIN_FRAME_LENGTH = 10;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Puzzle Fight!");
    auto oldTime = std::chrono::steady_clock::now();
    auto newTime = oldTime;
    float deltaTime;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            // Add input
        }

        window.clear();

        newTime = std::chrono::steady_clock::now();
        deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(newTime - oldTime).count();
        oldTime = newTime;
        if (deltaTime < MIN_FRAME_LENGTH) {
            continue;
        }
        Game::update(deltaTime);
        Game::draw(window);
        window.display();
    }

    return 0;
}
