//
// Created by Hugo on 29/03/2021.
//
#include "../structures/structures.h"

#ifndef PROJET_SABOTEUR_SABOTEUR_GROUPE_X_PLAYER_TURN_H
#define PROJET_SABOTEUR_SABOTEUR_GROUPE_X_PLAYER_TURN_H

int placement_on_players(player* player_tab_infos, card *current_card, config configuration, int x, int y, int o, int v);

void draw_debuff(player* player_tab_infos, config configuration);

int check_placement_on_void(config configuration, int x, int y);

int check_placement_on_deck(player *deck_slot, int j, config configuration, int x, int y);

int check_placement_on_pool_pick(config configuration, int x, int y);

int check_placement_on_board(board *game_board, card *current_card, int i, int j);

void draw_players_ranking(int selection_players, config configuration);

int card_next_to_end(board *game_board, int i, int j, int* detect_end_y,card *current_card);

#endif //PROJET_SABOTEUR_SABOTEUR_GROUPE_X_PLAYER_TURN_H
