#include <superkarel.h>

void poloz();
void turn_right();
void chod();
void zbieraj();
void ukladaj_1();
void zbieraj_vsetko();
void ukladaj_2();
void chod_spat();

int main() {
    turn_on("task_3.kw");
    set_step_delay(20);

    chod();
    turn_left();
    turn_left();
    ukladaj_1();
    chod_spat();
    while (right_is_clear()){
        turn_left();
        turn_left();
        ukladaj_2();
        chod_spat();
    }
    turn_left();
    turn_left();
    ukladaj_2();

    turn_right();
    while (front_is_clear()){
        step();
    }
    turn_right();
    step();
    turn_right();
    while (front_is_clear()){
        step();
    }
    turn_right();
    step();
    turn_left();
    step();
    turn_left();

    turn_off();
    return 0;
}

void turn_right(){
    turn_left();
    turn_left();
    turn_left();
}
void zbieraj(){
    if (beepers_present()){
        pick_beeper();
    }
}
void chod(){
    while (front_is_clear()){
        step();
        zbieraj();
    }
}
void zbieraj_vsetko(){
    while (beepers_present()){
        pick_beeper();
    }
}
void poloz(){
    if (beepers_in_bag()){
        put_beeper();
    }
}
void ukladaj_1(){
    while (front_is_clear()){
        if (right_is_blocked()){
            poloz();
        }
        step();
    }
}
void chod_spat(){
    if (left_is_clear()){
        turn_left();
        step();
        turn_left();
        chod();
    }    
}
void ukladaj_2(){
    zbieraj_vsetko();
    while (front_is_clear()){
        turn_right();
        step();
        turn_left();
        turn_left();
        if (beepers_present()){
            step();
            poloz();
            turn_right();
        }
        else {
            step();
            turn_right();
        }
    step();
    }
}
