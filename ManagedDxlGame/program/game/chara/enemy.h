#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "enemy_base.h"
#include "player.h"

//追尾エネミー
class TrackingEnemy : public EnemyBase {
public:

	//追尾エネミーのコンストラクタ
	TrackingEnemy();
	void update(float delta_time);
	void draw();

private:

	//追尾エネミー位置情報
	tnl::Vector3 te_pos_;
	//追尾エネミーサイズ
	const int te_width_ = 48;						//幅			
	const int te_height_ = 48;						//高さ

	float elapsed_time_ = 0.0f;

	//エネミーアニメーション種類（向き）
	enum TrackingEnemyAnime {
		TE_DIR_LEFT,
		TE_DIR_RIGHT,
		TE_DIR_MAX
	};

	float te_anim_time_count_ = 0;
	//追尾エネミーアニメーションの方向
	int te_anim_ctrl_dir_ = TE_DIR_LEFT;
	//追尾エネミーアニメーションフレーム数
	int te_anim_ctr_frame_ = 0;
	//追尾エネミーアニメーションハンドル
	int te_anim_hdls_[TE_DIR_MAX][3];

private:

	Shared<Player> player_;

};

class LapsEnemy : public EnemyBase {
public:

	LapsEnemy();

};
//射撃エネミー
class ShootEnemy : EnemyBase {
public:

	//射撃エネミーコンストラクタ
	ShootEnemy();
	//射撃エネミー位置情報取得関数
	tnl::Vector3& getS_EnemyPos();

	void update(float delta_time);
	void draw();

private:

	tnl::Vector3 se_pos_;

	const int se_width_ = 32;
	const int se_height_ = 32;

	//エネミーアニメーション種類（向き）
	enum ShootEnemyAnime {
		SE_DIR_LEFT,
		SE_DIR_RIGHT,
		SE_DIR_MAX
	};

	float se_anim_time_count_ = 0;
	int se_anim_ctrl_dir_ = SE_DIR_LEFT;
	int se_anim_ctr_frame_ = 0;
	int se_anim_hdls_[SE_DIR_MAX][3];

};

