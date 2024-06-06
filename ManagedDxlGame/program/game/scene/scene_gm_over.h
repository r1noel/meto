#pragma once
#include "../common/gm_scene_base.h"

class SceneGameOver : public SceneBase {
public:

	//タイトルのコンストラクタ
	SceneGameOver();
	void update(float delta_time) override;
	void draw() override;

private:

	//タイトル背景ハンドル
	int gm_over_gpc_hdl_;
	//タイトルBGM
	int gm_over_bgm_;

};