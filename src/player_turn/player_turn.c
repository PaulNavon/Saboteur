//
// Created by Hugo on 29/03/2021.
//

#include "player_turn.h"

int
placement_on_players(player *player_tab_infos, card *current_card, config configuration, int x, int y, int o, int v) {
    if (current_card->type >= 'A' && current_card->type <= 'C') {
        if (x > configuration.width / 120 && x < configuration.width / 4 &&
            y > configuration.height / player_tab_infos->ytopratio &&
            y < configuration.height / player_tab_infos->ybotratio && (o != v)) {
            switch (current_card->type) {
                case 'A':
                    if (player_tab_infos->board_damage == false) {
                        player_tab_infos->board_damage = true;
                        return 1;
                    }
                    break;
                case 'B':
                    if (player_tab_infos->reactor_damage == false) {
                        player_tab_infos->reactor_damage = true;
                        return 1;
                    }
                    break;
                case 'C':
                    if (player_tab_infos->suit_damage == false) {
                        player_tab_infos->suit_damage = true;
                        return 1;
                    }
                    break;
                default:
                    break;
            }
        }
    } else if (current_card->type >= 'D' && current_card->type <= 'I') {
        if (x > configuration.width / 120 && x < configuration.width / 4 &&
            y > configuration.height / player_tab_infos->ytopratio &&
            y < configuration.height / player_tab_infos->ybotratio && (o == v)) {
            switch (current_card->type) {
                case 'D':
                    if (player_tab_infos->board_damage == true) {
                        player_tab_infos->board_damage = false;
                        return 1;
                    }
                    break;
                case 'E':
                    if (player_tab_infos->reactor_damage == true) {
                        player_tab_infos->reactor_damage = false;
                        return 1;
                    }
                    break;
                case 'F':
                    if (player_tab_infos->suit_damage == true) {
                        player_tab_infos->suit_damage = false;
                        return 1;
                    }
                    break;
                case 'G':
                    if (player_tab_infos->reactor_damage == true) {
                        player_tab_infos->reactor_damage = false;
                        return 1;
                    } else if (player_tab_infos->suit_damage == true) {
                        player_tab_infos->suit_damage = false;
                        return 1;
                    }
                    break;
                case 'H':
                    if (player_tab_infos->board_damage == true) {
                        player_tab_infos->board_damage = false;
                        return 1;
                    } else if (player_tab_infos->suit_damage == true) {
                        player_tab_infos->suit_damage = false;
                        return 1;
                    }
                    break;
                case 'I':
                    if (player_tab_infos->board_damage == true) {
                        player_tab_infos->board_damage = false;
                        return 1;
                    } else if (player_tab_infos->reactor_damage == true) {
                        player_tab_infos->reactor_damage = false;
                        return 1;
                    }
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}

void draw_debuff(player *player_tab_infos, config configuration) {
    ALLEGRO_FONT *problem = al_load_ttf_font("../fonts/agency-fb/agency-fb-bold.ttf", configuration.height / 33.75, 0);

    if (player_tab_infos->board_damage == true) {
        al_draw_textf(
                problem,
                al_map_rgba(145, 0, 0, 70),
                configuration.width / 1.95,
                configuration.height / 3.2 -
                al_get_font_ascent(configuration.font),
                ALLEGRO_ALIGN_CENTER,
                "YOUR CONTROL DECK IS ON FIRE !");
    }
    if (player_tab_infos->reactor_damage == true) {
        al_draw_textf(
                problem,
                al_map_rgba(145, 0, 0, 70),
                configuration.width / 1.95,
                configuration.height / 2.9 -
                al_get_font_ascent(configuration.font),
                ALLEGRO_ALIGN_CENTER,
                "YOUR REACTORS ARE DOWN !");
    }
    if (player_tab_infos->suit_damage == true) {
        al_draw_textf(
                problem,
                al_map_rgba(145, 0, 0, 70),
                configuration.width / 1.95,
                configuration.height / 2.7 -
                al_get_font_ascent(configuration.font),
                ALLEGRO_ALIGN_CENTER,
                "YOUR OXYGEN GENERATOR IS LEAKING !");
    }
}

int check_placement_on_void(config configuration, int x, int y) {
    if (x > configuration.width / 1.43 && x < configuration.width / 1.28 && y > configuration.height / 11 &&
        y < configuration.height / 5.17) {
        return 1;
    } else { return 0; }
}

int check_placement_on_pool_pick(config configuration, int x, int y) {
    if (x > configuration.width / 1.27 && x < configuration.width / 1.16 && y > configuration.height / 11 &&
        y < configuration.height / 5.17) {
        return 1;
    } else { return 0; }
}

int check_placement_on_deck(player *deck_slot, int j, config configuration, int x, int y) {
    if (x >= configuration.width / deck_slot->hand[j].xratio &&
        x < configuration.width / deck_slot->hand[j + 1].xratio &&
        y >= configuration.height / deck_slot->hand[j].yratio &&
        y < configuration.height / 4.596 && deck_slot->hand[j].front_image == NULL) {
        return 1;
    } else { return 0; }
}

void draw_players_ranking(int selection_players, config configuration) {

    if (selection_players == 3) {
        ALLEGRO_BITMAP *ranking3p = al_load_bitmap("../images/Score/Score_screen_3players.png");
        al_draw_scaled_bitmap(ranking3p, 0, 0, 1920, 1080, 0, 0,
                              (float) configuration.width,
                              (float) configuration.height,
                              0);
        al_destroy_bitmap(ranking3p);
    } else if (selection_players == 4) {
        ALLEGRO_BITMAP *ranking4p = al_load_bitmap("../images/Score/Score_screen_4players.png");
        al_draw_scaled_bitmap(ranking4p, 0, 0, 1920, 1080, 0, 0,
                              (float) configuration.width,
                              (float) configuration.height,
                              0);
        al_destroy_bitmap(ranking4p);
    } else {
        ALLEGRO_BITMAP *ranking5p = al_load_bitmap("../images/Score/Score_screen_5players.png");
        al_draw_scaled_bitmap(ranking5p, 0, 0, 1920, 1080, 0, 0,
                              (float) configuration.width,
                              (float) configuration.height,
                              0);
        al_destroy_bitmap(ranking5p);
    }
}

int check_placement_on_board(board *game_board, card *current_card, int i, int j) {
    if (i == 0) {
        switch (current_card->type) {
            case 'J' :
                if (game_board->tab[i][j].type == '$') {
                    return 1;
                }
            case 'K' :
                current_card->front_image = al_load_bitmap("../images/Card_board/Black_hole.png");
                return 1;
            case 'L' :
                if (strchr(game_board->tab[i + 1][j].shift_id, 'L') != NULL) {
                    return 1;
                }
                break;
            case 'M':
                if (strchr(game_board->tab[i][j + 1].shift_id, 'U') != NULL ||
                    strchr(game_board->tab[i][j - 1].shift_id, 'D') != NULL) {
                    return 1;
                }
                break;
            case 'O' :
                if (strchr(game_board->tab[i + 1][j].shift_id, 'L') != NULL ||
                    strchr(game_board->tab[i][j + 1].shift_id, 'U') != NULL ||
                    strchr(game_board->tab[i][j - 1].shift_id, 'D') != NULL) {
                    return 1;
                }
                break;
            case 'P' :
                if (strchr(game_board->tab[i + 1][j].shift_id, 'L') != NULL ||
                    strchr(game_board->tab[i][j - 1].shift_id, 'D') != NULL) {
                    return 1;
                }
                break;
            case 'Q' :
                if (strchr(game_board->tab[i + 1][j].shift_id, 'L') != NULL ||
                    strchr(game_board->tab[i][j + 1].shift_id, 'U') != NULL) {
                    return 1;
                }
                break;
            case 'R' :
                if (strchr(game_board->tab[i + 1][j].shift_id, 'L') != NULL ||
                    strchr(game_board->tab[i][j - 1].shift_id, 'D') != NULL) {
                    return 1;
                }
                break;
            case 'S' :
                if (strchr(game_board->tab[i][j + 1].shift_id, 'U') != NULL) {
                    return 1;
                }
                break;
            case 'T' :
                if (strchr(game_board->tab[i][j + 1].shift_id, 'U') != NULL ||
                    strchr(game_board->tab[i][j - 1].shift_id, 'D') != NULL) {
                    return 1;
                }
                break;
            case 'U' :
                if (strchr(game_board->tab[i][j - 1].shift_id, 'D') != NULL) {
                    return 1;
                }
                break;
            case 'V' :
                if (strchr(game_board->tab[i + 1][j].shift_id, 'L') != NULL ||
                    strchr(game_board->tab[i][j + 1].shift_id, 'U') != NULL) {
                    return 1;
                }
                break;
            case 'W' :
                if (strchr(game_board->tab[i + 1][j].shift_id, 'L') != NULL ||
                    strchr(game_board->tab[i][j + 1].shift_id, 'U') != NULL ||
                    strchr(game_board->tab[i][j - 1].shift_id, 'D') != NULL) {
                    return 1;
                }
                break;
            case 'X' :
                if (strchr(game_board->tab[i + 1][j].shift_id, 'L') != NULL) {
                    return 1;
                }
                break;
            case '$':
                if (strchr(game_board->tab[i][j + 1].shift_id, 'U') != NULL ||
                    strchr(game_board->tab[i][j - 1].shift_id, 'D') != NULL) {
                    return 1;
                }
                break;
            default:
                return 0;
        }
    } else if (j == 0) {
        switch (current_card->type) {
            case 'J' :
                if (game_board->tab[i][j].type == '$') {
                    return 1;
                }
            case 'K' :
                current_card->front_image = al_load_bitmap("../images/Card_board/Black_hole.png");
                return 1;
            case 'L' :
                if (strchr(game_board->tab[i + 1][j].shift_id, 'L') != NULL ||
                    strchr(game_board->tab[i - 1][j].shift_id, 'R') != NULL) {
                    return 1;
                }
                break;
            case 'M':
                if (strchr(game_board->tab[i][j + 1].shift_id, 'U') != NULL) {
                    return 1;
                }
                break;
            case 'N':
                if (strchr(game_board->tab[i - 1][j].shift_id, 'R') != NULL) {
                    return 1;
                }
                break;
            case 'O' :
                if (strchr(game_board->tab[i + 1][j].shift_id, 'L') != NULL ||
                    strchr(game_board->tab[i - 1][j].shift_id, 'R') != NULL ||
                    strchr(game_board->tab[i][j + 1].shift_id, 'U') != NULL) {
                    return 1;
                }
                break;
            case 'P' :
                if (strchr(game_board->tab[i + 1][j].shift_id, 'L') != NULL ||
                    strchr(game_board->tab[i - 1][j].shift_id, 'R') != NULL) {
                    return 1;
                }
                break;
            case 'Q' :
                if (strchr(game_board->tab[i + 1][j].shift_id, 'L') != NULL ||
                    strchr(game_board->tab[i - 1][j].shift_id, 'R') != NULL ||
                    strchr(game_board->tab[i][j + 1].shift_id, 'U') != NULL) {
                    return 1;
                }
                break;
            case 'R' :
                if (strchr(game_board->tab[i + 1][j].shift_id, 'L') != NULL) {
                    return 1;
                }
                break;
            case 'S' :
                if (strchr(game_board->tab[i - 1][j].shift_id, 'R') != NULL ||
                    strchr(game_board->tab[i][j + 1].shift_id, 'U') != NULL) {
                    return 1;
                }
                break;
            case 'T' :
                if (strchr(game_board->tab[i - 1][j].shift_id, 'R') != NULL ||
                    strchr(game_board->tab[i][j + 1].shift_id, 'U') != NULL) {
                    return 1;
                }
                break;
            case 'U' :
                if (strchr(game_board->tab[i - 1][j].shift_id, 'R') != NULL) {
                    return 1;
                }
                break;
            case 'V' :
                if (strchr(game_board->tab[i + 1][j].shift_id, 'L') != NULL ||
                    strchr(game_board->tab[i][j + 1].shift_id, 'U') != NULL) {
                    return 1;
                }
                break;
            case 'W' :
                if (strchr(game_board->tab[i + 1][j].shift_id, 'L') != NULL ||
                    strchr(game_board->tab[i][j + 1].shift_id, 'U') != NULL) {
                    return 1;
                }
                break;
            case '$':
                if (strchr(game_board->tab[i - 1][j].shift_id, 'R') != NULL ||
                    strchr(game_board->tab[i][j + 1].shift_id, 'U') != NULL) {
                    return 1;
                }
                break;
            default:
                return 0;
        }
    } else {
        switch (current_card->type) {
            case 'J' :
                if (game_board->tab[i][j].type == '$') {
                    return 1;
                }
            case 'K' :
                current_card->front_image = al_load_bitmap("../images/Card_board/Black_hole.png");
                return 1;
            case 'L' :
                if (strchr(game_board->tab[i + 1][j].shift_id, 'L') != NULL ||
                    strchr(game_board->tab[i - 1][j].shift_id, 'R') != NULL) {
                    return 1;
                }
                break;
            case 'M':
                if (strchr(game_board->tab[i][j + 1].shift_id, 'U') != NULL ||
                    strchr(game_board->tab[i][j - 1].shift_id, 'D') != NULL) {
                    return 1;
                }
                break;
            case 'N':
                if (strchr(game_board->tab[i - 1][j].shift_id, 'R') != NULL) {
                    return 1;
                }
                break;
            case 'O' :
                if (strchr(game_board->tab[i + 1][j].shift_id, 'L') != NULL ||
                    strchr(game_board->tab[i - 1][j].shift_id, 'R') != NULL ||
                    strchr(game_board->tab[i][j + 1].shift_id, 'U') != NULL ||
                    strchr(game_board->tab[i][j - 1].shift_id, 'D') != NULL) {
                    return 1;
                }
                break;
            case 'P' :
                if (strchr(game_board->tab[i + 1][j].shift_id, 'L') != NULL ||
                    strchr(game_board->tab[i - 1][j].shift_id, 'R') != NULL ||
                    strchr(game_board->tab[i][j - 1].shift_id, 'D') != NULL) {
                    return 1;
                }
                break;
            case 'Q' :
                if (strchr(game_board->tab[i + 1][j].shift_id, 'L') != NULL ||
                    strchr(game_board->tab[i - 1][j].shift_id, 'R') != NULL ||
                    strchr(game_board->tab[i][j + 1].shift_id, 'U') != NULL) {
                    return 1;
                }
                break;
            case 'R' :
                if (strchr(game_board->tab[i + 1][j].shift_id, 'L') != NULL ||
                    strchr(game_board->tab[i][j - 1].shift_id, 'D') != NULL) {
                    return 1;
                }
                break;
            case 'S' :
                if (strchr(game_board->tab[i - 1][j].shift_id, 'R') != NULL ||
                    strchr(game_board->tab[i][j + 1].shift_id, 'U') != NULL) {
                    return 1;
                }
                break;
            case 'T' :
                if (strchr(game_board->tab[i - 1][j].shift_id, 'R') != NULL ||
                    strchr(game_board->tab[i][j + 1].shift_id, 'U') != NULL ||
                    strchr(game_board->tab[i][j - 1].shift_id, 'D') != NULL) {
                    return 1;
                }
                break;
            case 'U' :
                if (strchr(game_board->tab[i - 1][j].shift_id, 'R') != NULL ||
                    strchr(game_board->tab[i][j - 1].shift_id, 'D') != NULL) {
                    return 1;
                }
                break;
            case 'V' :
                if (strchr(game_board->tab[i + 1][j].shift_id, 'L') != NULL ||
                    strchr(game_board->tab[i][j + 1].shift_id, 'U') != NULL) {
                    return 1;
                }
                break;
            case 'W' :
                if (strchr(game_board->tab[i + 1][j].shift_id, 'L') != NULL ||
                    strchr(game_board->tab[i][j + 1].shift_id, 'U') != NULL ||
                    strchr(game_board->tab[i][j - 1].shift_id, 'D') != NULL) {
                    return 1;
                }
                break;
            case 'X' :
                if (strchr(game_board->tab[i + 1][j].shift_id, 'L') != NULL) {
                    return 1;
                }
                break;
            case '$':
                if (strchr(game_board->tab[i - 1][j].shift_id, 'R') != NULL ||
                    strchr(game_board->tab[i][j + 1].shift_id, 'U') != NULL ||
                    strchr(game_board->tab[i][j - 1].shift_id, 'D') != NULL) {
                    return 1;
                }
                break;
            default:
                return 0;
        }
    }
    return 0;
}

int card_next_to_end(board *game_board, int i, int j, int *detect_end_y,card *current_card) {
    if (j == 0 && i==9) {
        if(game_board->tab[i][j+1].type == '$' && strchr(current_card->shift_id,'D')!=NULL){
            *detect_end_y = j;
            return 1;
        }
    }
    if (j == 1 && i==8) {
        if(game_board->tab[i+1][j].type == '$' && strchr(current_card->shift_id,'R')!=NULL){
            *detect_end_y = j;
            return 1;
        }
    }
    if (j ==2 && i==9) {
        if((game_board->tab[i][j-1].type == '$' && strchr(current_card->shift_id,'U')!=NULL)||(game_board->tab[i][j+1].type == '$' && strchr(current_card->shift_id,'D')!=NULL)){
            if(game_board->tab[i][j-1].value>game_board->tab[i][j+1].value){
                *detect_end_y = j-1;
            }else{ *detect_end_y = j+1;}

            return 1;
        }
    }
    if (j == 3 && i==8) {
        if(game_board->tab[i+1][j].type == '$' && strchr(current_card->shift_id,'R')!=NULL){
            *detect_end_y = j;
            return 1;
        }
    }
    if (j ==4 && i==9) {
        if((game_board->tab[i][j-1].type == '$' && strchr(current_card->shift_id,'U')!=NULL)||(game_board->tab[i][j+1].type == '$' && strchr(current_card->shift_id,'D')!=NULL)){
            if(game_board->tab[i][j-1].value>game_board->tab[i][j+1].value){
                *detect_end_y = j-1;
            }else{ *detect_end_y = j+1;}
            return 1;
        }
    }
    if (j == 5 && i==8) {
        if(game_board->tab[i+1][j].type == '$' && strchr(current_card->shift_id,'R')!=NULL){
            *detect_end_y = j;
            return 1;
        }
    }
    if (j == 7 && i==9) {
        if(game_board->tab[i][j-1].type == '$' && strchr(current_card->shift_id,'U')!=NULL){
            *detect_end_y = j;
            return 1;
        }
    }
    return 0;
}