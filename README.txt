*****Joahsoft C library*****
Only for linux


***terminal controller***
#include "tc.h"
Move cursor around                |tc_move_cursor(x,y)
Have colors and background colors |RED, GREEN, YELLOW, BLUE, WHITE, CYAN, MAG (COLOR_ or BG_)
Turn on and off echo              |tc_echo_off() and tc_echo_on()
Find the size of the terminal     |tc_terminal_size(ptr cols, ptr rows)
Clear the terminal                |tc_clear()


***dictionary in c***
#include "dict.h"
Set key/value pair of char[24]    |setdict(dictionary, key, value, index)
Find the value of a specific key  |dictk(length-of-dictionary, dictionary, key) returns value
