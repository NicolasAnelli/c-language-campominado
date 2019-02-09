/*
 * Implementar um jogo de campo minado que atenda as premissas
 * - Tabuleiro 10x10
 * - o jogador tem 5 vidas
 * - os valores possíveis serão 0-3
 * - deve-se informar linha e coluna para a aposta
 * - acumular os pontos do jogador
 * - não pode jogar novamente linha e coluna ja informada
 * - se acertar o valor 0 perde
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void cls();

int main() {

	char memoria[10][10];
	int tabuleiro[10][10];
	int vidas = 5;
	int pontos = 0, jogadas = 0;;

	int i, j;
	int linha_escolhida, coluna_escolhida;

	srand(time(NULL));

	// Inicializa posições da memória
	for(i=0; i<10; i++)
		for(j=0; j<10; j++)
			memoria[i][j] = '?';

	// Inicializa posições do tabuleiro com números aleatórios
	for(i=0; i<10; i++)
		for(j=0; j<10; j++)
			tabuleiro[i][j] = rand()%4;

	do {
		cls();

		printf("----------------------------------------------------------------------------------\n");
		printf("Score: %i \t\t\tMine Field\t\t\t\t Lives: %i \n", pontos, vidas);
		printf("----------------------------------------------------------------------------------\n");

		// Imprime Header das colunas
		printf("L\\C");
		for(i=0; i<10; i++)
			printf("\t%i:", i);
		printf("\n\n");

		// Imprime tabuleiro
		for(i=0; i<10; i++) {
			// Escreve o numero da linha a ser montada
			printf("%i: \t", i);

			for(j=0; j<10; j++) {
				// Se ainda não tiver sido descoberto, printa caractere '?'
				if(memoria[i][j] == '?')
					printf("%c \t", memoria[i][j]);
				// senao printa o valor do tabuleiro
				else
					printf("%i \t", tabuleiro[i][j]);
			}
			printf("\n\n");
		}

		printf("----------------------------------------------------------------------------------\n");
		// Pergunta a jogada
		printf("Digite a linha desejada: ");
		scanf("%i", &linha_escolhida);

		printf("Digite a coluna desejada: ");
		scanf("%i", &coluna_escolhida);

		jogadas++;

		// TODO tratar valores fora do intervalo aceito

		// Processa a jogada escolhida
		if('?' == memoria[linha_escolhida][coluna_escolhida]) {
			memoria[linha_escolhida][coluna_escolhida] = 'X';

			// Se acertar o 0, perde uma vida
			if(tabuleiro[linha_escolhida][coluna_escolhida] == 0) {
				vidas--;
			}

			// Adiciona os pontos da posição escolhida
			pontos += tabuleiro[linha_escolhida][coluna_escolhida];
		} else {
			// Ja foi essa posição, fazer algo?
		}

	} while(vidas > 0);

	// Imprime score final
	cls();
	printf("Fim do jogo!\n\n");
	printf("Voce fez %i pontos, em %i jogadas. \n\n\n", pontos, jogadas);

	return 0;
}

void cls() {
	// Se for windows, substituir por
	// system("cls");

	// Possível outra soluçao
	// printf("\e[1;1H\e[2J");

	// Se for Mac
	system("clear");
}
