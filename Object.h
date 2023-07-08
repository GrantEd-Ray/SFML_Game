#pragma once
#include <SFML/Graphics.hpp>
//#include <Game.h>
//#include <Player.h>
#include <string>
#include <cmath>

namespace mt
{
    struct Coord
    {
        double x;
        double y;
    };

    class Object {
    protected:
        Coord m_start;

    public:
        Object(Coord st_0) : m_start(st_0)
        {

        }
        virtual void Set_Color() {};

    };

    class Wall : public Object
    {
    protected:
        double m_len_x, m_len_y;
        sf::RectangleShape* m_rect;
    public:
        Wall(Coord p, double len_x, double len_y) : Object(p)
        {
            m_rect = new sf::RectangleShape(sf::Vector2f(len_x, len_y));
            m_rect->setPosition(p.x, p.y);
        }

        ~Wall()
        {
            delete m_rect;
        }

        void Set_Color() override
        {
            m_rect->setFillColor(sf::Color::White);
        }

        sf::RectangleShape* Get()
        {
            return m_rect;
        }
    };

    class Player : public Object
    {
    protected:
        double m_radius;
        sf::CircleShape* m_ball;

    public:
        Player(Coord center, double radius) : Object(center)
        {
            m_radius = radius;
            m_ball = new sf::CircleShape(m_radius);
            m_ball->setOrigin(m_radius + 1, m_radius - 1);
            m_ball->setPosition(center.x, center.y);
        }

        ~Player()
        {
            delete m_ball;
        }
        void Set_Color() override
        {
            m_ball->setFillColor(sf::Color::Blue);
        }

        sf::CircleShape* Get()
        {
            return m_ball;
        }

        void SetPosition(float x, float y)
        {
            m_ball->setPosition(x, y);
        }
    };

    class GuideLine : public Object
    {
    protected:
        sf::RectangleShape* m_line;
    public:
        GuideLine(Coord p, double len_x, double len_y): Object(p)
        {
            m_line = new sf::RectangleShape(sf::Vector2f(len_x, len_y));
            m_line->setOrigin(0, len_y / 2);
            m_line->setPosition(p.x, p.y);
        }

        ~GuideLine()
        {
            delete m_line;
        }

        void Set_Angle(double angle)
        {
            m_line->setRotation(angle);
        }

        void Set_Length(double len)
        {
            m_line->setSize(sf::Vector2f(len, 25));
        }

        sf::RectangleShape* Get()
        {
            return m_line;
        }
    };
}




