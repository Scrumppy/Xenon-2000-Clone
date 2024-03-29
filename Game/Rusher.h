#pragma once

#include "Pawn.h"
#include "Vector2D.h"

class TransformComponent;

class Rusher : public Pawn
{
public:
	Rusher();
	~Rusher();

	virtual void Init();
	virtual void Update();

	virtual void BeginOverlap(Entity* otherEntity);
	virtual void EndOverlap(Entity* otherEntity);

	virtual void Fire();

	virtual void TakeDamage(float damage);

private:
	Vector2D startPosition;
	Vector2D playerPosition;
	float speed;

	TransformComponent* transformComponent = nullptr;
};