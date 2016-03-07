#ifndef INPUT_H
#define INPUT_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>



void reset_terminal_mode();
void set_conio_terminal_mode();
int kbhit();
int getch();

#endif
