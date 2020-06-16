#ifndef ENEMY_H
#define ENEMY_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "others.h"
#include <math.h>
#include <vector>
using namespace std;

//forward declarations
class cpu;

//abc enemy
class enemy {
    protected:
        cpu* game;
        p position;
        int segment = 1;
        double hp;
        double size;
        double grow_speed = 0.5;
        double speed;
        double money;
        double money_grow = 0.35;
        double money_grow_exp = 0.5;
        double decline_money = 0.2;
        double start_hp;
        double start_size;
        double damage_multiplier = 1;
        color my_color, my_iced_color, my_base_color;
        double iced_multiplier = 0.9;
        int iced_times = 0;
        vector<int> iced_delays;
        
    public:
        virtual void dr_enemy() = 0;
        void move_enemy(vector<p>& path, int k);
        void deal_damage(int id, double damage);
        void multiply_multiplier(double by);

        void ice_me(int ice_timer);
        void disice_me();
        void melt();

        double get_money();
        virtual ~enemy();
        
        p& get_position();

};

//************************************************************
//basic_enemy - derived class
class basic_enemy : public enemy {
    private:
        double base_hp = 2;
        double base_size = 5;
        double enemy_speed = 33;
        double base_money = 0.2;

        color enemy_color = color(120, 120, 0, 128);
        color iced_color = color(120, 120, 200, 128);

    public:
        basic_enemy(cpu* _game);
        virtual void dr_enemy();
        virtual ~basic_enemy();
};

//************************************************************
//speeder - derived class
class speeder : public enemy {
    private:
        double base_hp = 0.25;
        double base_size = 1.5;
        double enemy_speed = 66;
        double base_money = 0.05;

        color enemy_color = color(0,153,153,128);
        color iced_color = color(0,153,253,128);

    public:
    
        speeder(cpu* _game);
        virtual void dr_enemy();
        virtual ~speeder();
};

class boss : public enemy {
    private:
        double base_hp = 70;
        double base_size = 7;
        double enemy_speed = 16;
        double base_money = 5; 
    
        color enemy_color = color(0,103,51,128);
        color iced_color = color(0,103,151,128);

    public:
        boss(cpu* _game);
        virtual void dr_enemy();
        virtual ~boss();
};

#endif

