#pragma once
#include "../common/gm_scene_base.h"

class SceneTitle : public SceneBase {
public:

	//�^�C�g���̃R���X�g���N�^
	SceneTitle();
	void update(float delta_time) override;
	void draw() override;

private:

	//�^�C�g���w�i�n���h��
	int title_gpc_hdl_;
	//�^�C�g��BGM
	int title_bgm_;

};