//
// Created by Hugo on 25/03/2021.
//

#include "../structures/structures.h"

#ifndef PROJET_SABOTEUR_SABOTEUR_GROUPE_X_CARD_SHUFFLE_H
#define PROJET_SABOTEUR_SABOTEUR_GROUPE_X_CARD_SHUFFLE_H

void player_hand_initialization(player Gamer[], int *modifyingphysicalsize, char pick[]);

void new_card(player *player, card occurence_point[LIGNES - 1], char call[], int i, int *modifyingphysicalsize, char pick[]);

void inputCalling(char calling[]);

void inputOccurrenceValues(const char calling[], card occurrence_point[LIGNES-1]);

void loadingCards(char c, int i, int j, board *game_board);

void loadingHand(char c, int i, card *occurrence_point);

void followedByPioche(char calling[], card occurrence_point[LIGNES-1]);

void bagMix(char pick[]);

void CardBag(char *pick, const char *calling, card occurrence_point[LIGNES-1]);

void Bag(char *calling, char *pick, card occurrence_point[LIGNES]);

char pickCard(char pick[ACTION_CARD + 1], int *modifyingphysicalsize);

void give_image_id(player *player, card occurence_point[LIGNES-1], config configuration, char call[]);

void destroyBitmap(card occurrence_point[LIGNES],const char calling[]);

#endif //PROJET_SABOTEUR_SABOTEUR_GROUPE_X_CARD_SHUFFLE_H
