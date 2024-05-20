#pragma once
#include "../camera/camera.h"

//“G‚ÌŠî–{î•ñ
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
	
	int e_hp_;					//“G‚Ì‘Ì—Í
	int e_att_;					//“G‚ÌUŒ‚—Í
	int e_gpc_hdl_;				//“G‚Ì‰æ‘œƒnƒ“ƒhƒ‹
	float e_move_speed_;		//“G‚ÌˆÚ“®‘¬“x
	float e_view_angle_;		//“G‚Ì‹–ìŠp
	tnl::Vector3 e_draw_pos_;	//“G‚ÌˆÊ’u

	//¶‘¶ƒtƒ‰ƒO
	bool e_alive_flag = true;
};