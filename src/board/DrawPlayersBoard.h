#include "../structures/structures.h"

#ifndef SABOTEUR_DRAWPLAYERSBOARD_H
#define SABOTEUR_DRAWPLAYERSBOARD_H


void display_players_onboard(config configuration, player * player_tab_infos,int selection_players,ALLEGRO_FONT* players_nickname);

void function_in_game(int selection_players, player *player_tab_infos);

void show_function(int v, int selection_players, player *player_tab_infos, config configuration,ALLEGRO_FONT *players_nickname );

void position_under_card(int i, player *player_tab_infos, config configuration,ALLEGRO_FONT *players_nickname);

void show_function_end_game( int selection_players, player *player_tab_infos, config configuration, ALLEGRO_TIMER *timerRev, ALLEGRO_EVENT_QUEUE *queue_rev,
                             struct ALLEGRO_BITMAP *rev1, ALLEGRO_BITMAP *rev2, ALLEGRO_BITMAP *rev3);

void place(int selection_players, player *player_tab_infos);

void ranking(int selection_players, player *player_tab_infos, config configuration, ALLEGRO_TIMER *timerRev, ALLEGRO_EVENT_QUEUE *queue_rev,ALLEGRO_BITMAP *gold_med, ALLEGRO_BITMAP *silver_med, ALLEGRO_BITMAP *bronze_med);
#endif