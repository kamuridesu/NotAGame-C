#include "logger.h"
#include "input.h"
#include "utils.h"
#include "objects.h"
#include "draw.h"
#include <iostream>
#include <stdlib.h>



#ifndef GAME_H
#define GAME_H


bool checkCollision(Player player, Enemy enemy) {
    if(player.x_pos.size == enemy.x_pos.size && player.y_pos.size == enemy.y_pos.size) {
        return true;
    }
    return false;
}


Enemy randomPosition(Enemy enemy) {
    enemy.x_pos.size = rand() % (get_terminal_size()[0] - 1);
    enemy.y_pos.size = rand() % (get_terminal_size()[1] - 1);
    return enemy;
}


void game(const std::string& name) {
    float clock = 0.009;
    int* terminal_size = get_terminal_size();

    int score = 0;

    Player player;
    Enemy enemy;

    player.name = name;
    player.sprite = "o";
    player.x_pos.size = 1;
    player.y_pos.size = 1;

    enemy.name = "enemy";
    enemy.sprite = "x";
    enemy = randomPosition(enemy);

    while (true) {
        draw(player, clock);
        draw(enemy, clock);
        draw("Score: " + std::to_string(score), clock);

        if(kbhit())  {
            char input = getch();
            if (input == 'w') {
                if(player.y_pos.size < 0) {
                    player.y_pos.size = 1;
                } else {
                    player.y_pos.size--;
                }
            } else if (input == 's') {
                if(!(player.y_pos.size >= terminal_size[1] - 1)) {
                    player.y_pos.size++;
                }
            } else if (input == 'a') {
                if(player.x_pos.size < 0) {
                    player.x_pos.size = 1;
                } else {
                    player.x_pos.size--;
                }
            } else if (input == 'd') {
                if(!(player.x_pos.size > terminal_size[0] - 1)) {
                    player.x_pos.size++;
                } 
            } else if (input == 'q') {
                break;
            }
            if(checkCollision(player, enemy)) {
                score++;
                enemy = randomPosition(enemy);
            }
        }
    }
}


#endif