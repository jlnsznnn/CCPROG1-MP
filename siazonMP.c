/******************************************************************************
This is to certify that this project is my own work, based on my personal
efforts in studying and applying the concepts learned. I have constructed
the functions and their respective algorithms and corresponding code by
myself. The program was run, tested, and debugged by my own efforts. I
further certify that I have not copied in part or whole or otherwise
plagiarized the work of other students and/or persons.
Siazon, Jalene Graciella T. - 12209244 - S23A
******************************************************************************/
/*   
     Description:      In this game, players have the option to either move left, 
	                   move right, or shoot every turn. When the player makes a 
					   move, the enemy begins to move in a pattern in their turn. 
					   The player can only move one tile per turn and when firing 
					   a laser, if there are multiple enemies on the same column, 
					   the enemy that is closest to the player will be the only 
					   one destroyed. The player receives 10 points for each opponent 
					   they destroy, but the enemy will respawn at the top of the map 
					   again. The game will end once the player attains a score of 100 
					   points, meaning that  the player has won, or when the enemies 
					   reach the bottom of the map, which means that the player has lost.
					   
     Programmed by:    Siazon, Jalene Graciella T.  - S23A
	 
     Last modified:    12/04/22
	 
     Version:          Version 12
	 
	 Acknowledgements: Neso Academy. (2018, August 5). Special Programs in C − Pyramid 
	                   of Stars. YouTube. https://www.youtube.com/watch?v=KdM6OrvcjPI
                       - this tutorial helped me on printing the game's tiles
	 
*/

#include <stdio.h>

/*  This function is for displaying the game tiles that shows the enemies and player
    Precondition: All parameters are whole numbers and non-negative values 
	@param nScore shows the player's score
	@param nRow is the row of the game tiles
	@param nCol is the column of the game tiles
	@param nEnemyRow1 is Enemy 1's position in the row (vertical)
	@param nEnemyRow2 is Enemy 2's position in the row (vertical)
	@param nEnemyRow3 is Enemy 3's position in the row (vertical)
	@param nEnemyCol1 is Enemy 1's position in the column (horizontal)
	@param nEnemyCol2 is Enemy 2's position in the column (horizontal)
	@param nEnemyCol3 is Enemy 3's position in the column (horizontal)
	@param nPlayerRow is the player's position in the row
	@param nPlayerCol is the player's position in the column
	@return void
*/
void showTiles(int nScore, int nRow, int nCol, int nEnemyRow1, 
               int nEnemyRow2, int nEnemyRow3, int nEnemyCol1, 
			   int nEnemyCol2, int nEnemyCol3, int nPlayerRow, 
			   int nPlayerCol)
{
	
	printf("___________________________\n\n");
	printf("Game Map:\n");
	printf("-----------------   * \n");

    // nested for loop that prints the enemies inside the tiles
	for (nRow = 1; nRow <= 5; nRow++)
	{
		for (nCol = 1; nCol <= 4 ; nCol++)
		{
			if ((nEnemyRow1 == nRow && nEnemyCol1 == nCol)||
			    (nEnemyRow2 == nRow && nEnemyCol2 == nCol)||
				(nEnemyRow3 == nRow && nEnemyCol3 == nCol))
			{
				printf("| X ");
			}
			else 
			{
				printf("|   ");
			}
		}
		// prints the number of rows on the side
		printf("|   %d\n", nRow); 
	}
	printf("-----------------   * \n");

    // nested for loop that prints the players inside the tiles
	for (nRow = 1; nRow <= 1; nRow++)
	{
		for (nCol = 1; nCol <= 4 ; nCol++)
		{
			if (nPlayerRow == nRow && nPlayerCol == nCol)
			{
				printf("| P ");
			}
			else 
			{
				printf("|   ");
			}
		}
		printf("|   *");
	}
	
	printf("\n-----------------   * \n");
	printf("Score: %.3d", nScore);
}

/*  This function makes enemy 1 move
    Precondition: All parameters are whole numbers and non-negative values
    @param *nEnemyCol1's value will be checked and adjusted depending on the condition
	@param *nEnemyRow1's value will be checked and adjusted depending on the condition
	@return void
*/
void enemy1Move (int *nEnemyRow1, int *nEnemyCol1)
{
    if (*nEnemyCol1 == 1 || *nEnemyCol1 == 2)
	{   
	    // condition for enemy 1 to move right 
		if (*nEnemyCol1 == 1 && (*nEnemyRow1 % 2 == 1))
		{
			*nEnemyCol1 += 1;
		} 
        // condition for enemy 1 to move right down
		else if (*nEnemyCol1 == 2 && (*nEnemyRow1 % 2 == 1))
		{
			*nEnemyRow1 += 1;
		}
		// condition for enemy 1 to move left 
		else if (*nEnemyCol1 == 2 && (*nEnemyRow1 % 2 == 0))
		{
			*nEnemyCol1 -= 1;
		}
		// condition for enemy 1 to move left down
		else if (*nEnemyCol1 == 1 && (*nEnemyRow1 % 2 == 0))
		{
			*nEnemyRow1 += 1;
		}
	}
}

/*  This function makes enemy 2 move
    Precondition: All parameters are whole numbers and non-negative values
    @param *nEnemyCol2's value will be checked and adjusted depending on the condition
	@param *nEnemyRespawn is a new variable made to create a more unique condition 
	        which value will also be checked and adjusted
	@param *nEnemyRow2's value will be checked and adjusted depending on the condition
	@return void
*/

void enemy2Move (int *nEnemyRow2, int *nEnemyCol2, int *nEnemyRespawn)
{
	if (((*nEnemyCol2 == 2) && (*nEnemyRespawn != 0))||( *nEnemyCol2 == 3))
	{
		// condition for enemy 2 to move right
		if (*nEnemyCol2 == 2 && (*nEnemyRow2 % 2 == 1))
		{
			*nEnemyCol2 += 1;	
			*nEnemyRespawn = *nEnemyCol2;
		} 
		// condition for enemy 2 to move right down
		else if (*nEnemyCol2 == 3 && (*nEnemyRow2 % 2 == 1))
		{
			*nEnemyRow2 += 1;
			*nEnemyRespawn = *nEnemyCol2;
		}
		// condition for enemy 2 to move left
		else if (*nEnemyCol2 == 3 && (*nEnemyRow2 % 2 == 0))
		{
			*nEnemyCol2 -= 1;
			*nEnemyRespawn = *nEnemyCol2;
		}	
		// condition for enemy 2 to move left down
		else if (*nEnemyCol2 == 2 && (*nEnemyRow2 % 2 == 0))
		{
			*nEnemyRow2 += 1;
			*nEnemyRespawn = *nEnemyCol2;
		} 
	}
	// conditions for enemy 2 movement when respawned
	else if (*nEnemyCol2 == 1 || *nEnemyCol2 == 2 )
	{   
		if (*nEnemyRespawn == 1 && (*nEnemyRow2 % 2 == 1))
		{
			// making the conditon more unique 
			*nEnemyRespawn -= 1; 
			*nEnemyCol2 = *nEnemyRespawn + 2;
		}
		else if (*nEnemyCol2 == 2 && (*nEnemyRow2 % 2 == 1))
		{
			*nEnemyRow2 += 1;
		}
		else if (*nEnemyCol2 == 2 && (*nEnemyRow2 % 2 == 0))
		{
			// making the conditon more unique 
			*nEnemyRespawn += 1;
			*nEnemyCol2 = *nEnemyRespawn;
		}
		else if (*nEnemyRespawn == 1 && (*nEnemyRow2 % 2 == 0))
   	    {
			*nEnemyRow2 += 1;
		}
	}
}

/*  This function makes enemy 3 move
    Precondition: All parameters are whole numbers and non-negative values
    @param *nEnemyCol3's value will be checked and adjusted depending on the condition
	@param *nEnemyRow3's value will be checked and adjusted depending on the condition
	@return void
*/
void enemy3Move (int *nEnemyRow3, int *nEnemyCol3)
{
	if (*nEnemyCol3 == 3 || *nEnemyCol3 == 4)
	{
		// condition for enemy 3 to move right 
		if (*nEnemyCol3 == 3 && (*nEnemyRow3 % 2 == 1))
		{
			*nEnemyCol3 += 1;	
		} 
		// condition for enemy 3 to move right down
		else if (*nEnemyCol3 == 4 && (*nEnemyRow3 % 2 == 1))
		{
			*nEnemyRow3 += 1;
		}
		// condition for enemy 3 to move left 
		else if (*nEnemyCol3 == 4 && (*nEnemyRow3 % 2 == 0))
		{
			*nEnemyCol3 -= 1;
		}
		// condition for enemy 3 to move left down
		else if (*nEnemyCol3 == 3 && (*nEnemyRow3 % 2 == 0))
		{
			*nEnemyRow3 += 1;
		}
	}
	// conditions for enemy 3 movement when respawned
	else if (*nEnemyCol3 == 1 || *nEnemyCol3 == 2)
	{   
		if (*nEnemyCol3 == 1 && (*nEnemyRow3 % 2 == 1))
		{
			*nEnemyCol3 += 1;
		} 
		else if (*nEnemyCol3 == 2 && (*nEnemyRow3 % 2 == 1))
		{
			*nEnemyRow3 += 1;
		}
		else if (*nEnemyCol3 == 2 && (*nEnemyRow3 % 2 == 0))
		{
			*nEnemyCol3 -= 1;
		}
		else if (*nEnemyCol3 == 1 && (*nEnemyRow3 % 2 == 0))
		{
			*nEnemyRow3 += 1;
		}
	}
}

/*  This function shows what will happen if the player's laser fire
    Precondition: All parameters are whole numbers and non-negative values
	@param *nPlayerCol's value will be checked
	@param *nEnemyRow1's value will be checked and adjusted based on the condition
	@param *nEnemyCol1's value will be checked and adjusted based on the condition
	@param *nEnemyRow2's value will be checked and adjusted based on the condition
	@param *nEnemyCol2's value will be checked and adjusted based on the condition
	@param *nEnemyRow3's value will be checked and adjusted based on the condition
	@param *nEnemyCol3's value will be checked and adjusted based on the condition
	@param *nScore's value will be adjusted based on the condition
	@param *nEnemyRespawn's value will be adjusted based on the condition
	@return void
*/
void playerFire(int *nScore, int *nEnemyRespawn, int *nPlayerCol, 
                int *nEnemyRow1, int *nEnemyRow2, int *nEnemyRow3,
				int *nEnemyCol1, int *nEnemyCol2, int *nEnemyCol3)
{	

	if ((*nPlayerCol == *nEnemyCol1) && (*nPlayerCol != *nEnemyCol2) &&
    	(*nPlayerCol != *nEnemyCol3))
	{
		*nEnemyCol1 = 1;
		*nEnemyRow1 = 1;
		*nScore += 10;
	}
	
	else if ((*nPlayerCol != *nEnemyCol1) && (*nPlayerCol == *nEnemyCol2) && 
	         (*nPlayerCol != *nEnemyCol3))
	{
		*nEnemyCol2 = 1;
		*nEnemyRespawn = *nEnemyCol2;
		*nEnemyRow2 = 1;
		*nScore += 10;
	}

	else if ((*nPlayerCol != *nEnemyCol1) && (*nPlayerCol != *nEnemyCol2) && 
	         (*nPlayerCol == *nEnemyCol3))
	{
		*nEnemyCol3 = 1;
		*nEnemyRow3 = 1;
		*nScore += 10;
	}
	
	// shooting only one enemy conditions for the bonus points
	else if ((*nPlayerCol == *nEnemyCol1) && (*nPlayerCol == *nEnemyCol2) && 
	         (*nPlayerCol != *nEnemyCol3))
	{
		if (*nEnemyRow1 > *nEnemyRow2)
		{
		*nEnemyCol1 = 1;
		*nEnemyRow1 = 1;
		*nScore += 10;
		}
		else if(*nEnemyRow1 < *nEnemyRow2)
		{
		*nEnemyCol2 = 1;
		*nEnemyRespawn = *nEnemyCol2;
		*nEnemyRow2 = 1;
		*nScore += 10;
		}
	}
	
	else if ((*nPlayerCol == *nEnemyCol1) && (*nPlayerCol != *nEnemyCol2) && 
	         (*nPlayerCol == *nEnemyCol3))
	{
		if (*nEnemyRow1 > *nEnemyRow3)
		{
		*nEnemyCol1 = 1;
		*nEnemyRow1 = 1;
		*nScore += 10;
		}
		else if(*nEnemyRow1 < *nEnemyRow3)
		{
		*nEnemyCol3 = 1;
		*nEnemyRow3 = 1;
		*nScore += 10;
		}
	}
	
	else if ((*nPlayerCol != *nEnemyCol1) && (*nPlayerCol == *nEnemyCol2) && 
	         (*nPlayerCol == *nEnemyCol3))
	{
		if (*nEnemyRow2 > *nEnemyRow3)
		{
		*nEnemyCol2 = 1;
		*nEnemyRespawn = *nEnemyCol2;
		*nEnemyRow2 = 1;
		*nScore += 10;
		}
		else if(*nEnemyRow2 < *nEnemyRow3)
		{
		*nEnemyCol3 = 1;
		*nEnemyRow3 = 1;
		*nScore += 10;
		}
	}
	
	else if ((*nPlayerCol == *nEnemyCol1) && (*nPlayerCol == *nEnemyCol2) && 
	         (*nPlayerCol == *nEnemyCol3))
	{
		if ((*nEnemyRow1 > *nEnemyRow2) && (*nEnemyRow1 > *nEnemyRow3))
		{
		*nEnemyCol1 = 1;
		*nEnemyRow1 = 1;
		*nScore += 10;
		}
		else if ((*nEnemyRow2 > *nEnemyRow1) && (*nEnemyRow2 > *nEnemyRow3))
		{
		*nEnemyCol2 = 1;
		*nEnemyRespawn = *nEnemyCol2;
		*nEnemyRow2 = 1;
		*nScore += 10;
		}
		else if ((*nEnemyRow3 > *nEnemyRow1) && (*nEnemyRow3 > *nEnemyRow2))
		{
		*nEnemyCol3 = 1;
		*nEnemyRow3 = 1;
		*nScore += 10;
		}
	}
	enemy1Move(nEnemyRow1, nEnemyCol1);
	enemy2Move(nEnemyRow2, nEnemyCol2, nEnemyRespawn);
	enemy3Move(nEnemyRow3, nEnemyCol3);
}

/*  This function will be called into the main to show the player and enemies movements
    Precondition: All parameters are whole numbers and non-negative values
	@param nAction's value will be checked
	@param *nPlayerCol's value will be checked and adjusted based on the condition
	@param *nEnemyRow1 will display its current state
	@param *nEnemyCol1 will display its current state
	@param *nEnemyRow2 will display its current state 
	@param *nEnemyCol2 will display its current state 
	@param *nEnemyRow3 will display its current state 
	@param *nEnemyCol3 will display its current state 
	@param *nScore will display its current state 
	@param *nEnemyRespawn will display its current state
	@return void
*/
void playerEnemyMove(int nAction, int *nScore, int *nPlayerCol, 
                     int *nEnemyRow1, int *nEnemyCol1, int *nEnemyRow2,
				     int *nEnemyCol2, int *nEnemyRow3, int *nEnemyCol3,
					 int *nEnemyRespawn)
{
	if (nAction == 1)
	{    
        /* condition so that the player won't go outside the tile 
		and the enemies don't move as it counts as an invalid action
		if action 2 is chosen while it's on the outermost left*/
			   
		if (*nPlayerCol > 1)
		{
			*nPlayerCol -= 1;
			enemy1Move (nEnemyRow1, nEnemyCol1);
			enemy2Move (nEnemyRow2, nEnemyCol2, nEnemyRespawn);
			enemy3Move (nEnemyRow3, nEnemyCol3);
		}
		else if (*nPlayerCol == 1)
		{
			*nPlayerCol -= 0;
			printf("\n  ------------------\n");
		    printf(" | Invalid Action!! |\n");
		    printf("  ------------------\n");
	    }
	}
	else if (nAction == 2)
	{   
        /* condition so that the player won't go outside the tile 
		and the enemies don't move as it counts as an invalid action
		if action 2 is chosen while it's on the outermost right*/
			   
		if (*nPlayerCol >= 1 && *nPlayerCol < 4)
		{
			*nPlayerCol += 1;
			enemy1Move (nEnemyRow1, nEnemyCol1);
			enemy2Move (nEnemyRow2, nEnemyCol2, nEnemyRespawn);
			enemy3Move (nEnemyRow3, nEnemyCol3);
		}
		else if (*nPlayerCol == 4)
		{
			*nPlayerCol -= 0;
			printf("\n  ------------------\n");
		    printf(" | Invalid Action!! |\n");
		    printf("  ------------------\n");
	    }
	}
	else if (nAction == 3)
	{
		*nPlayerCol -= 0;
		playerFire(nScore, nEnemyRespawn, nPlayerCol, 
                   nEnemyRow1, nEnemyRow2, nEnemyRow3,
				   nEnemyCol1, nEnemyCol2, nEnemyCol3);
	}
	else if (nAction != 1 || nAction != 2 || nAction != 3)
	{   
        // also invalid if a number not among the displayed action is chosen
		printf("\n  ------------------\n");
		printf(" | Invalid Action!! |\n");
		printf("  ------------------\n");
	}
}

/*  This function shows the game's status or when will the player win or lose
    Precondition: All parameters are whole numbers and non-negative values
	@param nScore's value is to be checked
	@param nRow will display its current state 
	@param nCol will display its current state 
	@param nEnemyRow1's value will be checked and will display its current state 
	@param nEnemyRow2's value will be checked and will display its current state 
	@param nEnemyRow3's value will be checked and will display its current state 
	@param nEnemyCol1 will display its current state 
	@param nEnemyCol2 will display its current state 
	@param nEnemyCol3 will display its current state 
	@param nPlayerRow will display its current state 
	@param nPlayerCol will display its current state 
	@return nGameOver which will terminate the program if the player win or loses
	        if its value turns into 1
*/
int gameStatus(int nScore, int nRow, int nCol, int nEnemyRow1, 
               int nEnemyRow2, int nEnemyRow3, int nEnemyCol1, 
			   int nEnemyCol2, int nEnemyCol3, int nPlayerRow, 
			   int nPlayerCol)
{
	int nGameOver = 0;
	// condition when the player wins
	if (nScore >= 100)
	{
		showTiles(nScore, nRow, nCol, nEnemyRow1, nEnemyRow2, 
	              nEnemyRow3, nEnemyCol1, nEnemyCol2, nEnemyCol3, 
			      nPlayerRow, nPlayerCol);
		printf("\n===========================\n");
		printf("         *(^ O ^)* \n");
		printf("     -----------------\n");
		printf("    | V I C T O R Y ! |\n");
		printf("     -----------------\n");
		printf("===========================\n");
		nGameOver += 1; // terminates the program
	}
	// condition when the player loses
	else if (nEnemyRow1 > 5 || nEnemyRow2 > 5 || nEnemyRow3 > 5)
	{
		showTiles(nScore, nRow, nCol, nEnemyRow1, nEnemyRow2, 
	              nEnemyRow3, nEnemyCol1, nEnemyCol2, nEnemyCol3, 
			      nPlayerRow, nPlayerCol);
		printf("\n===========================\n");
		printf(" The enemy has reached the\n   the bottom of the map!\n");
		printf("    -----------------\n");
		printf("   | D E F E A T E D |\n");
		printf("    -----------------\n");
		printf("===========================\n");
		nGameOver += 1; // terminates the program
	}
	return nGameOver;
}

int main()
{
	// rows and columns in the tiles
	int nRow = 1, nCol = 1; 
	
	// enemies starting position
	int nEnemyRow1 = 1, nEnemyCol1 = 1; 
	int nEnemyRow2 = 1, nEnemyCol2 = 2; 
	int nEnemyRow3 = 1, nEnemyCol3 = 3;
	
	//enemy 2 respawn variable
	int nEnemyRespawn = nEnemyCol2;
	
	// player starting position
	int nPlayerRow = 1, nPlayerCol = 1; 
	
	// others
	int nAction;
	int nScore = 0;
	int nOver = 0;
	
	// header
	printf("\n******************************\n");
	printf("* HIT ME WITH YOUR BEST SHOT *\n");
	printf("******************************\n");
	
	// loop used so that the game won't end until nOver is 1
	while(!nOver)
	{
	
	// display the tiles
	showTiles(nScore, nRow, nCol, nEnemyRow1, nEnemyRow2, 
	          nEnemyRow3, nEnemyCol1, nEnemyCol2, nEnemyCol3, 
			  nPlayerRow, nPlayerCol);
			  
	// choose action
	printf ("\nActions: \n [1] - move left\n [2] - move right\n [3] - fire laser\n");				 
	printf("\nInput Action: ");
	scanf("%d",&nAction);
	
	// move the player and the enemies
	playerEnemyMove(nAction, &nScore, &nPlayerCol, &nEnemyRow1, 
	                &nEnemyCol1,&nEnemyRow2, &nEnemyCol2, &nEnemyRow3, 
					&nEnemyCol3, &nEnemyRespawn);
					
	//check if player win or lose
	nOver = gameStatus (nScore, nRow, nCol, nEnemyRow1, nEnemyRow2, 
	                    nEnemyRow3, nEnemyCol1, nEnemyCol2, nEnemyCol3, 
			            nPlayerRow, nPlayerCol);
	}
	return 0;
}