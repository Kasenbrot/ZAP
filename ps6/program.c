#define _POSIX_C_SOURCE 200201L
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>

int main(){
    srand(time(NULL));/////
    initscr();/////
    cbreak();/////
    noecho();/////
    keypad(stdscr, TRUE);/////
    curs_set(FALSE);/////
    nodelay(stdscr, TRUE);/////
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    struct timespec ts = {
        .tv_sec = 0,
        .tv_nsec = 0.001 * 100000000L
    };

    char karty[32]={'7','7','8','8','9','9','D','D','J','J','Q','Q','K','K','A','A',
    '7','7','8','8','9','9','D','D','J','J','Q','Q','K','K','A','A'};
    int karty_skore[32]={7,7,8,8,9,9,10,10,1,1,1,1,2,2,11,11,
    7,7,8,8,9,9,10,10,1,1,1,1,2,2,11,11};
    int celkove_skore = 0; 
    int pokusy = 5;
    for (int x = 0; x < COLS-4; x++){
        for (int y = 0; y < LINES-2; y++){
            mvprintw(y+1,x+2,"|");
            ///refresh();
            ///nanosleep(&ts, NULL);
        }
    }
    for (int x = 0; x < COLS-8; x++){
        for (int y = 0; y < LINES-4; y++){
            mvprintw(y+2,x+4," ");
            refresh();
            nanosleep(&ts, NULL);
        }
    }
    mvprintw(LINES/2-8,COLS/2-6,"BLACKJACK");
    mvprintw(LINES/2-6,COLS/2-18,"vytaj v hre BLACKJACK tvojou ulohou");
    mvprintw(LINES/2-5,COLS/2-28,"je ziskat co najvysie skore z 5 hier, pocet pokusov: "
    "%d",pokusy);
    mvprintw(LINES/2-4,COLS/2-40,"(stlac 'N' pre novu kartu, stlac 'K' pre koniec kola, stlac 'QQ' pre koniec hry)");
    mvprintw(LINES/2+5,COLS/2-13,"tvoje celkove skore je:");
    mvprintw(LINES/2+6,COLS/2-2,"%d",celkove_skore);
    refresh();

    int skore = 0;
    int karta;

    for (int i = 0; i < pokusy; i++){
        int f = 0;
        while (f == 0){
            int input = getch();
            switch(input){
                case 'q': case 'Q':{
                    getchar();
                    endwin();
                    return EXIT_SUCCESS;
                    break;
                }
                case 'n': case 'N':{
                    if (skore < 21){
                        karta = rand()%32;
                        skore = skore + karty_skore[karta];
                        mvprintw(LINES/2-1,COLS/2-3,"[ ]");
                        if (karta < 16){
                            attron(COLOR_PAIR(1));
                            mvprintw(LINES/2-1,COLS/2-2,"%c",karty[karta]);
                            attroff(COLOR_PAIR(1));
                        }
                        else{
                            attron(COLOR_PAIR(2));
                            mvprintw(LINES/2-1,COLS/2-2,"%c",karty[karta]);
                            attroff(COLOR_PAIR(2));
                        }
                        mvprintw(LINES/2+1,COLS/2-11,"hodnota karty je: ""%d ",karty_skore[karta]);
                        mvprintw(LINES/2+2,COLS/2-16,"tvoje skore v tomto kole: ""%d",skore);
                        if (skore > 21){
                            mvprintw(LINES/2+3,COLS/2-15,"prekrocil si 21, stlac 'K'");
                        }
                    }
                    refresh();
                    break;
                }
                case 'k': case 'K':{
                    mvprintw(LINES/2+3,COLS/2-17,"                              ");
                    if (skore > 21){
                        skore = 0;
                    }
                    celkove_skore = celkove_skore + skore;
                    skore = 0;
                    mvprintw(LINES/2+2,COLS/2-16,"tvoje skore v tomto kole: ""%d  ",skore);
                    mvprintw(LINES/2+6,COLS/2-2,"%d",celkove_skore);
                    mvprintw(LINES/2-5,COLS/2-28,"je ziskat co najvysie skore z 5 hier, pocet pokusov: "
                    "%d",(pokusy-i-1));
                    f = 1;
                    refresh();
                    break;
                }
            }
        }
    }
    if (celkove_skore == 0){
        mvprintw(LINES/2+7,COLS/2-13,"        nic moc        ");
    }
    if (celkove_skore > 0){
        mvprintw(LINES/2+7,COLS/2-12,"mohlo to byt aj lepsie ");
    }
    if (celkove_skore > 40){
        mvprintw(LINES/2+7,COLS/2-12,"        priemer        ");
    }
    if (celkove_skore > 60){
        mvprintw(LINES/2+7,COLS/2-12,"      dobra praca      ");
    }
    if (celkove_skore > 80){
        mvprintw(LINES/2+7,COLS/2-12,"        vyborne        ");
    }
    refresh();




    //mvprintw(LINES/2+7,COLS/2-2,"%d",celkove_skore);

    getchar();/////
    endwin();/////
    return EXIT_SUCCESS;
}















