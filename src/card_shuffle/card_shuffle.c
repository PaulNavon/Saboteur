
#include "../structures/structures.h"
#include "card_shuffle.h"
#include "../board/board.h"

//We create a table with the letters from A to Q
void inputCalling(char calling[]) {
    int i, a = (int) 'A';
    for (i = 0; i < LIGNES - 1; i++) {
        calling[i] = (char) a;
        a += 1;
    }
}

void player_hand_initialization(player *player, int *modifyingphysicalsize, char pick[]) {
    for (int j = 0; j < MAX_DECK - 1; j++) {
        player->hand->deck[j] = pickCard(pick, modifyingphysicalsize);
    }
}

//Using the letter table, we enter the different values such as: their occurrences and their points
void inputOccurrenceValues(const char calling[], card occurrence_point[LIGNES -
                                                                       1]) {//initialize the number of times the letters are present in the drawer + their values
    int i;
    for (i = 0; i < LIGNES - 1; i++) {
        switch (calling[i]) {
            case 'A': {
                occurrence_point[i].quantity = 2;
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_Action/Card_Dashboard_Damaged.png");
                occurrence_point[i].type = 'A';
                occurrence_point[i].shift_id = "A";
                break;
            }
            case 'B': {
                occurrence_point[i].quantity = 2;
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_Action/Card_Reactor_Failure.png");
                occurrence_point[i].type = 'B';
                occurrence_point[i].shift_id = "A";
                break;
            }
            case 'C': {
                occurrence_point[i].quantity = 2;
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_Action/Card_Damaged_Suit.png");
                occurrence_point[i].type = 'C';
                occurrence_point[i].shift_id = "A";
                break;
            }
            case 'D': {
                occurrence_point[i].quantity = 2;
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_Action/Card_Dashboard_Repaired.png");
                occurrence_point[i].type = 'D';
                occurrence_point[i].shift_id = "A";
                break;
            }
            case 'E': {
                occurrence_point[i].quantity = 2;
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_Action/Card_Reactor_Repaired.png");
                occurrence_point[i].type = 'E';
                occurrence_point[i].shift_id = "A";
                break;
            }
            case 'F': {
                occurrence_point[i].quantity = 2;
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_Action/Card_Repaired_Suit.png");
                occurrence_point[i].type = 'F';
                occurrence_point[i].shift_id = "A";
                break;
            }
            case 'G': {
                occurrence_point[i].quantity = 2;
                occurrence_point[i].front_image = al_load_bitmap(
                        "../images/Card_Action/Card_Reactor+Suit_Repaired.png");
                occurrence_point[i].type = 'G';
                occurrence_point[i].shift_id = "A";
                break;
            }
            case 'H': {
                occurrence_point[i].quantity = 2;
                occurrence_point[i].front_image = al_load_bitmap(
                        "../images/Card_Action/Card_Dashboard+Suit_Repaired.png");
                occurrence_point[i].type = 'H';
                occurrence_point[i].shift_id = "A";
                break;
            }
            case 'I': {
                occurrence_point[i].quantity = 2;
                occurrence_point[i].front_image = al_load_bitmap(
                        "../images/Card_Action/Card_Dashboard+Reactor_Repaired.png");
                occurrence_point[i].type = 'I';
                occurrence_point[i].shift_id = "A";
                break;
            }
            case 'J': {
                occurrence_point[i].quantity = 3;
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_Action/Card_Map.png");
                occurrence_point[i].type = 'J';
                occurrence_point[i].shift_id = "A";
                break;
            }
            case 'K': {
                occurrence_point[i].quantity = 3;
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_Action/Card_Meteor_Shower.png");
                occurrence_point[i].type = 'K';
                occurrence_point[i].shift_id = "A";
                break;
            }
            case 'L': {
                occurrence_point[i].quantity = 6;
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_board/Card_moove_1.png");
                occurrence_point[i].type = 'L';
                occurrence_point[i].shift_id = "LR";
                break;
            }
            case 'M': {
                occurrence_point[i].quantity = 6;
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_board/Card_moove_2.png");
                occurrence_point[i].type = 'M';
                occurrence_point[i].shift_id = "UD";
                break;
            }
            case 'N': {
                occurrence_point[i].quantity = 3;
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_board/Card_moove_3.png");
                occurrence_point[i].type = 'N';
                occurrence_point[i].shift_id = "L";
                break;
            }
            case 'O': {
                occurrence_point[i].quantity = 3;
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_board/Card_moove_4.png");
                occurrence_point[i].type = 'O';
                occurrence_point[i].shift_id = "LRUD";
                break;
            }
            case 'P': {
                occurrence_point[i].quantity = 3;
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_board/Card_moove_5.png");
                occurrence_point[i].type = 'P';
                occurrence_point[i].shift_id = "LRU";
                break;
            }
            case 'Q': {
                occurrence_point[i].quantity = 3;
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_board/Card_moove_6.png");
                occurrence_point[i].type = 'Q';
                occurrence_point[i].shift_id = "LRD";
                break;
            }
            case 'R': {
                occurrence_point[i].quantity = 3;
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_board/Card_moove_7.png");
                occurrence_point[i].type = 'R';
                occurrence_point[i].shift_id = "UR";
                break;
            }
            case 'S': {
                occurrence_point[i].quantity = 3;
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_board/Card_moove_8.png");
                occurrence_point[i].type = 'S';
                occurrence_point[i].shift_id = "LD";
                break;
            }
            case 'T': {
                occurrence_point[i].quantity = 3;
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_board/Card_moove_9.png");
                occurrence_point[i].type = 'T';
                occurrence_point[i].shift_id = "UDL";
                break;
            }
            case 'U': {
                occurrence_point[i].quantity = 3;
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_board/Card_moove_10.png");
                occurrence_point[i].type = 'U';
                occurrence_point[i].shift_id = "LU";
                break;
            }
            case 'V': {
                occurrence_point[i].quantity = 3;
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_board/Card_moove_11.png");
                occurrence_point[i].type = 'V';
                occurrence_point[i].shift_id = "DR";
                break;
            }
            case 'W': {
                occurrence_point[i].quantity = 3;
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_board/Card_moove_12.png");
                occurrence_point[i].type = 'W';
                occurrence_point[i].shift_id = "UDR";
                break;
            }
            case 'X': {
                occurrence_point[i].quantity = 3;
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_board/Card_moove_13.png");
                occurrence_point[i].type = 'X';
                occurrence_point[i].shift_id = "R";
                break;
            }
            default :
                break;
        }
    }
}

void loadingCards(char c, int j, int i, board *game_board) {
    switch (c) {
        case 'A': {
            game_board->tab[i][j].front_image = al_load_bitmap("../images/Card_Action/Card_Dashboard_Damaged.png");
            game_board->tab[i][j].type = 'A';
            game_board->tab[i][j].shift_id = "A";
            break;
        }
        case 'B': {
            game_board->tab[i][j].front_image = al_load_bitmap("../images/Card_Action/Card_Reactor_Failure.png");
            game_board->tab[i][j].type = 'B';
            game_board->tab[i][j].shift_id = "A";
            break;
        }
        case 'C': {
            game_board->tab[i][j].front_image = al_load_bitmap("../images/Card_Action/Card_Damaged_Suit.png");
            game_board->tab[i][j].type = 'C';
            game_board->tab[i][j].shift_id = "A";
            break;
        }
        case 'D': {
            game_board->tab[i][j].front_image = al_load_bitmap("../images/Card_Action/Card_Dashboard_Repaired.png");
            game_board->tab[i][j].type = 'D';
            game_board->tab[i][j].shift_id = "A";
            break;
        }
        case 'E': {
            game_board->tab[i][j].front_image = al_load_bitmap("../images/Card_Action/Card_Reactor_Repaired.png");
            game_board->tab[i][j].type = 'E';
            game_board->tab[i][j].shift_id = "A";
            break;
        }
        case 'F': {
            game_board->tab[i][j].front_image = al_load_bitmap("../images/Card_Action/Card_Repaired_Suit.png");
            game_board->tab[i][j].type = 'F';
            game_board->tab[i][j].shift_id = "A";
            break;
        }
        case 'G': {
            game_board->tab[i][j].front_image = al_load_bitmap("../images/Card_Action/Card_Reactor+Suit_Repaired.png");
            game_board->tab[i][j].type = 'G';
            game_board->tab[i][j].shift_id = "A";
            break;
        }
        case 'H': {
            game_board->tab[i][j].front_image = al_load_bitmap("../images/Card_Action/Card_Dashboard+Suit_Repaired.png");
            game_board->tab[i][j].type = 'H';
            game_board->tab[i][j].shift_id = "A";
            break;
        }
        case 'I': {
            game_board->tab[i][j].front_image = al_load_bitmap(
                    "../images/Card_Action/Card_Dashboard+Reactor_Repaired.png");
            game_board->tab[i][j].type = 'I';
            game_board->tab[i][j].shift_id = "A";
            break;
        }
        case 'J': {
            game_board->tab[i][j].front_image = al_load_bitmap("../images/Card_Action/Card_Map.png");
            game_board->tab[i][j].type = 'J';
            game_board->tab[i][j].shift_id = "A";
            break;
        }
        case 'K': {
            game_board->tab[i][j].front_image = al_load_bitmap("../images/Card_Action/Card_Meteor_Shower.png");
            game_board->tab[i][j].type = 'K';
            game_board->tab[i][j].shift_id = "A";
            break;
        }
        case 'L': {
            game_board->tab[i][j].front_image = al_load_bitmap("../images/Card_board/Card_moove_1.png");
            game_board->tab[i][j].type = 'L';
            game_board->tab[i][j].shift_id = "LR";
            break;
        }
        case 'M': {
            game_board->tab[i][j].front_image = al_load_bitmap("../images/Card_board/Card_moove_2.png");
            game_board->tab[i][j].type = 'M';
            game_board->tab[i][j].shift_id = "UD";
            break;
        }
        case 'N': {
            game_board->tab[i][j].front_image = al_load_bitmap("../images/Card_board/Card_moove_3.png");
            game_board->tab[i][j].type = 'N';
            game_board->tab[i][j].shift_id = "L";
            break;
        }
        case 'O': {
            game_board->tab[i][j].front_image = al_load_bitmap("../images/Card_board/Card_moove_4.png");
            game_board->tab[i][j].type = 'O';
            game_board->tab[i][j].shift_id = "LRUD";
            break;
        }
        case 'P': {
            game_board->tab[i][j].front_image = al_load_bitmap("../images/Card_board/Card_moove_5.png");
            game_board->tab[i][j].type = 'P';
            game_board->tab[i][j].shift_id = "LRU";
            break;
        }
        case 'Q': {
            game_board->tab[i][j].front_image = al_load_bitmap("../images/Card_board/Card_moove_6.png");
            game_board->tab[i][j].type = 'Q';
            game_board->tab[i][j].shift_id = "LRD";
            break;
        }
        case 'R': {
            game_board->tab[i][j].front_image = al_load_bitmap("../images/Card_board/Card_moove_7.png");
            game_board->tab[i][j].type = 'R';
            game_board->tab[i][j].shift_id = "UR";
            break;
        }
        case 'S': {
            game_board->tab[i][j].front_image = al_load_bitmap("../images/Card_board/Card_moove_8.png");
            game_board->tab[i][j].type = 'S';
            game_board->tab[i][j].shift_id = "LD";
            break;
        }
        case 'T': {
            game_board->tab[i][j].front_image = al_load_bitmap("../images/Card_board/Card_moove_9.png");
            game_board->tab[i][j].type = 'T';
            game_board->tab[i][j].shift_id = "UDL";
            break;
        }
        case 'U': {
            game_board->tab[i][j].front_image = al_load_bitmap("../images/Card_board/Card_moove_10.png");
            game_board->tab[i][j].type = 'U';
            game_board->tab[i][j].shift_id = "LU";
            break;
        }
        case 'V': {
            game_board->tab[i][j].front_image = al_load_bitmap("../images/Card_board/Card_moove_11.png");
            game_board->tab[i][j].type = 'V';
            game_board->tab[i][j].shift_id = "DR";
            break;
        }
        case 'W': {
            game_board->tab[i][j].front_image = al_load_bitmap("../images/Card_board/Card_moove_12.png");
            game_board->tab[i][j].type = 'W';
            game_board->tab[i][j].shift_id = "UDR";
            break;
        }
        case 'X': {
            game_board->tab[i][j].front_image = al_load_bitmap("../images/Card_board/Card_moove_13.png");
            game_board->tab[i][j].type = 'X';
            game_board->tab[i][j].shift_id = "R";
            break;
        }
        case 'Y': {
            //game_board->tab[i][j].front_image = al_load_bitmap("../images/Card_ending/Back_Card_Planet_screengame.png");
            game_board->tab[i][j].back_image_big = al_load_bitmap("../images/Card_ending/Card_Planet_1_Big.png");
            game_board->tab[i][j].back_image = al_load_bitmap("../images/Card_ending/Card_Planet_1.png");
            game_board->tab[i][j].type = '$';
            game_board->tab[i][j].shift_id = "SION";
            break;
        }
        case 'a': {
            game_board->tab[i][j].front_image = al_load_bitmap("../images/Card_board/card_start.png");
            game_board->tab[i][j].type = '%';
            game_board->tab[i][j].shift_id = "RDLU";
            break;
        }
        case 'Z': {
            game_board->tab[i][j].front_image =NULL;
            game_board->tab[i][j].type = 0;
            game_board->tab[i][j].shift_id = "0";
            break;
        }
        default :
            break;
    }
}

void loadingHand(char c, int i, card *occurrence_point) {//initialize the number of times the letters are present in the drawer + their values
        switch (c) {
            case 'A': {
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_Action/Card_Dashboard_Damaged.png");
                occurrence_point[i].type = 'A';
                occurrence_point[i].shift_id = "A";
                break;
            }
            case 'B': {
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_Action/Card_Reactor_Failure.png");
                occurrence_point[i].type = 'B';
                occurrence_point[i].shift_id = "A";
                break;
            }
            case 'C': {
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_Action/Card_Damaged_Suit.png");
                occurrence_point[i].type = 'C';
                occurrence_point[i].shift_id = "A";
                break;
            }
            case 'D': {
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_Action/Card_Dashboard_Repaired.png");
                occurrence_point[i].type = 'D';
                occurrence_point[i].shift_id = "A";
                break;
            }
            case 'E': {
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_Action/Card_Reactor_Repaired.png");
                occurrence_point[i].type = 'E';
                occurrence_point[i].shift_id = "A";
                break;
            }
            case 'F': {
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_Action/Card_Repaired_Suit.png");
                occurrence_point[i].type = 'F';
                occurrence_point[i].shift_id = "A";
                break;
            }
            case 'G': {
                occurrence_point[i].front_image = al_load_bitmap(
                        "../images/Card_Action/Card_Reactor+Suit_Repaired.png");
                occurrence_point[i].type = 'G';
                occurrence_point[i].shift_id = "A";
                break;
            }
            case 'H': {
                occurrence_point[i].front_image = al_load_bitmap(
                        "../images/Card_Action/Card_Dashboard+Suit_Repaired.png");
                occurrence_point[i].type = 'H';
                occurrence_point[i].shift_id = "A";
                break;
            }
            case 'I': {
                occurrence_point[i].front_image = al_load_bitmap(
                        "../images/Card_Action/Card_Dashboard+Reactor_Repaired.png");
                occurrence_point[i].type = 'I';
                occurrence_point[i].shift_id = "A";
                break;
            }
            case 'J': {
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_Action/Card_Map.png");
                occurrence_point[i].type = 'J';
                occurrence_point[i].shift_id = "A";
                break;
            }
            case 'K': {
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_Action/Card_Meteor_Shower.png");
                occurrence_point[i].type = 'K';
                occurrence_point[i].shift_id = "A";
                break;
            }
            case 'L': {
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_board/Card_moove_1.png");
                occurrence_point[i].type = 'L';
                occurrence_point[i].shift_id = "LR";
                break;
            }
            case 'M': {
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_board/Card_moove_2.png");
                occurrence_point[i].type = 'M';
                occurrence_point[i].shift_id = "UD";
                break;
            }
            case 'N': {
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_board/Card_moove_3.png");
                occurrence_point[i].type = 'N';
                occurrence_point[i].shift_id = "L";
                break;
            }
            case 'O': {
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_board/Card_moove_4.png");
                occurrence_point[i].type = 'O';
                occurrence_point[i].shift_id = "LRUD";
                break;
            }
            case 'P': {
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_board/Card_moove_5.png");
                occurrence_point[i].type = 'P';
                occurrence_point[i].shift_id = "LRU";
                break;
            }
            case 'Q': {
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_board/Card_moove_6.png");
                occurrence_point[i].type = 'Q';
                occurrence_point[i].shift_id = "LRD";
                break;
            }
            case 'R': {
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_board/Card_moove_7.png");
                occurrence_point[i].type = 'R';
                occurrence_point[i].shift_id = "UR";
                break;
            }
            case 'S': {
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_board/Card_moove_8.png");
                occurrence_point[i].type = 'S';
                occurrence_point[i].shift_id = "LD";
                break;
            }
            case 'T': {
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_board/Card_moove_9.png");
                occurrence_point[i].type = 'T';
                occurrence_point[i].shift_id = "UDL";
                break;
            }
            case 'U': {
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_board/Card_moove_10.png");
                occurrence_point[i].type = 'U';
                occurrence_point[i].shift_id = "LU";
                break;
            }
            case 'V': {
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_board/Card_moove_11.png");
                occurrence_point[i].type = 'V';
                occurrence_point[i].shift_id = "DR";
                break;
            }
            case 'W': {
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_board/Card_moove_12.png");
                occurrence_point[i].type = 'W';
                occurrence_point[i].shift_id = "UDR";
                break;
            }
            case 'X': {
                occurrence_point[i].front_image = al_load_bitmap("../images/Card_board/Card_moove_13.png");
                occurrence_point[i].type = 'X';
                occurrence_point[i].shift_id = "R";
                break;
            }
            default :
                break;
        }

}

//This function manages our letter array and our value array (occurrences and points)
void followedByPioche(char calling[], card occurrence_point[LIGNES]) {
    inputCalling(calling);
    inputOccurrenceValues(calling, occurrence_point);
}

//We mix the board that will be used as a pick for the easel
void bagMix(char pick[]) {
    int i, lettreadeplace, interverser;
    char securite1, securite2;
    for (i = 0; i < FIN_PIOCHE; i++) {
        do {
            lettreadeplace = rand() % (FIN_PIOCHE - DEBUT_PIOCHE + 1) + DEBUT_PIOCHE;
            interverser = rand() % (FIN_PIOCHE - -DEBUT_PIOCHE + 1) + DEBUT_PIOCHE;
            securite1 = pick[lettreadeplace];
            securite2 = pick[interverser];
        } while (securite1 == 0 || securite2 == 0);
        pick[interverser] = securite1;
        pick[lettreadeplace] = securite2;
    }
}

//We initialize our array which will be used as a pick
void CardBag(char *pick, const char *calling, card occurrence_point[LIGNES - 1]) {
    int i, j, nbLettres = 0, securite = 0;
    for (i = 0; i < LIGNES - 1; i++) {
        nbLettres += occurrence_point[i].quantity;
        for (j = securite; j < nbLettres; j++) {
            pick[j] = calling[i];
        }
        securite = nbLettres;
    }
    bagMix(pick);
}

//This function is used to create the deck
void Bag(char *calling, char *pick, card occurrence_point[LIGNES - 1]) {
    followedByPioche(calling, occurrence_point);
    CardBag(pick, calling, occurrence_point);
}

//Pull the letters one by one, invert the selected letter with the last one and
//decrease the logical size at which you can draw in order not to get letters already drawn
char pickCard(char *pick, int *modifyingphysicalsize) {
    int alea;
    char lettre, securite;
    alea = rand() % (((ACTION_CARD - 1) - *modifyingphysicalsize) + 1);
    lettre = pick[alea];
    securite = pick[((ACTION_CARD - 1) - *modifyingphysicalsize) + 1];
    pick[((ACTION_CARD - 1) - *modifyingphysicalsize) + 1] = lettre;
    pick[alea] = securite;
    (*modifyingphysicalsize)++;
    return lettre;
}

void new_card(player *player, card occurence_point[LIGNES - 1], char call[], int i, int *modifyingphysicalsize,
              char pick[]) {
    player->hand->deck[i] = pickCard(pick, modifyingphysicalsize);
    inputCalling(call);
    for (int j = 0; j < LIGNES - 1; j++) {
        if (player->hand->deck[i] == call[j]) {
            player->hand[i].front_image = occurence_point[j].front_image;
            player->hand[i].type = occurence_point[j].type;
            player->hand[i].shift_id = occurence_point[j].shift_id;
        }
    }
}

void give_image_id(player *player, card occurence_point[LIGNES - 1], config configuration, char call[]) {
    int j;
    int i;
    inputCalling(call);
    for (i = 0; i < MAX_DECK - 1; i++) {
        for (j = 0; j < LIGNES - 1; j++) {
            if (player->hand->deck[i] == call[j]) {
                player->hand[i].front_image = occurence_point[j].front_image;
                player->hand[i].type = occurence_point[j].type;
                player->hand[i].shift_id = occurence_point[j].shift_id;
            }
        }
        draw_player_hand(configuration, player);
    }
}

void destroyBitmap(card occurrence_point[LIGNES], const char calling[]) {
    for (int i = 0; i < LIGNES - 1; i++) {
        switch (calling[i]) {
            case 'A': {
                al_destroy_bitmap(occurrence_point[i].front_image);
                break;
            }
            case 'B': {
                al_destroy_bitmap(occurrence_point[i].front_image);
                break;
            }
            case 'C': {
                al_destroy_bitmap(occurrence_point[i].front_image);
                break;
            }
            case 'D': {
                al_destroy_bitmap(occurrence_point[i].front_image);
                break;
            }
            case 'E': {
                al_destroy_bitmap(occurrence_point[i].front_image);
                break;
            }
            case 'F': {
                al_destroy_bitmap(occurrence_point[i].front_image);
                break;
            }
            case 'G': {
                al_destroy_bitmap(occurrence_point[i].front_image);
                break;
            }
            case 'H': {
                al_destroy_bitmap(occurrence_point[i].front_image);
                break;
            }
            case 'I': {
                al_destroy_bitmap(occurrence_point[i].front_image);
                break;
            }
            case 'J': {
                al_destroy_bitmap(occurrence_point[i].front_image);
                break;
            }
            case 'K': {
                al_destroy_bitmap(occurrence_point[i].front_image);
                break;
            }
            case 'L': {
                al_destroy_bitmap(occurrence_point[i].front_image);
                break;
            }
            case 'M': {
                al_destroy_bitmap(occurrence_point[i].front_image);
                break;
            }
            case 'N': {
                al_destroy_bitmap(occurrence_point[i].front_image);
                break;
            }
            case 'O': {
                al_destroy_bitmap(occurrence_point[i].front_image);
                break;
            }
            case 'P': {
                al_destroy_bitmap(occurrence_point[i].front_image);
                break;
            }
            case 'Q': {
                al_destroy_bitmap(occurrence_point[i].front_image);
                break;
            }
            case 'R': {
                al_destroy_bitmap(occurrence_point[i].front_image);
                break;
            }
            case 'S': {
                al_destroy_bitmap(occurrence_point[i].front_image);
                break;
            }
            case 'T': {
                al_destroy_bitmap(occurrence_point[i].front_image);
                break;
            }
            case 'U': {
                al_destroy_bitmap(occurrence_point[i].front_image);
                break;
            }
            case 'V': {
                al_destroy_bitmap(occurrence_point[i].front_image);
                break;
            }
            case 'W': {
                al_destroy_bitmap(occurrence_point[i].front_image);
                break;
            }
            case 'X': {
                al_destroy_bitmap(occurrence_point[i].front_image);
                break;
            }
            default :
                break;
        }
    }
}