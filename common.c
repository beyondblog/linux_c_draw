/*
 * =====================================================================================
 *
 *       Filename:  common.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2014/08/29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Richard Yang
 *   Organization:
 *
 * =====================================================================================
 */

#include <stdio.h>
#include "common.h"


void clear() {
    printf("\033[2J");
}

void textcolor(char* color) {
    fprintf(stdout, "%s", color);
}

void backgroud_color(char* color) {
    fprintf(stdout, "%s", color);
}

void color_reset() {
    fprintf(stdout, "%s", COLOR_RESET);
}


void set_cursor_point(int x, int y) {
    fprintf(stdout, "\033[%d;%dH",  y, x);
}

void hide_cursor() {
    fprintf(stdout, CURSOR_HIDE);
}

void show_cursor() {
    fprintf(stdout, CURSOR_SHOW);
}

void save_cursor() {
    fprintf(stdout, CURSOR_SAVE);
}

void load_cursor() {
    fprintf(stdout, CURSOR_LOAD);
}

int getch(void)
{
    int c = 0;
    struct termios org_opts, new_opts;
    int res = 0;
    //-----  store old settings -----------
    res = tcgetattr(STDIN_FILENO, &org_opts);
    assert(res == 0);
    //---- set new terminal parms --------
    memcpy(&new_opts, &org_opts, sizeof(new_opts));
    new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
    c = getchar();
    //------  restore old settings ---------
    res = tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
    assert(res == 0);
    return c;
}
