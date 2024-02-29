#pragma once
#include "../camera/camera.h"

//“G‚ÌŠî–{î•ñ
class EnemyBase {
public:

	 EnemyBase(const tnl::Vector3& pos, int gpc_hdl) : e_pos_(pos), e_gpc_hdl_(gpc_hdl){};

	//bool getAliveFlag() { return e_alive_flag = true; };

	 virtual void draw(const Shared<Camera> camera);

	 tnl::Vector3 e_draw_pos_;	//“G‚ÌˆÊ’u

protected:

	EnemyBase() {};
	
	int e_hp_;					//“G‚Ì‘Ì—Í
	int e_att_;					//“G‚ÌUŒ‚—Í
	tnl::Vector3 e_pos_ {0, 0, 0};
	int e_gpc_hdl_;				//“G‚Ì‰æ‘œƒnƒ“ƒhƒ‹
	float e_move_speed_;		//“G‚ÌˆÚ“®‘¬“x
	float e_view_angle_;		//“G‚Ì‹–ìŠp
	//¶‘¶ƒtƒ‰ƒO
	bool e_alive_flag = true;
};