#include <superkarel.h>

void turn_right();
void turn_west();
void turn_east();
void turn_south();
void turn_north();
void chod();
void hladaj_poklad();

int main() {
    turn_on("task_6.kw");
    set_step_delay(300);


    hladaj_poklad();


    turn_off();
    return 0;
}

void turn_right(){
    turn_left();
    turn_left();
    turn_left();
}
void turn_west(){
    while(not_facing_west()){
        turn_left();
    }
}
void turn_east(){
    while(not_facing_east()){
        turn_left();
    }
}
void turn_south(){
    while(not_facing_south()){
        turn_left();
    }
}
void turn_north(){
    while(not_facing_north()){
        turn_left();
    }
}
void chod(){
    while (no_beepers_present()){
        step();
    }
}
void hladaj_poklad(){
    chod();
    pick_beeper();
    if (no_beepers_present()){
        turn_north();
        hladaj_poklad();
    }
    else {
        pick_beeper();
        if (no_beepers_present()){
            turn_west();
            hladaj_poklad();
        }
        else{
            pick_beeper();
            if (no_beepers_present()){
                turn_south();
                hladaj_poklad();
            }
            else{
                pick_beeper();
                if (no_beepers_present()){
                    turn_east();
                    hladaj_poklad();
                }
                else{
                    pick_beeper();
                }
            }
        }
    }
}

