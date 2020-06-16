#ifndef TURRET_H
#define TURRET_H
#include "others.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <string>
#include <vector>
#include "enemy.h"
using namespace std;

//forward declarations:
class cpu;

//abc turret:
class turret {
    protected: 
        cpu* game;
        p position;
        int turret_level = 1;
        double turret_size;
        int delay = 0;
        color fill = color(205,205,205,255);
        color border = color(0,0,0,255);

    public:
        virtual double get_range() = 0;
        virtual void dr_turret() = 0;
        void dr_range();
        virtual void make_shot(vector<enemy*>& enemies, string type) = 0;
        bool enemy_in_range(enemy* suspect); 
        double get_turret_size();
        p& get_position();
        void set_position(p _position);
        virtual ~turret();

        void set_fill(color _fill);
        void set_border(color _border);

};

//derived classes:
class laser : public turret {
    private:
        double range = 100;
        double damage = 200;
        int delay_after_shot = 120;

    public:
        laser(cpu* _game, p _position);
        virtual void dr_turret();
        virtual void make_shot(vector<enemy*>& enemies, string type);
        virtual double get_range();
        virtual ~laser();

};

class burn : public turret {
    private:
        double range = 70;
        double damage = 0.05;
        int delay_after_shot = 0;
        double make_vunerable_by = 1.001;

    public:
        burn(cpu* _game, p _position);
        virtual void dr_turret();
        virtual void make_shot(vector<enemy*>& enemies, string type);
        virtual double get_range();
        virtual ~burn();
};

class ice : public turret {
    private:
        double range = 150;
        double damage = 20;
        int delay_after_shot = 250;
        int ice_time = 500;

    public:
        ice(cpu* _game, p _position);
        virtual void dr_turret();
        virtual void make_shot(vector<enemy*>& enemies, string type);
        virtual double get_range();
        virtual ~ice();

};

#endif
