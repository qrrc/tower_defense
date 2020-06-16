#include "enemy.h"
#include "cpu.h"

//************************************************************
//enemy - base class

void enemy::move_enemy(vector<p>& path, int k){
    melt();
    double dist_from_end = dist(position, path[segment]); 
    double move_by = speed/(game -> get_refresh());
    if(dist_from_end > move_by) {
        position = move(position, path[segment], move_by);
    } else 
        if (path.size() - 1 > segment) {
            position = move(path[segment], path[segment+1], (move_by - dist_from_end));
            segment = segment + 1;}
        else {
            game -> enemy_scored(k);
        }
}

p& enemy::get_position() {
    return position;
}

void enemy::deal_damage(int id, double damage) {
    damage = damage * damage_multiplier;
    hp = hp - damage;
    size = start_size * ((hp + start_hp * 0.3 ) / (start_hp * 1.3));
    if(hp <= 0) {
        game -> kill_enemy(id);
    }
}

double enemy::get_money() {
    return money;
}

enemy::~enemy(){}

void enemy::multiply_multiplier(double by) {
    damage_multiplier = by * damage_multiplier;
}

void enemy::ice_me(int ice_timer) {
    iced_delays.push_back(ice_timer);
    speed = speed * iced_multiplier;
    my_color = my_iced_color;
    iced_times ++;
}

void enemy::disice_me() {
    speed = speed / iced_multiplier;
    iced_times --;
    if(iced_times == 0) {my_color = my_base_color;}
}

void enemy::melt() {
    for(int i = iced_times - 1; i >= 0; i--) {
        iced_delays[i] = iced_delays[i] - 1;
        if(iced_delays[i] == 0) {
            disice_me();
            iced_delays.erase(iced_delays.begin() + i);
        }
    } 
}

//************************************************************
//basic enemy - derived class

void basic_enemy::dr_enemy() {
    al_draw_filled_circle(position.x, position.y, size,
            al_map_rgba(my_color.r, my_color.g, 
                my_color.b, my_color.a));
    
    al_draw_circle(position.x, position.y, size,
            al_map_rgba(my_color.r, my_color.g, 
                my_color.b, my_color.a), 2);
}

basic_enemy::basic_enemy(cpu* _game) {
    game = _game;
    my_color = enemy_color;
    my_base_color = enemy_color;
    my_iced_color = iced_color;
    position = game -> get_start();
    hp = base_hp + base_hp * (game -> get_level()) * (game -> get_level());
    start_hp = hp;
    start_size = base_size + (grow_speed * (game -> get_level()));
    size = start_size;
    speed = enemy_speed;
    money = money_grow * base_money * (game -> get_level());
    money = pow(money / decline_money, money_grow_exp) * decline_money;

}

basic_enemy::~basic_enemy(){}
//************************************************************
//speeder - derived class
void speeder::dr_enemy() {
    al_draw_filled_circle(position.x, position.y, size,
            al_map_rgba(my_color.r, my_color.g, 
                my_color.b, my_color.a));
    
    al_draw_circle(position.x, position.y, size,
            al_map_rgba(my_color.r, my_color.g, 
                my_color.b, my_color.a), 2);
        
}

speeder::speeder(cpu* _game) {
    game = _game;
    position = game -> get_start();
    my_color = enemy_color;
    my_base_color = enemy_color;
    my_iced_color = iced_color;
    hp = base_hp + base_hp * (game -> get_level()) * (game -> get_level());
    start_hp = hp;
    start_size = base_size + (grow_speed * (game -> get_level()));
    size = start_size;
    speed = enemy_speed;
    money = money_grow * base_money * (game -> get_level());
    money = pow(money, money_grow_exp);
}

speeder::~speeder(){}
//************************************************************
//boss - derived class
void boss::dr_enemy() {
    al_draw_filled_circle(position.x, position.y, size,
            al_map_rgba(my_color.r, my_color.g, 
                my_color.b, my_color.a));
    
    al_draw_circle(position.x, position.y, size,
            al_map_rgba(enemy_color.r, enemy_color.g, 
                enemy_color.b, enemy_color.a), 2);
        
}


boss::boss(cpu* _game) {
    game = _game;
    position = game -> get_start();
    my_color = enemy_color;
    my_base_color = enemy_color;
    my_iced_color = iced_color;
    hp = base_hp + base_hp * (game -> get_level()) * (game -> get_level());
    start_hp = hp;
    start_size = base_size + (grow_speed * (game -> get_level()));
    size = start_size;
    speed = enemy_speed;
    money = money_grow * base_money * (game -> get_level());
    money = pow(money, money_grow_exp);
}

boss::~boss(){}
