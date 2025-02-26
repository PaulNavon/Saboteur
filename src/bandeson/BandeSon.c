#include "BandeSon.h"

void backgroundmusic_Menu_play(ALLEGRO_SAMPLE *menuBackground,ALLEGRO_SAMPLE_ID* id){
    al_play_sample(menuBackground, 0.3, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, id);
}

void backgroundmusic_Menu_stop(ALLEGRO_SAMPLE *menuBackground,ALLEGRO_SAMPLE_ID* id){
    al_stop_sample(id);
}

void backgroundmusic_ingame_play(ALLEGRO_SAMPLE *ingamebackground,ALLEGRO_SAMPLE_ID* id2){
    al_play_sample(ingamebackground, 0.3, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, id2);
}
void backgroundmusic_ingame_stop(ALLEGRO_SAMPLE *ingamebackground,ALLEGRO_SAMPLE_ID* id2){
    al_stop_sample(id2);
}