#include <stdio.h>
#include <stdlib.h> 
#include "ballsortpuzzle.h"
#include <string.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

void generator(const int rows, const int columns, char field[rows][columns]){

void generator(const int rows, const int columns, char field[rows][columns]);
int main(){
int rows = 4;
int columns = 6;
char field[rows][columns];
generator(rows, columns, field);
return 0;
}
//////////////////////////////////////////////////////////////////////////////
void generator(const int rows, const int columns, char field[rows][columns]){
srand(time(NULL));
int variable1,variable2;
int pocet_znakov = columns*rows-2*rows;
/*int stlpec1,stlpec2;
stlpec1 = (rand()%columns);
stlpec2 = (rand()%columns);
while (stlpec2 == stlpec1){
stlpec2 = (rand()%columns);
}
*/
//////////////SHUFFLE////////////////////////////////////////////////////////////////
char znaky[] = {'A','B','C','D','E','F','G','H'};
char zoznam_znakov[pocet_znakov];
for (int i = 0; i < rows; i++){
for (int j = 0; j < columns; j++){
zoznam_znakov[i*rows+j] = znaky[i];
}
}
for (int i = 0; i < pocet_znakov;i++)
{
variable1 = (rand()%(pocet_znakov))+1;
variable2 = zoznam_znakov[i];
zoznam_znakov[i] = zoznam_znakov[variable1];
zoznam_znakov[variable1] = variable2;
}
//////////////VYPIS POLA///////////////////////////////////////////////
for (int i = 0; i < rows; i++){
for (int j = 0; j < columns; j++){
/*if (j == stlpec1 || j == stlpec2){
field[i][j] = '_';
}
else {
field[i][j] = zoznam_znakov[i*4+j];
}
*/
field[i][j] = zoznam_znakov[i*4+j];
printf(" %c ", field[i][j]);
}
printf("\n");
}
//////////////TESTY/////////////////////////////////////////////////
printf("%i\n", pocet_znakov);
for (int i = 0; i < pocet_znakov; i++){
printf("%c ", zoznam_znakov[i]);
}
}

}

















