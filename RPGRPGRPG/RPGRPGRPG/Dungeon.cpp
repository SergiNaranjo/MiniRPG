#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include "Consts.h"
#include "Character.h"

void PrintMap(char map[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++) {
		// Imprimir la línea divisoria superior
		for (int j = 0; j < COLS; j++) {
			printf(" ---");
		}
		printf("\n");

		// Imprimir las filas del tablero
		for (int j = 0; j < COLS; j++) {
			printf("|   ");
		}
		printf("|\n");


		// Imprimir las filas del tablero
		for (int j = 0; j < COLS; j++) {
			printf("|   ");
		}
		printf("|\n");

		for (int j = 0; j < COLS; j++) {
			printf("|   ");
		}
		printf("|\n");
	}

	// Imprimir la última línea divisoria
	for (int j = 0; j < ROWS; j++) {
		printf(" ---");
	}
	printf("\n");
}

void Dungeon()
{
	char map[ROWS][COLS];

	// DUNGEON
	Player stats;

	printf("------DUNGEON------\n");
	printf("\n");

	printf("Player -> P   Enemy -> E  Chest -> C\n");
	printf("\n");

	printf("Health: %d / %d\n", stats.actualHealth, stats.health);
	printf("Potions: %d / %d\n", stats.potions, MAX_POTIONS);
	printf("Moves: %d / %d\n", stats.agility, MAX_AGILITY);
	printf("\n");


	PrintMap(map);


	printf("\n");
	printf("-------------------\n");
	printf("\n");
	printf("WASD -> Move\n");
	printf("P -> Potion\n");
	printf("\n");
	printf("Enter your action\n");
}