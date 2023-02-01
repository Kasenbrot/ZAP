#include <superkarel.h>

void turn_right();
void ram();
void rob_ram();
void hladaj_stred();

int main() {
    turn_on("task_5.kw");
    set_step_delay(100);


    ram();
    turn_left();
    turn_left();
    hladaj_stred();
    turn_right();
    hladaj_stred();
    while(not_facing_north()){
        turn_left();
    }


    turn_off();
    return 0;
}

void turn_right(){
    turn_left();
    turn_left();
    turn_left();
}
void rob_ram(){
    while(front_is_clear()){
        step();
        put_beeper();
    }
}
void ram(){
    while(not_facing_west()){
        turn_left();
    }
    while(front_is_clear()){
        step();
    }
    turn_left();
    while(front_is_clear()){
        step();
    }
    turn_left();
    rob_ram();
    turn_left();
    rob_ram();
    turn_left();
    rob_ram();
    turn_left();
    rob_ram();
}
void hladaj_stred(){
    if (front_is_clear()){
        step();
        step();
        hladaj_stred();
        turn_left();
        turn_left();
        step();
        turn_left();
        turn_left();
    }
}











