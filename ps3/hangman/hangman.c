#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "hangman.h"
#include <string.h> 
#include <time.h>
#include <ctype.h>

int get_word(char secret[]){
    // check if file exists first and is readable
    FILE *fp = fopen(WORDLIST_FILENAME, "rb");
    if( fp == NULL ){
        fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
        return 1;
    }
    // get the filesize first
    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;
    do{
        // generate random number between 0 and filesize
        long int random = (rand() % size) + 1;
        // seek to the random position of file
        fseek(fp, random, SEEK_SET);
        // get next word in row ;)
        int result = fscanf(fp, "%*s %20s", secret);
        if( result != EOF )
            break;
    }while(1);
    fclose(fp);
    return 0;
}
//////////////////////////////////////////////////////////////////////////////
int is_word_guessed(const char secret[], const char letters_guessed[]){
    int i = 0;
    int y = 0;
    int x = 0;
    while(i != strlen(secret)){
        while(y != strlen(letters_guessed)){
            if (secret[i] == letters_guessed[y]){
                x = x + 1;
            }
            y = y + 1;
        }
        i = i + 1;
        y = 0;
    }
    if (x == strlen(secret)){
        return 1;
    }
    else {
        return 0;
    }
}
////////////////////////////////////////////////////////////////////////////
void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]){
    int i = 0;
    int y = 0;
    int x = 0;
    while(i != strlen(secret)){
        while(y != strlen(letters_guessed)){
            if (secret[i] == letters_guessed[y]){
                x = 1;
            }
            y = y + 1;
        }
        if (x == 1){
            guessed_word[i] = secret[i];
        }
        else {
            guessed_word[i] = 95;
        }
        i = i + 1;
        y = 0;
        x = 0;
    }
    int z = strlen(secret);
    guessed_word[z] = '\0';
}
////////////////////////////////////////////////////////////////////////////
     int i = 97;
     int y = 0;
     int x = 0;
     while(i != 123 ){
         while(y != strlen(letters_guessed)){
             if (secret[i] == letters_guessed[y]){
                 x = x + 1;
             }
             y = y + 1;
        }
        i = i + 1;
        y = 0;
    }
    if (x == strlen(secret)){
        return 1;
    }
    else {
        return 0;
    }
}





/*void get_available_letters(const char letters_guessed[], char available_letters[]){
    char abeceda[27] = "abcdefghijklmnopqrstuvwxyz";
    printf("%s\n", abeceda);
    int i = 0;
    int y = 0;
    int x = 0;
    int z = 0;
    while(i != 26){
        while (y != strlen(letters_guessed)){
            if (abeceda[i] == letters_guessed[y]){
                x = 1;
            }
        }
        if (x == 1){
            z = strlen(available_letters);
            available_letters[z] = abeceda[i];
        }
        y = 0;
        x = 0;
        i = i + 1;
    }
}
*/












