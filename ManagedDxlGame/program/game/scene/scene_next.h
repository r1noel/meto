#pragma once
#include "../common/gm_scene_base.h"

class SceneNext :public SceneBase {
public:
	SceneNext();
	void update(float delta_time) override;
	void draw()override;
private:
	int next_gpc_hdl_;

};