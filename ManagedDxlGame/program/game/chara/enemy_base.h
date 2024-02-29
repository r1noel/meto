#pragma once
#include "../camera/camera.h"

//�G�̊�{���
class EnemyBase {
public:

	 EnemyBase(const tnl::Vector3& pos, int gpc_hdl) : e_pos_(pos), e_gpc_hdl_(gpc_hdl){};

	//bool getAliveFlag() { return e_alive_flag = true; };

	 virtual void draw(const Shared<Camera> camera);

	 tnl::Vector3 e_draw_pos_;	//�G�̈ʒu

protected:

	EnemyBase() {};
	
	int e_hp_;					//�G�̗̑�
	int e_att_;					//�G�̍U����
	tnl::Vector3 e_pos_ {0, 0, 0};
	int e_gpc_hdl_;				//�G�̉摜�n���h��
	float e_move_speed_;		//�G�̈ړ����x
	float e_view_angle_;		//�G�̎���p
	//�����t���O
	bool e_alive_flag = true;
};