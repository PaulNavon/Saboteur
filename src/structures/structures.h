#ifndef PROJET_SABOTEUR_SABOTEUR_GROUPE_X_STRUCTURES_H
#define PROJET_SABOTEUR_SABOTEUR_GROUPE_X_STRUCTURES_H

#define ROWS 8
#define COLUMNS 11
#define HAND 6
#define ACTION_CARD 70
#define LIGNES 25
#define DEBUT_PIOCHE 1
#define FIN_PIOCHE 70
#define MAX_DECK 7
#define MAX_PSEUDO 21
#define MAX_CHARACTERS 5
#define MAX_NUMBERS 6
#define MIN_NUMBERS 1
#define BLACK al_map_rgb(0,0,0)
#define NB_GAMES 3
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

enum {
    UP, DOWN, LEFT, RIGHT, KEYS_COUNT
};

typedef struct {
    int width;
    int height;
    int screen_mode;
    int frame_rate;
    int change;
    ALLEGRO_FONT *font;
    ALLEGRO_BITMAP *main_screen;
    ALLEGRO_BITMAP *option_screen;
} config;

typedef struct {
    int x, y;
    double xratio, yratio;
    int width, height;
    int quantity;
    char type;
    int value;
    bool selected;
    char id;
    char* shift_id;
    char deck[MAX_DECK];
    ALLEGRO_BITMAP *back_image;
    ALLEGRO_BITMAP *buff_image;
    ALLEGRO_BITMAP *front_image;
    ALLEGRO_BITMAP *back_image_big;
} card;

typedef struct {
    card *hand;
    char name[MAX_PSEUDO];
    bool reactor_damage;
    bool board_damage;
    bool suit_damage;
    double ytopratio, ybotratio;
    int score;
    ALLEGRO_BITMAP * skin;
    int skins;
    char gamer_id;
    double xroleratio, yroleratio;
    double yscoreratio;
    ALLEGRO_BITMAP *back_image;
    ALLEGRO_BITMAP *front_image;
} player;

typedef struct {
    double r, c;
    int hand_number;
    bool modification;
    ALLEGRO_BITMAP *image;
} buffer_position;

typedef struct {
    card **tab;
    ALLEGRO_BITMAP *board_image;
} board;

#endif