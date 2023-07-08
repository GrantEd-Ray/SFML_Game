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

    void Game::Move(double t, float angle, float velocity, mt::Player player, std::vector<mt::Wall*> walls, const mt::Wall& floor)
    {
        float x_0 = 200;
        float y_0 = 600;
        float g = -9.8;

        float vx = velocity * cos(angle * M_PI / 180);
        float vy = velocity * sin(angle * M_PI / 180);

        float x = x_0 + vx * t;
        float y = y_0 - vy * t;
        player.SetPosition(x, y);

        x_0 = x;
        y_0 = y;
        vy = vy + g * t;

        bool is_x_changed = false;
        bool is_y_changed = false;

        for (int i = 0; i < walls.size(); i++)
        {
            if (player.Get()->getGlobalBounds().intersects(walls[i]->Get()->getGlobalBounds()) && !is_x_changed)
            {
                vx *= -0.9;
                is_x_changed = true;
            }
            if (!player.Get()->getGlobalBounds().intersects(walls[i]->Get()->getGlobalBounds()))
            {
                is_x_changed = false;
            }
        }

    }

    void Game::Run()
    {
        double angle = 0;
        float velocity = 0;

        bool is_angle_set = false;
        bool is_vel_set = false;

        std::cout << "Enter the angle of throw: ";
        //std::cin >> angle;

        std::cout << "Enter the force of throw: ";
        //std::cin >> velocity;

        mt::Player player({ 200, 600 }, 40);
        //player.NewVelocity(velocity);
        //player.SetAngle(angle);
        //player.UpdateVelocity();

        mt::GuideLine line({200, 600}, 50, 5);
        mt::GuideLine vel({ 100, 750 }, 10, 25);

        int angle_modifier = -1;
        int vel_modifier = 1;

        bool is_angle_changed = false;
        bool is_vel_changed = false;

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
            while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && !is_angle_set)
            {
                m_window->clear();
                angle += 1 * t * angle_modifier;

                if ((angle <= -90 || angle >= 0) && !is_angle_changed)
                {
                    angle_modifier *= -1;
                    is_angle_changed = true;
                }
                if (angle < -20 && angle > -80)
                    is_angle_changed = false;

                line.Set_Angle(angle);
                m_window->draw(*line.Get());
                m_window->display();

            }
            is_angle_set = true;
            angle *= -1;

            while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::F)) && !is_vel_set)
            {
                m_window->clear();
                velocity += 10 * t * vel_modifier;

                if ((velocity >= 1000 || velocity <= 0) && !is_vel_changed)
                {
                    vel_modifier *= -1;
                    is_vel_changed = true;
                }
                if (velocity < 700 && velocity > 100)
                    is_vel_changed = false;

                std::cout << velocity << " " << vel_modifier << std::endl;

                vel.Set_Length(velocity);
                m_window->draw(*vel.Get());
                m_window->display();

            }
            is_vel_set = true;
            velocity /= 10;




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