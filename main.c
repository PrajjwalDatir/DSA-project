/*
-----------------------------------------------------------------------------
CHAIN REACTION GAME 
111803131
DIV.2 S1 BATCH
PRAJJWAL DATIR
-----------------------------------------------------------------------------
* M x M board. 
* Configurable by user. 
* Upto 1024X1024 for current version.
* N human players to be supported.  


Chain Reaction is a Strategy Game for 1 To 8 Players playing simultaneously.

Objective of the game is to Eliminate all of the Opponent's Balls by Strategically Exploding your Balls and Owing neighbor Boxes.

A player may only put an Ball in an empty Box or a Box having Ball of its own color. When the Box reaches threshold,The Ball Explodes and move to neighbor Boxes.
When there is no Balls of the opponent on the Board : You Win!
*/




/*All recommemded libraries are included*/
#include<stdio.h>
#include<stdlib.h>
#include"chain.h"
#include<error.h>

int main()
{
	/*this two variables tempx tempy store the current 
	given input of the location */
	int tempx, tempy;

	printf("\nEnter the number of players!\n");
	/*it scans the total number of players to be played*/
	scanf("%d", &players);

	printf("\nEnter matrix less than 1024X1024 :");
	/*it scans the input about the size of the board user want.*/
	scanf("%d%d", &limitx, &limity);

	/*this reduces limitx and limity each by 1 because in C, one start counting from 0*/
	limitx--;
	limity--;

	/*this loop assigns 0 value and TRANS colour which means that boxes in the board
	belong to no one at the start*/
	for (int i = 0; i < limitx; i++)
	{
		for (int j = 0; j < limity; j++)
		{
			board[i][j] = 0;
			color[i][j] = TRANS;
		}
	}
	/*chance starts with 0 i.e. through player 1 game starts*/
	chance = 0;
	winner == 0;
	Exit1 = 0;
	Exit2 = 0;
	Exit3 = 0;
	blasted = 0;
	printf("\nCAUTION : typing anything except numbers isn't allowed!\n");
	sleep(2);
	printf("Enter your location as the co-ordinates of the box where you want to add a ball\n\n");
	sleep(2);

	/*Here onwards Game starts*/	
	while (1)/*an infinite loop till the game ends.*/
	{	
		/*This if() conditioncan be used if % operator on large number is slower than if()
		/*if(chance >= 100*players)
			chance = 0;*/

		/*scannow() is called first everytime the loop runs so that we keep getting
		updates about the players.s*/	
		Exit2 = scannow();

		/*after taking updates show() function shows us the board so that we can place our balls on it*/
		show();		

		/*this scans the two variables which store the current 
		given input in tempx and tempy*/
		printf("\nEnter location\n");
		scanf("%d%d", &tempx, &tempy);
		
		/*this reduces tempx and tempy each by 1 because in C, one start counting from 0*/
		tempx--;
		tempy--;
		
		/*This if() is for checking whether the inputs are in given bounded matrix or not*/		
		if (tempx < 0 || tempy < 0 || tempx>limitx || tempy>limity)
		{
			printf("Kindly input correct location, wait 2 seconds for your sins\n");
			//system("PAUSE");
			sleep(2);
			//getchar();
			continue;
		}
		
		/*this else if() is for checking whether we are putting values in different player's place or not*/
		else if (color[tempx][tempy] != (chance % players) + 1 && color[tempx][tempy] != 0)
		{
			printf("You cannot play on other players location, wait 2 seconds for your sins\n");
			sleep(2);
			//getchar();
			//int pause(void);
			continue;
		}

		/* if above conditions are false then we pass our location to the add() function for further operations*/
		else
			Exit3 = add(tempx, tempy);
		
		/*If infinte chain reaction happens then it declares the winner and returns*/
		if(Exit2 == 1){
			printf("WINNER WINNER CHICKEN DINNER\n!");
			sleep(2);
			break;
			return 0;
		}
		if(Exit3 == 1){
			printf("\n not able to compute!\n\n'");
			sleep(2);
			break;
			return 0;
		}
		
		/*it keeps increasing chance so that next player will be prompted to play.*/
		chance++;
	}
	return 0;
}