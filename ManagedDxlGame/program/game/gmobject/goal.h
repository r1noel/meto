#pragma once
#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class Camera;

class Goal {
public:

	void draw(const Camera& camera);
	const tnl::Vector3& getGoalPos();
	int getGoalWidth();
	int getGoalHeight();
private:

	tnl::Vector3 goal_pos_ = { 7104,623,0 };
	const int goal_width_ = 300;										//ÉSÅ[Éãïù
	const int goal_height_ = 100;									//ÉSÅ[ÉãçÇÇ≥
};