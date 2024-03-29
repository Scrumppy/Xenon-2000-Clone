#pragma once

#include "GameEngine.h"
#include "World.h"
#include "GameObject.h"
#include <vector>

class PlayerLifeUI;
class Player;

class GameManager : public GameObject
{
public:
	GameManager()
	{

		player = nullptr;

		indexToRemove = 0;

		lonerSpawnTimer = 0.f;
		lonerSpawnTimerMax = 100.f + (rand() % (110 - 100) + 1);

		rusherSpawnTimer = 0.f;
		rusherSpawnTimerMax = 190 + (rand() % (205 - 190) + 1);

		debrisSpawnTimer = 150.f;
		debrisSpawnTimerMax = 150 + (rand() % (200 - 150) + 1);

		pickupSpawnTimer = 0.f;
		pickupSpawnTimerMax = 200.f + (rand() % (210 - 200) + 1);

		asteroidSpawnTimer = 0.f;
		asteroidSpawnTimerMax = 250.f + (rand() % (270 - 250) + 1);

		enemiesToSpawn = 0;
		pickupsToSpawn = 0;
	}

	~GameManager();

	static GameManager* GetInstance()
	{
		return m_instance = (m_instance != nullptr) ? m_instance : new GameManager();
	}

	void Init() override;

	void Update() override;

	template <typename T>
	void InstantiateProjectile(class Vector2D position, float projectileRange, float projectileSpeed)
	{
		if (&world)
		{
			world.CreateEntity<T>(position, projectileRange, projectileSpeed);
		}
	}

	void CreateLevel();

	void SpawnEnemies();

	void SpawnDebris();

	void SpawnPickups();

	void LoadUI();

	void EraseLife();

private:
	static GameManager* m_instance;

	World& world = GameEngine::GetEngine()->GetWorld();

	Player* player;

	std::vector<PlayerLifeUI*> playerLives;
	int indexToRemove;

	int enemiesToSpawn;

	//Spawn Timers
	float lonerSpawnTimer;
	float lonerSpawnTimerMax;

	float rusherSpawnTimer;
	float rusherSpawnTimerMax;

	float debrisSpawnTimer;
	float debrisSpawnTimerMax;

	float pickupSpawnTimer;
	float pickupSpawnTimerMax;

	int pickupsToSpawn;

	float asteroidSpawnTimer;
	float asteroidSpawnTimerMax;
};
