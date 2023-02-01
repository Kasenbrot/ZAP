#include <stdio.h>

int main(int agrc, char* argv[]){
    FILE *fp = fopen(argv[1], "r");
    FILE *fpc = fopen(argv[2], "w");
    int ii = 0;
    int x = 0;
    int xx = 0;
    char veta[1000];
    char veta2[1000];
    int zaciatok1 = 0;
    int zaciatok = 0;
    char pismeno = fgetc(fp);
    while (pismeno != EOF){
        if (zaciatok1 == 0){
        if (x == 4){
            if (pismeno == 'T'){
                x = 5;
            }
            else {
                x = 0;
            }
        }
        if (x == 3){
            if (pismeno == 'R'){
                x = 4;
            }
            else {
                x = 0;
            }
        }
        if (x == 2){
            if (pismeno == 'A'){
                x = 3;
            }
            else {
                x = 0;
            }
        }
        if (x == 1){
            if (pismeno == 'T'){
                x = 2;
            }
            else {
                x = 0;
            }
        }
        if (x == 0){
            if (pismeno == 'S'){
                x = 1;
            }
            else {
                x = 0;
            }
        }
        if (x == 5){
            zaciatok1 = 1;
            zaciatok = ii+1;
            x = 0;
        }
        }
        else{
            if (xx == 3){
                if (pismeno == 'P'){
                    xx = 4;
                }
                else{
                    xx = 0;
                }
            }
            if (xx == 2){
                if (pismeno == 'O'){
                    xx = 3;
                }
                else{
                    xx = 0;
                }
            }
            if (xx == 1){
                if (pismeno == 'T'){
                    xx = 2;
                }
                else{
                    xx = 0;
                }
            }
            if (xx == 0){
                if (pismeno == 'S'){
                    xx = 1;
                }
                else{
                    xx = 0;
                }
            }
            if(xx==4){
                break;
            }
        }
        veta[ii] = pismeno;
        pismeno = fgetc(fp);
        ii = ii + 1;
    }
    //fclose(fp);
    //fclose(fps);
    ii = ii - 4;
    for (int i = 0; i < ii+1; i++){
        //printf("%c", veta[i]);
    }
    //printf("\n");
    //printf("koniec vety(ii) %d\n", ii);
    //printf("zaciatok vety %d\n", zaciatok);
    int s = 0;
    for(int i = zaciatok; i < ii; i++){
        //printf("%c", veta[i]);
        veta2[s]=veta[i];
        s = s + 1;
    }
    //printf("\n");
    char veta3[1000];
    int f = 0;
    int g = 0;
    for(int i=0; i < ii-zaciatok; i++){
        if (veta2[i]==' '){
            g = g + 1;
        }
        if (g%2 == 0){
            veta3[f]=veta2[i];
            //printf("%c", veta2[i]);
            f = f + 1;
        }
    }
    //printf("\n");
    //printf("%d\n", g);
    //printf("%d\n", f);
    for(int i=0; i < f; i++){
        //printf("%c", veta3[i]);
    }
    //printf("\n");
    char veta4[f-1];
    for(int i = 0; i < (f-1); i++){
        veta4[i]=veta3[i+1];
    }
    //printf("\n\n\n");
    for (int i = 0; i < f-1; i++){
        //printf("%c", veta4[i]);
    }
    //printf("\n");
    for (int i = 0; i < f-1; i ++){
        fputc(veta4[i],fpc);
    }
    fclose(fp);
    fclose(fpc);
    return  0;
}










