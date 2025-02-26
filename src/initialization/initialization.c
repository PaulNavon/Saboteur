//
// Created by Hugo on 23/03/2021.
//

#include "initialization.h"


void init_current_card(card *current_card, card card) {
    current_card->x = card.x-50, current_card->y = card.y-30;
    current_card->front_image = card.front_image;
    current_card->type = card.type;
    current_card->shift_id = card.shift_id;

    if (card.back_image != NULL) {
        current_card->front_image = card.back_image;
        current_card->back_image = card.front_image;
    }
}

void init_pool_pick(card *pool_pick, config configuration, int *modifyingphysicalsize, char pick[], card occurence_point[LIGNES - 1], char call[]) {
    pool_pick->deck[0] = pickCard(pick, modifyingphysicalsize);
    pool_pick->back_image = al_load_bitmap("../images/Card_board/Back_Card_Moove.png");
    pool_pick->yratio = 10.7;
    pool_pick->y = configuration.height / 7;
    pool_pick->xratio = 1.27;
    pool_pick->x = configuration.width / 1.21;
    inputCalling(call);
    for (int j = 0; j < LIGNES - 1; j++) {
        if (pool_pick->deck[0] == call[j]) {
            pool_pick->front_image = occurence_point[j].front_image;
            pool_pick->type = occurence_point[j].type;
            pool_pick->shift_id = occurence_point[j].shift_id;
        }
    }
}

void init_player(player **player_tab, int selection_player) {
    for (int i = 0; i < selection_player; i++) {
        player_tab[i]->board_damage = false;
        player_tab[i]->reactor_damage = false;
        player_tab[i]->suit_damage = false;
    }
    player_tab[0]->ytopratio = 2.78;
    player_tab[0]->ybotratio = 2.16;
    player_tab[1]->ytopratio = 2;
    player_tab[1]->ybotratio = 1.69;
    player_tab[2]->ytopratio = 1.61;
    player_tab[2]->ybotratio = 1.38;
    if (selection_player > 3) {
        player_tab[3]->ytopratio = 1.33;
        player_tab[3]->ybotratio = 1.17;
    }
    if (selection_player > 4) {
        player_tab[4]->ytopratio = 1.14;
        player_tab[4]->ybotratio = 1.02;
    }
}

void init_player_tab_infos(player* player_tab_infos, int selection_players) {
    player_tab_infos[0].ytopratio = 2.78;
    player_tab_infos[0].ybotratio = 2.16;
    player_tab_infos[0].xroleratio = 6.26;
    player_tab_infos[0].yroleratio = 2.746;
    player_tab_infos[0].ybotratio = 2.16;
    player_tab_infos[0].yscoreratio = 2.4;
    player_tab_infos[1].ytopratio = 2.05;
    player_tab_infos[1].ybotratio = 1.74;
    player_tab_infos[1].xroleratio = 87.467;
    player_tab_infos[1].yroleratio = 2.022;
    player_tab_infos[1].yscoreratio = 1.83;
    player_tab_infos[2].ytopratio = 1.61;
    player_tab_infos[2].ybotratio = 1.38;
    player_tab_infos[2].xroleratio = 6.26;
    player_tab_infos[2].yroleratio = 1.601;
    player_tab_infos[2].yscoreratio = 1.48;

    if (selection_players > 3) {
        player_tab_infos[3].ytopratio = 1.33;
        player_tab_infos[3].ybotratio = 1.17;
        player_tab_infos[3].xroleratio = 87.467;
        player_tab_infos[3].yroleratio = 1.327;
        player_tab_infos[3].yscoreratio = 1.24;
    }
    if (selection_players > 4) {
        player_tab_infos[4].ytopratio = 1.14;
        player_tab_infos[4].ybotratio = 1.02;
        player_tab_infos[4].xroleratio = 6.26;
        player_tab_infos[4].yroleratio = 1.131;
        player_tab_infos[4].yscoreratio = 1.07;
    }
}

void init_player_hand(player *player, config configuration) {
    player->hand = calloc(HAND, sizeof(card));
    for (int i = 0; i < HAND; i++) {
        player->hand[i].selected = NULL;
        player->hand[i].yratio = 10.7;
        player->hand[i].value = 0;
        player->hand[i].y = configuration.height / 7;
        player->hand[i].front_image = NULL;
    }
    player->hand[0].xratio = 56.47;
    player->hand[0].x = configuration.width / 19;
    player->hand[1].xratio = 9.796;
    player->hand[1].x = configuration.width / 7.22;
    player->hand[2].xratio = 5.348;
    player->hand[2].x = configuration.width / 4.45;
    player->hand[3].xratio = 3.678;
    player->hand[3].x = configuration.width / 3.22;
    player->hand[4].xratio = 2.8;
    player->hand[4].x = configuration.width / 2.54;
    player->hand[5].xratio = 2.267;
    player->hand[5].x = configuration.width / 2.09;
}

void init_board(board *game_board, int selection_player) {
    switch (selection_player) {
        case 3: game_board->board_image = al_load_bitmap("../images/Title_screen/board_3p.jpg");
        break;
        case 4: game_board->board_image = al_load_bitmap("../images/Title_screen/board_4p.jpg");
        break;
        case 5: game_board->board_image = al_load_bitmap("../images/Title_screen/board_5p.jpg");
            break;
        default:
            game_board->board_image = al_load_bitmap("../images/Title_screen/board_3p.jpg");
            break;
    }
    game_board->tab = calloc(COLUMNS, sizeof(card *));
    for (int i = 0; i < COLUMNS; i++) {
        game_board->tab[i] = calloc(ROWS, sizeof(card));
    }
    for (int i = 0; i < COLUMNS; i++) {
        for (int j = 0; j < ROWS; j++) {
            game_board->tab[i][j].front_image = NULL;
            game_board->tab[i][j].type = 0;
            game_board->tab[i][j].shift_id = "SION";
            game_board->tab[i][j].selected = NULL;
        }
    }

    ///TILES POSITION INITIALISATION
    for (int i = 0; i < COLUMNS; i++) {
        game_board->tab[i][0].yratio = 2.88;
        game_board->tab[i][1].yratio = 2.255;
        game_board->tab[i][2].yratio = 1.86;
        game_board->tab[i][3].yratio = 1.59;
        game_board->tab[i][4].yratio = 1.39;
        game_board->tab[i][5].yratio = 1.23;
        game_board->tab[i][6].yratio = 1.106;
        game_board->tab[i][7].yratio = 1;
    }

    for (int i = 0; i < ROWS; i++) {
        game_board->tab[0][i].xratio = 3.918;
        game_board->tab[1][i].xratio = 3.033;
        game_board->tab[2][i].xratio = 2.477;
        game_board->tab[3][i].xratio = 2.09;
        game_board->tab[4][i].xratio = 1.81;
        game_board->tab[5][i].xratio = 1.596;
        game_board->tab[6][i].xratio = 1.427;
        game_board->tab[7][i].xratio = 1.29;
        game_board->tab[8][i].xratio = 1.177;
        game_board->tab[9][i].xratio = 1.08;
        game_board->tab[10][i].xratio = 1;
    }
}

void load_board_images(board *game_board) {
    game_board->tab[1][3].front_image = al_load_bitmap("../images/Card_board/card_start.png");
    game_board->tab[1][3].type = '%';
    game_board->tab[1][3].shift_id = "RDLU";
    game_board->tab[1][3].value = 0;

    game_board->tab[9][1].front_image = al_load_bitmap("../images/Card_ending/Back_Card_Planet_screengame.png");
    game_board->tab[9][1].back_image= al_load_bitmap("../images/Card_ending/Card_Planet_1.png");
    game_board->tab[9][1].back_image_big= al_load_bitmap("../images/Card_ending/Card_Planet_1_Big.png");
    game_board->tab[9][1].type = '$';
    game_board->tab[9][1].shift_id = "SION";
    game_board->tab[9][1].value = 100;
    game_board->tab[9][1].buff_image = NULL;

    game_board->tab[9][3].front_image = al_load_bitmap("../images/Card_ending/Back_Card_Planet_screengame.png");
    game_board->tab[9][3].back_image= al_load_bitmap("../images/Card_ending/Card_Planet_2.png");
    game_board->tab[9][3].back_image_big= al_load_bitmap("../images/Card_ending/Card_Planet_2_Big.png");
    game_board->tab[9][3].type = '$';
    game_board->tab[9][3].shift_id = "SION";
    game_board->tab[9][3].value = 5;
    game_board->tab[9][3].buff_image = NULL;

    game_board->tab[9][5].front_image = al_load_bitmap("../images/Card_ending/Back_Card_Planet_screengame.png");
    game_board->tab[9][5].back_image= al_load_bitmap("../images/Card_ending/Card_Planet_3.png");
    game_board->tab[9][5].back_image_big= al_load_bitmap("../images/Card_ending/Card_Planet_3_Big.png");
    game_board->tab[9][5].type = '$';
    game_board->tab[9][5].shift_id = "SION";
    game_board->tab[9][5].value = 50;
    game_board->tab[9][5].buff_image = NULL;
}