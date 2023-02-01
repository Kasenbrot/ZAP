#include <stdio.h>

float lift_a_car(const int stick_length, const int human_weight, const int car_weight);
float unit_price(const float pack_price, const int rolls_count, const int pieces_count);
int opposite_number(const int n, const int number);
int collatz(const int number);
void counter(const int input_array[], const int array_size, int result_array[2]);
unsigned long sum_squared(const int line);
unsigned long special_counter(const int input_array[], const int array_size);
int special_numbers(const int input_array[], const int array_size, int result_array[]);

int main(){

    

    return 0;
}
//////////////////////////////////////////////////
int special_numbers(const int input_array[], const int array_size, int result_array[]){
    int i = 0;
    int x = 0;
    int sucet = 0;
    int pocet = array_size - 1;
    while(i != array_size){
        while (i != pocet){
            sucet = sucet + input_array[pocet];
            pocet = pocet - 1;
        }
        if (input_array[i] > sucet){
            result_array[i] = input_array[i];
        }
        x = x + 1;
        i++;
    }
    return x;
}
//////////////////////////////////////////////////////
float lift_a_car(const int stick_length, const int human_weight, const int car_weight){
    float vysledok1 = 1.0 * stick_length * human_weight / (human_weight + car_weight);
    vysledok1 = (int) (vysledok1 * 100 + 0.5) / 100.0;
    return vysledok1;
}
float unit_price(const float pack_price, const int rolls_count, const int pieces_count){
    float vysledok2 = 100.0 * pack_price / (rolls_count * pieces_count);
    vysledok2 = (int) (vysledok2 * 100 + 0.5) / 100.0;
    return vysledok2;
}
int opposite_number(const int n, const int number){
    float vysledok4 = 0;
    if (number <= n/2){
        vysledok4 = number + n/2;
    }
    else{
        vysledok4 = number - n/2;
    }
    return vysledok4;
}
int collatz(const int number){
    int vysledok3 = 1;
    int x = number;
    while (x != 1){
        if (x % 2 == 0){
            x = x / 2;
        }
        else {
            x = x * 3 + 1;
        }
        vysledok3 = vysledok3 +1;
    }
    return vysledok3;
}
void counter(const int input_array[], const int array_size, int result_array[2]){
    result_array[0] = 0;
    result_array[1] = 0;
    int i = 0;
    while(i != array_size){
        if ((i) % 2 ==1){
            result_array[1] = result_array[1] + input_array[i];
        }
        else {
            result_array[0] = result_array[0] + input_array[i];
        }
        i++;
    }
}
unsigned long sum_squared(const int line){
    long double zlomok = 0;
    long double zlomok1 = 2;
    long double vysledok6 = 1;
    for (int i = 1; i < line+1; i++){
        zlomok = zlomok + (i);
        vysledok6 = vysledok6 * zlomok1;
        zlomok1 = zlomok1 + 1/zlomok;
    }
    if (line < 6){
        vysledok6 = vysledok6;
    }
    else {
        vysledok6 = vysledok6 + 1;
    }
    return vysledok6;
}
unsigned long special_counter(const int input_array[], const int array_size){
    unsigned long vysledok8 = 0;
    int i = 0;
    while(i != array_size){
        if ((i) % 2 ==1){
            vysledok8 = vysledok8 + input_array[i] * input_array[i];
        }
        else {
            vysledok8 = vysledok8 + input_array[i];
        }
        i++;
    }
    return vysledok8;
}














