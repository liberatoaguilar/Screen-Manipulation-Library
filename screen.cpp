#include <iostream>
#include <string>
#include "screen.h"

using std::cout;
using std::string;
using std::to_string;

/* Sets the x and y position of the cursor
 * Precondition := x and y are in bounds */
void Screen::setPos(unsigned int x, unsigned int y)
{
    // TODO test for invalid
    this->x = x;
    this->y = y;
    cout << "\033["+to_string(x)+";"
            +to_string(y)+";"+";H";    
}

/* Moves the cursor num lines up 
 * Precondition := Must be in bounds (>=0) */
void Screen::up(unsigned int num)
{
    if ((static_cast<int>(this->y) 
                - static_cast<int>(num)) >= 0) 
    {
        this->y -= num;
        cout << "\033["+to_string(num)+"A";
    } else {
        throw std::runtime_error("Out of bounds (up)");
    }

}

/* Moves the cursor num lines down
 * Precondition := Must be in bounds (<=window size) */
void Screen::down(unsigned int num)
{
    // TODO Implement test
    this->y += num;
    cout << "\033["+to_string(num)+"B";
}

/* Moves the cursor num columns to the right
 * Precondition := Must be in bounds (<=window size) */
void Screen::right(unsigned int num)
{
    // TODO Implement test
    this->x += num;
    cout << "\033["+to_string(num)+"C";
}

/* Moves the cursor num columns to the left
 * Precondition := Must be in bounds (<=0) */
void Screen::left(unsigned int num)
{
    if ((static_cast<int>(this->x) 
                - static_cast<int>(num)) >= 0) 
    {
        this->x -= num;
        cout << "\033["+to_string(num)+"D";
    } else {
        throw std::runtime_error("Out of bounds (left)");
    }
}

/* Internal test from "constants.h" */
bool Screen::testMode(string mode)
{
    return (mode == MODES::RESET 
            || mode == MODES::BOLD
            || mode == MODES::DIM
            || mode == MODES::ITALIC
            || mode == MODES::UNDERLINE
            || mode == MODES::BLINKING
            || mode == MODES::INVERSE
            || mode == MODES::INVISIBLE
            || mode == MODES::STRIKETHROUGH)
}

/* Set mode if valid 
 * Precondition := valid mode */
void Screen::setMode(string mode)
{
    if (testMode(mode))
    {
        cout << mode;
    } else {
        throw std::runtime_error("Unknown mode");
    }
}

/* Internal test from "constants.h" */
bool Screen::testColor(string color)
{
    return (color == COLORS::FG::BLACK
            || color == COLORS::FG::RED
            || color == COLORS::FG::GREEN
            || color == COLORS::FG::YELLOW
            || color == COLORS::FG::BLUE
            || color == COLORS::FG::MAGENTA
            || color == COLORS::FG::CYAN
            || color == COLORS::FG::WHITE
            || color == COLORS::BG::BLACK
            || color == COLORS::BG::RED
            || color == COLORS::BG::GREEN
            || color == COLORS::BG::YELLOW
            || color == COLORS::BG::BLUE
            || color == COLORS::BG::MAGENTA
            || color == COLORS::BG::CYAN
            || color == COLORS::BG::WHITE
            || color == COLORS::RESET)
}

/* Sets color if valid
 * Precondition := valid color */
void setColor(string color)
{
    if (testColor(color))
    {
        cout << color;
    } else {
        throw std::runtime_error("Unkown color");
    }
}

/* Sets color from id 
 * Precondition := valid id (0-255) */
void setColor(unsigned int id)
{
    if (id <= COLORS::ID_MAX)
    {
        cout << "\033[38;5;$"+to_string(id)+"m";
    } else {
        throw std::runtime_error("Invalid color id");
    }
}

