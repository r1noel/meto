#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "enemy_base.h"
#include "player.h"
#include "../gmobject/bullet.h"
#include "../gmobject/m_chip.h"
#include <list>

class EnemyBullet;

//追尾エネミー 98
class TrackingEnemy : public EnemyBase {
public:
	TrackingEnemy();
	//追尾エネミーのコンストラクタ
	TrackingEnemy(const tnl::Vector3& pos, int gpc_hdl);
	void update(float delta_time)override;
	void draw(const Shared<Camera> camera)override;
	int getAnimeHdls();
	int getTeWidthSize();
	int getTeHeightSize();
	bool isActive() { return is_active_; }
	void setActive(bool is_active) { is_active_ = is_active; }

	void Delete();

	
private:

	//追尾エネミー位置情報
	//tnl::Vector3 e_draw_pos_;
	//追尾エネミーサイズ
	const int te_width_ = 32;						//幅			
	const int te_height_ = 32;						//高さ

	float elapsed_time_ = 0.0f;

	float speed_ = 0.0f;						//プレイヤー速度
	float acceleration_ = 1.0f;					//重力加速度
	float drop_time_ = 0.0f;					//滞空時間

	const float DETECT_RANGE = 300.0f;

	//エネミーアニメーション種類（向き）
	enum  TrackingEnemyAnime {
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
	bool is_active_ = true;

private:

	Shared<Player> player_;

};

//class LapsEnemy : public EnemyBase {
//public:
//
//	LapsEnemy();
//
//};

////射撃エネミー 99
//class ShootEnemy : public EnemyBase {
//public:
//	ShootEnemy();
//	//射撃エネミーコンストラクタ
//	ShootEnemy(const tnl::Vector3& pos, int gpc_hdl) :EnemyBase(pos, gpc_hdl) {};
//	//射撃エネミー位置情報取得関数
//	tnl::Vector3& getS_EnemyPos();
//
//	void update(float delta_time);
//	void draw(const Shared<Camera> camera)override;
//	
//
//	//void Delete();
//
//	std::list<EnemyBullet*> e_bullet_list;
//	
//private:
//
//	//tnl::Vector3 e_draw_pos_;
//
//	//幅
//	const int se_width_ = 32;
//	//高さ
//	const int se_height_ = 32;
//
//
//	//エネミーアニメーション種類（向き）
//	enum ShootEnemyAnime {
//		SE_DIR_LEFT,
//		SE_DIR_RIGHT,
//		SE_DIR_MAX
//	};
//
//	float se_anim_time_count_ = 0;
//	int se_anim_ctrl_dir_ = SE_DIR_LEFT;
//	int se_anim_ctr_frame_ = 0;
//	int se_anim_hdls_[SE_DIR_MAX][3];
//
//	Shared<Player> player_;
//
//
//};

