#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void printBoard(char memory[10][10], int board[10][10], int points, int lives);
void clearScreen();

int main() {

	char memory[10][10];
	int board[10][10];
	int lives = 5;
	int points = 0, plays = 0;;

	int i, j;
	int c_line, c_column;

	srand(time(NULL));

	// Initializing memory positions
	for(i=0; i<10; i++)
		for(j=0; j<10; j++)
			memory[i][j] = '?';

	// Initializing table with random numbers lower than 4
	for(i=0; i<10; i++)
		for(j=0; j<10; j++)
			board[i][j] = rand()%4;

	while (1) {

		clearScreen();
		printBoard(memory, board, points, lives);

		printf("Type the target ROW: ");
		scanf("%i", &c_line);

		clearScreen();
		printBoard(memory, board, points, lives);

		printf("Type the target COLUMN: ");
		scanf("%i", &c_column);

		plays++;

		if(memory[c_line][c_column] == '?') {
			memory[c_line][c_column] = 'X';

			// If hits zero, loses one live
			if(board[c_line][c_column] == 0) {
				lives--;
			}

			// Adding points
			points += board[c_line][c_column];
		} else {
			// Already hit this, should i do something?
		}

		if (lives == 0) {
			clearScreen();
			printf("Game over!\n\n");
			printf("You did %i points, in %i plays. \n\n\n", points, plays);
			return EXIT_SUCCESS;
		}
	}
}

void printBoard(char memory[10][10], int board[10][10], int points, int lives) {

	int i, j;

	printf("----------------------------------------------------------------------------------\n");
	printf("Score: %i \t\t\tMine Field\t\t\t\t Lives: %i \n", points, lives);
	printf("----------------------------------------------------------------------------------\n");

	// Imprime Header das colunas
	printf("L\\C");
	for(i=0; i<10; i++)
		printf("\t%i:", i);
	printf("\n\n");

	// Imprime board
	for(i=0; i<10; i++) {
		// Escreve o numero da linha a ser montada
		printf("%i: \t", i);

		for(j=0; j<10; j++) {
			// Se ainda não tiver sido descoberto, printa caractere '?'
			if(memory[i][j] == '?')
				printf("%c \t", memory[i][j]);
			// senao printa o valor do board
			else
				printf("%i \t", board[i][j]);
		}
		printf("\n\n");
	}

	printf("----------------------------------------------------------------------------------\n");

}

void clearScreen() {
#if defined(_WIN32) || defined(_WIN64)
	system("cls");
#endif
#if defined(__unix__) || defined(__APPLE__) || defined(__linux__)
	printf("\e[1;1H\e[2J");
#endif
}
