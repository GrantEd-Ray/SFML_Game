#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include "Game.h"
//#include <Player.h>
//#include <Walls.h>
#include "Object.h"
#include <string>
#include <iostream>
#include <vector>
#include <cmath>

namespace mt
{
    Game::~Game()
    {
        if (m_window != nullptr)
            delete m_window;
    }

    void Game::set_name(const std::string name)
    {
        m_name = name;
    }

    void Game::set_resolution(int width, int height)
    {
        m_width = width;
        m_height = height;
    }

    void Game::setup()
    {
        m_window = new sf::RenderWindow(sf::VideoMode(m_width, m_height), m_name);
    }

    void Game::Run()
    {
        double angle = 0;
        float velocity = 0;

        std::cout << "Enter the angle of throw: ";
        std::cin >> angle;

        std::cout << "Enter the force of throw: ";
        std::cin >> velocity;

        //mt::Player player({ 200, 600 }, 40);
        //player.NewVelocity(velocity);
        //player.SetAngle(angle);
        //player.UpdateVelocity();

        mt::GuideLine line({200, 600}, 50, 5);

        sf::Clock timer;

        double t = 0;

        while (m_window->isOpen())
        {
            sf::Event event;
            while (m_window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    m_window->close();
            }

            sf::Time dt = timer.restart();
            t = dt.asMicroseconds() / 1e6 * 4;

            m_window->clear();
            //player.Move(t);
            while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))
            {
                angle += 1 * t;
                line.Set_Angle(angle);
                m_window->draw(*line.Get());

            }

            //m_window->draw(*player.Get());

            /*for (auto & wall : mt::walls)
            {
                m_window->draw(*wall->Get());
            }
            m_window->draw(*mt::Floor->Get());
            */

            m_window->display();

        }
    }
}