#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

/*add() funtion is created so that every input is added to the given location. 
Boundary conditions are already taken care in these function
also in add() check() function is called which decides whether the given location should be blasted or not. 
If it is unstable then blast() function is called in add() function if not then it returns*/
int add(int x, int y);


/*check() function checks whether the input location we are giving has reached it's limit of containing 'balls' 
or is available for the insertion of another ball onto that location*/
int check(int x, int y);


/*if the check() function returns 1 which means that given location is unstable 
then the function blast() comes into picture
blast() is used to blast the given funtion such that
its all existing adjacent locations will get 1 extra ball on their location
also it uses add() function to add the balls to adjacent locations.
If the next place where ball is added is unstable then it is taken care by using
check funtion in add so that it calls blast() again
this way Chain Reactions are taken care of
and it does not return till whole board is stable*/
int blast(int x, int y);


/*Show() funtion is the most basic funtion which prints which player will play now
it prints the current board status
it also take care of elimanating chance of lost players 
and it also declares the winner after completion of game*/
void show(void);


/*scannow() function keeps checking whether any player is lost or not 
if a player is lost then it passes that value to show() funtion so that it won't be prompted to play*/
int scannow(void);

/*this variable defines the extreme limits of the grid taken through the user input along X axis*/
int limitx;

/*this variable defines the extreme limits of the grid taken through the user input along X axis*/ 
int limity;

/*this variable stores total no of players in it*/
int players;

/*this variable keeps track of whose chance it is*/
int chance;

/*Lost[] keep track of losing player*/
int Lost[1024];

/*boxes is a varible to check if someone wins*/
int winner;

/*this variable is created to overcome some exceptions*/
int Exit1;

/*this variables is created to overcome some exceptions*/
int Exit2, Exit3;

/*this 2D arrey represents our board of chain reaction game*/
int board[1024][1024];

/*this variable keep track of the colour of player in every box of our board */
int color[1024][1024];

/*this enum is created to give users specific colours*/
//colors are limited we have to use 000 to FFF format to take lot many players.
enum colors { TRANS, RED, GREEN, YELLOW, BLUE, ORANGE, PURPLE, VIOLET, WHITE};

int i, j, blasted; /*counters*/