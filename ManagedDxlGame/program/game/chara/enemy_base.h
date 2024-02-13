#pragma once
#include "../dxlib_ext/dxlib_ext.h"

//“G‚ÌŠî–{î•ñ
class EnemyBase {
protected:

	int e_hp_;					//“G‚Ì‘Ì—Í
	int e_att_;					//“G‚ÌUŒ‚—Í
	int e_gpc_hdl_;				//“G‚Ì‰æ‘œƒnƒ“ƒhƒ‹
	tnl::Vector3 e_pos_;		//“G‚ÌˆÊ’u
	float e_move_speed_;			//“G‚ÌˆÚ“®‘¬“x
	float e_view_angle_;		//“G‚Ì‹–ìŠp

};