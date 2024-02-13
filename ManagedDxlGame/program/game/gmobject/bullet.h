#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "../chara/player.h"
#include "../chara/enemy.h"

class Bullet {
public:

	Bullet(tnl::Vector3 bulletpos) { bullet_pos_ = bulletpos; }
	float radius_ = 10;
	//’e‚ÌˆÊ’uî•ñ
	tnl::Vector3 bullet_pos_;
	//’e‘¬‚ğİ’è‚·‚éŠÖ”
	void setVelocity(const tnl::Vector3& velocity) {

		velocity_ = velocity;

	}

	void update(float delta_time);
	void draw();

private:

	Shared<Player> player_;
	Shared<ShootEnemy> s_enemy_;
	//‘¬“x
	tnl::Vector3 velocity_;
	//’e‘¬
	float bullet_speed_ = 5.0f;

};