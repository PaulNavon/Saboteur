#include "../structures/structures.h"


#ifndef MAIN_C_RULES_H
#define MAIN_C_RULES_H

#define BLACK al_map_rgb(0,0,0)

void scroll(int* Z, int OldZ,config configuration, ALLEGRO_BITMAP *rules_low, ALLEGRO_BITMAP *rules_medium,
            ALLEGRO_BITMAP *rules_high);

#endif //MAIN_C_RULES_H
