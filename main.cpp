#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>
#include "Game.hpp"

const float MIN_FRAME_LENGTH = 16;

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
        if (deltaTime < MIN_FRAME_LENGTH) {
            auto sleep_time = std::chrono::milliseconds(static_cast<int>(MIN_FRAME_LENGTH - deltaTime));
            if (sleep_time > std::chrono::milliseconds(0)) {
                std::this_thread::sleep_for(sleep_time);
            }
            continue;
        }
        oldTime = newTime;
        Game::update(deltaTime);
        Game::draw(window);
        window.display();
    }

    return 0;
}
