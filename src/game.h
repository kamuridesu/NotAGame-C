#include "logger.h"
#include "input.h"
#include "utils.h"
#include "objects.h"
#include "draw.h"
#include <iostream>
#include <stdlib.h>


#ifndef GAME_H
#define GAME_H


void game(const std::string& name) {
    float clock = 1;
    int* terminal_size = get_terminal_size();

    int score = 0;


    Player player;
    Enemy enemy;

    player.name = name;
    player.sprite = "o";
    player.x_pos.size = 0;
    player.y_pos.size = 0;

    enemy.name = "enemy";
    enemy.sprite = "x";
    enemy.x_pos.size = 0;
    enemy.y_pos.size = 0;

    int x = 0;
    while (true) {
        x += 1;
        if (x % 2 == 0) {
            player.x_pos.size += 2;
            player.y_pos.size += 2;
        } else {
            enemy.x_pos.size += 1;
            enemy.y_pos.size += 1;
        }
        draw(player, clock);
        draw(enemy, clock);
        if(x == 15000) {
            break;
        }
        // if(kbhit())  {
        //     char input = getch();
        //     if (input == 'w') {
        //         if(player.y_pos.size < 0) {
        //             player.y_pos.size = 0;
        //         } else {
        //             player.y_pos.size++;
        //         }
        //     } else if (input == 's') {
        //         if(player.y_pos.size > terminal_size[1]) {
        //             player.y_pos.size = terminal_size[1];
        //         } else {
        //             player.y_pos.size--;
        //         }
        //     } else if (input == 'a') {
        //         if(player.x_pos.size < 0) {
        //             player.x_pos.size = 0;
        //         } else {
        //             player.x_pos.size++;
        //         }
        //     } else if (input == 'd') {
        //         if(player.x_pos.size > terminal_size[0]) {
        //             player.x_pos.size = terminal_size[0];
        //         } else {
        //             player.x_pos.size--;
        //         }
        //     } else if (input == 'q') {
        //         break;
        //     }
        // }
    }


    


}


#endif