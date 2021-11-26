#include <iostream>
#include "screen.h"
#include "poker.h"

using std::cin, std::cout, std::endl;

int main()
{
    Screen s;
    Game g;
    g.init(s);
    g.start(s);
    return 0;
}

