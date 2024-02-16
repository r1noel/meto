#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "../chara/player.h"

class Camera {
public:

	Camera(tnl::Vector3 startPos);

	tnl::Vector3 target_ = { 0,0,0 };							//ƒJƒƒ‰ˆÊ’u
	void update(float delta_time,tnl::Vector3 target_pos);		
	void draw();
	
private:

};
