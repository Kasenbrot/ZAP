#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void encode_char(const char character, bool bits[8]);
char decode_byte(const bool bits[8]);
void encode_string(const char string[], bool bytes[strlen(string)+1][8]);
void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]);
void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]);
void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]);

int main(){

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////
void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]){
    for (int cele = 0; cele < rows; cele++){
        for (int i = 0; i < 8; i++){
            bytes[cele][i]=0;
        }
    }
    for (int cele = 0; cele < rows; cele++){
        for (int i = 0; i < 8; i++){
            bytes[cele][i]=blocks[i+((cele/cols)*8)][(cele+cols)%cols];
        }
    }
}
void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]){
    for (int cele = 0; cele < offset*8; cele++){
        for (int cele2 = 0; cele2 < cols; cele2++){
            blocks[cele][cele2]=0;
        }
    }
    for (int cele = 0; cele < rows; cele++){
        for (int cele2 = 0; cele2 < 8; cele2++){
            blocks[cele2+((cele)/cols)*8][(cele+cols)%cols]=bytes[cele][cele2];
        }
    }
}
void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]){
    int x = 0;
    int y = 1;
    for (int k = 0; k < rows; k++){
        for(int i = 0; i < 8; i++){
        x = x + (bytes[k][7-i] * y);
        y = y*2;
        }
        string[k] = x;
        x = 0;
        y = 1;
    }
}
void encode_string(const char string[], bool bytes[strlen(string)+1][8]){
    for (int x = 0; x <= strlen(string); x++){
        
        int cislo = string[x];
        for (int y = 7; y+1>0; y--){
            if (cislo >=1<<y){
                cislo = cislo - (1<<y);
                bytes[x][y*(-1)+7] = 1;
            }
            else{
                bytes[x][y*(-1)+7] = 0;
            }
        }
    }
}
void encode_char(const char character, bool bits[8]){
    int cislo = character;
    for (int j = 7; j+1>0; j--){
        if (cislo >=1<<j){
            cislo = cislo - (1<<j);
            bits[j*(-1)+7] = 1;
        }
        else{
            bits[j*(-1)+7] = 0;
        }
    }
}
char decode_byte(const bool bits[8]){
    int x = 0;
    int y = 1;
    for(int i = 0; i < 8; i++){
        x = x + (bits[7-i] * y);
        y = y*2;
    }
    return x;
}














































