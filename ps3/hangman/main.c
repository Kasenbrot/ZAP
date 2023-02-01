#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <sys/stat.h>
#include "hangman.h"
#include "hangman.c"
#include <time.h>
#include <ctype.h>


int main(){


    char result[30];
    get_available_letters("arpstxgoieyu", result);
    printf("%s\n", result);
    //get_available_letters("arpstxgoieyu", available_letters);
    //printf("%s\n", available_letters);




return 0;
}













