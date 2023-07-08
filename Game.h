#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
//#include "Walls.h"

namespace mt
{
    class Game {
    private:
        int m_width, m_height;
        std::string m_name;
        sf::RenderWindow* m_window = nullptr;

    public:
        Game(){}

        ~Game();

        void set_name(const std::string name);

        void set_resolution(int width, int height);

        void setup();

        void Move(double t, float angle, float velocity, mt::Player player, std::vector<mt::Wall*> walls, const mt::Wall& floor);

        void Run();
    };
}



