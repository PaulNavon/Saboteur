#include "src/title_screen/title_screen.h"
#include "src/board/board.h"
#include "src/initialization/initialization.h"
#include "src/bandeson/BandeSon.h"
#include "src/card_shuffle/card_shuffle.h"
#include "src/player_turn/player_turn.h"
#include "src/Rules/Rules.h"
#include "src/AlphabetPourLesNuls/Alphabet.h"
#include "src/board/DrawPlayersBoard.h"
#include "src/save/save.h"

int main(void) {
    //INSTALL ALL
    srand(time(NULL));
    if (!al_init()) { error_message("Initialisation Allegro"); }
    if (!al_install_keyboard()) { error_message("Installation clavier"); }
    if (!al_install_mouse()) { error_message("Initialisation souris"); }
    al_init_font_addon();
    if (!al_init_ttf_addon()) { error_message("Initialisation polices TTF"); }
    if (!al_init_image_addon()) { error_message("Initialisation images"); }
    if (!al_init_primitives_addon()) { error_message("Primitives"); }
    //SOUND INITIALISATION
    if (!al_install_audio()) { error_message("failed to initialize audio!\n"); }
    if (!al_init_acodec_addon()) { error_message("failed to initialize audio codecs!\n"); }
    if (!al_reserve_samples(2)) { error_message("failed to reserve samples!\n"); }


    bool end = false;
    bool done = false;
    bool shift = false;

    //GET DESKTOP INFO
    int nva = al_get_num_video_adapters();
    if (nva < 1) { return 0; }
    al_set_new_bitmap_flags(ALLEGRO_ALPHA_TEST);
    ALLEGRO_MONITOR_INFO aminfo;
    al_get_monitor_info(0, &aminfo);
    int desktop_width = aminfo.x2 - aminfo.x1 + 1;
    int desktop_height = aminfo.y2 - aminfo.y1 + 1;
    int modifyingphysicalsize = 0;
    int dumb_card = 0;
    card occurrence_point[LIGNES - 1];
    char calling[LIGNES - 1], pick[ACTION_CARD - 1], table[LIGNES - 1];
    buffer_position selection;
    //INIT VARIABLES
    ALLEGRO_DISPLAY *display;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_EVENT_QUEUE *queue;
    ALLEGRO_EVENT_QUEUE *queue_rev;
    ALLEGRO_FONT *fontRoboto40 = NULL;
    ALLEGRO_FONT *agency = NULL;
    ALLEGRO_EVENT event = {0};
    ALLEGRO_SAMPLE_ID id;
    ALLEGRO_SAMPLE *menubackground = al_load_sample("../src/bandeson/chronometry.wav");
    ALLEGRO_SAMPLE_ID id2;
    ALLEGRO_SAMPLE *ingamebackground = al_load_sample("../src/bandeson/TheCoreCeleste.wav");

    if (!menubackground) { error_message("Audio clip sample1 not loaded!\n"); }
    if (!ingamebackground) { error_message("Audio clip sample2 not loaded!\n"); }

    //Rules
    int Z = 0, OldZ = Z, first_time_on_akali = 0; //easteregg
    bool exitrule = 0;
    ALLEGRO_BITMAP *rules_low = al_load_bitmap("../images/Rules/screenlittle.jpg");
    ALLEGRO_BITMAP *rules_medium = al_load_bitmap("../images/Rules/screenmedium.jpg");
    ALLEGRO_BITMAP *rules_high = al_load_bitmap("../images/Rules/screenbig.jpg");
    assert(rules_low != NULL);
    assert(rules_medium != NULL);
    assert(rules_high != NULL);
    al_set_mouse_z(0);

    //CREDIT
    bool exitcredit = false;
    int first_time_on_yasuo = 0;//easteregg
    ALLEGRO_BITMAP *credit = al_load_bitmap("../images/Credit/Credit.jpg");
    assert(credit != NULL);

    //Selection
    int character, a, q, t, h, skins = 0, selection_players = 3, ff = 0, nb_games;
    bool exit_selection_game = false;
    bool endjoueurselection = false, endjoueurselection2 = false, quitselection = false, fate_selection = false;
    ALLEGRO_BITMAP *players_nb_minimum = al_load_bitmap("../images/Selection/how_many_player1.jpg");
    ALLEGRO_BITMAP *players_nb_medium = al_load_bitmap("../images/Selection/how_many_player2.jpg");
    ALLEGRO_BITMAP *players_nb_high = al_load_bitmap("../images/Selection/how_many_player3.jpg");
    ALLEGRO_BITMAP *player_selection = al_load_bitmap("../images/Selection/player_selection.jpg");
    ALLEGRO_BITMAP *number_bitmap = al_load_bitmap("../images/Selection/how_many_rounds.jpg");
    assert(players_nb_minimum != NULL);
    assert(players_nb_medium != NULL);
    assert(players_nb_high != NULL);
    assert(player_selection != NULL);

    ALLEGRO_BITMAP *tab_characters[MAX_CHARACTERS] = {0};
    tab_characters[0] = al_load_bitmap("../images/Character/Character 1.png");
    tab_characters[1] = al_load_bitmap("../images/Character/Character 2.png");
    tab_characters[2] = al_load_bitmap("../images/Character/Character 3.png");
    tab_characters[3] = al_load_bitmap("../images/Character/Character 4.png");
    tab_characters[4] = al_load_bitmap("../images/Character/Character 5.png");

    assert(tab_characters[0] != NULL);
    assert(tab_characters[1] != NULL);
    assert(tab_characters[2] != NULL);
    assert(tab_characters[3] != NULL);
    assert(tab_characters[4] != NULL);
    player *player_tab_infos = NULL;
    ALLEGRO_FONT *player_number = NULL;
    ALLEGRO_FONT *selection_number = NULL;
    ALLEGRO_FONT *number_red_message = NULL;

    // Loading
    bool load = false;
    bool loading_game = false;
    int games_counter = 0, round_counter = 0;
    FILE *saveDataChar = NULL;

    //Revelation end game
    ALLEGRO_BITMAP *rev_3p = al_load_bitmap("../images/Revelation/Revelation_3p.png");
    ALLEGRO_BITMAP *rev_4p = al_load_bitmap("../images/Revelation/Revelation_4p.png");
    ALLEGRO_BITMAP *rev_5p = al_load_bitmap("../images/Revelation/Revelation_5p.png");
    ALLEGRO_BITMAP *role_revelation = al_load_bitmap("../images/Title_screen/role_revelation.jpg");
    ALLEGRO_BITMAP *surrender = al_load_bitmap("../images/Title_screen/surrender.jpg");
    ALLEGRO_BITMAP *loading = al_load_bitmap("../images/Revelation/Loading.png");

    ALLEGRO_BITMAP *gold_med = al_load_bitmap("../images/Score/gold_medal.png");
    ALLEGRO_BITMAP *silver_med = al_load_bitmap("../images/Score/silver_medal.png");
    ALLEGRO_BITMAP *bronze_med = al_load_bitmap("../images/Score/bronze_medal.png");
    ALLEGRO_TIMER *timer_revelation = NULL;

    //In game
    bool endgame = false, endturn = false, backmenu = true, fix = false;
    ALLEGRO_BITMAP *helpFPS = NULL;
    ALLEGRO_BITMAP *helpFPS2 = NULL;


    unsigned char pressed_keys[KEYS_COUNT] = {0};
    bool already_played_action_card = false;
    int Xshift = 0, Yshift = 0, modification = 0, nb_tour = 0, no_card_left = 0, detect_end_y = 0;
    {
        selection.image = NULL;
        selection.c = 0;
        selection.r = 0;
    }
    config configuration;
    config old_configuration;
    board game_board;
    card current_card;
    card pool_pick;
    al_set_new_bitmap_flags(ALLEGRO_MEMORY_BITMAP);
    init_configuration(&configuration, &old_configuration);
    ALLEGRO_FONT *players_nickname = NULL;

    display = al_create_display(configuration.width, configuration.height);
    if (!display) {
        free_board(&game_board);
        error_message("Création de la fenêtre");
    }
    al_set_window_title(display, "SABOTEUR SPACE EDITION");
    al_set_window_position(display, desktop_width / 6, desktop_height / 6);

    agency = al_load_ttf_font("../fonts/agency-fb/agency-fb-bold.ttf", 50, 0);
    if (!agency) {
        free_board(&game_board);
        al_destroy_display(display);
        error_message("Chargement de la police Roboto");
    }

    queue = al_create_event_queue();
    queue_rev = al_create_event_queue();
    if (!queue && !queue_rev) {
        free_board(&game_board);
        al_destroy_display(display);
        al_destroy_font(fontRoboto40);
        al_destroy_font(agency);
        al_destroy_timer(timer);
        error_message("Création de l'event queue");
    }

    //REGISTER ALL EVENTS
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue_rev, al_get_display_event_source(display));

    al_draw_scaled_bitmap(configuration.main_screen, 0, 0, 1920, 1080, 0, 0, (float) configuration.width,
                          (float) configuration.height,
                          0);
    al_flip_display();
    //Sounds initialisation
    backgroundmusic_ingame_play(ingamebackground, &id2);
    backgroundmusic_ingame_stop(ingamebackground, &id2);
    backgroundmusic_Menu_play(menubackground, &id);

    do {
        backmenu = true;
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_KEY_DOWN:
                if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                    end = 1;
                }
                break;
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                end = 1;
                break;
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:

                //START Selection
                if (event.mouse.x > (configuration.width / 3.25) &&
                    event.mouse.x<(configuration.width / 1.446) && event.mouse.y>(configuration.height / 2.3) &&
                    event.mouse.y < (configuration.height / 1.93)) {

                    //stop menu's background music & start game's background music
                    backgroundmusic_Menu_stop(menubackground, &id);
                    backgroundmusic_ingame_play(ingamebackground, &id2);
                    if (loading_game == false) {
                        al_draw_scaled_bitmap(players_nb_minimum, 0, 0, 1920, 1080, 0, 0, (float) configuration.width,
                                              (float) configuration.height,
                                              0);

                        al_flip_display();
                    } else {
                        quitselection = true;
                        endjoueurselection = true;
                        endjoueurselection2 = true;
                        backmenu = false;
                    }
                    while (!quitselection) {
                        al_wait_for_event(queue, &event);
                        switch (event.type) {
                            case ALLEGRO_EVENT_DISPLAY_CLOSE :
                                end = true;
                                quitselection = true;
                                backmenu = true;
                                break;
                            case ALLEGRO_EVENT_KEY_DOWN:
                                if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                                    backmenu = true;
                                    quitselection = true;
                                }
                                break;
                            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN :
                                if (event.mouse.x > (configuration.width / 19.2) &&
                                    event.mouse.x<(configuration.width / 2.743)
                                                  && event.mouse.y>(configuration.height / 1.8) &&
                                    event.mouse.y < (configuration.height / 1.44)) {
                                    selection_players = 3;
                                    al_draw_scaled_bitmap(players_nb_minimum, 0, 0, 1920, 1080, 0, 0,
                                                          (float) configuration.width, (float) configuration.height,
                                                          0);
                                    al_flip_display();
                                }
                                if (event.mouse.x > (configuration.width / 2.743) &&
                                    event.mouse.x<(configuration.width / 1.485)
                                                  && event.mouse.y>(configuration.height / 1.8) &&
                                    event.mouse.y < (configuration.height / 1.44)) {
                                    selection_players = 4;
                                    al_draw_scaled_bitmap(players_nb_medium, 0, 0, 1920, 1080, 0, 0,
                                                          (float) configuration.width, (float) configuration.height,
                                                          0);
                                    al_flip_display();
                                }
                                if (event.mouse.x > (configuration.width / 1.485) &&
                                    event.mouse.x<(configuration.width / 1.055)
                                                  && event.mouse.y>(configuration.height / 1.8) &&
                                    event.mouse.y < (configuration.height / 1.44)) {
                                    selection_players = 5;
                                    al_draw_scaled_bitmap(players_nb_high, 0, 0, 1920, 1080, 0, 0,
                                                          (float) configuration.width, (float) configuration.height,
                                                          0);
                                    al_flip_display();

                                }

                                if (event.mouse.x > (configuration.width / 2.313) &&
                                    event.mouse.x<(configuration.width / 1.765)
                                                  && event.mouse.y>(configuration.height / 1.222) &&
                                    event.mouse.y < (configuration.height / 1.07)) {
                                    if (selection_players == 0) { selection_players = 3; }

                                    player_tab_infos = calloc(selection_players, sizeof(player));
                                    for (a = 0; a < selection_players; a++) {
                                        for (q = 0; q < MAX_PSEUDO; q++) {
                                            player_tab_infos[a].name[q] = '0';
                                        }
                                    }
                                    player_number = al_load_ttf_font("../fonts/agency-fb/agency-fb-bold.ttf",
                                                                     configuration.height / 8.5, 0);
                                    backmenu = false;
                                    do {
                                        int player_key = 0;
                                        for (h = 0; h < selection_players; h++) {
                                            al_clear_to_color(BLACK);
                                            al_draw_scaled_bitmap(player_selection, 0, 0, 1920, 1080, 0, 0,
                                                                  (float) configuration.width,
                                                                  (float) configuration.height, 0);
                                            al_draw_scaled_bitmap(tab_characters[skins], 0, 0, 469, 469,
                                                                  configuration.width / 1.62,
                                                                  configuration.height / 2.89,
                                                                  (float) configuration.width / 4,
                                                                  (float) configuration.height / 2.3, 0);
                                            al_draw_textf(player_number,
                                                          al_map_rgb(255, 255, 255),
                                                          old_configuration.width / 4.6,
                                                          old_configuration.height / 37,
                                                          ALLEGRO_ALIGN_LEFT,
                                                          ("%d"), h + 1);
                                            al_flip_display();
                                            do {
                                                al_wait_for_event(queue, &event);
                                                switch (event.type) {
                                                    case ALLEGRO_EVENT_DISPLAY_CLOSE :
                                                        end = true;
                                                        quitselection = true;
                                                        endjoueurselection = true;
                                                        endjoueurselection2 = true;
                                                        backmenu = true;
                                                        break;
                                                    case ALLEGRO_EVENT_KEY_DOWN:
                                                        if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                                                            quitselection = true;
                                                            endjoueurselection = true;
                                                            endjoueurselection2 = true;
                                                            backmenu = true;
                                                        } else {
                                                            if ((event.keyboard.keycode == ALLEGRO_KEY_BACKSPACE ||
                                                                 event.keyboard.keycode == ALLEGRO_KEY_DELETE) &&
                                                                player_tab_infos[h].name[0] != '0' &&
                                                                player_key != 0) {
                                                                player_tab_infos[h].name[player_key - 1] = '0';
                                                                player_key--;
                                                            } else {
                                                                character = alphabet(event.keyboard.keycode);
                                                                if (character != 200 &&
                                                                    player_key < MAX_PSEUDO - 1) {
                                                                    //200 => default in folder Alphabet
                                                                    player_tab_infos[h].name[player_key] = (char) character;
                                                                    player_key++;
                                                                }
                                                            }
                                                            al_clear_to_color(BLACK);
                                                            al_draw_scaled_bitmap(player_selection, 0, 0, 1920,
                                                                                  1080, 0,
                                                                                  0,
                                                                                  (float) configuration.width,
                                                                                  (float) configuration.height, 0);
                                                            al_draw_scaled_bitmap(tab_characters[skins], 0, 0, 469,
                                                                                  469,
                                                                                  configuration.width / 1.62,
                                                                                  configuration.height / 2.89,
                                                                                  (float) configuration.width / 4,
                                                                                  (float) configuration.height /
                                                                                  2.3,
                                                                                  0);
                                                            al_draw_textf(player_number,
                                                                          al_map_rgb(255, 255, 255),
                                                                          old_configuration.width / 4.6,
                                                                          old_configuration.height / 37,
                                                                          ALLEGRO_ALIGN_LEFT,
                                                                          ("%d"), h + 1);
                                                            if (player_key >= MAX_PSEUDO - 1) {
                                                                //Keeps the warning on the screen if there is still 20 characters in the nickname
                                                                al_draw_textf(old_configuration.font,
                                                                              al_map_rgba(145, 0, 0, 70),
                                                                              old_configuration.width / 27,
                                                                              old_configuration.height / 1.8 -
                                                                              al_get_font_ascent(
                                                                                      old_configuration.font),
                                                                              ALLEGRO_ALIGN_LEFT,
                                                                              ("MAX CHARACTERS : %d"),
                                                                              MAX_PSEUDO - 1);
                                                            }
                                                            //Draw the nickname on the screen
                                                            for (t = 0; t < MAX_PSEUDO; t++) {
                                                                if (player_tab_infos[h].name[t] == '0' ||
                                                                    player_tab_infos[h].name[t] == '\n') {
                                                                    player_tab_infos[h].name[t] = ' ';
                                                                }
                                                            }
                                                            al_draw_textf(old_configuration.font,
                                                                          al_map_rgb(49, 15, 48),
                                                                          old_configuration.width / 27,
                                                                          old_configuration.height / 2.15 -
                                                                          al_get_font_ascent(
                                                                                  old_configuration.font),
                                                                          ALLEGRO_ALIGN_LEFT,
                                                                          ("%s"), player_tab_infos[h].name);
                                                            al_flip_display();
                                                        }
                                                        break;
                                                    case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                                                        if (event.mouse.x > (configuration.width / 1.774) &&
                                                            event.mouse.x<(configuration.width / 1.616)
                                                                          && event.mouse.y>(
                                                                    configuration.height / 2.026) &&
                                                            event.mouse.y <
                                                            (configuration.height / 1.5)) {//Going Left (skins)
                                                            if (skins == 0) {
                                                                skins = MAX_CHARACTERS - 1;
                                                            } else { skins--; }
                                                            al_clear_to_color(BLACK);
                                                            al_draw_scaled_bitmap(player_selection, 0, 0, 1920,
                                                                                  1080, 0,
                                                                                  0,
                                                                                  (float) configuration.width,
                                                                                  (float) configuration.height, 0);
                                                            for (t = 0; t < MAX_PSEUDO; t++) {
                                                                if (player_tab_infos[h].name[t] == '0' ||
                                                                    player_tab_infos[h].name[t] == '\n') {
                                                                    player_tab_infos[h].name[t] = ' ';
                                                                }
                                                            }
                                                            al_draw_textf(old_configuration.font,
                                                                          al_map_rgb(49, 15, 48),
                                                                          old_configuration.width / 27,
                                                                          old_configuration.height / 2.15 -
                                                                          al_get_font_ascent(
                                                                                  old_configuration.font),
                                                                          ALLEGRO_ALIGN_LEFT,
                                                                          ("%s"), player_tab_infos[h].name);
                                                            al_draw_scaled_bitmap(tab_characters[skins], 0, 0, 469,
                                                                                  469,
                                                                                  configuration.width / 1.62,
                                                                                  configuration.height / 2.89,
                                                                                  (float) configuration.width / 4,
                                                                                  (float) configuration.height /
                                                                                  2.3,
                                                                                  0);
                                                            al_draw_textf(player_number,
                                                                          al_map_rgb(255, 255, 255),
                                                                          old_configuration.width / 4.6,
                                                                          old_configuration.height / 37,
                                                                          ALLEGRO_ALIGN_LEFT,
                                                                          ("%d"), h + 1);
                                                            al_flip_display();
                                                        }
                                                        if (event.mouse.x > (configuration.width / 1.118) &&
                                                            event.mouse.x<(configuration.width / 1.055)
                                                                          && event.mouse.y>(
                                                                    configuration.height / 2.026) &&
                                                            event.mouse.y <
                                                            (configuration.height / 1.5)) {//Going Right (skins)
                                                            if (skins == MAX_CHARACTERS - 1) {
                                                                skins = 0;
                                                            } else { skins++; }
                                                            al_clear_to_color(BLACK);
                                                            al_draw_scaled_bitmap(player_selection, 0, 0, 1920,
                                                                                  1080, 0,
                                                                                  0,
                                                                                  (float) configuration.width,
                                                                                  (float) configuration.height, 0);
                                                            for (t = 0; t < MAX_PSEUDO; t++) {
                                                                if (player_tab_infos[h].name[t] == '0' ||
                                                                    player_tab_infos[h].name[t] == '\n') {
                                                                    player_tab_infos[h].name[t] = ' ';
                                                                }
                                                            }
                                                            al_draw_textf(old_configuration.font,
                                                                          al_map_rgb(49, 15, 48),
                                                                          old_configuration.width / 27,
                                                                          old_configuration.height / 2.15 -
                                                                          al_get_font_ascent(
                                                                                  old_configuration.font),
                                                                          ALLEGRO_ALIGN_LEFT,
                                                                          ("%s"), player_tab_infos[h].name);
                                                            al_draw_scaled_bitmap(tab_characters[skins], 0, 0, 469,
                                                                                  469,
                                                                                  configuration.width / 1.62,
                                                                                  configuration.height / 2.89,
                                                                                  (float) configuration.width / 4,
                                                                                  (float) configuration.height /
                                                                                  2.3,
                                                                                  0);
                                                            al_draw_textf(player_number,
                                                                          al_map_rgb(255, 255, 255),
                                                                          old_configuration.width / 4.6,
                                                                          old_configuration.height / 37,
                                                                          ALLEGRO_ALIGN_LEFT,
                                                                          ("%d"), h + 1);
                                                            al_flip_display();
                                                        }
                                                        if (event.mouse.x > (configuration.width / 6.784) &&
                                                            event.mouse.x<(configuration.width / 3.549)
                                                                          && event.mouse.y>(
                                                                    configuration.height / 1.22) &&
                                                            event.mouse.y < (configuration.height / 1.07)) {
                                                            if (h < selection_players) {
                                                                if (player_tab_infos[h].name[0] == '0' ||
                                                                    player_tab_infos[h].name[0] == ' ') {
                                                                    strcpy(player_tab_infos[h].name, "Player ");
                                                                    switch (h + 1) {//Player number ?
                                                                        case 1:
                                                                            player_tab_infos[h].name[7] = '1';
                                                                            break;
                                                                        case 2:
                                                                            player_tab_infos[h].name[7] = '2';
                                                                            break;
                                                                        case 3:
                                                                            player_tab_infos[h].name[7] = '3';
                                                                            break;
                                                                        case 4:
                                                                            player_tab_infos[h].name[7] = '4';
                                                                            break;
                                                                        case 5:
                                                                            player_tab_infos[h].name[7] = '5';
                                                                            break;
                                                                        default:
                                                                            break;
                                                                    }
                                                                    for (t = 0; t < MAX_PSEUDO; t++) {
                                                                        if (player_tab_infos[h].name[t] == '0' ||
                                                                            player_tab_infos[h].name[t] == '\n') {
                                                                            player_tab_infos[h].name[t] = ' ';
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                            if (h ==
                                                                selection_players - 1) { quitselection = true; }
                                                            endjoueurselection = true;
                                                            endjoueurselection2 = true;
                                                        }//DONE
                                                        break;
                                                    default:
                                                        break;
                                                }
                                            } while (!endjoueurselection);
                                            player_tab_infos[h].name[MAX_PSEUDO - 1] = '\0';
                                            player_tab_infos[h].skins = skins;
                                            player_tab_infos[h].skin = tab_characters[skins];
                                            player_key = 0;
                                            skins = 0;
                                            endjoueurselection = false;
                                            if (quitselection) { break; }
                                        }
                                    } while (!endjoueurselection2);
                                    endjoueurselection2 = false;
                                }
                                break;
                            default :
                                break;
                        }
                    }
                    quitselection = false;
                    if (backmenu) {
                        free(player_tab_infos);
                        backgroundmusic_ingame_stop(ingamebackground, &id2);
                        backgroundmusic_Menu_play(menubackground, &id);
                        al_draw_scaled_bitmap(configuration.main_screen, 0, 0, 1920, 1080, 0, 0,
                                              (float) configuration.width,
                                              (float) configuration.height,
                                              0);
                        al_flip_display();
                    }
                }

                //LOAD GAME
                if (event.mouse.x > (configuration.width / 3.25) &&
                    event.mouse.x<(configuration.width / 1.446) && event.mouse.y>(configuration.height / 1.86) &&
                    event.mouse.y < (configuration.height / 1.63)) {

                    al_draw_textf(agency, al_map_rgba(200, 200, 200, 50), (float) configuration.width / 2,
                                  configuration.height / 2.8 - al_get_font_ascent(agency), ALLEGRO_ALIGN_CENTER,
                                  ("%s"), "GAME LOADING...");
                    al_flip_display(), loading_game = true;
                    game_board.tab = calloc(COLUMNS, sizeof(card *));
                    for (int i = 0; i < COLUMNS; i++) {
                        game_board.tab[i] = calloc(ROWS, sizeof(card));
                    }
                    saveDataChar = fopen("../saveDataChar.txt", "r");
                    char c;
                    int save;
                    //Retrieve nb players (nb)
                    fscanf(saveDataChar, "%d", &selection_players);
                    fseek(saveDataChar, +2, SEEK_CUR);

                    player_tab_infos = calloc(selection_players, sizeof(player));
                    if (!player_tab_infos) {
                        error_message("Retrieving players' informations failed");
                    }

                    for (int x = 0; x < selection_players; x++) {
                        player_tab_infos[x].hand = calloc(HAND, sizeof(card));
                    }
                    init_board(&game_board, selection_players);
                    switch (selection_players) {
                        case 3:
                            game_board.board_image = al_load_bitmap("../images/Title_screen/board_3p.jpg");
                            break;
                        case 4:
                            game_board.board_image = al_load_bitmap("../images/Title_screen/board_4p.jpg");
                            break;
                        case 5:
                            game_board.board_image = al_load_bitmap("../images/Title_screen/board_5p.jpg");
                            break;
                        default:
                            game_board.board_image = al_load_bitmap("../images/Title_screen/board_3p.jpg");
                            break;
                    }




                    //Retrieve game board (char)
                    for (int s = 0; s < ROWS - 1; s++) {
                        for (int w = 0; w < COLUMNS - 1; w++) {
                            fscanf(saveDataChar, "%c", &c);
                            loadingCards(c, s, w, &game_board);
                        }
                        fseek(saveDataChar, +2, SEEK_CUR);
                    }


                    //Retrieve players' skin
                    for (int n = 0; n < selection_players; n++) {
                        fscanf(saveDataChar, "%d", &save);
                        player_tab_infos[n].skin = tab_characters[save];
                        fseek(saveDataChar, 2, SEEK_CUR);

                        fscanf(saveDataChar, "%d", &save);
                        player_tab_infos[n].reactor_damage = save;
                        fseek(saveDataChar, 2, SEEK_CUR);

                        fscanf(saveDataChar, "%d", &save);
                        player_tab_infos[n].board_damage = save;
                        fseek(saveDataChar, 2, SEEK_CUR);

                        fscanf(saveDataChar, "%d", &save);
                        player_tab_infos[n].suit_damage = save;
                        fseek(saveDataChar, 2, SEEK_CUR);
                    }

                    for (int n = 0; n < selection_players; n++) {
                        save = player_tab_infos[n].skins;
                        fprintf(saveDataChar, "%d\n", save);
                        save = player_tab_infos[n].reactor_damage;
                        fprintf(saveDataChar, "%d\n", save);
                        save = player_tab_infos[n].board_damage;
                        fprintf(saveDataChar, "%d\n", save);
                        save = player_tab_infos[n].suit_damage;
                        fprintf(saveDataChar, "%d\n", save);

                    }
                    //Retrieve players' nickname
                    for (int s = 0; s < selection_players; s++) {
                        fgets(player_tab_infos[s].name, MAX_PSEUDO, saveDataChar);
                        fseek(saveDataChar, +2, SEEK_CUR);
                    }
                    //Retrieve players' hand/deck
                    for (int s = 0; s < selection_players; s++) {
                        init_player_hand(&player_tab_infos[s], configuration);
                        for (int w = 0; w < MAX_DECK - 1; w++) {
                            fscanf(saveDataChar, "%c", &c);
                            loadingHand(c, w, player_tab_infos[s].hand);
                        }
                        fseek(saveDataChar, +2, SEEK_CUR);
                    }
                    //Retrieve players' score
                    for (int n = 0; n < selection_players; n++) {
                        fscanf(saveDataChar, "%d", &save);
                        player_tab_infos[n].score = save;
                        fseek(saveDataChar, +2, SEEK_CUR);
                    }
                    //Retrieve players' role
                    for (int s = 0; s < selection_players; s++) {
                        fscanf(saveDataChar, "%c", &c);
                        fseek(saveDataChar, +2, SEEK_CUR);

                        player_tab_infos[s].gamer_id = c;
                        if (c == 'A') {
                            player_tab_infos[s].front_image = al_load_bitmap(
                                    "../images/Card_player/Card_Player_Astronaute.png");
                        } else {
                            player_tab_infos[s].front_image = al_load_bitmap(
                                    "../images/Card_player/Card_Player_Sabotor_1.png");
                        }
                        player_tab_infos[s].back_image = al_load_bitmap("../images/Card_player/Back_Card_Player.png");
                    }
                    //Retrieve nb games
                    fscanf(saveDataChar, "%d", &nb_games);
                    fseek(saveDataChar, +2, SEEK_CUR);

                    //Retrieve game counter
                    fscanf(saveDataChar, "%d", &games_counter);
                    fseek(saveDataChar, +2, SEEK_CUR);

                    //Retrieve round counter
                    fscanf(saveDataChar, "%d", &round_counter);

                    fclose(saveDataChar);
                    al_rest(1);

                    al_draw_scaled_bitmap(configuration.main_screen, 0, 0, 1920, 1080, 0, 0,
                                          (float) configuration.width,
                                          (float) configuration.height,
                                          0);
                    al_draw_textf(agency, al_map_rgba(200, 200, 200, 50), (float) configuration.width / 2,
                                  configuration.height / 2.8 - al_get_font_ascent(agency), ALLEGRO_ALIGN_CENTER,
                                  ("%s"),
                                  "GAME LOADED, THE GAME WILL START SOON!"), al_flip_display(), loading_game = true;
                    al_flip_display();
                    al_rest(1);
                }

                //Start the game board
                if (!backmenu || loading_game) {
                    if (loading_game) {
                        backgroundmusic_Menu_stop(menubackground, &id);
                        backgroundmusic_ingame_play(ingamebackground, &id2);
                    }
                    if (configuration.height == 720) {
                        players_nickname = al_load_ttf_font("../fonts/agency-fb/agency-fb-bold.ttf",
                                                            configuration.height / 55, 0);
                    } else if (configuration.height == 480) {
                        players_nickname = al_load_ttf_font("../fonts/agency-fb/agency-fb-bold.ttf",
                                                            configuration.height / 70, 0);
                    } else if (configuration.height == 1080) {
                        players_nickname = al_load_ttf_font("../fonts/agency-fb/agency-fb-bold.ttf",
                                                            configuration.height / 40, 0);
                    }
                    timer = al_create_timer(1.0 / configuration.frame_rate);
                    if (!timer) {
                        free_board(&game_board);
                        al_destroy_display(display);
                        al_destroy_font(fontRoboto40);
                        al_destroy_font(agency);
                        error_message("Création du timer");
                    }
                    timer_revelation = al_create_timer(2);
                    if (!timer_revelation) {
                        free_board(&game_board);
                        al_destroy_display(display);
                        al_destroy_font(fontRoboto40);
                        al_destroy_font(agency);
                        al_destroy_timer(timer);
                        error_message("Création du timer de révélation");
                    }

                    al_register_event_source(queue, al_get_timer_event_source(timer));
                    al_register_event_source(queue_rev, al_get_timer_event_source(timer_revelation));
                    al_start_timer(timer);
                    al_start_timer(timer_revelation);
                    if (loading_game == false) {
                        for (int z = 0; z < selection_players; z++) {
                            init_player_hand(&player_tab_infos[z], configuration);
                            player_tab_infos[z].board_damage = false;
                            player_tab_infos[z].reactor_damage = false;
                            player_tab_infos[z].suit_damage = false;
                            player_tab_infos[z].score = 0;
                        }
                    }
                    init_player_tab_infos(player_tab_infos, selection_players);
                    helpFPS = al_create_bitmap(configuration.width, configuration.height);
                    helpFPS2 = al_create_bitmap(configuration.width, configuration.height);
                    int w, z, v;
                    if (loading_game == true) {
                        w = games_counter;
                        v = round_counter;
                    } else {
                        int number, selected_number = 0;
                        selection_number = al_load_ttf_font("../fonts/agency-fb/agency-fb-bold.ttf",
                                                            configuration.height / 8.5, 0);
                        number_red_message = al_load_ttf_font("../fonts/agency-fb/agency-fb-bold.ttf",
                                                              configuration.height / 15.428, 0);
                        w = v = 0;
                        al_draw_scaled_bitmap(number_bitmap, 0, 0, 1920, 1080, 0, 0, configuration.width,
                                              configuration.height, 0);
                        al_draw_textf(selection_number, al_map_rgb(49, 15, 48), configuration.width / 2.214,
                                      configuration.height / 2.147, ALLEGRO_ALIGN_CENTER, "%d", selected_number);
                        if (selected_number == 0) {
                            al_draw_textf(number_red_message, al_map_rgba(145, 0, 0, 70), configuration.width / 2,
                                          configuration.height / 1.576, ALLEGRO_ALIGN_CENTER,
                                          "YOU WILL AUTOMATICALLY GET 3 TURNS IF YOU SELECT 0 TURNS");

                        }
                        al_flip_display();
                        do {
                            al_wait_for_event(queue, &event);
                            switch (event.type) {
                                case ALLEGRO_EVENT_DISPLAY_CLOSE:
                                    done = true;
                                    end = true;
                                    exit_selection_game = true;
                                    break;
                                case ALLEGRO_EVENT_KEY_DOWN:
                                    if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                                        done = true;
                                        exit_selection_game = true;
                                        //Going back to menu, stop music game and put the menu's music
                                        backgroundmusic_ingame_stop(ingamebackground, &id2);
                                        backgroundmusic_Menu_play(menubackground, &id);
                                    } else {
                                        number = nb_games_selection(event.keyboard.keycode);
                                        if (number != 200) {
                                            selected_number = number;
                                            //afficher le chiffre
                                            al_draw_scaled_bitmap(number_bitmap, 0, 0, 1920, 1080, 0, 0,
                                                                  (float) configuration.width,
                                                                  (float) configuration.height, 0);
                                            al_draw_textf(selection_number, al_map_rgb(49, 15, 48),
                                                          configuration.width / 2.214, configuration.height / 2.147,
                                                          ALLEGRO_ALIGN_CENTER, "%d", selected_number);
                                            if (selected_number == 0) {
                                                al_draw_textf(number_red_message, al_map_rgba(145, 0, 0, 70),
                                                              configuration.width / 2, configuration.height / 1.576,
                                                              ALLEGRO_ALIGN_CENTER,
                                                              "YOU WILL AUTOMATICALLY GET 3 TURNS IF YOU SELECT 0 TURNS");
                                            }
                                            al_flip_display();
                                        }
                                    }
                                    break;
                                case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                                    if ((event.mouse.x > (configuration.width / 2.313) &&
                                         event.mouse.x<(configuration.width / 1.765)
                                                       && event.mouse.y>(configuration.height / 1.222) &&
                                         event.mouse.y < (configuration.height / 1.07))) {
                                        if (0 >= selected_number || selected_number >= 10) {
                                            nb_games = NB_GAMES;
                                            exit_selection_game = true;
                                        } else {
                                            nb_games = selected_number;
                                            exit_selection_game = true;
                                        }
                                    }
                                    break;
                                default:
                                    break;
                            }
                        } while (!exit_selection_game);
                        exit_selection_game = false;
                    }
                    if (done) {
                        done = false;
                        al_draw_scaled_bitmap(configuration.main_screen, 0, 0, 1920, 1080, 0, 0,
                                              (float) configuration.width,
                                              (float) configuration.height,
                                              0);
                        al_flip_display();
                        break;
                    }
                    for (; w < nb_games; w++) {//Nb games
                        // We save all these drawings ******************************************************************
                        if (loading_game == false) {
                            games_counter = w;
                            no_card_left = 0;
                            nb_tour = 0;
                            ff = 0;
                            for (z = 0; z < selection_players; z++) {
                                player_tab_infos[z].board_damage = false;
                                player_tab_infos[z].reactor_damage = false;
                                player_tab_infos[z].suit_damage = false;
                            }
                            Bag(calling, pick, occurrence_point);
                            function_in_game(selection_players, player_tab_infos); // attribution du rôle
                            reset_current_card(&current_card);
                            init_board(&game_board, selection_players);
                            load_board_images(&game_board);
                            modifyingphysicalsize = 0;

                            if (backmenu == true) {
                                break;
                            }
                            for (z = 0; z < selection_players; z++) {
                                player_hand_initialization(&player_tab_infos[z], &modifyingphysicalsize, pick);
                                give_image_id(&player_tab_infos[z], occurrence_point, configuration, table);
                            }
                        }
                        Bag(calling, pick, occurrence_point);
                        init_pool_pick(&pool_pick, configuration, &modifyingphysicalsize, pick, occurrence_point,
                                       table);
                        loading_game = false;
                        // We save all these drawings ******************************************************************
                        al_set_target_bitmap(helpFPS);
                        draw_board(&game_board, configuration);
                        display_players_onboard(configuration, player_tab_infos, selection_players, players_nickname);
                        draw_pool_pick(pool_pick, configuration);
                        link_card_number(&game_board);
                        //**********************************************************************************************
                        al_save_bitmap("../images/Card_board/helpFPS.jpg", helpFPS);
                        al_set_target_bitmap(al_get_backbuffer(display));
                        draw_round_announcement(&game_board, configuration, player_tab_infos, pool_pick, w,
                                                selection_players, players_nickname);

                        while (!endgame) {
                            for (; v < selection_players && endgame == false; v++) {

                                draw_turn_announcement(configuration, player_tab_infos, v,
                                                       selection_players, players_nickname, nb_tour,
                                                       modifyingphysicalsize);
                                al_set_target_bitmap(helpFPS);
                                draw_board(&game_board, configuration);
                                display_players_onboard(configuration, player_tab_infos,
                                                        selection_players, players_nickname);
                                if (modifyingphysicalsize <= 69) {
                                    draw_pool_pick(pool_pick, configuration);
                                }
                                show_function(v, selection_players, player_tab_infos, configuration, players_nickname);
                                al_save_bitmap("../images/Card_board/helpFPS.jpg", helpFPS);
                                al_set_target_bitmap(helpFPS2);
                                al_draw_bitmap(helpFPS, 0, 0, 0);
                                draw_player_hand(configuration, &player_tab_infos[v]);
                                draw_debuff(&player_tab_infos[v], configuration);
                                al_save_bitmap("../images/Card_board/helpFPS2.jpg", helpFPS2);
                                al_set_target_bitmap(al_get_backbuffer(display));
                                al_draw_bitmap(helpFPS2, 0, 0, 0);
                                al_flip_display();
                                do {
                                    if (load == true) { break; }
                                    al_wait_for_event(queue, &event);
                                    switch (event.type) {
                                        case ALLEGRO_EVENT_DISPLAY_CLOSE:
                                            done = true;
                                            end = true;
                                            load = true;
                                            break;
                                        case ALLEGRO_EVENT_KEY_DOWN:
                                            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                                                done = true;
                                                load = true;
                                            }
                                            break;
                                        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN: {
                                            if (current_card.front_image == NULL) {
                                                select_card(event.mouse.x, event.mouse.y, configuration,
                                                            &player_tab_infos[v],
                                                            &current_card,
                                                            &selection);
                                                if (check_placement_on_pool_pick(configuration, event.mouse.x,
                                                                                 event.mouse.y) == 1 &&
                                                    dumb_card == 0) {
                                                    init_current_card(&current_card, pool_pick);
                                                    selection.hand_number = 10;
                                                }
                                            }
                                            if (current_card.front_image != NULL) {
                                                if (selection.hand_number != 10) {
                                                    player_tab_infos[v].hand[selection.hand_number].front_image = NULL;
                                                }
                                                shift = 1;
                                                Xshift = event.mouse.x - current_card.x;
                                                Yshift = event.mouse.y - current_card.y;
                                            }
                                            al_set_target_bitmap(helpFPS2);
                                            al_draw_bitmap(helpFPS, 0, 0, 0);
                                            draw_player_hand(configuration, &player_tab_infos[v]);
                                            draw_debuff(&player_tab_infos[v], configuration);
                                            al_save_bitmap("../images/Card_board/helpFPS2.jpg", helpFPS2);
                                            al_set_target_bitmap(al_get_backbuffer(display));
                                        }
                                            break;
                                        case ALLEGRO_EVENT_MOUSE_BUTTON_UP: {
                                            if (event.mouse.x > configuration.width / 1.10 &&
                                                event.mouse.x < configuration.width / 1.03 &&
                                                event.mouse.y > configuration.height / 11.5 &&
                                                event.mouse.y < configuration.height / 5.12) {
                                                al_draw_scaled_bitmap(surrender, 0, 0, 1920, 1080, 0, 0,
                                                                      (float) configuration.width,
                                                                      (float) configuration.height,
                                                                      0);
                                                al_flip_display();
                                                while (fate_selection != true) {
                                                    al_wait_for_event(queue, &event);
                                                    switch (event.type) {
                                                        case ALLEGRO_EVENT_MOUSE_BUTTON_UP: {
                                                            if (event.mouse.x > configuration.width / 4.2 &&
                                                                event.mouse.x < configuration.width / 3 &&
                                                                event.mouse.y > configuration.height / 1.62 &&
                                                                event.mouse.y < configuration.height / 1.42) {
                                                                fate_selection = true;
                                                                endturn = true;
                                                                ff++;
                                                            } else if (event.mouse.x > configuration.width / 1.52 &&
                                                                       event.mouse.x < configuration.width / 1.35 &&
                                                                       event.mouse.y > configuration.height / 1.62 &&
                                                                       event.mouse.y < configuration.height / 1.42) {
                                                                fate_selection = true;
                                                                al_set_target_bitmap(helpFPS2);
                                                                al_draw_bitmap(helpFPS, 0, 0, 0);
                                                                draw_player_hand(configuration, &player_tab_infos[v]);
                                                                draw_debuff(&player_tab_infos[v], configuration);
                                                                al_save_bitmap("../images/Card_board/helpFPS2.jpg",
                                                                               helpFPS2);
                                                                al_set_target_bitmap(al_get_backbuffer(display));
                                                                al_flip_display();
                                                            }
                                                        }
                                                            break;
                                                    }
                                                }
                                                fate_selection = false;
                                            }

                                            if (current_card.front_image != NULL) {
                                                shift = Xshift = Yshift = 0;
                                                for (int o = 0; o < selection_players; o++) {
                                                    if (placement_on_players(&player_tab_infos[o], &current_card,
                                                                             configuration, event.mouse.x,
                                                                             event.mouse.y, o, v) == 1) {
                                                        already_played_action_card = true;
                                                        reset_current_card(&current_card);
                                                        new_card(&player_tab_infos[v], occurrence_point, calling,
                                                                 selection.hand_number, &modifyingphysicalsize,
                                                                 pick);
                                                        if (modifyingphysicalsize >= 69) {
                                                            no_card_left++;
                                                        }
                                                        al_set_target_bitmap(helpFPS2);
                                                        al_draw_bitmap(helpFPS, 0, 0, 0);
                                                        draw_player_hand(configuration, &player_tab_infos[v]);
                                                        draw_debuff(&player_tab_infos[v], configuration);
                                                        al_save_bitmap("../images/Card_board/helpFPS2.jpg", helpFPS2);
                                                        al_set_target_bitmap(al_get_backbuffer(display));
                                                        al_flip_display();
                                                    }
                                                }

                                                for (int j = 0; j < MAX_DECK; j++) {
                                                    if (current_card.back_image != NULL &&
                                                        check_placement_on_deck(&player_tab_infos[v], j, configuration,
                                                                                event.mouse.x,
                                                                                event.mouse.y) == 1 && dumb_card == 0 &&
                                                        modifyingphysicalsize <= 69) {
                                                        player_tab_infos[v].hand[j].front_image = current_card.back_image;
                                                        player_tab_infos[v].hand[j].type = current_card.type;
                                                        player_tab_infos[v].hand[j].shift_id = current_card.shift_id;
                                                        reset_current_card(&current_card);
                                                        init_pool_pick(&pool_pick, configuration,
                                                                       &modifyingphysicalsize,
                                                                       pick,
                                                                       occurrence_point, table);
                                                        al_set_target_bitmap(helpFPS2);
                                                        al_draw_bitmap(helpFPS, 0, 0, 0);
                                                        draw_player_hand(configuration, &player_tab_infos[v]);
                                                        draw_debuff(&player_tab_infos[v], configuration);
                                                        al_save_bitmap("../images/Card_board/helpFPS2.jpg", helpFPS2);
                                                        al_set_target_bitmap(al_get_backbuffer(display));
                                                        al_draw_bitmap(helpFPS2, 0, 0, 0);
                                                        al_flip_display();
                                                        endturn = true;
                                                        ff = 0;
                                                    }
                                                }

                                                for (int k = 0; k < 11; k++) {
                                                    for (int j = 0; j < MAX_DECK; j++) {
                                                        if (game_board.tab[k][j].selected == true &&
                                                            current_card.back_image == NULL && dumb_card == 0) {
                                                            if (player_tab_infos[v].board_damage == false &&
                                                                player_tab_infos[v].reactor_damage == false &&
                                                                player_tab_infos[v].suit_damage == false) {
                                                                if (check_placement_on_board(&game_board, &current_card,
                                                                                             k,
                                                                                             j) == 1) {
                                                                    if (current_card.type == 'J') {
                                                                        game_board.tab[k][j].buff_image = game_board.tab[k][j].front_image;
                                                                        game_board.tab[k][j].front_image = game_board.tab[k][j].back_image;
                                                                        player_tab_infos[v].hand[selection.hand_number].front_image = NULL;
                                                                        player_tab_infos[v].hand[selection.hand_number].type = 0;
                                                                        player_tab_infos[v].hand[selection.hand_number].shift_id = 0;
                                                                        selection.c = 0;
                                                                        selection.r = 0;
                                                                    } else if (current_card.type == 'K') {
                                                                        game_board.tab[k][j].front_image = current_card.front_image;
                                                                        game_board.tab[k][j].type = current_card.type;
                                                                        game_board.tab[k][j].shift_id = current_card.shift_id;
                                                                        player_tab_infos[v].hand[selection.hand_number].front_image = NULL;
                                                                        player_tab_infos[v].hand[selection.hand_number].type = 0;
                                                                        player_tab_infos[v].hand[selection.hand_number].shift_id = 0;
                                                                        selection.c = 0;
                                                                        selection.r = 0;
                                                                        endturn = true;
                                                                    } else {
                                                                        game_board.tab[k][j].front_image = current_card.front_image;
                                                                        game_board.tab[k][j].type = current_card.type;
                                                                        game_board.tab[k][j].shift_id = current_card.shift_id;
                                                                        selection.c = 0;
                                                                        selection.r = 0;
                                                                        if (modifyingphysicalsize <= 69) {
                                                                            new_card(&player_tab_infos[v],
                                                                                     occurrence_point,
                                                                                     calling,
                                                                                     selection.hand_number,
                                                                                     &modifyingphysicalsize,
                                                                                     pick);
                                                                        }
                                                                        ff = 0;
                                                                        endturn = true;
                                                                    }
                                                                    if (card_next_to_end(&game_board, k, j,
                                                                                         &detect_end_y,
                                                                                         &current_card) ==
                                                                        1 && current_card.type != 'J' &&
                                                                        current_card.type != 'K') {
                                                                        value_to_score(&game_board, player_tab_infos, v,
                                                                                       detect_end_y, configuration,
                                                                                       selection_players);
                                                                        al_flip_display();
                                                                        al_rest(1);
                                                                        show_function_end_game(selection_players,
                                                                                               player_tab_infos,
                                                                                               configuration,
                                                                                               timer_revelation,
                                                                                               queue_rev,
                                                                                               rev_3p, rev_4p, rev_5p);
                                                                        fix = true;
                                                                        endgame = true;
                                                                    }
                                                                    reset_current_card(&current_card);
                                                                    al_set_target_bitmap(helpFPS);
                                                                    draw_board(&game_board, configuration);
                                                                    show_function(v, selection_players,
                                                                                  player_tab_infos,
                                                                                  configuration, players_nickname);
                                                                    display_players_onboard(configuration,
                                                                                            player_tab_infos,
                                                                                            selection_players,
                                                                                            players_nickname);
                                                                    if (modifyingphysicalsize <= 69) {
                                                                        draw_pool_pick(pool_pick, configuration);
                                                                    }
                                                                    if (modifyingphysicalsize >= 69) {
                                                                        no_card_left++;
                                                                    }
                                                                    //**************************************************************************************************
                                                                    show_function(v, selection_players,
                                                                                  player_tab_infos,
                                                                                  configuration, players_nickname);
                                                                    al_save_bitmap("../images/Card_board/helpFPS.jpg",
                                                                                   helpFPS);
                                                                    al_set_target_bitmap(al_get_backbuffer(display));
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                selection.c = 0;
                                                selection.r = 0;
                                                if (selection.hand_number != 10 && endturn == false) {
                                                    player_tab_infos[v].hand[selection.hand_number].front_image = current_card.front_image;
                                                    player_tab_infos[v].hand[selection.hand_number].type = current_card.type;
                                                    player_tab_infos[v].hand[selection.hand_number].shift_id = current_card.shift_id;
                                                }

                                                if (already_played_action_card == false) {
                                                    if (check_placement_on_void(configuration, event.mouse.x,
                                                                                event.mouse.y) == 1) {
                                                        reset_current_card(&current_card);
                                                        player_tab_infos[v].hand[selection.hand_number].front_image = NULL;
                                                        player_tab_infos[v].hand[selection.hand_number].type = 0;
                                                        player_tab_infos[v].hand[selection.hand_number].shift_id = 0;
                                                        if (modifyingphysicalsize <= 69) {
                                                            new_card(&player_tab_infos[v], occurrence_point, calling,
                                                                     selection.hand_number, &modifyingphysicalsize,
                                                                     pick);
                                                        }
                                                        dumb_card++;
                                                        if (dumb_card == 3) {
                                                            if (modifyingphysicalsize >= 69) {
                                                                no_card_left++;
                                                            }
                                                            ff = 0;
                                                            endturn = true;
                                                        }
                                                    }
                                                }
                                                reset_current_card(&current_card);
                                                al_set_target_bitmap(helpFPS2);
                                                al_draw_bitmap(helpFPS, 0, 0, 0);
                                                draw_player_hand(configuration, &player_tab_infos[v]);
                                                draw_debuff(&player_tab_infos[v], configuration);
                                                al_save_bitmap("../images/Card_board/helpFPS2.jpg", helpFPS2);
                                                al_set_target_bitmap(al_get_backbuffer(display));
                                                al_draw_bitmap(helpFPS2, 0, 0, 0);
                                                al_flip_display();
                                                if (fix) {
                                                    if (w != NB_GAMES) {
                                                        al_draw_scaled_bitmap(loading, 0, 0, 1920, 1080, 0, 0,
                                                                              (float) configuration.width,
                                                                              (float) configuration.height,
                                                                              0);
                                                        al_flip_display();
                                                        al_rest(1);
                                                    } else {
                                                        draw_players_ranking(selection_players, configuration);
                                                    }
                                                }
                                                fix = false;
                                                al_flip_display();
                                            }
                                            break;
                                        }
                                        case ALLEGRO_EVENT_MOUSE_AXES: {
                                            if (current_card.front_image != NULL) {
                                                check_selected_tile(event.mouse.x, event.mouse.y, &game_board,
                                                                    configuration,
                                                                    &selection, player_tab_infos, selection_players,
                                                                    current_card);
                                                if (shift) {
                                                    current_card.x = event.mouse.x - Xshift;
                                                    current_card.y = event.mouse.y - Yshift;
                                                    modification = true;
                                                }
                                            }
                                            break;
                                        }
                                        case ALLEGRO_EVENT_TIMER: {
                                            if (current_card.front_image != NULL) {
                                                update_card_position(&current_card, pressed_keys, &modification,
                                                                     configuration);
                                                replace_if_outside_board(&current_card, configuration, event.mouse.x,
                                                                         event.mouse.y);
                                                if (modification == true && al_is_event_queue_empty(queue)) {
                                                    al_draw_bitmap(helpFPS2, 0, 0, 0);
                                                    highlight_tile(selection, configuration);
                                                    draw_card(&current_card, configuration);
                                                    al_flip_display();
                                                    modification = false;
                                                }
                                            }
                                            break;
                                        }
                                        default:
                                            break;
                                    }
                                } while (!endturn);
                                if (no_card_left == selection_players) {
                                    for (int i = 0; i < selection_players; i++) {
                                        if (player_tab_infos[i].gamer_id == 'S') {
                                            player_tab_infos[i].score += 100;
                                        }
                                    }
                                    show_function_end_game(selection_players,
                                                           player_tab_infos,
                                                           configuration,
                                                           timer_revelation, queue_rev,
                                                           rev_3p, rev_4p, rev_5p);
                                    endgame = true;
                                }
                                if (ff == selection_players) {
                                    for (int i = 0; i < selection_players; i++) {
                                        if (player_tab_infos[i].gamer_id == 'S') {
                                            player_tab_infos[i].score += 100;
                                        }
                                    }
                                    show_function_end_game(selection_players,
                                                           player_tab_infos,
                                                           configuration,
                                                           timer_revelation, queue_rev,
                                                           rev_3p, rev_4p, rev_5p);
                                    endgame = true;
                                }
                                for (int n = 1; n < 6; n += 2) {
                                    if (game_board.tab[9][n].buff_image != NULL) {
                                        game_board.tab[9][n].front_image = game_board.tab[9][n].buff_image;
                                    }
                                    game_board.tab[9][n].buff_image = NULL;
                                }
                                if (load == true) { break; }
                                selection.hand_number = 0;
                                dumb_card = 0;
                                endturn = false;
                                already_played_action_card = false;
                                if (v == selection_players - 1) {
                                    round_counter = 0;
                                    v = -1;
                                } else {
                                    round_counter++;
                                }
                            }
                            if (load == true) {
                                break;
                            } else {
                                nb_tour++;
                            }
                        }
                        if (load == true) { break; }
                        endgame = false;
                    }
                    if (load == true) {
                        load = false;
                        saveDataChar = fopen("../saveDataChar.txt", "w");
                        //save nb players
                        fprintf(saveDataChar, "%d\n", selection_players);
                        //save game board
                        for (int s = 0; s < ROWS - 1; s++) {
                            for (int w = 0; w < COLUMNS - 1; w++) {
                                save_board_data(game_board, &saveDataChar, w, s);
                            }
                            fprintf(saveDataChar, "\n");
                        }
                        //save players' skin & debuff
                        int save;
                        for (int n = 0; n < selection_players; n++) {
                            save = player_tab_infos[n].skins;
                            fprintf(saveDataChar, "%d\n", save);
                            save = player_tab_infos[n].reactor_damage;
                            fprintf(saveDataChar, "%d\n", save);
                            save = player_tab_infos[n].board_damage;
                            fprintf(saveDataChar, "%d\n", save);
                            save = player_tab_infos[n].suit_damage;
                            fprintf(saveDataChar, "%d\n", save);

                        }
                        //save players' nickname
                        for (int s = 0; s < selection_players; s++) {
                            fprintf(saveDataChar, "%s", player_tab_infos[s].name);
                            fprintf(saveDataChar, "\n");
                        }
                        //save players' hand/deck
                        for (int s = 0; s < selection_players; s++) {
                            for (int w = 0; w < 6; w++) {
                                fprintf(saveDataChar, "%c", player_tab_infos[s].hand[w].type);
                            }
                            fprintf(saveDataChar, "\n");
                        }
                        //save players' score
                        for (int n = 0; n < selection_players; n++) {
                            save = player_tab_infos[n].score;
                            fprintf(saveDataChar, "%d\n", save);
                        }
                        //save players' role
                        for (int s = 0; s < selection_players; s++) {
                            fprintf(saveDataChar, "%c", player_tab_infos[s].gamer_id);
                            fprintf(saveDataChar, "\n");
                        }
                        //save nb games
                        fprintf(saveDataChar, "%d\n", nb_games);
                        //save game counter
                        fprintf(saveDataChar, "%d\n", games_counter);
                        //save round counter
                        fprintf(saveDataChar, "%d\n", round_counter);
                        /*
                        //save the game deck
                        fprintf(saveDataChar, "%s\n", calling);
                        //save the physical size of the game deck we can use
                        fprintf(saveDataChar, "%d\n", modifyingphysicalsize);*/

                        fclose(saveDataChar);

                    } else {
                        ranking(selection_players, player_tab_infos, configuration, timer_revelation,
                                queue_rev, gold_med, silver_med, bronze_med);
                    }
                    done = false;
                    backgroundmusic_ingame_stop(ingamebackground, &id2);
                    backgroundmusic_Menu_play(menubackground, &id);
                    al_draw_scaled_bitmap(configuration.main_screen, 0, 0, 1920, 1080, 0, 0,
                                          (float) configuration.width,
                                          (float) configuration.height,
                                          0);
                    al_flip_display();
                }
                //QUIT
                if (event.mouse.x > (configuration.width / 2.22) &&
                    event.mouse.x<(configuration.width / 1.82) && event.mouse.y>(configuration.height / 1.22) &&
                    event.mouse.y < (configuration.height / 1.15)) { end = 1; }


                //OPTION
                if (event.mouse.x > (configuration.width / 3.25) &&
                    event.mouse.x<(configuration.width / 1.446) && event.mouse.y>(configuration.height / 1.6) &&
                    event.mouse.y < (configuration.height / 1.4)) {
                    display_option_screen(&configuration, &old_configuration);
                    do {
                        al_wait_for_event(queue, &event);

                        switch (event.type) {
                            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                                done = true;
                                end = true;
                                break;
                            case ALLEGRO_EVENT_KEY_DOWN:
                                if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                                    done = true;
                                }
                                break;
                            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:

                                //CHANGE SCREEN SIZE
                                if (event.mouse.x > (old_configuration.width / 2.6) &&
                                    event.mouse.x<(old_configuration.width / 1.63) && event.mouse.y>(
                                            old_configuration.height / 3.98) &&
                                    event.mouse.y < (old_configuration.height / 3.04)) {
                                    change_screen_size(&configuration);
                                    change_images_scale(&current_card, configuration);
                                    display_option_screen(&configuration, &old_configuration);
                                    configuration.change = true;
                                }

                                //FULLSCREEN MODE
                                if (event.mouse.x > (old_configuration.width / 2.6) &&
                                    event.mouse.x<(old_configuration.width / 1.3) && event.mouse.y>(
                                            old_configuration.height / 2.5) &&
                                    event.mouse.y < (old_configuration.height / 2.04)) {
                                    change_screen_mode(&configuration);
                                    change_images_scale(&current_card, configuration);
                                    display_option_screen(&configuration, &old_configuration);
                                    configuration.change = true;
                                }

                                //FRAME RATE
                                if (event.mouse.x > (old_configuration.width / 2.6) &&
                                    event.mouse.x<(old_configuration.width / 1.3) && event.mouse.y>(
                                            old_configuration.height / 1.78) &&
                                    event.mouse.y < (old_configuration.height / 1.53)) {
                                    switch (configuration.frame_rate) {
                                        case 30:
                                            configuration.frame_rate = 50;
                                            break;
                                        case 50:
                                            configuration.frame_rate = 60;
                                            break;
                                        case 60:
                                            configuration.frame_rate = 30;
                                            break;
                                        default:
                                            configuration.frame_rate = 60;
                                            break;
                                    }
                                    display_option_screen(&configuration, &old_configuration);
                                }

                                //DONE
                                if (event.mouse.x > (old_configuration.width / 2.31) &&
                                    event.mouse.x<(old_configuration.width / 1.76) && event.mouse.y>(
                                            old_configuration.height / 1.22) &&
                                    event.mouse.y < (old_configuration.height / 1.07)) { done = true; }
                                break;
                            default:
                                break;
                        }
                    } while (!done);
                    if (configuration.change == true) {
                        al_resize_display(display, configuration.width, configuration.height);
                        if (configuration.screen_mode == 1) {
                            al_set_new_display_flags(ALLEGRO_FULLSCREEN);
                            al_destroy_display(display);
                            al_create_display(configuration.width, configuration.height);
                        }
                        al_set_window_position(display, 0, 0);
                    }
                    al_draw_scaled_bitmap(configuration.main_screen, 0, 0, 1920, 1080, 0, 0,
                                          (float) configuration.width,
                                          (float) configuration.height, 0);
                    al_flip_display();
                    old_configuration.height = configuration.height;
                    old_configuration.width = configuration.width;
                    old_configuration.font = configuration.font;
                    configuration.change = false;
                    done = false;
                }
                //RULES GAME
                if (event.mouse.x > (configuration.width / 2.8) &&
                    event.mouse.x<(configuration.width / 2.09) && event.mouse.y>(configuration.height / 1.35) &&
                    event.mouse.y < (configuration.height / 1.24)) {
                    while (!exitrule) {
                        if (first_time_on_akali ==
                            0) {//easteregg from League of Legend for playing only 1 time the bitmap
                            switch (configuration.height) {
                                case 1080:
                                    al_draw_bitmap(rules_high, 0, 0, 0);
                                    al_flip_display();
                                    break;
                                case 720:
                                    al_draw_bitmap(rules_medium, 0, 0, 0);
                                    al_flip_display();
                                    break;
                                case 480:
                                    al_draw_bitmap(rules_low, 0, 0, 0);
                                    al_flip_display();
                                    break;
                                default:
                                    break;
                            }
                            first_time_on_akali = 1;
                        }
                        al_wait_for_event(queue, &event);
                        switch (event.type) {
                            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                                exitrule = true;
                                end = true;
                                break;
                            case ALLEGRO_EVENT_KEY_DOWN:
                                if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                                    exitrule = true;
                                }
                                break;
                            case ALLEGRO_EVENT_MOUSE_AXES:
                                Z = event.mouse.z;
                                if (Z != OldZ) {//Check Z axis position
                                    scroll(&Z, OldZ, configuration, rules_low, rules_medium, rules_high);
                                    OldZ = Z;
                                }
                                break;
                            default:
                                break;
                        }
                    }
                    al_draw_scaled_bitmap(configuration.main_screen, 0, 0, 1920, 1080, 0, 0,
                                          (float) configuration.width,
                                          (float) configuration.height, 0);
                    al_flip_display();
                    exitrule = false;
                    first_time_on_akali = 0;
                    al_set_mouse_z(0);
                }//END RULE

                //CREDIT
                if (event.mouse.x > (configuration.width / 1.92) &&
                    event.mouse.x<(configuration.width / 1.56) && event.mouse.y>(configuration.height / 1.35) &&
                    event.mouse.y < (configuration.height / 1.24)) {
                    int easter_egg = 0;
                    while (!exitcredit) {
                        if (first_time_on_yasuo ==
                            0) {//easteregg from League of Legend used for playing only 1 time the bitmap
                            al_draw_scaled_bitmap(credit, 0, 0, 6000, 3000, 0, 0, (float) configuration.width,
                                                  (float) configuration.height, 0);
                            al_flip_display();
                            first_time_on_yasuo = 1;
                        }
                        al_wait_for_event(queue, &event);
                        switch (event.type) {
                            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                                exitcredit = true;
                                end = true;
                                break;
                            case ALLEGRO_EVENT_KEY_DOWN:
                                if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) { exitcredit = true; }
                                break;
                            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN :
                                easter_egg++;
                                if (easter_egg == 3) {
                                    Bingus(configuration);
                                }
                                break;
                            default:
                                break;
                        }
                    }
                    al_draw_scaled_bitmap(configuration.main_screen, 0, 0, 1920, 1080, 0, 0,
                                          (float) configuration.width,
                                          (float) configuration.height, 0);
                    al_flip_display();
                    exitcredit = false;
                    first_time_on_yasuo = 0;
                }//END CREDIT
            default:
                break;
        }
    } while (!end);

    //Stop music (safety)
    backgroundmusic_Menu_stop(menubackground, &id);
    backgroundmusic_ingame_stop(ingamebackground, &id2);

    //destroy music
    al_destroy_sample(menubackground);
    al_destroy_sample(ingamebackground);


    al_destroy_event_queue(queue);
    al_destroy_event_queue(queue_rev);
    al_destroy_display(display);

    if (timer != NULL && timer_revelation != NULL) {
        al_destroy_timer(timer);
        al_destroy_timer(timer_revelation);
    }

    al_destroy_bitmap(rev_3p);
    al_destroy_bitmap(rev_4p);
    al_destroy_bitmap(rev_5p);
    al_destroy_bitmap(role_revelation);
    al_destroy_bitmap(gold_med);
    al_destroy_bitmap(silver_med);
    al_destroy_bitmap(bronze_med);
    al_destroy_bitmap(loading);

    //destroy bitmap for menu
    al_destroy_bitmap(configuration.main_screen);
    al_destroy_bitmap(configuration.option_screen);

    //destroy bitmap for rules
    al_destroy_bitmap(rules_low);
    al_destroy_bitmap(rules_medium);
    al_destroy_bitmap(rules_high);


    //destroy bitmap for credit
    al_destroy_bitmap(credit);

    //destroy bitmap for selection
    al_destroy_bitmap(players_nb_minimum);
    al_destroy_bitmap(players_nb_medium);
    al_destroy_bitmap(players_nb_high);
    al_destroy_bitmap(player_selection);
    al_destroy_bitmap(number_bitmap);

    if (player_number != NULL) {
        al_destroy_font(player_number);
    }

    //In game
    al_destroy_bitmap(helpFPS);
    al_destroy_bitmap(helpFPS2);
    al_destroy_bitmap(surrender);

    if (tab_characters[0] != NULL) {
        for (int i = 0; i < MAX_CHARACTERS; i++) {
            al_destroy_bitmap(tab_characters[i]);
        }
    }

    //destroy bitmap moove
    if (!backmenu) {
        destroyBitmap(occurrence_point, table);
    }

    //destroy for font
    al_destroy_font(fontRoboto40);
    al_destroy_font(agency);
    if (players_nickname != NULL) {
        al_destroy_font(players_nickname);
    }
    if (selection_number != NULL) {
        al_destroy_font(selection_number);
    }
    saveDataChar = NULL;
    return 0;
}