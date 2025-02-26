//
// Created by Hugo on 15/03/2021.
//

#include "title_screen.h"
#include "../structures/structures.h"

void error_message(const char *txt) {
    printf("ERROR : %s", txt);
    exit(EXIT_FAILURE);
}

//SWITCH BETWEEN FULLSCREEN AND WINDOWED
void change_screen_mode(config* configuration) {

    switch (configuration->screen_mode)
    {
        case 0: al_set_new_display_flags(ALLEGRO_FULLSCREEN); configuration->screen_mode = 1, configuration->font = al_load_ttf_font("../fonts/agency-fb/agency-fb-bold.ttf", 60, 0), configuration->width = 1920, configuration->height = 1080;
            break;
        case 1: al_set_new_display_flags(ALLEGRO_WINDOWED); configuration->screen_mode = 0;
            break;
    }
}

//SWITCH BETWEEN 480p, 720p AND 1080p
void change_screen_size(config* configuration) {

    switch ( (configuration)->height )
    {
        case 480: configuration->width = 1280, (configuration)->height = 720, configuration->font = al_load_ttf_font("../fonts/agency-fb/agency-fb-bold.ttf", 50, 0); ;
            break;
        case 720: configuration->width = 1920, (configuration)->height = 1080, configuration->font = al_load_ttf_font("../fonts/agency-fb/agency-fb-bold.ttf", 60, 0);;
            break;
        case 1080: al_set_new_display_flags(ALLEGRO_WINDOWED); configuration->screen_mode = 0, configuration->font = al_load_ttf_font("../fonts/agency-fb/agency-fb-bold.ttf", 30, 0), configuration->width = 854, configuration->height = 480;
            break;
        default: configuration->width = 1280, configuration->height = 720;
            break;
    }
}

void change_images_scale(card* current_card,config configuration) {
    current_card->height = configuration.height/10.38;
    current_card->width = configuration.width/13.52;
}

void init_configuration(config* configuration, config* old_configuration) {
    configuration->width = 1280; configuration->height = 720; configuration->screen_mode = 0;
    configuration->main_screen = al_load_bitmap("../images/Title_screen/main_screen.jpg");
    configuration->option_screen = al_load_bitmap("../images/Title_screen/option_screen.jpg");
    configuration->font = al_load_ttf_font("../fonts/agency-fb/agency-fb-bold.ttf", 45, 0);
    configuration->frame_rate = 60;

    old_configuration->width = configuration->width;
    old_configuration->height = configuration->height;
    old_configuration->font = configuration->font;

    assert(configuration->main_screen);
    assert(configuration->option_screen);
    assert(configuration->font);
}

void display_option_screen(config* configuration, config* old_configuration) {
    al_draw_scaled_bitmap(configuration->option_screen, 0, 0, 1920, 1080, 0, 0, old_configuration->width,
                          old_configuration->height, 0);
    al_draw_textf(old_configuration->font, al_map_rgb(49, 15, 48), old_configuration->width / 1.988,
                  old_configuration->height / 3.25 - al_get_font_ascent(old_configuration->font), ALLEGRO_ALIGN_CENTER,
                  ("%dx%d"), configuration->width, configuration->height );
    al_draw_textf(old_configuration->font, al_map_rgb(49, 15, 48), old_configuration->width / 1.988,
                  old_configuration->height / 1.58 - al_get_font_ascent(old_configuration->font), ALLEGRO_ALIGN_CENTER,
                  ("%d FPS"), configuration->frame_rate );
    if (configuration->screen_mode == 0) {
        al_draw_textf(old_configuration->font, al_map_rgb(49, 15, 48), old_configuration->width / 1.988,
                      old_configuration->height / 2.15 - al_get_font_ascent(old_configuration->font), ALLEGRO_ALIGN_CENTER,
                      ("OFF"));
    }else {
        al_draw_textf(old_configuration->font, al_map_rgb(49, 15, 48), old_configuration->width / 1.988,
                      old_configuration->height / 2.15 - al_get_font_ascent(old_configuration->font), ALLEGRO_ALIGN_CENTER,
                      ("ON"));
    }
    al_flip_display();
}

void Bingus(config configuration) {
    ALLEGRO_BITMAP *bingus = al_load_bitmap("../images/Credit/BINGUS.png");
    assert(bingus != NULL);
    float rand_size = 0;
        for (int j = 0; j < 80; j++) {
            rand_size = ((rand() % (3 - 1) / 1.8) + 0.2);
            al_draw_scaled_rotated_bitmap(bingus, 227, 227, rand() % (configuration.width),
                                          rand() % (configuration.height),
                                          (float) rand_size, (float) rand_size,
                                          rand() % 360, 0);
            al_draw_scaled_rotated_bitmap(bingus, 227, 227, rand() % (configuration.width),
                                          rand() % (configuration.height),
                                          (float) rand_size, (float) rand_size,
                                          rand() % 360, 0);
            al_flip_display();
        }
    al_destroy_bitmap(bingus);
};