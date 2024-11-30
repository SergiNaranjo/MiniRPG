#pragma once


struct Enemy
{
	char enemy = 'E';
	int health = rand() % (MAX_HP_ENEMY - 1 - MIN_HP_ENEMY) + MIN_HP_ENEMY;
	int stamina = rand() % (MAX_STAMINA_ENEMY - 1 - MIN_STAMINA_ENEMY) + MIN_STAMINA_ENEMY;
	bool isDead;
	int actualEnemyHealth = health;
	int actualEnemyStamina = stamina;
};