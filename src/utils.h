#include <sys/ioctl.h>
#include <unistd.h>


#ifndef UTILS_H
#define UTILS_H


// get the number of columns in the terminal
int get_terminal_width() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}


// get the number of rows in the terminal
int get_terminal_height() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_row;
}


// get the full size of the terminal in a array
int* get_terminal_size() {
    int* size = new int[2];
    size[0] = get_terminal_width();
    size[1] = get_terminal_height();
    return size;
}

#endif