#pragma once
#include "Consts.h"

struct Player
{
	char character = 'P';
	int gold = 0;
	int health = rand() % (MAX_HP_PLAYER - 1 - MIN_HP_PLAYER) + MIN_HP_PLAYER;
	int stamina = rand() % (MAX_STAMINA_PLAYER - 1 - MAX_STAMINA_PLAYER) + MIN_STAMINA_PLAYER;
	int agility = MAX_AGILITY;
	int potions = MAX_POTIONS;
	int actualHealth = health;
	int actualStamina = stamina;
	int actualPotions = potions;
	bool isDead = false;
};