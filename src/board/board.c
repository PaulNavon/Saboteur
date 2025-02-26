//
// Created by Hugo on 19/03/2021.
//
#include "../structures/structures.h"
#include "../initialization/initialization.h"
#include "../board/DrawPlayersBoard.h"


void draw_card(card *card, config configuration) {
    al_draw_scaled_bitmap(card->front_image, 0, 0, (float) al_get_bitmap_width(card->front_image),
                          (float) al_get_bitmap_height(card->front_image),
                          (float) card->x, (float) card->y, configuration.width / 13.426,
                          (float) configuration.height / 11, 0);
}

void update_card_position(card *current_card, const unsigned char pressed_keys[], int *modification, config configuration) {
    if (pressed_keys[LEFT]) {
        current_card->x -= 10;
        if (current_card->x < 0) { current_card->x = 0; }
        *modification = 1; // On indique qu'on doit repeindre mais on ne le fait pas ici, des données
        // peuvent encore changer (deux touches enfoncées par exemple (haut et bas))
    }
    if (pressed_keys[RIGHT]) {
        current_card->x += 10;
        if (current_card->x + current_card->width > configuration.width) {
            current_card->x = configuration.width -
                              current_card->width;
        }
        *modification = 1;
    }
}

void free_board(board *game_board) {
    for (int i = 0; i < COLUMNS; i++) {
        free(game_board->tab[i]);
    }
    free(game_board);
}

void free_player(player *player) {
    free(player->hand);
}

void select_card(int x, int y, config configuration, player *player, card *current_card, buffer_position *selection) {
    for (int i = 0; i < MAX_DECK - 2; i++) {
        if (x >= configuration.width / player->hand[i].xratio &&
            x < configuration.width / player->hand[i + 1].xratio &&
            y >= configuration.height / player->hand[i].yratio &&
            y < configuration.height / 4.596 && (player->hand[i].front_image != NULL) &&
            current_card->front_image == NULL) {
            init_current_card(current_card, player->hand[i]);
            selection->hand_number = i;
        } else if (x >= configuration.width / player->hand[5].xratio &&
                   x < configuration.width / 1.929 &&
                   y >= configuration.height / player->hand[5].yratio &&
                   y < configuration.height / 4.5 && (player->hand[5].front_image != NULL) &&
                   current_card->front_image == NULL) {
            init_current_card(current_card, player->hand[5]);
            selection->hand_number = 5;
        }
    }
}

void pick_card(int x, int y, config configuration, card *current_card, card *pool_pick) {
    if (x >= configuration.width / 1.275 &&
        x < configuration.width / 5.51 &&
        y >= configuration.height / 1.14 &&
        y < configuration.height / 4 && current_card->front_image == NULL) {
    }
    init_current_card(current_card, *pool_pick);
}

void reset_current_card(card *current_card) {
    current_card->front_image = NULL;
    current_card->back_image = NULL;
    current_card->type = 0;
    current_card->shift_id = NULL;
    current_card->height = 0;
    current_card->width = 0;
    current_card->x = 0;
    current_card->y = 0;
}

void draw_pool_pick(card pool_pick, config configuration) {
    al_draw_scaled_bitmap(pool_pick.back_image, 0, 0,
                          (float) al_get_bitmap_width(pool_pick.back_image),
                          (float) al_get_bitmap_height(pool_pick.back_image),
                          configuration.width / pool_pick.xratio,
                          configuration.height / pool_pick.yratio,
                          configuration.width / 13.426,
                          configuration.height / 11, 0);
}

void draw_player_hand(config configuration, player *player) {
    for (int i = 0; i < MAX_DECK - 1; i++) {
        if (player->hand[i].front_image != NULL) {
            al_draw_scaled_bitmap(player->hand[i].front_image, 0, 0,
                                  (float) al_get_bitmap_width(player->hand[i].front_image),
                                  (float) al_get_bitmap_height(player->hand[i].front_image),
                                  configuration.width / player->hand[i].xratio,
                                  configuration.height / player->hand[i].yratio,
                                  configuration.width / 13.426,
                                  configuration.height / 10.4, 0);
        }
    }
}

void draw_board(board *game_board, config configuration) {
    al_draw_scaled_bitmap(game_board->board_image, 0, 0,
                          (float) al_get_bitmap_width(game_board->board_image),
                          (float) al_get_bitmap_height(game_board->board_image), 0, 0,
                          configuration.width,
                          configuration.height, 0);

    for (int i = 0; i < COLUMNS; i++) {
        for (int j = 0; j < ROWS; j++) {
            if (game_board->tab[i][j].front_image != NULL) {
                al_draw_scaled_bitmap(game_board->tab[i][j].front_image, 0, 0,
                                      (float) al_get_bitmap_width(game_board->tab[i][j].front_image),
                                      (float) al_get_bitmap_height(game_board->tab[i][j].front_image),
                                      configuration.width / game_board->tab[i][j].xratio,
                                      configuration.height / game_board->tab[i][j].yratio,
                                      configuration.width / 13.426,
                                      configuration.height / 10.69, 0);
            }
        }
    }
}

void highlight_tile(buffer_position position, config configuration) {
    if (position.r == 1.43 || position.r == 1.275) {
        al_draw_filled_rectangle((float)(configuration.width / position.r), (configuration.height / position.c),
                                 (float)(configuration.width / position.r) + configuration.width / 12.5,
                                 (float)(configuration.height / position.c) + configuration.height / 9.5,
                                 al_map_rgba(150, 150, 150, 70));
    } else if (position.r == 120){
        al_draw_filled_rectangle((float)(configuration.width / position.r), (float)(configuration.height / position.c),
                                 (configuration.width / position.r) + configuration.width / 4.21,
                                 (configuration.height / position.c) + configuration.height / 9.56,
                                 al_map_rgba(150, 150, 150, 70));
    } else {
        al_draw_filled_rectangle((float)(configuration.width / position.r), (float)(configuration.height / position.c),
                                 (configuration.width / position.r) + configuration.width / 13.426,
                                 (configuration.height / position.c) + configuration.height / 10.5,
                                 al_map_rgba(150, 150, 150, 70));
    }
}

void check_selected_tile(int x, int y, board *game_board, config configuration, buffer_position *selection, player *player_tab_infos, int selection_players, card current_card) {
    selection->modification = false;
    if (x < configuration.width) {
        for (int i = 0; i < COLUMNS; i++) {
            for (int j = 0; j < ROWS; j++) {
                if (x >= configuration.width / game_board->tab[i][j].xratio &&
                    x < configuration.width / game_board->tab[i + 1][j].xratio &&
                    y >= configuration.height / game_board->tab[i][j].yratio &&
                    y < configuration.height / game_board->tab[i + 1][j + 1].yratio &&
                    (game_board->tab[i][j].front_image == NULL)) {
                    game_board->tab[i][j].selected = true;
                    selection->r = game_board->tab[i][j].xratio, selection->c = game_board->tab[i][j].yratio;
                    selection->modification = true;
                } else if (x >= configuration.width / game_board->tab[i][j].xratio &&
                           x < configuration.width / game_board->tab[i + 1][j].xratio &&
                           y >= configuration.height / game_board->tab[i][j].yratio &&
                           y < configuration.height / game_board->tab[i + 1][j + 1].yratio &&
                           (game_board->tab[i][j].front_image != NULL) && current_card.type == 'K' && game_board->tab[i][j].type != '%' &&  game_board->tab[i][j].type != '$') {
                    game_board->tab[i][j].selected = true;
                    selection->r = game_board->tab[i][j].xratio, selection->c = game_board->tab[i][j].yratio;
                    selection->modification = true;
                } else if (x >= configuration.width / game_board->tab[i][j].xratio &&
                           x < configuration.width / game_board->tab[i + 1][j].xratio &&
                           y >= configuration.height / game_board->tab[i][j].yratio &&
                           y < configuration.height / game_board->tab[i + 1][j + 1].yratio && current_card.type == 'J' && game_board->tab[i][j].type == '$') {
                    game_board->tab[i][j].selected = true;
                    selection->r = game_board->tab[i][j].xratio, selection->c = game_board->tab[i][j].yratio;
                    selection->modification = true;
                }else {
                    game_board->tab[i][j].selected = false;
                }
            }
        }

        if (x > configuration.width / 1.43 && x < configuration.width / 1.28 && y > configuration.height / 11.13 &&
            y < configuration.height / 5.17) {
            selection->r = 1.43, selection->c = 11.13;
        } else if (x >= configuration.width / 1.275 &&
                   x < configuration.width / 1.156 &&
                   y >= configuration.height / 11.13 &&
                   y < configuration.height / 5.17) {
            selection->r = 1.275, selection->c = 11.13;
        } else {
            if (selection->modification == false) {
                selection->r = 0;
                selection->c = 0;
            }
        }

        for (int k=0; k<selection_players; k++) {
            if (x > configuration.width / 120 && x < configuration.width / 4 &&
                y > configuration.height / player_tab_infos[k].ytopratio &&
                y < configuration.height / player_tab_infos[k].ybotratio) {
                selection->r = 120;
                selection->c = player_tab_infos[k].ytopratio;
            }
        }
    }
}

void draw_round_announcement(board *game_board, config configuration, player *player, card pool_pick, int w, int selection_players,ALLEGRO_FONT* players_nickname) {
    ALLEGRO_BITMAP *new_round = al_load_bitmap("../images/Title_screen/new_game.png");
    ALLEGRO_FONT *agency;
    if (configuration.height == 480) { agency = al_load_ttf_font("../fonts/agency-fb/agency-fb-bold.ttf", 85, 0); }
    else if (configuration.height == 720) {
        agency = al_load_ttf_font("../fonts/agency-fb/agency-fb-bold.ttf", 115, 0);
    }
    else if (configuration.height == 1080) {
        agency = al_load_ttf_font("../fonts/agency-fb/agency-fb-bold.ttf", 165, 0);
    }
    else { agency = al_load_ttf_font("../fonts/agency-fb/agency-fb-bold.ttf", 100, 0); }
    draw_board(game_board, configuration);
    display_players_onboard(configuration,player,selection_players,players_nickname);
    draw_pool_pick(pool_pick, configuration);
    al_draw_scaled_bitmap(new_round, 0, 0, 1920, 1080, 0, 0, (float)configuration.width, (float)configuration.height, 0);
    al_draw_textf(agency, al_map_rgb(255, 255, 255), configuration.width / 2.35,
                  configuration.height / 2.16 - al_get_font_ascent(agency), ALLEGRO_ALIGN_LEFT,
                  ("ROUND %d"), w + 1);
    al_flip_display();
    al_destroy_bitmap(new_round);
    al_destroy_font(agency);
    al_rest(2.5);
}

void draw_turn_announcement(config configuration, player *player,int w,int player_selection,ALLEGRO_FONT* players_nickname, int nb_tour, int modifyingphysicalsize) {
    ALLEGRO_BITMAP *your_turn = al_load_bitmap("../images/Title_screen/your_turn.png");
    ALLEGRO_FONT *agency;
    ALLEGRO_EVENT_QUEUE *queue;
    ALLEGRO_EVENT event = {0};
    int count = 0;

    queue = al_create_event_queue();
    al_register_event_source(queue, al_get_keyboard_event_source());

    if (configuration.height == 480) { agency = al_load_ttf_font("../fonts/agency-fb/agency-fb-bold.ttf", 65, 0); }
    else if (configuration.height == 720) { agency = al_load_ttf_font("../fonts/agency-fb/agency-fb-bold.ttf", 95, 0); }
    else if (configuration.height == 1080) {
        agency = al_load_ttf_font("../fonts/agency-fb/agency-fb-bold.ttf", 145, 0);
    } else { agency = al_load_ttf_font("../fonts/agency-fb/agency-fb-bold.ttf", 100, 0); }

    al_draw_scaled_bitmap(your_turn, 0, 0, 1920, 1080, 0, 0, (float)configuration.width, (float)configuration.height, 0);
    al_draw_textf(agency, al_map_rgb(255, 255, 255), (float)configuration.width / 2,
                  configuration.height / 2.8 - al_get_font_ascent(agency), ALLEGRO_ALIGN_CENTER,
                  ("%s"), player[w].name);
    al_flip_display();
    while (al_is_event_queue_empty(queue)) {
        al_wait_for_event(queue, &event);
    }
    if(nb_tour==0) {
        if (player[w].gamer_id == 'S') {
            ALLEGRO_BITMAP *role_sabotor = al_load_bitmap("../images/Title_screen/role_revelation_sabotor.jpg");
            al_draw_scaled_bitmap(role_sabotor, 0, 0, 1920, 1080, 0, 0, (float)configuration.width, (float)configuration.height, 0);
            al_destroy_bitmap(role_sabotor);
        } else {
            if (player_selection == 5) {
                ALLEGRO_BITMAP *role_crewmate2 = al_load_bitmap("../images/Title_screen/role_revelation_crewmate2.jpg");
                al_draw_scaled_bitmap(role_crewmate2, 0, 0, 1920, 1080, 0, 0, (float)configuration.width, (float)configuration.height, 0);
                al_destroy_bitmap(role_crewmate2);
            }else {
                ALLEGRO_BITMAP *role_crewmate = al_load_bitmap("../images/Title_screen/role_revelation_crewmate.jpg");
                al_draw_scaled_bitmap(role_crewmate, 0, 0, 1920, 1080, 0, 0, (float)configuration.width, (float)configuration.height, 0);
                al_destroy_bitmap(role_crewmate);
            }
        }
        al_flip_display();
        al_rest(1.5);
    }
    al_destroy_event_queue(queue);
    al_destroy_bitmap(your_turn);
    al_destroy_font(agency);
}

void replace_if_outside_board(card *current_card, config configuration, int x, int y) {
    if (current_card->x < 0) { current_card->x = 0; }
    if (current_card->x > configuration.width) {
        current_card->x = configuration.width - current_card->width;
    }
    if (current_card->y < 0) { current_card->y = 0; }
    if (current_card->y > configuration.height) {
        current_card->y = configuration.height - current_card->height;
    }
}


void link_card_number(board *game_board) {
    int c = 0;
    c = rand() % (MAX_NUMBERS - MIN_NUMBERS + 1) + MIN_NUMBERS;
    switch (c) {
        case 1 :
            game_board->tab[9][1].front_image = al_load_bitmap("../images/Card_ending/Back_Card_Planet_screengame.png");
            game_board->tab[9][1].back_image = al_load_bitmap("../images/Card_ending/Card_Planet_1.png");
            game_board->tab[9][1].back_image_big = al_load_bitmap("../images/Card_ending/Card_Planet_1_Big.png");
            game_board->tab[9][1].type = '$';
            game_board->tab[9][1].shift_id = "SION";
            game_board->tab[9][1].value = 100;

            game_board->tab[9][3].front_image = al_load_bitmap("../images/Card_ending/Back_Card_Planet_screengame.png");
            game_board->tab[9][3].back_image = al_load_bitmap("../images/Card_ending/Card_Planet_2.png");
            game_board->tab[9][3].back_image_big = al_load_bitmap("../images/Card_ending/Card_Planet_2_Big.png");
            game_board->tab[9][3].type = '$';
            game_board->tab[9][3].shift_id = "SION";
            game_board->tab[9][3].value = 0;

            game_board->tab[9][5].front_image = al_load_bitmap("../images/Card_ending/Back_Card_Planet_screengame.png");
            game_board->tab[9][5].back_image = al_load_bitmap("../images/Card_ending/Card_Planet_3.png");
            game_board->tab[9][5].back_image_big = al_load_bitmap("../images/Card_ending/Card_Planet_3_Big.png");
            game_board->tab[9][5].type = '$';
            game_board->tab[9][5].shift_id = "SION";
            game_board->tab[9][5].value = 50;
            break;
        case 2 :
            game_board->tab[9][1].front_image = al_load_bitmap("../images/Card_ending/Back_Card_Planet_screengame.png");
            game_board->tab[9][1].back_image = al_load_bitmap("../images/Card_ending/Card_Planet_1.png");
            game_board->tab[9][1].back_image_big = al_load_bitmap("../images/Card_ending/Card_Planet_1_Big.png");
            game_board->tab[9][1].type = '$';
            game_board->tab[9][1].shift_id = "SION";
            game_board->tab[9][1].value = 100;

            game_board->tab[9][5].front_image = al_load_bitmap("../images/Card_ending/Back_Card_Planet_screengame.png");
            game_board->tab[9][5].back_image = al_load_bitmap("../images/Card_ending/Card_Planet_2.png");
            game_board->tab[9][5].back_image_big = al_load_bitmap("../images/Card_ending/Card_Planet_2_Big.png");
            game_board->tab[9][5].type = '$';
            game_board->tab[9][5].shift_id = "SION";
            game_board->tab[9][5].value = 0;

            game_board->tab[9][3].front_image = al_load_bitmap("../images/Card_ending/Back_Card_Planet_screengame.png");
            game_board->tab[9][3].back_image = al_load_bitmap("../images/Card_ending/Card_Planet_3.png");
            game_board->tab[9][3].back_image_big = al_load_bitmap("../images/Card_ending/Card_Planet_3_Big.png");
            game_board->tab[9][3].type = '$';
            game_board->tab[9][3].shift_id = "SION";
            game_board->tab[9][3].value = 50;
            break;
        case 3 :
            game_board->tab[9][3].front_image = al_load_bitmap("../images/Card_ending/Back_Card_Planet_screengame.png");
            game_board->tab[9][3].back_image = al_load_bitmap("../images/Card_ending/Card_Planet_1.png");
            game_board->tab[9][3].back_image_big = al_load_bitmap("../images/Card_ending/Card_Planet_1_Big.png");
            game_board->tab[9][3].type = '$';
            game_board->tab[9][3].shift_id = "SION";
            game_board->tab[9][3].value = 100;

            game_board->tab[9][5].front_image = al_load_bitmap("../images/Card_ending/Back_Card_Planet_screengame.png");
            game_board->tab[9][5].back_image = al_load_bitmap("../images/Card_ending/Card_Planet_2.png");
            game_board->tab[9][5].back_image_big = al_load_bitmap("../images/Card_ending/Card_Planet_2_Big.png");
            game_board->tab[9][5].type = '$';
            game_board->tab[9][5].shift_id = "SION";
            game_board->tab[9][5].value = 0;

            game_board->tab[9][3].front_image = al_load_bitmap("../images/Card_ending/Back_Card_Planet_screengame.png");
            game_board->tab[9][3].back_image = al_load_bitmap("../images/Card_ending/Card_Planet_3.png");
            game_board->tab[9][3].back_image_big = al_load_bitmap("../images/Card_ending/Card_Planet_3_Big.png");
            game_board->tab[9][3].type = '$';
            game_board->tab[9][3].shift_id = "SION";
            game_board->tab[9][3].value = 50;
            break;
        case 4 :
            game_board->tab[9][3].front_image = al_load_bitmap("../images/Card_ending/Back_Card_Planet_screengame.png");
            game_board->tab[9][3].back_image = al_load_bitmap("../images/Card_ending/Card_Planet_1.png");
            game_board->tab[9][3].back_image_big = al_load_bitmap("../images/Card_ending/Card_Planet_1_Big.png");
            game_board->tab[9][3].type = '$';
            game_board->tab[9][3].shift_id = "SION";
            game_board->tab[9][3].value = 100;

            game_board->tab[9][1].front_image = al_load_bitmap("../images/Card_ending/Back_Card_Planet_screengame.png");
            game_board->tab[9][1].back_image = al_load_bitmap("../images/Card_ending/Card_Planet_2.png");
            game_board->tab[9][1].back_image_big = al_load_bitmap("../images/Card_ending/Card_Planet_2_Big.png");
            game_board->tab[9][1].type = '$';
            game_board->tab[9][1].shift_id = "SION";
            game_board->tab[9][1].value = 0;

            game_board->tab[9][5].front_image = al_load_bitmap("../images/Card_ending/Back_Card_Planet_screengame.png");
            game_board->tab[9][5].back_image = al_load_bitmap("../images/Card_ending/Card_Planet_3.png");
            game_board->tab[9][5].back_image_big = al_load_bitmap("../images/Card_ending/Card_Planet_3_Big.png");
            game_board->tab[9][5].type = '$';
            game_board->tab[9][5].shift_id = "SION";
            game_board->tab[9][5].value = 50;
            break;
        case 5 :
            game_board->tab[9][3].front_image = al_load_bitmap("../images/Card_ending/Back_Card_Planet_screengame.png");
            game_board->tab[9][3].back_image = al_load_bitmap("../images/Card_ending/Card_Planet_1.png");
            game_board->tab[9][3].back_image_big = al_load_bitmap("../images/Card_ending/Card_Planet_1_Big.png");
            game_board->tab[9][3].type = '$';
            game_board->tab[9][3].shift_id = "SION";
            game_board->tab[9][3].value = 100;

            game_board->tab[9][5].front_image = al_load_bitmap("../images/Card_ending/Back_Card_Planet_screengame.png");
            game_board->tab[9][5].back_image = al_load_bitmap("../images/Card_ending/Card_Planet_2.png");
            game_board->tab[9][5].back_image_big = al_load_bitmap("../images/Card_ending/Card_Planet_2_Big.png");
            game_board->tab[9][5].type = '$';
            game_board->tab[9][5].shift_id = "SION";
            game_board->tab[9][5].value = 0;

            game_board->tab[9][1].front_image = al_load_bitmap("../images/Card_ending/Back_Card_Planet_screengame.png");
            game_board->tab[9][1].back_image = al_load_bitmap("../images/Card_ending/Card_Planet_3.png");
            game_board->tab[9][1].back_image_big = al_load_bitmap("../images/Card_ending/Card_Planet_3_Big.png");
            game_board->tab[9][1].type = '$';
            game_board->tab[9][1].shift_id = "SION";
            game_board->tab[9][1].value = 50;
            break;
        case 6 :
            game_board->tab[9][5].front_image = al_load_bitmap("../images/Card_ending/Back_Card_Planet_screengame.png");
            game_board->tab[9][5].back_image = al_load_bitmap("../images/Card_ending/Card_Planet_1.png");
            game_board->tab[9][5].back_image_big = al_load_bitmap("../images/Card_ending/Card_Planet_1_Big.png");
            game_board->tab[9][5].type = '$';
            game_board->tab[9][5].shift_id = "SION";
            game_board->tab[9][5].value = 100;

            game_board->tab[9][3].front_image = al_load_bitmap("../images/Card_ending/Back_Card_Planet_screengame.png");
            game_board->tab[9][3].back_image = al_load_bitmap("../images/Card_ending/Card_Planet_2.png");
            game_board->tab[9][3].back_image_big = al_load_bitmap("../images/Card_ending/Card_Planet_2_Big.png");
            game_board->tab[9][3].type = '$';
            game_board->tab[9][3].shift_id = "SION";
            game_board->tab[9][3].value = 0;

            game_board->tab[9][1].front_image = al_load_bitmap("../images/Card_ending/Back_Card_Planet_screengame.png");
            game_board->tab[9][1].back_image = al_load_bitmap("../images/Card_ending/Card_Planet_3.png");
            game_board->tab[9][1].back_image_big = al_load_bitmap("../images/Card_ending/Card_Planet_3_Big.png");
            game_board->tab[9][1].type = '$';
            game_board->tab[9][1].shift_id = "SION";
            game_board->tab[9][1].value = 50;
        default:
            break;
    }
}

void value_to_score(board *game_board, player *player_tab_infos, int v, int y, config configuration, int selection_players) {
    if (player_tab_infos[v].gamer_id == 'A') {
        player_tab_infos[v].score+=game_board->tab[9][y].value;
    }
    for (int i=0; i<selection_players; i++) {
        if (player_tab_infos[i].gamer_id == 'A' && (i != v)) {
            player_tab_infos[i].score+=(game_board->tab[9][y].value/2);
        }
    }
    al_draw_scaled_bitmap(game_board->tab[9][y].back_image, 0, 0,
                          (float) al_get_bitmap_width(game_board->tab[9][y].front_image),
                          (float) al_get_bitmap_height(game_board->tab[9][y].front_image),
                          configuration.width / game_board->tab[9][y].xratio,
                          configuration.height / game_board->tab[9][y].yratio,
                          configuration.width / 13.426,
                          configuration.height / 10.69, 0);
    al_draw_scaled_bitmap(game_board->tab[9][y].back_image_big, 0, 0,
                          (float) al_get_bitmap_width(game_board->tab[9][y].back_image_big),
                          (float) al_get_bitmap_height(game_board->tab[9][y].back_image_big),
                          0,
                          0,
                          (float)configuration.width,
                          (float)configuration.height, 0);
}