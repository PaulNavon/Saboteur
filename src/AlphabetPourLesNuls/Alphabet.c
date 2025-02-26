#include "Alphabet.h"

int alphabet(int keycode) {
    int letter;
    switch (keycode) {
        //We transform the keycode from Allegro into an ASCII character
        //Letters
        case 1:
            letter = 65;
            break;
        case 2:
            letter = 66;
            break;
        case 3:
            letter = 67;
            break;
        case 4:
            letter = 68;
            break;
        case 5:
            letter = 69;
            break;
        case 6:
            letter = 70;
            break;
        case 7:
            letter = 71;
            break;
        case 8:
            letter = 72;
            break;
        case 9:
            letter = 73;
            break;
        case 10:
            letter = 74;
            break;
        case 11:
            letter = 75;
            break;
        case 12:
            letter = 76;
            break;
        case 13:
            letter = 77;
            break;
        case 14:
            letter = 78;
            break;
        case 15:
            letter = 79;
            break;
        case 16:
            letter = 80;
            break;
        case 17:
            letter = 81;
            break;
        case 18:
            letter = 82;
            break;
        case 19:
            letter = 83;
            break;
        case 20:
            letter = 84;
            break;
        case 21:
            letter = 85;
            break;
        case 22:
            letter = 86;
            break;
        case 23:
            letter = 87;
            break;
        case 24:
            letter = 88;
            break;
        case 25:
            letter = 89;
            break;
        case 26:
            letter = 90;
            break;
            //Numbers
        case 28:
            letter = 49;
            break;
        case 29:
            letter = 50;
            break;
        case 30:
            letter = 51;
            break;
        case 31:
            letter = 52;
            break;
        case 32:
            letter = 53;
            break;
        case 33:
            letter = 54;
            break;
        case 34:
            letter = 55;
            break;
        case 35:
            letter = 56;
            break;
        case 36:
            letter = 57;
            break;
            //Numbers from key_pad
        case 38:
            letter = 49;
            break;
        case 39:
            letter = 50;
            break;
        case 40:
            letter = 51;
            break;
        case 41:
            letter = 52;
            break;
        case 42:
            letter = 53;
            break;
        case 43:
            letter = 54;
            break;
        case 44:
            letter = 55;
            break;
        case 45:
            letter = 56;
            break;
        case 46:
            letter = 57;
            break;
            // SPACE
        case 75:
            letter = 32;
            break;
            //Debugger
        default :
            letter = 200;
            break;
    }
    return letter;
}

int nb_games_selection(int keycode) {
    int number;
    switch (keycode) {
        case 27:
            number=0;
            break;
        case 28:
            number = 1;
            break;
        case 29:
            number = 2;
            break;
        case 30:
            number = 3;
            break;
        case 31:
            number = 4;
            break;
        case 32:
            number = 5;
            break;
        case 33:
            number = 6;
            break;
        case 34:
            number = 7;
            break;
        case 35:
            number = 8;
            break;
        case 36:
            number = 9;
            break;
            //Numbers from key_pad
        case 37 :
            number =0;
            break;
        case 38:
            number = 1;
            break;
        case 39:
            number = 2;
            break;
        case 40:
            number = 3;
            break;
        case 41:
            number = 4;
            break;
        case 42:
            number = 5;
            break;
        case 43:
            number = 6;
            break;
        case 44:
            number = 7;
            break;
        case 45:
            number = 8;
            break;
        case 46:
            number = 9;
            break;
            //Debugger
        default :
            number = 200;
            break;
    }
    return number;
}