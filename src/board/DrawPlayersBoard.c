#include "DrawPlayersBoard.h"

void display_players_onboard(config configuration, player *player_tab_infos, int selection_players,
                             ALLEGRO_FONT *players_nickname) {
    switch (selection_players) {
        case 3:
            //player 1
            al_draw_textf(players_nickname,
                          al_map_rgb(255, 255, 255),
                          (float) configuration.width / 12,
                          configuration.height / 2.3 -
                          al_get_font_ascent(configuration.font),
                          ALLEGRO_ALIGN_LEFT,
                          ("%s"), player_tab_infos[0].name);
            al_draw_scaled_bitmap(player_tab_infos[0].skin, 0, 0, 469, 469,
                                  (float) configuration.width / -48,
                                  configuration.height / 3.484,
                                  configuration.width / 8.348,
                                  configuration.height / 4.696,
                                  0);
            al_draw_scaled_bitmap(player_tab_infos[0].back_image, 0, 0, 205, 150,
                                  (float) configuration.width / 6.26,
                                  configuration.height / 2.746,
                                  configuration.width / 12.180,
                                  configuration.height / 10.684,
                                  0);
            //player 2
            al_draw_textf(players_nickname,
                          al_map_rgb(255, 255, 255),
                          configuration.width / 5.053,
                          configuration.height / 1.788 -
                          al_get_font_ascent(configuration.font),
                          ALLEGRO_ALIGN_RIGHT,
                          ("%s"), player_tab_infos[1].name);
            al_draw_scaled_bitmap(player_tab_infos[1].skin, 0, 0, 469, 469,
                                  configuration.width / 6.75,
                                  configuration.height / 2.34,
                                  configuration.width / 8.348,
                                  configuration.height / 4.696,
                                  0);
            al_draw_scaled_bitmap(player_tab_infos[1].back_image, 0, 0, 205, 150,
                                  (float) configuration.width / 87.467,
                                  configuration.height / 2.022,
                                  configuration.width / 12.180,
                                  configuration.height / 10.684,
                                  0);
            //player 3
            al_draw_textf(players_nickname,
                          al_map_rgb(255, 255, 255),
                          (float) configuration.width / 12,
                          configuration.height / 1.448 -
                          al_get_font_ascent(configuration.font),
                          ALLEGRO_ALIGN_LEFT,
                          ("%s"), player_tab_infos[2].name);
            al_draw_scaled_bitmap(player_tab_infos[2].skin, 0, 0, 469, 469,
                                  (float) configuration.width / -48,
                                  configuration.height / 1.8,
                                  configuration.width / 8.348,
                                  configuration.height / 4.696,
                                  0);
            al_draw_scaled_bitmap(player_tab_infos[2].back_image, 0, 0, 205, 150,
                                  (float) configuration.width / 6.26,
                                  configuration.height / 1.601,
                                  configuration.width / 12.180,
                                  configuration.height / 10.684,
                                  0);
            break;
        case 4 :
            //player 1
            al_draw_textf(players_nickname,
                          al_map_rgb(255, 255, 255),
                          (float) configuration.width / 12,
                          configuration.height / 2.3 -
                          al_get_font_ascent(configuration.font),
                          ALLEGRO_ALIGN_LEFT,
                          ("%s"), player_tab_infos[0].name);

            al_draw_scaled_bitmap(player_tab_infos[0].skin, 0, 0, 469, 469,
                                  (float) configuration.width / -48,
                                  configuration.height / 3.484,
                                  configuration.width / 8.348,
                                  configuration.height / 4.696,
                                  0);
            al_draw_scaled_bitmap(player_tab_infos[0].back_image, 0, 0, 205, 150,
                                  (float) configuration.width / 6.26,
                                  configuration.height / 2.746,
                                  configuration.width / 12.180,
                                  configuration.height / 10.684,
                                  0);
            //player 2
            al_draw_textf(players_nickname,
                          al_map_rgb(255, 255, 255),
                          configuration.width / 5.053,
                          configuration.height / 1.788 -
                          al_get_font_ascent(configuration.font),
                          ALLEGRO_ALIGN_RIGHT,
                          ("%s"), player_tab_infos[1].name);
            al_draw_scaled_bitmap(player_tab_infos[1].skin, 0, 0, 469, 469,
                                  configuration.width / 6.75,
                                  configuration.height / 2.34,
                                  configuration.width / 8.348,
                                  configuration.height / 4.696,
                                  0);
            al_draw_scaled_bitmap(player_tab_infos[1].back_image, 0, 0, 205, 150,
                                  (float) configuration.width / 87.467,
                                  configuration.height / 2.022,
                                  configuration.width / 12.180,
                                  configuration.height / 10.684,
                                  0);
            //player 3
            al_draw_textf(players_nickname,
                          al_map_rgb(255, 255, 255),
                          (float) configuration.width / 12,
                          configuration.height / 1.448 -
                          al_get_font_ascent(configuration.font),
                          ALLEGRO_ALIGN_LEFT,
                          ("%s"), player_tab_infos[2].name);
            al_draw_scaled_bitmap(player_tab_infos[2].skin, 0, 0, 469, 469,
                                  (float) configuration.width / -48,
                                  configuration.height / 1.8,
                                  configuration.width / 8.348,
                                  configuration.height / 4.696,
                                  0);
            al_draw_scaled_bitmap(player_tab_infos[2].back_image, 0, 0, 205, 150,
                                  (float) configuration.width / 6.26,
                                  configuration.height / 1.601,
                                  configuration.width / 12.180,
                                  configuration.height / 10.684,
                                  0);
            //player 4
            al_draw_textf(players_nickname,
                          al_map_rgb(255, 255, 255),
                          configuration.width / 5.053,
                          configuration.height / 1.219 -
                          al_get_font_ascent(configuration.font),
                          ALLEGRO_ALIGN_RIGHT,
                          ("%s"), player_tab_infos[3].name);
            al_draw_scaled_bitmap(player_tab_infos[3].skin, 0, 0, 469, 469,
                                  configuration.width / 6.75,
                                  configuration.height / 1.44,
                                  configuration.width / 8.348,
                                  configuration.height / 4.696,
                                  0);
            al_draw_scaled_bitmap(player_tab_infos[3].back_image, 0, 0, 205, 150,
                                  (float) configuration.width / 87.467,
                                  configuration.height / 1.327,
                                  configuration.width / 12.180,
                                  configuration.height / 10.684,
                                  0);
            break;
        case 5 :
            //player 1
            al_draw_textf(players_nickname,
                          al_map_rgb(255, 255, 255),
                          (float) configuration.width / 12,
                          configuration.height / 2.3 -
                          al_get_font_ascent(configuration.font),
                          ALLEGRO_ALIGN_LEFT,
                          ("%s"), player_tab_infos[0].name);

            al_draw_scaled_bitmap(player_tab_infos[0].skin, 0, 0, 469, 469,
                                  (float) configuration.width / -48,
                                  configuration.height / 3.484,
                                  configuration.width / 8.348,
                                  configuration.height / 4.696,
                                  0);
            al_draw_scaled_bitmap(player_tab_infos[0].back_image, 0, 0, 205, 150,
                                  (float) configuration.width / 6.26,
                                  configuration.height / 2.746,
                                  configuration.width / 12.180,
                                  configuration.height / 10.684,
                                  0);
            //player 2
            al_draw_textf(players_nickname,
                          al_map_rgb(255, 255, 255),
                          configuration.width / 5.053,
                          configuration.height / 1.788 -
                          al_get_font_ascent(configuration.font),
                          ALLEGRO_ALIGN_RIGHT,
                          ("%s"), player_tab_infos[1].name);
            al_draw_scaled_bitmap(player_tab_infos[1].skin, 0, 0, 469, 469,
                                  configuration.width / 6.75,
                                  configuration.height / 2.34,
                                  configuration.width / 8.348,
                                  configuration.height / 4.696,
                                  0);
            al_draw_scaled_bitmap(player_tab_infos[1].back_image, 0, 0, 205, 150,
                                  (float) configuration.width / 87.467,
                                  configuration.height / 2.022,
                                  configuration.width / 12.180,
                                  configuration.height / 10.684,
                                  0);
            //player 3
            al_draw_textf(players_nickname,
                          al_map_rgb(255, 255, 255),
                          (float) configuration.width / 12,
                          configuration.height / 1.448 -
                          al_get_font_ascent(configuration.font),
                          ALLEGRO_ALIGN_LEFT,
                          ("%s"), player_tab_infos[2].name);
            al_draw_scaled_bitmap(player_tab_infos[2].skin, 0, 0, 469, 469,
                                  (float) configuration.width / -48,
                                  configuration.height / 1.8,
                                  configuration.width / 8.348,
                                  configuration.height / 4.696,
                                  0);
            al_draw_scaled_bitmap(player_tab_infos[2].back_image, 0, 0, 205, 150,
                                  (float) configuration.width / 6.26,
                                  configuration.height / 1.601,
                                  configuration.width / 12.180,
                                  configuration.height / 10.684,
                                  0);
            //player 4
            al_draw_textf(players_nickname,
                          al_map_rgb(255, 255, 255),
                          configuration.width / 5.053,
                          configuration.height / 1.226 -
                          al_get_font_ascent(configuration.font),
                          ALLEGRO_ALIGN_RIGHT,
                          ("%s"), player_tab_infos[3].name);
            al_draw_scaled_bitmap(player_tab_infos[3].skin, 0, 0, 469, 469,
                                  configuration.width / 6.75,
                                  configuration.height / 1.44,
                                  configuration.width / 8.348,
                                  configuration.height / 4.696,
                                  0);
            al_draw_scaled_bitmap(player_tab_infos[3].back_image, 0, 0, 205, 150,
                                  (float) configuration.width / 87.467,
                                  configuration.height / 1.327,
                                  configuration.width / 12.180,
                                  configuration.height / 10.684,
                                  0);
            //player 5
            al_draw_textf(players_nickname,
                          al_map_rgb(255, 255, 255),
                          (float) configuration.width / 12,
                          configuration.height / 1.053 -
                          al_get_font_ascent(configuration.font),
                          ALLEGRO_ALIGN_LEFT,
                          ("%s"), player_tab_infos[4].name);
            al_draw_scaled_bitmap(player_tab_infos[4].skin, 0, 0, 469, 469,
                                  (float) configuration.width / -48,
                                  configuration.height / 1.212,
                                  (float) configuration.width / 8.348,
                                  (float) configuration.height / 4.696,
                                  0);
            al_draw_scaled_bitmap(player_tab_infos[4].back_image, 0, 0, 205, 150,
                                  (float) configuration.width / 6.26,
                                  configuration.height / 1.131,
                                  configuration.width / 12.180,
                                  configuration.height / 10.684,
                                  0);
            break;
        default:
            break;
    }
}

void function_in_game(int selection_players, player *player_tab_infos) {
    int c = 0, f = 0;
    f = rand() % selection_players;
    c = rand() % selection_players;
    if (selection_players <= 4) {
        player_tab_infos[f].front_image = al_load_bitmap("../images/Card_player/Card_Player_Sabotor_1.png");
        player_tab_infos[f].back_image = al_load_bitmap("../images/Card_player/Back_Card_Player.png");
        player_tab_infos[f].gamer_id = 'S';

        for (int i = 0; i < selection_players; i++) {
            if (i != f) {
                player_tab_infos[i].front_image = al_load_bitmap(
                        "../images/Card_player/Card_Player_Astronaute.png");
                player_tab_infos[i].back_image = al_load_bitmap("../images/Card_player/Back_Card_Player.png");
                player_tab_infos[i].gamer_id = 'A';
            }
        }
    }
    if (selection_players == 5) {
        for (int i = 0; i < selection_players; i++) {
            if ((i == f) || (i == c)) {
                player_tab_infos[i].front_image = al_load_bitmap("../images/Card_player/Card_Player_Sabotor_1.png");
                player_tab_infos[i].back_image = al_load_bitmap("../images/Card_player/Back_Card_Player.png");
                player_tab_infos[i].gamer_id = 'S';
            } else {
                player_tab_infos[i].front_image = al_load_bitmap("../images/Card_player/Card_Player_Astronaute.png");
                player_tab_infos[i].back_image = al_load_bitmap("../images/Card_player/Back_Card_Player.png");
                player_tab_infos[i].gamer_id = 'A';
            }
        }
    }
}

//Montre la carte à chaque tour
void show_function(int v, int selection_players, player *player_tab_infos, config configuration,
                   ALLEGRO_FONT *players_nickname) {
    ALLEGRO_FONT *score = al_load_ttf_font("../fonts/agency-fb/agency-fb-bold.ttf",
                                           configuration.height / 40, 0);

    al_draw_scaled_bitmap(player_tab_infos[v].front_image, 0, 0, 205, 150,
                          (float) configuration.width / player_tab_infos[v].xroleratio,
                          configuration.height / player_tab_infos[v].yroleratio,
                          configuration.width / 12.180,
                          configuration.height / 10.684,
                          0);
    for (int i = 0; i < selection_players; i++) {
        al_draw_textf(score,
                      al_map_rgb(255, 255, 255),
                      (float) configuration.width / 8.2,
                      configuration.height / player_tab_infos[i].yscoreratio,
                      ALLEGRO_ALIGN_RIGHT,
                      ("%d"), player_tab_infos[i].score);
    }
    //en haut
    position_under_card(v, player_tab_infos, configuration, players_nickname);

}

void position_under_card(int i, player *player_tab_infos, config configuration, ALLEGRO_FONT *players_nickname) {
    ALLEGRO_FONT *score = al_load_ttf_font("../fonts/agency-fb/agency-fb-bold.ttf",
                                           configuration.height / 40, 0);
    al_draw_text(score,
                 al_map_rgb(255, 255, 255),
                 (float) configuration.width / 7.245, configuration.height / 216, ALLEGRO_ALIGN_LEFT,
                 "Player Turn :");

    al_draw_textf(score,
                  al_map_rgb(255, 255, 255),
                  (float) configuration.width / 3.36, configuration.height / 216, ALLEGRO_ALIGN_LEFT,
                  ("%s"), player_tab_infos[i].name);

    al_draw_scaled_bitmap(player_tab_infos[i].skin, 80, 70, 469, 469,
                          (float) configuration.width / 4,
                          configuration.height / 19200,
                          (float) configuration.width / 16.45,
                          (float) configuration.height / 16.45, 0);
    al_draw_textf(score,
                  al_map_rgb(255, 255, 255),
                  (float) configuration.width / 1.95,
                  configuration.height / 216,
                  ALLEGRO_ALIGN_RIGHT,
                  ("Score : %d"), player_tab_infos[i].score);
}

void
show_function_end_game(int selection_players, player *player_tab_infos, config configuration, ALLEGRO_TIMER *timerRev,
                       ALLEGRO_EVENT_QUEUE *queue_rev,
                       ALLEGRO_BITMAP *rev1, ALLEGRO_BITMAP *rev2, ALLEGRO_BITMAP *rev3) {
    double y, y2;
    ALLEGRO_FONT *score = al_load_ttf_font("../fonts/agency-fb/agency-fb-bold.ttf",
                                           configuration.height / 35, 0);

    for (int i = 0; i < selection_players; i++) {
        ALLEGRO_EVENT event_rev = {0};
        al_wait_for_event(queue_rev, &event_rev);
        if (event_rev.type == ALLEGRO_EVENT_TIMER) {
            if (selection_players == 3) {
                al_draw_scaled_bitmap(rev1, 0, 0, 1920, 1080, 0, 0, (float) configuration.width,
                                      (float) configuration.height,
                                      0);
            } else if (selection_players == 4) {
                al_draw_scaled_bitmap(rev2, 0, 0, 1920, 1080, 0, 0, (float) configuration.width,
                                      (float) configuration.height,
                                      0);
            } else {
                al_draw_scaled_bitmap(rev3, 0, 0, 1920, 1080, 0, 0, (float) configuration.width,
                                      (float) configuration.height,
                                      0);
            }
            if (i == 0) {
                y = 2.535;
                y2 = 2.4;
            } else if (i == 1) {
                y = 1.945;
                y2 = 1.862;
            } else if (i == 2) {
                y = 1.581;
                y2 = 1.521;
            } else if (i == 3) {
                y = 1.334;
                y2 = 1.288;
            } else {
                y = 1.150;
                y2 = 1.1206;
            }
            al_draw_scaled_bitmap(player_tab_infos[i].front_image, 0, 0, 205, 150,
                                  (float) configuration.width / 1.655,
                                  configuration.height / y,
                                  configuration.width / 12.180,
                                  configuration.height / 10.684,
                                  0);
            if (player_tab_infos[i].gamer_id == 'S') {
                al_draw_textf(score,
                              al_map_rgb(255, 255, 255),
                              (float) configuration.width / 2.865,
                              configuration.height / y2,
                              ALLEGRO_ALIGN_LEFT,
                              ("%s was a SABOTOR"), player_tab_infos[i].name);
            } else {
                al_draw_textf(score,
                              al_map_rgb(255, 255, 255),
                              (float) configuration.width / 2.865,
                              configuration.height / y2,
                              ALLEGRO_ALIGN_LEFT,
                              ("%s was a CREWMATE"), player_tab_infos[i].name);
            }
            if (i == 1 || i == 2 || i == 3 || i == 4) {
                for (int j = 0; j < i; j++) {

                    if (j == 0) {
                        y = 2.535;
                        y2 = 2.4;
                    } else if (j == 1) {
                        y = 1.945;
                        y2 = 1.862;
                    } else if (j == 2) {
                        y = 1.581;
                        y2 = 1.521;
                    } else if (j == 3) {
                        y = 1.334;
                        y2 = 1.288;
                    } else {
                        y = 1.150;
                        y2 = 1.13;
                    }
                    al_draw_scaled_bitmap(player_tab_infos[j].front_image, 0, 0, 205, 150,
                                          (float) configuration.width / 1.655,
                                          configuration.height / y,
                                          configuration.width / 12.180,
                                          configuration.height / 10.684,
                                          0);
                    if (player_tab_infos[j].gamer_id == 'S') {
                        al_draw_textf(score,
                                      al_map_rgb(255, 255, 255),
                                      (float) configuration.width / 2.865,
                                      configuration.height / y2,
                                      ALLEGRO_ALIGN_LEFT,
                                      ("%s was a SABOTOR"), player_tab_infos[j].name);
                    } else {
                        al_draw_textf(score,
                                      al_map_rgb(255, 255, 255),
                                      (float) configuration.width / 2.865,
                                      configuration.height / y2,
                                      ALLEGRO_ALIGN_LEFT,
                                      ("%s was a CREWMATE"), player_tab_infos[j].name);
                    }
                }
            }

        }
        al_flip_display();
        al_rest(1);
    }
    al_rest(4);
    al_stop_timer(timerRev);
}

void place(int selection_players, player *player_tab_infos) {
    int i, j;
    player player_switch[1];
    for (i = 0; i < selection_players; i++) {

        for (j = i; j < selection_players; j++) {
            if (player_tab_infos[j].score >= player_tab_infos[i].score) {
                player_switch[0] = player_tab_infos[i];
                player_tab_infos[i] = player_tab_infos[j];
                player_tab_infos[j] = player_switch[0];
            }
        }
    }
}

void ranking(int selection_players, player *player_tab_infos, config configuration, ALLEGRO_TIMER *timerRev,
             ALLEGRO_EVENT_QUEUE *queue_rev, ALLEGRO_BITMAP *gold_med,
             ALLEGRO_BITMAP *silver_med, ALLEGRO_BITMAP *bronze_med) {
    double y, y2, y3;
    int isEnd = 0, r = 0, g = 0, b = 0;
    ALLEGRO_FONT *score = al_load_ttf_font("../fonts/agency-fb/agency-fb-bold.ttf",
                                           configuration.height / 35, 0);
    ALLEGRO_FONT *winer = al_load_ttf_font("../fonts/agency-fb/agency-fb-bold.ttf",
                                           configuration.height / 25, 0);
    place(selection_players, player_tab_infos);

    for (int i = selection_players - 1; i >= 0; i--) {
        ALLEGRO_EVENT event_rev = {0};
        al_wait_for_event(queue_rev, &event_rev);
        if (event_rev.type == ALLEGRO_EVENT_TIMER) {
            if (selection_players == 3) {
                ALLEGRO_BITMAP* ranking3p=al_load_bitmap("../images/Score/Score_screen_3players.png");
                al_draw_scaled_bitmap(ranking3p, 0, 0, 1920, 1080, 0, 0, (float) configuration.width,
                                      (float) configuration.height,
                                      0);
                al_destroy_bitmap(ranking3p);
            } else if (selection_players == 4) {
                ALLEGRO_BITMAP* ranking4p=al_load_bitmap("../images/Score/Score_screen_3players.png");
                al_draw_scaled_bitmap(ranking4p, 0, 0, 1920, 1080, 0, 0, (float) configuration.width,
                                      (float) configuration.height,
                                      0);
                al_destroy_bitmap(ranking4p);
            } else {
                ALLEGRO_BITMAP* ranking5p=al_load_bitmap("../images/Score/Score_screen_3players.png");
                al_draw_scaled_bitmap(ranking5p, 0, 0, 1920, 1080, 0, 0, (float) configuration.width,
                                      (float) configuration.height,
                                      0);
                al_destroy_bitmap(ranking5p);
            }
            if (i == 0) {
                y = 2.7;
                y2 = 2.4;
                y3 = 2.58;
                r = 255;
                g = 215;
                b = 0;
                al_draw_scaled_bitmap(gold_med, 80, 120, 1020, 1020,
                                      (float) configuration.width / 3.84,
                                      configuration.height / y3,
                                      configuration.width / 20.40,
                                      configuration.height / 12,
                                      0);
                al_draw_text(winer,
                             al_map_rgb(r, g, b),
                             (float) configuration.width / 1.344,
                             configuration.height / y2,
                             ALLEGRO_ALIGN_RIGHT,
                             "WINNER !!");
            } else if (i == 1) {
                y = 2.04;
                y2 = 1.862;
                y3 = 1.96;
                r = 192;
                g = 192;
                b = 192;
                al_draw_scaled_bitmap(silver_med, 80, 120, 1020, 1020,
                                      (float) configuration.width / 3.84,
                                      configuration.height / y3,
                                      configuration.width / 20.40,
                                      configuration.height / 12,
                                      0);

            } else if (i == 2) {
                y = 1.636;
                y2 = 1.521;
                y3 = 1.589;
                r = 156;
                g = 82;
                b = 33;
                al_draw_scaled_bitmap(bronze_med, 80, 120, 1020, 1020,
                                      (float) configuration.width / 3.84,
                                      configuration.height / y3,
                                      configuration.width / 20.40,
                                      configuration.height / 12,
                                      0);

            } else if (i == 3) {
                y = 1.366;
                y2 = 1.288;
                r = 255;
                g = 255;
                b = 255;
            } else {
                y = 1.184;
                y2 = 1.1206;
                r = 255;
                g = 255;
                b = 255;
            }
            al_draw_scaled_bitmap(player_tab_infos[i].skin, 80, 70, 469, 469,
                                  (float) configuration.width / 3.17,
                                  configuration.height / y,
                                  configuration.width / 8.348,
                                  configuration.height / 4.696, 0);
            al_draw_textf(score,
                          al_map_rgb(r, g, b),
                          (float) configuration.width / 2.461,
                          configuration.height / y2,
                          ALLEGRO_ALIGN_LEFT,
                          ("%s"), player_tab_infos[i].name);
            al_draw_textf(score,
                          al_map_rgb(r, g, b),
                          (float) configuration.width / 1.828,
                          configuration.height / y2,
                          ALLEGRO_ALIGN_LEFT,
                          ("%d"), player_tab_infos[i].score);
        }

        if (i == 1 || i == 2 || i == 3 || i == 0) {
            for (int j = selection_players - 1; j > i - 1; j--) {

                if (j == 0) {
                    y = 2.7;
                    y2 = 2.4;
                    y3 = 2.58;
                    r = 255;
                    g = 215;
                    b = 0;
                    al_draw_scaled_bitmap(gold_med, 80, 120, 1020, 1020,
                                          (float) configuration.width / 3.84,
                                          configuration.height / y3,
                                          configuration.width / 20.40,
                                          configuration.height / 12,
                                          0);
                    al_draw_text(winer,
                                 al_map_rgb(r, g, b),
                                 (float) configuration.width / 1.344,
                                 configuration.height / y2,
                                 ALLEGRO_ALIGN_RIGHT,
                                 "WINNER !!");
                } else if (j == 1) {
                    y = 2.04;
                    y2 = 1.862;
                    y3 = 1.96;
                    r = 192;
                    g = 192;
                    b = 192;
                    al_draw_scaled_bitmap(silver_med, 80, 120, 1020, 1020,
                                          (float) configuration.width / 3.84,
                                          configuration.height / y3,
                                          configuration.width / 20.40,
                                          configuration.height / 12,
                                          0);

                } else if (j == 2) {
                    y = 1.636;
                    y2 = 1.521;
                    y3 = 1.589;
                    r = 156;
                    g = 82;
                    b = 33;
                    al_draw_scaled_bitmap(bronze_med, 80, 120, 1020, 1020,
                                          (float) configuration.width / 3.84,
                                          configuration.height / y3,
                                          configuration.width / 20.40,
                                          configuration.height / 12,
                                          0);

                } else if (j == 3) {
                    y = 1.366;
                    y2 = 1.288;
                    r = 255;
                    g = 255;
                    b = 255;
                } else {
                    y = 1.184;
                    y2 = 1.1206;
                    r = 255;
                    g = 255;
                    b = 255;
                }
                al_draw_scaled_bitmap(player_tab_infos[j].skin, 80, 70, 469, 469,
                                      (float) configuration.width / 3.17,
                                      configuration.height / y,
                                      configuration.width / 8.348,
                                      configuration.height / 4.696, 0);
                al_draw_textf(score,
                              al_map_rgb(r, g, b),
                              (float) configuration.width / 2.461,
                              configuration.height / y2,
                              ALLEGRO_ALIGN_LEFT,
                              ("%s"), player_tab_infos[j].name);
                al_draw_textf(score,
                              al_map_rgb(r, g, b),
                              (float) configuration.width / 1.828,
                              configuration.height / y2,
                              ALLEGRO_ALIGN_LEFT,
                              ("%d"), player_tab_infos[j].score);
            }
        }
        al_flip_display();
        if (i == 1 || i == 2) {
            al_rest(2);
        } else {
            al_rest(1.3);
        }
    }

    al_rest(5);
}