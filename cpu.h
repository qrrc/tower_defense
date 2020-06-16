#ifndef CPU_H
#define CPU_H

#include "others.h"
#include "turret.h"
#include "enemy.h"
#include "effect.h"
#include <vector>
#include <string>
#include "drawer.h"
using namespace std;

//forward declarations:
class turret;
class enemy;
class effect;
class drawer;

//class cpu:
class cpu {

    private:
        int lives = 20;

        int level = 1;
        int unleashed_enemies_number = 0;
        bool unleash_enemies = false;
        bool weave_in_progress = false;
        

        double speed = 10;
        double money = 100;
        int show_range = 0;
        p window_size = p(800,600);
        double path_radius = 25;
        double refresh = 60; //times per sec
        int turn = 1;

        string shoot_type = "closest";

        double laser_size = 15;
        double laser_cost = 30;
        double burn_size = 10;
        double burn_cost = 20;
        double ice_size = 20;
        double ice_cost = 40;

        int basic_enemies_in_weave = 20;
        int speeder_in_weave = 50;
        int boss_in_weave = 3;
        int basic_enemy_delay = 60;
        int speeder_delay = 20;
        int boss_delay = 300;

        vector<p> board = {p(100,100), p(700, 100), p(700,500), p(100, 500)}; 
            // vector of four points - clockwise
        vector<p> path = {p(100,100), p(700,300), p(200,300), p(600,500)};  
            // vector of n points - enemy path

        drawer paint;
        vector<turret*> turrets;
        vector<enemy*> enemies;
        vector<effect*> effects;

        vector<turret*> placer;
        color cant_place_fill = color(205,0,0,255);
        color can_place_fill = color(0,205,0,255);

    public:
        cpu();
        
        bool is_turret_offboard(double turret_size, p turret_center);
        bool is_turret_onpath(double turret_size, p turret_center);
        bool is_turret_onturret(double turret_size, p turret_center);
        bool is_turret_coliding(double turret_size, p turret_center);

        void display_all();
        void display_help();
        
        //turrets
        void add_laser(p position);
        void add_burn(p position);
        void add_ice(p position);
        
        //enemies
        void add_basic_enemy();
        void add_speeder();
        void add_boss();

        //effects
        void add_laser_effect(p& A, p& B);
        void add_burn_effect(p& A, p& B);
        void add_ice_effect(p& turret_position, double turret_range);

        //placer
        void add_placer(string type);
        void remove_placer();
        void draw_placer();
        void set_placer(p position);

        void make_turn();
        void move_enemies();
        void damage_enemies();
        void decrease_effect_durability();
        void unleash();
        void unleash_weave_of_basic_enemies();
        void unleash_weave_of_speeders();
        void unleash_weave_of_boss();
        void unleash_enemies_true();
       
        void enemy_scored(int k);
        void deal_damage_to_enemy(int closest, double damage);
        void kill_enemy(int id);
        
        void change_show_range_state();


       //returns game statistics
        double get_refresh();
        p get_start();
        int get_level();
        int get_lives();
        vector<p>& get_path();
        double get_laser_size();
        double get_burn_size();
        double get_ice_size();
        int get_show_range();

};

#endif
