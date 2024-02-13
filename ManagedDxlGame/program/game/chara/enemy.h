#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "enemy_base.h"
#include "player.h"

//�ǔ��G�l�~�[
class TrackingEnemy : public EnemyBase {
public:

	//�ǔ��G�l�~�[�̃R���X�g���N�^
	TrackingEnemy();
	void update(float delta_time);
	void draw();

private:

	//�ǔ��G�l�~�[�ʒu���
	tnl::Vector3 te_pos_;
	//�ǔ��G�l�~�[�T�C�Y
	const int te_width_ = 48;						//��			
	const int te_height_ = 48;						//����

	float elapsed_time_ = 0.0f;

	//�G�l�~�[�A�j���[�V������ށi�����j
	enum TrackingEnemyAnime {
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

private:

	Shared<Player> player_;

};

class LapsEnemy : public EnemyBase {
public:

	LapsEnemy();

};
//�ˌ��G�l�~�[
class ShootEnemy : EnemyBase {
public:

	//�ˌ��G�l�~�[�R���X�g���N�^
	ShootEnemy();
	//�ˌ��G�l�~�[�ʒu���擾�֐�
	tnl::Vector3& getS_EnemyPos();

	void update(float delta_time);
	void draw();

private:

	tnl::Vector3 se_pos_;

	const int se_width_ = 32;
	const int se_height_ = 32;

	//�G�l�~�[�A�j���[�V������ށi�����j
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

