/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  unix c draw
 *
 *        Version:  1.0
 *        Created:  2014/08/29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Occam's Razor
 *   Organization:
 *
 * =====================================================================================
 */


#include <stdio.h>
#include <sys/ioctl.h>
#include "common.h"


int main(int agrc, char* argc[])
{
    clear();
    struct winsize window;
    ioctl(0, TIOCGWINSZ, &window);
    int row = window.ws_row;
    int col = window.ws_col;
    set_cursor_point(col / 2 - 6, row / 2);
    textcolor(TEXT_RED);
    fprintf(stdout, "Hello ");
    textcolor(TEXT_GREEN);
    fprintf(stdout, "World\n" TEXT_WHITE);
    set_cursor_point(col / 2 - 8, row / 2 + 2);
    fprintf(stdout, "Linux" TEXT_BLUE);
    fprintf(stdout, " COLOR" TEXT_PURPLE);
    fprintf(stdout, " TEXT\n");
    color_reset();

    //draw top bar
    set_cursor_point(0, 0);
    backgroud_color(BACKGRPUND_GREEN);
    for(int i = 0; i < col / 2; i++)
        printf("  ");
    set_cursor_point(col / 2 - 8, 0);
    textcolor(TEXT_WHITE);
    fprintf(stdout, "Appliction Title");

    //draw bottom bar
    set_cursor_point(0, row - 1);
    backgroud_color(BACKGRPUND_BLACK);
    for(int i = 0; i < col / 2; i++)
        printf("  ");
    set_cursor_point(0, row -1);
    textcolor(TEXT_WHITE);
    fprintf(stdout, "  Status Bar");
    set_cursor_point(0, row);
    
    hide_cursor();
    getchar();
    show_cursor();
    return 0;
}
