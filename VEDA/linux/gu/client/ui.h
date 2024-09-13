#ifndef _UI_H_
#define _UI_H_


#define MENU_SIZE 6
#define AUTH_MENU_SIZE 2

#pragma once
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "network.h"

typedef struct {
	int current_menu;
	int highlight;
	int logged_in;
} UIState;


void show_auth_menu(UIState *state);
void update_layout(UIState *state);
void init_windows();
void draw_header(WINDOW *header_win);
void draw_menu(WINDOW *menu_win, char **choices, int n_choices, int highlight);
void draw_content(WINDOW *content_win, int current_menu, UIState *state);
void draw_footer(WINDOW *footer_win);
void handle_input(int ch, UIState *state, int menu_size);
void draw_login_screen(WINDOW *win, UIState *state);
void draw_register_screen(WINDOW *win, UIState *state);
void show_auth_menu(UIState *state);
void show_main_ui(UIState *state);
void update_layout(UIState *state);
void start_menu();

#endif //_UI_H_
