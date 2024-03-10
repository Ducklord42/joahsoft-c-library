#include <stdio.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <termios.h>


#define COLOR_NORM  "\x1B[0m"
#define COLOR_RED  "\x1B[1;31m"
#define COLOR_GREEN  "\x1B[1;32m"
#define COLOR_YELLOW  "\x1B[1;33m"
#define COLOR_BLUE  "\x1B[1;34m"
#define COLOR_MAG  "\x1B[1;35m"
#define COLOR_CYAN  "\x1B[1;36m"
#define COLOR_WHITE  "\x1B[1;37m"

#define BG_NORM "\x1B[40m"
#define BG_RED "\x1B[41m"
#define BG_GREEN "\x1B[42m"
#define BG_YELLOW "\x1B[43m"
#define BG_BLUE "\x1B[44m"
#define BG_WHITE "\x1B[47m"


void tc_echo_off();
void tc_echo_on();
void tc_terminal_size(int *cols, int *rows);

void tc_terminal_size(int *cols, int *rows)
{
        struct winsize size;
        ioctl(1, TIOCGWINSZ, &size);
        *cols = size.ws_col;
        *rows = size.ws_row;
}

void tc_echo_off()
{
        struct termios term;
        tcgetattr(1, &term);
        term.c_lflag &= ~ECHO;
        tcsetattr(1, TCSANOW, &term);
}

void tc_echo_on()
{
        struct termios term;
        tcgetattr(1, &term);
        term.c_lflag |= ECHO;
        tcsetattr(1, TCSANOW, &term);
}

#define tc_clear() puts("\x1B[2J")

#define tc_move_cursor(X, Y) printf("\033[%d;%dH", Y, X)
