#pragma once
#include "../common/gm_scene_base.h"

class SceneGameOver : public SceneBase {
public:

	//�^�C�g���̃R���X�g���N�^
	SceneGameOver();
	void update(float delta_time) override;
	void draw() override;

private:

	//�^�C�g���w�i�n���h��
	int gm_over_gpc_hdl_;
	//�^�C�g��BGM
	int gm_over_bgm_;

};