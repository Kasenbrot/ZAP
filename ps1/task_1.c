#include <superkarel.h>

void turn_right();
void jump_over();
void zbieraj();
void chod_a_zbieraj();
void jump_over_back();

int main() {
    turn_on("task_1.kw");
    set_step_delay(200);

    while(beepers_in_bag()){
        put_beeper();
    }
    while (no_beepers_in_bag()){
        chod_a_zbieraj();
        jump_over();
        zbieraj();
    }
    turn_left();
    turn_left();


    do {
            jump_over_back();
                }
                    while (no_beepers_present());
                        pick_beeper();
    while (beepers_present()){
        pick_beeper();
    }
    while (not_facing_west()){
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

void jump_over(){
    turn_left();
    while (right_is_blocked()){
        step();
    }
    turn_right();
    do {
        step();
    }
    while (right_is_blocked());
    turn_right();
    while (front_is_clear()){
        step();
    }
    turn_left();
}   
void zbieraj(){
    if (beepers_present()){
    pick_beeper();
    }
}
void chod_a_zbieraj(){
    while (front_is_clear()){
        step();
        zbieraj();
    }
}
void jump_over_back(){
    while (front_is_clear()){
            step();
                }
                    turn_right();
                        while (left_is_blocked()){
                            step();
                                }
                                    turn_left();
do {
        step();
            }
                while(left_is_blocked());
                    turn_left();
                        while (front_is_clear()){
                                step();
                                    }
                                        turn_right();
                                            while (front_is_clear() && no_beepers_present()){
                                                    step();
                                                        }
}
                                                        
