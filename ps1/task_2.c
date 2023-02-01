#include <superkarel.h>

void turn_right();
void hladaj();
void zbieraj();
void vrat_sa();

int main() {
    turn_on("task_2.kw");
    set_step_delay(200);

    while (beepers_in_bag()){
        put_beeper();
    }
    while (no_beepers_in_bag()){
        hladaj();
    }
    turn_left();
    do {
        vrat_sa();
    }
    while (right_is_clear());
    while (beepers_present()){
        pick_beeper();
    }
    
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
void hladaj(){
    while (front_is_clear()){
        step();
        zbieraj();
    }
    turn_left();
}
void vrat_sa(){
    while (front_is_clear()){
        step();
    }
    turn_right();
}
