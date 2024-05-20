#pragma once
#include "../camera/camera.h"

//�G�̊�{���
class EnemyBase {
public:

	 EnemyBase(const tnl::Vector3& pos, int gpc_hdl) : e_draw_pos_(pos), e_gpc_hdl_(gpc_hdl){};

	//bool getAliveFlag() { return e_alive_flag = true; };
	 tnl::Vector3 e_pos_ {0, 0, 0};

	 virtual void update(float delta_time) = 0;

	 virtual void draw(const Shared<Camera> camera);


	 int getAnimeHdls() {
		 return e_gpc_hdl_;
	 }
	 tnl::Vector3& getEnemyPos() {
		 return e_draw_pos_;
	 }

protected:

	EnemyBase() {};
	
	int e_hp_;					//�G�̗̑�
	int e_att_;					//�G�̍U����
	int e_gpc_hdl_;				//�G�̉摜�n���h��
	float e_move_speed_;		//�G�̈ړ����x
	float e_view_angle_;		//�G�̎���p
	tnl::Vector3 e_draw_pos_;	//�G�̈ʒu

	//�����t���O
	bool e_alive_flag = true;
};