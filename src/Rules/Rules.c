#include "Rules.h"

void scroll(int* Z, int OldZ,config configuration, ALLEGRO_BITMAP *rules_low, ALLEGRO_BITMAP *rules_medium,
            ALLEGRO_BITMAP *rules_high) {
    int V;

    switch (configuration.height) {
        case 1080:
            if(*Z>0){
                *Z=0;
                al_set_mouse_z(*Z);
            }
            if(*Z<-51){
                *Z=-51;
                al_set_mouse_z(*Z);
            }
            V = 55*(*Z);
            if (-51< *Z && *Z < OldZ) {//Descendre
                al_clear_to_color(BLACK);
                al_draw_bitmap(rules_high, 0, (float)V, 0);
                al_flip_display();
            }
            if (OldZ < *Z && *Z < 0) {//Monter
                al_clear_to_color(BLACK);
                al_draw_bitmap(rules_high, 0, (float)V, 0);
                al_flip_display();
            }
            break;
        case 720:
            if(*Z>0){
                *Z=0;
                al_set_mouse_z(*Z);
            }
            if(*Z<-47){
                *Z=-47;
                al_set_mouse_z(*Z);
            }
            V = 40*(*Z);
            if (-47 < *Z && *Z < OldZ) {//Descendre
                al_clear_to_color(BLACK);
                al_draw_bitmap(rules_medium, 0, (float)V, 0);
                al_flip_display();
            }
            if (OldZ < *Z && *Z < 0) {//Monter
                al_clear_to_color(BLACK);
                al_draw_bitmap(rules_medium, 0, (float)V, 0);
                al_flip_display();
            }
            break;
        case 480:
            if(*Z>0){
                *Z=0;
                al_set_mouse_z(*Z);
            }
            if(*Z<-42){
                *Z=-42;
                al_set_mouse_z(*Z);
            }
            V = 30*(*Z);
            if (-42 < *Z && *Z < OldZ) {//Descendre
                al_clear_to_color(BLACK);
                al_draw_bitmap(rules_low, 0, (float)V, 0);
                al_flip_display();
            }
            if (OldZ < *Z && *Z < 0) {//Monter
                al_clear_to_color(BLACK);
                al_draw_bitmap(rules_low, 0, (float)V, 0);
                al_flip_display();
            }
            break;
        default:
            break;
    }
}