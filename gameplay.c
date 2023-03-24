#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

void decision(int a, int b, char *user_name, int *user_score, int *computer_score)
{
	if(a == b)
	{
		printf("\t\tDraw\n");
	}
	else{
		if (a == 2 && b == 0 || a == 1 && b == 0 || a == 2 && b == 1)
		{
			*user_score += 1;
			printf("\t\t*****%s Wins*****\n", user_name);
		}
		else if (a == 0 && b == 2 || a == 0 && b == 1 || a == 1 && b == 2)
		{
			*computer_score += 1;
			printf("\t\t*****COM Wins*****\n");
		}
	}
}

void start(int user, int computer, char *user_name, int *user_score, int *computer_score)
{
	srand(time(NULL));

	// Declarations

	int *user_ptr;
	int *computer_ptr;

	// Initializations

	user_ptr = &user;
	computer_ptr = &computer;
	*computer_ptr = rand() % 3;

	// Process/Functions

	printf("\t\t*****Rock**Paper**Scissors*****\n");

	printf("\t\t\t%s (%d) : (%d) COM\n", user_name, *user_score, *computer_score);

	printf("\t\t-----Rules/instructions-----\n");

	printf("\t\t* Pick a choice between 0 - 2.\n\t\t* 0 for Rock, 1 for Paper, 2 for Scissors.\n");

	printf("\n\t\t0: Rock 1: Paper 2: Scissors: ");
	scanf("%d", user_ptr);

	// Conditionals

	if (*user_ptr == 0)
	{
		printf("\t\t%s: Rock\n", user_name);
		rock();
		putchar('\n');
	}
	else if (*user_ptr == 1)
	{
		printf("\t\t%s: Paper\n", user_name);
		paper();
		putchar('\n');
	}
	else if (*user_ptr == 2)
	{
		printf("\t\t%s: Scissors\n", user_name);
		scissors();
		putchar('\n');
	}
	
	if (*computer_ptr == 0)
	{
		printf("\t\tCOM: Rock\n");
		rock();
		putchar('\n');
	}
	else if (*computer_ptr == 1)
	{
		printf("\t\tCOM: Paper\n");
		paper();
		putchar('\n');
	}
	else if (*computer_ptr == 2)
	{
		printf("\t\tCOM: Scissors\n");
		scissors();
		putchar('\n');
	}

	decision(*user_ptr, *computer_ptr, user_name, user_score, computer_score);
}