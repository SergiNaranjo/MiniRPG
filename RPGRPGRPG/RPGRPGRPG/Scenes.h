#pragma once

enum Scenes {DUNGEON, COMBAT, CHEST, GAMEOVER};

struct Scene
{
	Scenes currentScene;
	void Dungeon(Scene& scene);
	void Combat(Scene& manager);
	void Chest();
	void GameOver(Scene& manager);
};


