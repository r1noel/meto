#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "enemy_base.h"
#include "player.h"

class TrackingEnemy : public EnemyBase {
public:

	TrackingEnemy();
	void update(float delta_time);
	void draw();
	tnl::Vector3 te_pos_;

private:

	Shared<Player> player_;

};

class LapsEnemy : public EnemyBase {
public:

	LapsEnemy();

};

class ShootEnemy : EnemyBase {
public:

	ShootEnemy();

};

