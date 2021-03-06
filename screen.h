#ifndef _SCREEN
#define _SCREEN

#include <iostream>
#include <string>
#include "constants.h"

using std::cout;
using std::string;

class Screen
{
private:
    // x and y keep track of cursor position
    unsigned int x;
    unsigned int y;
    // window width and height
    unsigned int width;
    unsigned int height;
    // internal tests for mode/color validation
    bool testMode(string mode);
    bool testColor(string color);
    // get window dimensions
    void configDimensions();

public:
    // Constructor, x and y begin at 0
    Screen();
    ~Screen(); 

    // Getters
    unsigned int getX();
    unsigned int getY();
    unsigned int getWidth() const { return this->width; }
    unsigned int getHeight() const { return this->height; }
    // Save and restore cursor position
    void savePos() const { cout <<  "\033[s"; }
    void restorePos() const { cout <<  "\033[u"; }
    // Clears the entire screen
    void clear() const { cout <<  "\033[J"; }
    // Clears from the cursor down
    void clearDown() const { cout <<  "\033[0J"; }
    // Clears from the cursor up
    void clearUp() const { cout <<  "\033[1J"; }
    // Similar to clear, use when clear() doesn't
    void forceClear() const { cout << "\033[2J"; }
    // Clears entire line
    void clearLine() const { cout <<  "\033[K"; }
    // Clear from cursor to end of line
    void clearEnd() const { cout <<  "\033[0K"; }
    // Clears from cursor to beginning of line
    void clearBeg() const { cout <<  "\033[1K"; }
    // Hide and show cursor
    void hideCursor() const { cout <<  "\033[?25l"; }
    void showCursor() const { cout <<  "\033[?25h"; }
    
    // Detailed in screen.cpp
    void home();
    void setPos(unsigned int x, unsigned int y);
    void up(unsigned int num);
    void down(unsigned int num);
    void right(unsigned int num);
    void left(unsigned int num);
    void setMode(string mode);
    void setColor(string color);
    void setColor(unsigned int id);
    string getTruePos();

    // cout wrappers
    void print(string mess);
    void print(char mess);
    void flush() const { cout << std::flush; }

    // System cooked or raw
    // Print mode
    void setPrint() const { system("stty cooked"); }
    // Listen for key mode
    void setListen() const { system("stty raw"); }

};

#endif

