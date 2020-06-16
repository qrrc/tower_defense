#ifndef EFFECT_H
#define EFFECT_H
#include "others.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

//forward declarations:
class cpu;

//abc - effect:
class effect {
    protected:
        cpu* game;
        int show_by;

    public:
        virtual void dr_effect(int id) = 0;
        virtual ~effect();
        int get_show_by();
        void decrease_duration();
};

//derived classes:
class laser_effect : public effect {
    protected:
        color effect_color = color(255,0,0,128);
        p A, B;
        double line_size = 3;
        int laser_show_by = 10;

    public:
        laser_effect(p& _A, p& _B);
        virtual void dr_effect(int id);
        virtual ~laser_effect();
};

class burn_effect : public effect {
    protected:
        color effect_color = color(128,128,0,128);
        p A, B;
        double line_size = 1;
        int burn_show_by = 1;

    public:
        burn_effect(p& _A, p& _B);
        virtual void dr_effect(int id);
        virtual ~burn_effect();
};

class ice_effect : public effect {
    protected:
        color effect_color = color(0,70,70,0);
        p turret_position;
        double turret_range;
        int ice_show_by = 60;

    public:
        ice_effect(p& _turret_position, double _turret_range);
        virtual void dr_effect(int id);
        virtual ~ice_effect();
};

#endif

