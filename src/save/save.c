//
// Created by Hugo on 18/04/2021.
//

#include "save.h"

void save_board_data(board game_board, FILE** saveDataChar, int w, int s) {
            switch (game_board.tab[w][s].type) {
                case '\0':
                    fprintf(*saveDataChar, "Z");
                    break;
                case '%':
                    fprintf(*saveDataChar, "a");
                    break;
                case '$':
                    fprintf(*saveDataChar, "Y");
                    break;
                case 'L':
                    fprintf(*saveDataChar, "L");
                    break;
                case 'M':
                    fprintf(*saveDataChar, "M");
                    break;
                case 'N':
                    fprintf(*saveDataChar, "N");
                    break;
                case 'O':
                    fprintf(*saveDataChar, "O");
                    break;
                case 'P':
                    fprintf(*saveDataChar, "P");
                    break;
                case 'Q':
                    fprintf(*saveDataChar, "Q");
                    break;
                case 'R':
                    fprintf(*saveDataChar, "R");
                    break;
                case 'S':
                    fprintf(*saveDataChar, "S");
                    break;
                case 'T':
                    fprintf(*saveDataChar, "T");
                    break;
                case 'U':
                    fprintf(*saveDataChar, "U");
                    break;
                case 'V':
                    fprintf(*saveDataChar, "V");
                    break;
                case 'W':
                    fprintf(*saveDataChar, "W");
                    break;
                case 'X':
                    fprintf(*saveDataChar, "X");
                    break;
                default:
                    break;
            }
}