#include "../dxlib_ext/dxlib_ext.h"
#include "camera.h"

//プレイヤーを追従するためのカメラ
void Camera::update(float delta_time,tnl::Vector3 target_pos) {
	
	target_ += (target_pos - target_) * 0.05f;

}

void Camera::draw() {
	
}