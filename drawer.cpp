#include "drawer.h"
#include "cpu.h"
drawer::drawer(cpu* _game){
    game = _game;
}
drawer::drawer() {}

void drawer::dr_background() {
    al_clear_to_color(al_map_rgba(bg_color.r, bg_color.g, bg_color.b, bg_color.a));
}

void drawer::set_window_size(p _window_size) {
    window_size = _window_size;
}

void drawer::set_board(vector<p>& _board) {
    board = _board;
}

void drawer::dr_border() {
    al_draw_filled_rectangle(0,0,window_size.x, board[1].y,
                             al_map_rgba(border_color.r, border_color.g,
                                         border_color.b, border_color.a));
    al_draw_filled_rectangle(0,0,board[3].x, window_size.y, 
                             al_map_rgba(border_color.r, border_color.g,
                                         border_color.b, border_color.a));
    al_draw_filled_rectangle(0,board[3].y,window_size.x, window_size.y,
                             al_map_rgba(border_color.r, border_color.g, 
                                         border_color.b, border_color.a));
    al_draw_filled_rectangle(board[1].x,0,window_size.x, window_size.y,
                             al_map_rgba(border_color.r, border_color.g, 
                                         border_color.b, border_color.a));
}

void drawer::dr_path(double path_radius, vector<p>& path) {
    int n = path.size(); //number of points
    for(int i = 0; i < n; i++) {
        al_draw_filled_circle(path[i].x, path[i].y, path_radius, 
                al_map_rgba(path_color.r, path_color.g, 
                            path_color.b, path_color.a));
    }
    
    for(int i = 1; i < n; i++) {
        al_draw_line(path[i-1].x, path[i-1].y, path[i].x, path[i].y, 
                     al_map_rgba(path_color.r, path_color.g, 
                                 path_color.b, path_color.a),
                     2*path_radius);    
    }
}

void drawer::dr_turrets(vector<turret*>& turrets){
    for(int i = 0; i < turrets.size(); i++) {
        turrets[i] -> dr_turret();
    }
}

void drawer::dr_ranges(vector<turret*>& turrets){
    if((game -> get_show_range()) == 1) {
        for(int i = 0; i < turrets.size(); i++) {
            turrets[i] -> dr_range();
        }
    }
}

void drawer::dr_enemies(vector<enemy*>& enemies) {
    for(int i = 0; i < enemies.size(); i++) {
        enemies[i] -> dr_enemy();
    }
}

void drawer::dr_effects(vector<effect*>& effects) {
   for(int i = effects.size() - 1; i >= 0; i--) {
       effects[i] -> dr_effect(i);
   } 
}

void drawer::dr_stats(double money, int life, int level) {
    dr_money(money);
    dr_life(life);
    dr_level(level);
    dr_note();
}

void drawer::dr_note() {
    al_draw_text(fonts[0], al_map_rgba(200,200,200,255),
            note_position.x, note_position.y, 0,
            "Press H for HELP");
}

void drawer::dr_life(int life) {
    al_draw_text(fonts[0], al_map_rgba(200,200,200,255), 
            life_position.x, life_position.y, 0,
            ("Life " + to_string(life)).c_str() );
}

void drawer::dr_money(double money) {
    al_draw_text(fonts[0], al_map_rgba(200,200,200,255), 
            money_position.x, money_position.y, 0,
            ("Money " + to_string((int)money) + "." + 
             to_string((int)(money*100)%100)).c_str() );
}
//to_string((int)money)).c_str() + "." + 

void drawer::dr_level(int level) {
    al_draw_text(fonts[0], al_map_rgba(200,200,200,255), 
            level_position.x, level_position.y, 0,
            ("Level " + to_string(level)).c_str() );
}

void drawer::load_fonts() {
    fonts.push_back(al_load_ttf_font("courier.ttf", 16, 0));
    if(!fonts[0]) {
        fprintf(stderr, "could not load font courier16");
    }
}

void drawer::dr_help() {
    al_draw_filled_rectangle(200,180,600,430,al_map_rgba(0,0,0,255));
    al_draw_filled_rectangle(220,200,580,410,al_map_rgba(150,150,150,255));
    al_draw_text(fonts[0], al_map_rgba(0,0,0,255), 230, 210, 0, "Help:");
    al_draw_text(fonts[0], al_map_rgba(0,0,0,255), 230, 230, 0, 
            "H - this help");
    al_draw_text(fonts[0], al_map_rgba(0,0,0,255), 230, 250, 0, 
            "P - pause game ON/OFF");
    al_draw_text(fonts[0], al_map_rgba(0,0,0,255), 230, 270, 0, 
            "R - show range ON/OFF");
    al_draw_text(fonts[0], al_map_rgba(0,0,0,255), 230, 290, 0, 
            "L - place Laser turret (30)");
    al_draw_text(fonts[0], al_map_rgba(0,0,0,255), 230, 310, 0, 
            "B - place Burn turret (20)");
    al_draw_text(fonts[0], al_map_rgba(0,0,0,255), 230, 330, 0, 
            "I - place Ice turret (40)");
    al_draw_text(fonts[0], al_map_rgba(0,0,0,255), 230, 350, 0, 
            "SPACE - unleash enemies");
    al_draw_text(fonts[0], al_map_rgba(0,0,0,255), 230, 370, 0, 
            "ESC - quit game");
    al_draw_text(fonts[0], al_map_rgba(0,0,0,255), 230, 390, 0, 
            "Press ANY key to continue");
    
}
