#include "../dxlib_ext/dxlib_ext.h"
#include "../camera/camera.h"
#include "goal.h"

void Goal::draw(const Camera& camera) {

	tnl::Vector3 goal_pos = goal_pos_;

}
const tnl::Vector3& Goal::getGoalPos() {

	return goal_pos_;
}
int Goal::getGoalWidth() {

	return goal_width_;

}
int Goal::getGoalHeight() {

	return goal_height_;

}