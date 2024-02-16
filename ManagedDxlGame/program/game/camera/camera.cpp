#include "../dxlib_ext/dxlib_ext.h"
#include "camera.h"

Camera::Camera(tnl::Vector3 startPos) : target_(startPos) {

}

//�v���C���[��Ǐ]���邽�߂̃J����
void Camera::update(float delta_time,tnl::Vector3 target_pos) {
	
	target_ += (target_pos - target_) * 0.05f;

}

void Camera::draw() {
	
}