#include <iostream>
#include <unistd.h>
#include <string>
#include "screen.h"

using std::cin, std::cout, std::endl;
using std::to_string;

constexpr int timeDelay = 2000;

void drawLoad(Screen& s)
{
    s.hideCursor();
    for (int i = 1; i <= s.getHeight(); ++i)
    {
        if (i % 2 == 0)
        {
            s.setColor(COLORS::FG::RED);
        } else {
            s.setColor(COLORS::FG::BLUE);
        }
        if (i < 10)
        {
            s.print(to_string(i)+".  ");
            for (int j = 0; j < s.getWidth()-5; ++j)
            {
                s.print('@');
                s.flush();
                usleep(timeDelay);
            }
        } else {
            s.print(to_string(i)+". ");
            for (int j = 0; j < s.getWidth()-5; ++j)
            {
                s.print('@');
                s.flush();
                usleep(timeDelay);
            }
        }
        s.print('\n');
    }
}

int main()
{
    Screen s;
    drawLoad(s);
    s.up(s.getHeight()/2);
    s.right(s.getWidth()/2);
    s.print("HELLO\n");
    s.down(s.getHeight()/2-1);
    return 0;
}
