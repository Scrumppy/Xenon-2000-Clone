#pragma once

#include "Pawn.h"
#include "Vector2D.h"

class TransformComponent;
class SpriteComponent;
class Companion;

enum class WeaponAugment : int
{
	DEFAULT = 0,
	MEDIUM = 1,
	HEAVY = 2
};

class Player : public Pawn
{

public:
	Player();
	~Player();

	virtual void Init();

	virtual void Update();

	virtual void Fire();

	void AddPlayerCompanions();

	virtual void BeginOverlap(Entity* otherEntity);
	virtual void EndOverlap(Entity* otherEntity);

	virtual void TakeDamage(float damage);

	void BoostHealth(float health);

	bool CanFire();

	bool IsFiring();

	inline Vector2D GetPosition() { return playerPosition; }

	inline WeaponAugment GetWeaponAugment() { return currentWeaponAugment; }

	inline TransformComponent* GetTransform() { return playerTransform; }

	inline int GetLives() { return playerLives; }

	void FireCooldown();

	void UpgradeWeapon(WeaponAugment upgrade);

	void AttachCompanion();

	void ResetLife();

	bool IsAlive();

	int numOfCompanions;

private:
	Vector2D playerStartPosition;
	Vector2D playerPosition;
	float playerSpeed;

	TransformComponent* playerTransform = nullptr;
	SpriteComponent* spriteComponent = nullptr;

	float fireTimer;
	float fireTimerMax;

	bool canFire;
	bool isFiring;

	int playerLives;

	WeaponAugment currentWeaponAugment;

	Vector2D gunOffset;

	Companion* rightCompanion;
	Companion* leftCompanion;

	std::vector<Companion*> playerCompanions;
};