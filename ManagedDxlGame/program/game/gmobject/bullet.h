#pragma once
#include "../dxlib_ext/dxlib_ext.h"


class Player;
class ShootEnemy;

class EnemyBullet {
public:

	EnemyBullet(tnl::Vector3 bulletpos, tnl::Vector3 targetpos);
	float radius_ = 10;
	//�e�̈ʒu���
	tnl::Vector3 e_bullet_pos_;
	//�^�[�Q�b�g�ʒu���
	tnl::Vector3 target_pos_;


	void update(float delta_time);
	void draw();

private:

	Shared<Player> player_;
	Shared<ShootEnemy> s_enemy_;
	//�ړ���
	tnl::Vector3 moveValue_;
	//�e��
	float e_bullet_speed_ = 5.0f;

};
