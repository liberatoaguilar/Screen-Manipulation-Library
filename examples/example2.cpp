#include <iostream>
#include <string>
#include "screen.h"

using std::cin, std::cout, std::endl;

bool moveLogic(Screen& s)
{
    s.setListen();
    char c;
    s.setMode(MODES::INVISIBLE);
    cin >> c;
    if (c == 'q')
    {
        s.setPrint();
        s.showCursor();
        return false;
    }
    if (c == 'h')
    {
        try {
            s.setPrint();
            s.forceClear();
            s.left(1);
            s.setMode(MODES::RESET);
            s.print('<');
            s.setListen();
            return true;
        } catch (std::exception& e) {
            s.setMode(MODES::RESET);
            s.print('<');
            s.setListen();
            return true;
        }
    }
    if (c == 'j')
    {
        try {
            s.setPrint();
            s.forceClear();
            s.down(1);
            s.setMode(MODES::RESET);
            s.print('V');
            s.setListen();
            return true;
        } catch (std::exception& e) {
            s.setMode(MODES::RESET);
            s.print('V');
            s.setListen();
            return true;
        }
    }
    if (c == 'k')
    {
        try {
            s.setPrint();
            s.forceClear();
            s.up(1);
            s.setMode(MODES::RESET);
            s.print('^');
            s.setListen();
            return true;
        } catch (std::exception& e) {
            s.setMode(MODES::RESET);
            s.print('^');
            s.setListen();
            return true;
        }
    }
    if (c == 'l')
    {
        try {
            s.setPrint();
            s.forceClear();
            s.right(1);
            s.setMode(MODES::RESET);
            s.print('>');
            s.setListen();
            return true;
        } catch (std::exception& e) {
            s.setMode(MODES::RESET);
            s.print('>');
            s.setListen();
            return true;
        }
    }
    return true;
}

int main()
{
    Screen s;
    s.hideCursor();
    bool go = true;
    while (go)
    {
        go = moveLogic(s);
    }
    return 0;
}

