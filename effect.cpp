#include "effect.h"
#include "cpu.h"
//************************************************************
//effect methods

effect::~effect() {}

int effect::get_show_by() {return show_by;}

void effect::decrease_duration() {
    show_by--;
}

//************************************************************
//laser effect methods

laser_effect::laser_effect(p& _A, p& _B){
    A = _A; 
    B = _B;
    show_by = laser_show_by;
}

laser_effect::~laser_effect() {}

void laser_effect::dr_effect(int id){ 
    al_draw_line(A.x, A.y, B.x, B.y,
            al_map_rgba(effect_color.r, effect_color.g, 
                        effect_color.b, effect_color.a), line_size);
}

//************************************************************
//burn effect methods

burn_effect::burn_effect(p& _A, p& _B){
    A = _A; 
    B = _B;
    show_by = burn_show_by;
}

burn_effect::~burn_effect() {}

void burn_effect::dr_effect(int id){ 
    al_draw_line(A.x, A.y, B.x, B.y,
            al_map_rgba(effect_color.r, effect_color.g, 
                        effect_color.b, effect_color.a), line_size);
}

//************************************************************
//ice effect methods

ice_effect::ice_effect(p& _turret_position, double _turret_range){
    turret_position = _turret_position;
    turret_range = _turret_range;
    show_by = ice_show_by;
}

ice_effect::~ice_effect() {}

void ice_effect::dr_effect(int id){ 
    double a = show_by;
    double b = ice_show_by;
    double ci = a/b; //color intensity
    al_draw_filled_circle(turret_position.x, turret_position.y, turret_range,
            al_map_rgba(effect_color.r * ci, effect_color.g * ci, 
                        effect_color.b * ci, effect_color.a * ci));
}


