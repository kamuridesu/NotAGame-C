#include <stdio.h>
#include <termio.h>
#include <unistd.h>
#include <fcntl.h>


#ifndef INPUT_H
#define INPUT_H


/*
 * Detect keyboard keypress
 */
int kbhit() {
    struct termios oldt, newt;  // old and new terminal I/O settings
    int ch;  // character read from the keyboard
    int oldf;  // old terminal flags
    
    tcgetattr(STDIN_FILENO, &oldt);  // get the current terminal I/O settings
    newt = oldt;  // make a copy of the old settings
    newt.c_lflag &= ~(ICANON | ECHO);  // disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);  // apply the new settings
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);  // get the current file status flags
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);  // set the file status flags
    
    ch = getchar();  // read a character from the keyboard
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  // restore the old terminal I/O settings
    fcntl(STDIN_FILENO, F_SETFL, oldf);  // restore the old file status flags
    
    if(ch != EOF) {  // if the character was not EOF
        ungetc(ch, stdin);  // put the character back into the input stream
        return 1;  // return true
    }
    return 0;  // return false
}


/*
 * Get keyboard input
 */
char getch() {  // get a character from the keyboard
    char buf = 0;  // buffer to hold the character
    struct termios old = {0}; // old terminal I/O settings
    if (tcgetattr(0, &old) < 0){  // get the current terminal I/O settings
        perror("tcsetattr()");  // print an error message if it failed
    }
    old.c_lflag &= ~ICANON;  // disable canonical mode
    old.c_lflag &= ~ECHO;  // disable echo
    old.c_cc[VMIN] = 1;  // read a single character
    old.c_cc[VTIME] = 0;  // no timeout
    if (tcsetattr(0, TCSANOW, &old) < 0){  // apply the new settings
        perror("tcsetattr ICANON");  // print an error message if it failed
    }  
    if (read(0, &buf, 1) < 0){  // read a character from the keyboard
        perror ("read()");  // print an error message if it failed
    }
    old.c_lflag |= ICANON;  // enable canonical mode
    old.c_lflag |= ECHO;  // enable echo
    if (tcsetattr(0, TCSADRAIN, &old) < 0){  // apply the new settings
        perror ("tcsetattr ~ICANON");  // print an error message if it failed
    } 
    return (buf);  // return the character
}



#endif