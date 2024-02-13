#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "../chara/player.h"
#include "../chara/enemy.h"

class Bullet {
public:

	Bullet(tnl::Vector3 bulletpos) { bullet_pos_ = bulletpos; }
	float radius_ = 10;
	//弾の位置情報
	tnl::Vector3 bullet_pos_;
	//弾速を設定する関数
	void setVelocity(const tnl::Vector3& velocity) {

		velocity_ = velocity;

	}

	void update(float delta_time);
	void draw();

private:

	Shared<Player> player_;
	Shared<ShootEnemy> s_enemy_;
	//速度
	tnl::Vector3 velocity_;
	//弾速
	float bullet_speed_ = 5.0f;

};