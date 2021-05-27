# Screen Manipulation Library

## Screen Class
    * Private
        * Cursor position
    * Public
        * `home()` _ESC[H_
        * `setPos(x, y)` _ESC[{line};{col};H ESC[{line};{col}f_
        * `up(x)` _ESC[#A_
        * `down(x)` _ESC[#B_
        * `right(x)` _ESC[#C_
        * `left(x)` _ESC[#D_
        * `next(x)` _ESC[#E_
            * Need?
        * `prev(x)` _ESC[#F_
            * Need?
        * `setCol(x)` _ESC[#G_
            * Need?
            * Doesn't work
        * `string getTruePos()` _ESC[6n_
            * returns _ESC[#;#R_
            * _TODO_
        * `int getX()`
        * `int getY()`
        * `savePos()` _ESC[s_
        * `restorePos()` _ESC[u_
        * `clear()` _ESC[J_
        * `clearDown()` _ESC[0J_
        * `clearUp()` _ESC[1J_
        * `clearLine()` _ESC[K_
        * `clearEnd()` _ESC[0K_
        * `clearBeg()` _ESC[1K_
        * `setMode(mode)`
        * `setColor(color)`
        * `setColor(id)` _ESC[38;5;${ID}m_
        * `hideCursor()` _ESC[?25l_
        * `showCursor()` _ESC[?25h_


## Namespace Modes
    * Reset _ESC[0m_
    * Bold _ESC[1m_
    * Dim _ESC[2m_
    * Italic _ESC[3m_
    * Underline _ESC[4m_
    * Blinking _ESC[5m_
    * Inverse _ESC[7m_
    * Invisible _ESC[8m_
    * Strikethrough _ESC[9m_


## Namespace Colors
    * Foreground
        * Black _ESC[30m_
        * Red _ESC[31m_
        * Green _ESC[32m_
        * Yellow _ESC[33m_
        * Blue _ESC[34m_
        * Magenta _ESC[35m_
        * Cyan _ESC[36m_
        * White _ESC[37m_
    * Background
        * Black _ESC[40m_
        * Red _ESC[41m_
        * Green _ESC[42m_
        * Yellow _ESC[44m_
        * Blue _ESC[44m_
        * Magenta _ESC[45m_
        * Cyan _ESC[46m_
        * White _ESC[47m_
    * Reset _ESC[0m_
