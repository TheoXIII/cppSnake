#include <iostream>
#include <ncurses.h>

using namespace std ; 


//蛇　ゲーム　
//foray into game c++

enum snakeDirection {
    stop = 0,
    left,
    right,
    up,
    down, 
};

snakeDirection sDir ;

void welcomeScreen() ;
void game() ;
void draw(WINDOW * win) ;
WINDOW * setUp() ;
void input(WINDOW * win) ;
void logic() ;

bool gameOver ; 
const int width = 50 ;
const int height = 15 ;

int coordnateX, coordinateY, foodX, foodY, pionts;

int main(){

    game() ; 
    
    return 0 ; 
}

void game(){

    initscr() ;
    welcomeScreen() ;
    WINDOW * win = setUp() ;

    while(!gameOver){

        draw(win) ;
        input(win) ;
        logic() ;
    }

    refresh() ;
    mvwprintw(win, height/2, width/2, "Game Over") ;
    endwin() ;
}

void welcomeScreen(){

    refresh() ;

    cout << "\n\n\n\t\tWelcome to snake press enter to continue \r " << endl  ;

    getch() ;
    refresh() ;

}

WINDOW * setUp(){


    WINDOW * win  = newwin(height, width, 5,5) ;

    gameOver = false ; 

    coordnateX = width / 2 ;
    coordinateY = height / 2  ; 

    foodX = rand() % width ;
    foodY = rand() % height ;  
    pionts = 0 ;

    wmove(win, coordnateX, coordinateY) ;

    return win ;
}

void draw(WINDOW * win){

    clear();

    refresh() ;

    box(win,0,0) ;
    mvwprintw(win, 0, 2," Snake ") ;
    mvwprintw(win, foodY, foodX, "@") ;
    wrefresh(win) ;
}

void input(WINDOW * win){

    keypad(win, true) ;

    refresh() ;

    int keyStroke = wgetch(win) ;

    if(keyStroke == KEY_UP){
        mvwprintw(win, height/2, width/2, "up") ;
    }
    if(keyStroke == KEY_DOWN){
        mvwprintw(win, height/2, width/2, "down") ;
    }
    if(keyStroke == KEY_LEFT){
        mvwprintw(win, height/2, width/2, "left") ;
    }
    if(keyStroke == KEY_RIGHT){
        mvwprintw(win, height/2, width/2, "right") ;
    }


    wrefresh(win) ;

}

void logic(){
     
}