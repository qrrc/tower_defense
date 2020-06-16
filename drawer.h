#ifndef DRAWER_H
#define DRAWER_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "others.h"
#include "turret.h"
#include "enemy.h"
#include "effect.h"
#include <vector>
#include <string>
using namespace std;

//forward declarations:
class cpu;

//class
class drawer {
    private:
        cpu* game;
        color bg_color = color(130,0,0,255);
        color border_color = color(0,0,50,255);
        color path_color = color(50,0,0,255);
        p window_size;
        vector<p> board;

        vector<ALLEGRO_FONT*> fonts;

        p level_position = p(50,50); 
        p life_position = p(150,50); 
        p money_position = p(250,50); 
        p note_position = p(10,580);

    public:
        drawer();
        drawer(cpu* game);

        void load_fonts();

        void dr_background();
        void dr_border();
        void dr_path(double path_radius, vector<p>& path);
        void dr_turrets(vector<turret*>& turrets);
        void dr_ranges(vector<turret*>& turrets);
        void dr_enemies(vector<enemy*>& enemies);
        void dr_effects(vector<effect*>& effects);
        void dr_help();

        void dr_stats(double money, int life, int level);
        void dr_money(double money);
        void dr_life(int life);
        void dr_level(int level);
        void dr_note();

        void set_window_size(p _window_size);
        void set_board(vector<p>& board);

};

#endif
