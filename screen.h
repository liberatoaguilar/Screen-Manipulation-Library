#ifndef _SOMETHING
#define _SOMETHING

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
    // internal tests for mode/color validation
    bool testMode(string mode);
    bool testColor(string color);

public:
    // Constructor, x and y begin at 0
    Screen() : x(0), y(0) { this->home(); }

    // Getters
    unsigned int getX() const { return this->x; }
    unsigned int getY() const { return this->y; }
    // Go to (0, 0)
    void home() const { cout << "\033[H"; }
    // Save and restore cursor position
    void savePos() const { cout <<  "\033[s"; }
    void restorePos() const { cout <<  "\033[u"; }
    // Clears the entire screen
    void clear() const { cout <<  "\033[J"; }
    // Clears from the cursor down
    void clearDown() const { cout <<  "\033[0J"; }
    // Clears from the cursor up
    void clearUp() const { cout <<  "\033[1J"; }
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
    void setPos(unsigned int x, unsigned int y);
    void up(unsigned int num);
    void down(unsigned int num);
    void right(unsigned int num);
    void left(unsigned int num);
    void setMode(string mode);
    void setColor(string color);
    void setColor(unsigned int id);

    // cout wrappers
    void print(string mess) const { cout << mess; }
    void print(char mess) const { cout << mess; }

};

#endif

