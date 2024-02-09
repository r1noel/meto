#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "enemy_base.h"
#include "player.h"

class TrackingEnemy : public EnemyBase {
public:

	TrackingEnemy();
	void update(float delta_time);
	void draw();

private:

	//追尾エネミー位置情報
	tnl::Vector3 te_pos_;
	const int width_ = 48;						
	const int height_ = 48;
	float elapsed_time_ = 0.0f;

	//エネミーアニメーション種類（向き）
	enum PlayerAnime {
		DIR_LEFT,
		DIR_RIGHT,
		DIR_MAX
	};

	float te_anim_time_count_ = 0;
	int te_anim_ctrl_dir_ = DIR_LEFT;
	int te_anim_ctr_frame_ = 0;
	int te_anim_hdls_[DIR_MAX][3];

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

