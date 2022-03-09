#include <iostream>
#include <string>


#ifndef OBJECTS_H
#define OBJECTS_H


class Coordinate_X {
    public:
        int size;
        std::string symbol = " ";
};


class Coordinate_Y {
    public:
        int size;
        std::string symbol = "\n";
};


class Player {
    public:
        std::string name;
        std::string sprite;
        Coordinate_X x_pos;
        Coordinate_Y y_pos;
};


class Enemy {
    public:
        std::string name;
        std::string sprite;
        Coordinate_X x_pos;
        Coordinate_Y y_pos;
};

#endif