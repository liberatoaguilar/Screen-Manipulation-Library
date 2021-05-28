# Screen-Manipulation-Library

This is a simple C++ library that uses ANSI escape sequences to manipulate the cursor around the screen. Created to aid in making TUI applications.

## USAGE
* Initialize a `Screen` object
    * `Screen s;`
* Use The functions to print or move the cursor

### Functions
* `getX()` - returns internal x position
* `getY()` - returns internal y position
* `home()` - goes to (1, 1)
* `savePos()` - save cursor position
* `restorePos()` - restore cursor position
* `clear()` - clears the entire screen
* `clearDown()` - clears from the cursor down
* `clearUp()` - clears from the cursor up
* `clearLine()` - clears entire line
* `clearEnd()` - clears from the cursor to end of line
* `clearBeg()` - clears from the cursor to the beginning of line
* `hideCursor()` - hides the cursor
* `showCursor()` - shows the cursor
* `setPos(x, y)` - set cursor position
* `up(num)` - go up num rows
* `down(num)` - go down num rows
* `right(num)` - go right num columns
* `left(num)` - go left num columns
* `setMode(mode)` - set a mode from constants.h
* `setColor(color)` - set a color from constants.h
* `setColor(id)` - set a color from id
* `getTruePos()` - get the true row and column of the cursor
* `print(mess)` - prints a string or character

## NOTES:
* Default begins at (1, 1)
