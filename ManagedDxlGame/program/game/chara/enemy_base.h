#pragma once
#include "../dxlib_ext/dxlib_ext.h"

//�G�̊�{���
class EnemyBase {
public:

	bool getAliveFlag() { return e_alive_flag = true; };

protected:

	EnemyBase() {};
	
	int e_hp_;					//�G�̗̑�
	int e_att_;					//�G�̍U����
	int e_gpc_hdl_;				//�G�̉摜�n���h��
	tnl::Vector3 e_pos_;		//�G�̈ʒu
	float e_move_speed_;		//�G�̈ړ����x
	float e_view_angle_;		//�G�̎���p
	//�����t���O
	bool e_alive_flag = true;
};