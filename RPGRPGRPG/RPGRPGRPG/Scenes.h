#pragma once

enum Scenes {DUNGEON, COMBAT, CHEST};

struct Scene
{
	Scenes currentScene;
	void Dungeon();
	void Combat();
	void Chest();
};


