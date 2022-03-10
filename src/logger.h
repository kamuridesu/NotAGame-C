#include <fstream>
#include <string>
#include "objects.h"
#ifndef LOGGER_H
#define LOGGER_H

int saveLog(const std::string& content) {
    std::ofstream logger;
    logger.open("log.txt");
    logger << content;
    logger.close();
    return 0;
}


int saveLog(Player player) {
    std::ofstream logger;
    logger.open("log.txt");
    logger << player.y_pos.size << " " << player.x_pos.size << " " << player.sprite << " " << player.name << "\n";
    logger.close();
    return 0;
}

#endif