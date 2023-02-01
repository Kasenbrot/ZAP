#include <superkarel.h>

void turn_right();
void kontroluj();

int main() {
    turn_on("task_7.kw");
    set_step_delay(100);


//////////
    while (front_is_clear()){
        if (left_is_clear()){
            turn_left();
            step();
            put_beeper();
            turn_left();
            turn_left();
            step();
            turn_left();
        }
        step();
    }
    if (left_is_clear()){
        turn_left();
        step();
        put_beeper();
        turn_left();
        turn_left();
        step();
        turn_left();
    }
   turn_left();
   turn_left();
   while (front_is_clear()){
        step();
    }
    turn_left();
    turn_left();   
//////////


    while(front_is_clear()){
        if (left_is_clear()){
            turn_left();
            step();
            put_beeper();
            step();
            kontroluj();
            put_beeper();
            step();
            turn_left();
            if (front_is_clear()){
                step();
            }
        }
        else {
            if (front_is_clear()){
                step();
            }
        }
    }
    if (left_is_clear()){
        turn_left();
        step();
        put_beeper();
        step();
        kontroluj();
        put_beeper();
        step();
        turn_left();
    }
    turn_left();
    turn_left();
    while (front_is_clear()){
        step();
    }
    turn_left();
    turn_left();
    while(front_is_clear()){
        if (left_is_clear()){
            turn_left();
            step();
            pick_beeper();
            pick_beeper();
            if (no_beepers_present()){
                put_beeper();
            }
            else {
                pick_beeper();
            }
            turn_left();
            turn_left();
            step();
            turn_left();
            if (front_is_clear()){
                step();
            }
        }
        else{
            if (front_is_clear()){
                step();
            }
        }
    }
    if (left_is_clear()){
        turn_left();
        step();
        pick_beeper();
        pick_beeper();
        if (no_beepers_present()){
            put_beeper();
            }
        else {
            pick_beeper();
        }
        turn_left();
        turn_left();
        step();
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
void kontroluj(){
    while (no_beepers_present()){
        if (right_is_clear()){
            turn_right();
            step();
        }
        else if (front_is_clear()) {
            step();
        }
        else if (left_is_clear()){
            turn_left();
            step();
        }
        else {
            turn_left();
            turn_left();
        }
        kontroluj();
    }
}
