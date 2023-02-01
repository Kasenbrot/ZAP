#include <superkarel.h>

void turn_right();
void stlp();
void vypln_stlp();

int main() {
    turn_on("task_4.kw");
    set_step_delay(100);

        turn_left();
        while (right_is_clear()){
            stlp();
            turn_left();
            step();
            turn_left();
        }
        stlp();
        turn_left();

    turn_off();
    return 0;
}

void turn_right(){
    turn_left();
    turn_left();
    turn_left();
}
void vypln_stlp(){
    while(front_is_clear()){        
        if(no_beepers_present()){
            put_beeper();
        }
        step();
    }
    if (no_beepers_present()){
        put_beeper();
    }
}
void stlp(){
    while((no_beepers_present()) && (front_is_clear())){
            step();
    }
    if(beepers_present()){
        while(front_is_clear()){
            step();
        }
        turn_left();
        turn_left();
        vypln_stlp();
    }
    else{
        turn_left();
        turn_left();
        while(front_is_clear()){
            step();
        }
    }
}

