#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
//#include <Game.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <cmath>
#include "Game.h"

int main() {
    mt::Game game;

    game.set_name("Game_1");
    game.set_resolution(1200, 800);
    game.setup();
    game.Run();

    return 0;
}
