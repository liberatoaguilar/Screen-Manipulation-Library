#ifndef _CONSTANTS
#define _CONSTANTS

#include <string>

using std::string;

namespace MODES
{
    const string RESET = "\033[0m";
    const string BOLD = "\033[1m";
    const string DIM = "\033[2m";
    const string ITALIC = "\033[3m";
    const string UNDERLINE = "\033[4m";
    const string BLINKING = "\033[5m";
    const string INVERSE = "\033[7m";
    const string INVISIBLE = "\033[8m";
    const string STRIKETHROUGH = "\033[9m";
}

namespace COLORS
{
    namespace FG
    {
        const string BLACK = "\033[30m";
        const string RED = "\033[31m";
        const string GREEN = "\033[32m";
        const string YELLOW = "\033[33m";
        const string BLUE = "\033[34m";
        const string MAGENTA = "\033[35m";
        const string CYAN = "\033[36m";
        const string WHITE = "\033[37m";
    }

    namespace BG
    {
        const string BLACK = "\033[40m";
        const string RED = "\033[41m";
        const string GREEN = "\033[42m";
        const string YELLOW = "\033[44m";
        const string BLUE = "\033[44m";
        const string MAGENTA = "\033[45m";
        const string CYAN = "\033[46m";
        const string WHITE = "\033[47m";
    }

    const string RESET = "\033[0m";
    const int ID_MAX = 255;
}

#endif

