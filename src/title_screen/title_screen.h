//
// Created by Hugo on 15/03/2021.
//
#ifndef SABOTEUR_X_TITLE_SCREEN_H
#define SABOTEUR_X_TITLE_SCREEN_H

#include "../structures/structures.h"

void change_screen_mode(config *configuration);

void error_message(const char *txt);

void change_screen_size(config *configuration);

void change_images_scale(card *current_card, config configuration);

void init_configuration(config *configuration, config *old_configuration);

void display_option_screen(config *configuration, config *old_configuration);

void Bingus();
#endif //SABOTEUR_X_TITLE_SCREEN_H
