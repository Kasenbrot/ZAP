#include <stdio.h>
#include <stdlib.h>

int main(int agrc, char* argv[]){
    FILE *fp = fopen(argv[1], "r");

    int x = 0;
    int vysledok = 0;
    char pismeno = fgetc(fp);
    while (pismeno != EOF){
        if (x == 5){
            if (pismeno == 's' || pismeno == 'S'){
                x = 6;
            }
            else {
                x = 0;
            }
        }
        if (x == 4){
            if (pismeno == 'a' || pismeno == 'A'){
                x = 5;
            }
            else {
                x = 0;
            }
        }
        if (x == 3){
            if (pismeno == 'n' || pismeno == 'N'){
                x = 4;
            }
            else {
                x = 0;
            }
        }
        if (x == 2){
            if (pismeno == 'a' || pismeno == 'A'){
                x = 3;
            }
            else {
                x = 0;
            }
        }
        if (x == 1){
            if (pismeno == 'n' || pismeno == 'N'){
                x = 2;
            }
            else {
                x = 0;
            }
        }
        if (x == 0){
            if (pismeno == 'a' || pismeno == 'A'){
                x = 1;
            }
            else {
                x = 0;
            }
        }
        if (x == 6){
            vysledok = vysledok + 1;
            x = 0;
        }
        pismeno = fgetc(fp);
    }
    fclose(fp);
    FILE *fps = fopen(argv[1], "w");
    char xxx = vysledok + '0';
    fputc(xxx,fps);
    fclose(fps);

    return  0;
}



