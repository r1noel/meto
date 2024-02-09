#pragma once
#include "../common/gm_scene_base.h"

class SceneTitle : public SceneBase {
public:

	//タイトルのコンストラクタ
	SceneTitle();
	void update(float delta_time) override;
	void draw() override;

private:

	//タイトル背景ハンドル
	int title_gpc_hdl_;
	//タイトルBGM
	int title_bgm_;

};