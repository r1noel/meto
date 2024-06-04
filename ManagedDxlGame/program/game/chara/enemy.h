#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "enemy_base.h"
#include "player.h"
#include "../gmobject/bullet.h"
#include "../gmobject/m_chip.h"
#include <list>

class EnemyBullet;

//�ǔ��G�l�~�[ 98
class TrackingEnemy : public EnemyBase {
public:
	TrackingEnemy();
	//�ǔ��G�l�~�[�̃R���X�g���N�^
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

	//�ǔ��G�l�~�[�ʒu���
	//tnl::Vector3 e_draw_pos_;
	//�ǔ��G�l�~�[�T�C�Y
	const int te_width_ = 32;						//��			
	const int te_height_ = 32;						//����

	float elapsed_time_ = 0.0f;

	float speed_ = 0.0f;						//�v���C���[���x
	float acceleration_ = 1.0f;					//�d�͉����x
	float drop_time_ = 0.0f;					//�؋󎞊�

	const float DETECT_RANGE = 300.0f;

	//�G�l�~�[�A�j���[�V������ށi�����j
	enum  TrackingEnemyAnime {
		TE_DIR_LEFT,
		TE_DIR_RIGHT,
		TE_DIR_MAX
	};

	float te_anim_time_count_ = 0;
	//�ǔ��G�l�~�[�A�j���[�V�����̕���
	int te_anim_ctrl_dir_ = TE_DIR_LEFT;
	//�ǔ��G�l�~�[�A�j���[�V�����t���[����
	int te_anim_ctr_frame_ = 0;
	//�ǔ��G�l�~�[�A�j���[�V�����n���h��
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

////�ˌ��G�l�~�[ 99
//class ShootEnemy : public EnemyBase {
//public:
//	ShootEnemy();
//	//�ˌ��G�l�~�[�R���X�g���N�^
//	ShootEnemy(const tnl::Vector3& pos, int gpc_hdl) :EnemyBase(pos, gpc_hdl) {};
//	//�ˌ��G�l�~�[�ʒu���擾�֐�
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
//	//��
//	const int se_width_ = 32;
//	//����
//	const int se_height_ = 32;
//
//
//	//�G�l�~�[�A�j���[�V������ށi�����j
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

