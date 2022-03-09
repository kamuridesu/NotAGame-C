#include <fstream>
#include <string>
#ifndef LOGGER_H
#define LOGGER_H

int saveLog(const std::string& content) {
    std::ofstream logger;
    logger.open("log.txt");
    logger << content;
    logger.close();
    return 0;
}

#endif