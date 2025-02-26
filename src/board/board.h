//
// Created by Hugo on 19/03/2021.
//

#ifndef PROJET_SABOTEUR_SABOTEUR_GROUPE_X_BOARD_H
#define PROJET_SABOTEUR_SABOTEUR_GROUPE_X_BOARD_H

#include "../structures/structures.h"
#include "board.h"

void free_board(board *game_board);

void draw_pool_pick(card pool_pick, config configuration);

void draw_card(card *card, config configuration);

void select_card(int x, int y, config configuration, player *player, card *current_card, buffer_position *selection);

void reset_current_card(card *current_card);

void highlight_tile(buffer_position position, config configuration);

void draw_player_hand(config configuration, player *player);

void free_player(player *player);

void draw_round_announcement(board *game_board, config configuration, player *player, card pool_pick, int w, int selection_players,ALLEGRO_FONT* players_nickname);

void display_current_card(card current_card, config configuration);

void update_card_position(card *current_card, unsigned char pressed_keys[], int *modification, config configuration);

void check_selected_tile(int x, int y, board *game_board, config configuration, buffer_position *selection, player *player_tab_infos, int selection_players, card current_card);

void replace_if_outside_board(card *current_card, config configuration, int x, int y);

void draw_board(board *game_board, config configuration);

void draw_turn_announcement(config configuration, player *player, int w, int selection_players,ALLEGRO_FONT* players_nickname, int nb_tour, int modifyingphysicalsize);

void link_card_number(board *game_board);

void value_to_score(board *game_board,player *player_tab_infos, int v, int y, config configuration, int selection_players);
#endif //PROJET_SABOTEUR_SABOTEUR_GROUPE_X_BOARD_H
