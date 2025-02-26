//
// Created by Hugo on 23/03/2021.
//

#ifndef PROJET_SABOTEUR_SABOTEUR_GROUPE_X_INITIALIZATION_H
#define PROJET_SABOTEUR_SABOTEUR_GROUPE_X_INITIALIZATION_H

#include "../card_shuffle//card_shuffle.h"
#include "../structures/structures.h"

void init_board(board *game_board, int selection_player);

void init_player(player **player_tab, int selection_player);

void init_pool_pick(card *pool_pick, config configuration, int *modifyingphysicalsize, char pick[], card occurence_point[LIGNES - 1], char call[]);

void init_player_tab_infos(player* player_tab_infos, int selection_players);

void init_current_card(card *current_card, card player);

void load_board_images(board *game_board);

void init_player_hand(player *player, config configuration);

#endif //PROJET_SABOTEUR_SABOTEUR_GROUPE_X_INITIALIZATION_H
