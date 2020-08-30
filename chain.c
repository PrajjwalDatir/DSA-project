/*all the recommended libraries are included*/
#include<stdio.h>
#include<stdlib.h>
#include"chain.h"

/*check() is checks whether the location we entered is on the corner of the board or
on the edge of the board or is inside the board.
or will it explode scattering its balls to its adjacent sides */
int check(int x, int y)
{
		/*if it is on the edge*/
	if (limitx == x || x == 0 || limity == y || y == 0)
	{
		/*If it is on the corner*/
		if ((x == 0 && y == 0) || (x == 0 && y == limity) || (x == limitx && y == 0) || (x == limitx && y == limity))
		{
			if (board[x][y] >= 1) 
			{
				return 1;
			}
			else 
			{
				return 0; 
			}
		}
		else
		{
			if (board[x][y] >= 2) 
			{
				return 1; 
			}
			else 
			{ 
				return 0; 
			}
		}
	} 
	else
	{
		/*If it is inside of the board and not on edge or corner*/
		if (board[x][y] >= 3) 
		{
			return 1; 
		}
		else 
		{ 
			return 0; 
		}
	}
}

/*add() function is called through main() which adds one ball to the location taken through
input if check() returns that it will be stable even after adding it.
But if check() returns that it will explode after adding the ball to it
then add() calls blast()
here the chain reactions due to consecutive explodable boxes is handled using recursion*/
int add(int x, int y)
{
	blasted++;
	if (!check(x, y))
	{
		/*adds a ball to a box*/
		board[x][y]++;

		/*for unlimited number of players this can be used*/
		/*for(int i = 0; i < players; i++)
			if (chance % players == 0) {
				color[x][y] = i + 1; 
			}*/	
	
		if (chance % players == 0)
		{ /*for player 1*/
			color[x][y] = RED; 
		}
		if (chance % players == 1) 
		{ /*for player 2*/
			color[x][y] = GREEN; 
		}
		if (chance % players == 2) 
		{ /*for player 3*/
			color[x][y] = YELLOW; 
		}
		if (chance % players == 3) 
		{ /*for player 4*/
			color[x][y] = BLUE; 
		}
		if (chance % players == 4) 
		{ /*for player 5*/
			color[x][y] = ORANGE; 
		}
		if (chance % players == 5) 
		{ /*for player 6*/
			color[x][y] = PURPLE; 
		}
		if (chance % players == 6) 
		{ /*for player 7*/
			color[x][y] = VIOLET; 
		}
		if (chance % players == 7) 
		{ /*for player 8*/
			color[x][y] = WHITE; 
		}
	}
	else
	{
		/*Exit1 Stores the return value of the blast so that game can be overed*/
		Exit1 = blast(x, y);

		if (board[x][y] == 0)
		{	/*If there is no ball on this location then it gets TRANS coloureds*/
			color[x][y] = 0;
		}
		if (Exit1 == 1)
			return 1;
	}
	return 0;
}

/*blast() function is called through add when the box the user chooses is unstable after adding a ball to it
it explodes the box upon calling i.e. it distributes its existing balls to adjacent boxes
it only distributes a ball if the adjacent location is present that means it takes the location of the current box
and checks whether it is at the corner or edge or inside and it calls add() for each case*/
int blast(int x, int y)
{
	board[x][y] = 0;
	color[x][y] = 0;
	if (x + 1 <= limitx)
	{
		/*add() function is called on right side of the given location if it is explodable and the right box exists within the grid*/
		add(x + 1, y);
	}
	if (x - 1 >= 0)
	{
		/*add() function is called on left side of the given location if it is explodable and the left box exists within the grid*/
		add(x - 1, y);
	}
	if (y + 1 <= limity)
	{
		/*add() function is called on up side of the given location if it is explodable and the up box exists within the grid*/
		add(x, y + 1);
	}
	if (y - 1 >= 0)
	{
		/*add() function is called on down side of the given location if it is explodable and the down box exists within the grid*/
		add(x, y - 1);
	}
	return 0;
}


/*Show function simply shows the current state of the game*/
void show()
{
	for(i = 0; i < players; i++)
	{
		/*Lost[] is a concept to store the Playing or Lost status of the player
		and if a player is present in Lost[] then it's chance will be skipped
		also it increases the value of winner which again is used to declared the winner
		and the game when all other players loses except a single player*/
		if(Lost[chance % players] == 1)
			{
				chance++;
			}	
	}
	/*system("CLS");*///according to platforms
	system("clear");

	for (i = 0; i <= limitx; i++)
	{
		for (int j = 0; j <= limity; j++)
		{
			if (color[i][j] == 0) 
			{ 
				printf("0"); 
			}//TRANSPARENT
			if (color[i][j] == 1) 
			{ 
				printf("A"); 
			}//R
			if (color[i][j] == 2) 
			{ 
				printf("B"); 
			}//G
			if (color[i][j] == 3) 
			{ 
				printf("C"); 
			}//Y
			if (color[i][j] == 4) 
			{ 
				printf("D"); 
			}//B
			if (color[i][j] == 5) 
			{ 
				printf("E"); 
			}//O
			if (color[i][j] == 6) 
			{ 
				printf("F"); 
			}//P
			if (color[i][j] == 7) 
			{ 
				printf("G"); 
			}//V
			if (color[i][j] == 8) 
			{ 
				printf("H"); 
			}//White

			/*This prints the number of balls present in box of board of ith and jth location*/
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");

	/*To prompt the correct user to play now*/
	for (int i = players; i > 0; i--)
	{
		if ((chance % players) == (players - i)) {
			printf("PLAYER %d PLAY NOW\n", players - i + 1); 	
		}
	}
}

/*In scannow() flag variable concept is used. Through flag if the player does not has even a single box
of his colour even after playing at least once then it's flag is up or 1. which represents the loss
of that player*/
int scannow(void)
{
	int flag = 1, player_number;
	for (player_number = chance % players; player_number <= players; player_number++) 
	{
		flag = 1;
		for (i = 0; i <= limitx; i++)
		{
			for (j = 0; j <= limity; j++)
			{
				if (color[i][j] == player_number && Lost[player_number - 1] != 1) 
				{
					flag = 0;
				}
			}
		}
		if(flag == 1 && Lost[player_number - 1] != 1 && (chance > players))
		{
			/*winner is a variable which can be used to see if all other players are lost or not!*/
			winner++;
		}
		if (flag && (chance > players)/*number of players*/)
		{
				if(Lost[player_number - 1] != 1)
				{
					printf("PLAYER %d LOST\n", player_number);
					printf("wait 3 sec to tribute the loser!\n\n");
					sleep(3); /*pauses for 3 seconds*/
				}
		/*this assign a player as Lost through adding it to this array of losers*/
		Lost[player_number - 1] = 1;	
		}
	}
	if(winner >= (players -1) && (chance > players))
	{
		printf("Player %d Won\nWINNER WINNER CHICKEN DINNER!\n", chance % players);
		sleep(2000); /*To pause the screen for 2 seconds*/
		return 1;
	}
	return 0;
}