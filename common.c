/*
 * =====================================================================================
 *
 *       Filename:  common.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2014/08/29 08时59分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YangBing (),
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
