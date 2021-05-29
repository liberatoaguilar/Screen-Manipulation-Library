#include <iostream>
#include <string>
#include <sstream>
#include "screen.h"

using std::cout;
using std::cin;
using std::string;
using std::to_string;
using std::istringstream;

Screen::Screen() : x(1), y(1)
{
    this->configDimensions();
    this->home();
    this->clear();
}

Screen::~Screen()
{
    this->setMode(MODES::RESET);
    this->showCursor();
}

/* Gets window dimensions */
void Screen::configDimensions()
{
    // Get window dimensions
    this->setPos(999,999);
    string pos = this->getTruePos();
    istringstream posSS(pos);
    // Format returned is "[#;#"
    char bracket;
    int width;
    char semi;
    int height;
    posSS >> bracket >> height >> semi >> width;
    this->width = width;
    this->height = height;
}

/* Sets the x and y position of the cursor
 * Precondition := x and y are in bounds */
void Screen::setPos(unsigned int x, unsigned int y)
{
    if (x >= 1 && x <= this->width
            && y >= 1 && y <= this->height)
    {
        this->x = x;
        this->y = y;
        // Row = y, Col = x
        cout << "\033["+to_string(y)+";"
                +to_string(x)+";"+";H";    
    } else {
        throw std::runtime_error("Out of bounds (x, y)");
    }
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
    if (this->y + num <= this->height)
    {
        this->y += num;
        cout << "\033["+to_string(num)+"B";
    } else {
        throw std::runtime_error("Out of bounds (down)");
    }
}

/* Moves the cursor num columns to the right
 * Precondition := Must be in bounds (<=window size) */
void Screen::right(unsigned int num)
{
    if (this->x + num <= this->width)
    {
        this->x += num;
        cout << "\033["+to_string(num)+"C";
    } else {
        throw std::runtime_error("Out of bounds (right)");
    }
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
            || mode == MODES::STRIKETHROUGH);
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
            || color == COLORS::RESET);
}

/* Sets color if valid
 * Precondition := valid color */
void Screen::setColor(string color)
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
void Screen::setColor(unsigned int id)
{
    if (id <= COLORS::ID_MAX)
    {
        cout << "\033[38;5;$"+to_string(id)+"m";
    } else {
        throw std::runtime_error("Invalid color id");
    }
}

/* Gets string with cursor position
 * Modified from:
 * https://www.tutorialspoint.com/Read-a-character-from-standard-input-without-waiting-for-a-newline-in-Cplusplus */
string Screen::getTruePos()
{
    // Output ANSI code
    cout << "\033[6n";
    // To avoid pressing Enter
    system("stty raw");
    // Ignore escape character
    char esc;
    cin >> esc;

    string pos;
    char c;
    while(true) {
        cin >> c;
        if(c == 'R') { // Last character returned
            system("stty cooked");
            break;
        }  
        pos += c; // Append to string
    }
    // Format is "[#;#"
    return pos;
}

/* Go to (1, 1) */
void Screen::home()
{
    this->x = 1;
    this->y = 1;
    cout << "\033[H";
}
