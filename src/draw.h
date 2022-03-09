#include "objects.h"
#include <iostream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>


#ifndef DRAW_H
#define DRAW_H


void draw(Player player, float clear_time) {
    std::string content = "";
    for(int i = 0; i < player.y_pos.size; i++) {
        content += player.y_pos.symbol;
    }
    for(int i = 0; i < player.x_pos.size; i++) {
        content += player.x_pos.symbol;
    }
    content += player.sprite;
    std::cout << content << std::flush;
    sleep(clear_time);
    std::cout << "\033[2J\033[1;1H";
}

void draw(Enemy enemy, float clear_time) {
    std::string content = "";
    for(int i = 0; i < enemy.y_pos.size; i++) {
        content += enemy.y_pos.symbol;
    }
    for(int i = 0; i < enemy.x_pos.size; i++) {
        content += enemy.x_pos.symbol;
    }
    content += enemy.sprite;
    std::cout << content << std::flush;
    sleep(clear_time);
    std::cout << "\033[2J\033[1;1H";
}

void draw(const std::string content, float clear_time) {
    std::cout << content << std::flush;
    sleep(clear_time);
}



#endif