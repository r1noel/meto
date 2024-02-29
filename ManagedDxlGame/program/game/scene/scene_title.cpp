#include "../../dxlib_ext/dxlib_ext.h"
#include "scene_title.h"
#include "scene_play.h"
#include "../common/gm_manager.h"

SceneTitle::SceneTitle() {

	//背景画像読込
	title_gpc_hdl_ = LoadGraph("graphics/bone285.jpg");
	//BGM読込
	title_bgm_ = LoadSoundMem("sound/gravity.wav");
	//BGMループ再生
	PlaySoundMem(title_bgm_, DX_PLAYTYPE_LOOP, true);
}

void SceneTitle::update(float delta_time) {

	//背景画像表示
	DrawRotaGraph(630, 350, 1.0f, 0, title_gpc_hdl_, true);
	//プレイシーンへ移動
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN) || tnl::Input::IsPadDownTrigger(ePad::KEY_MAX)) {
		auto mgr = GameManager::GetInstance();
		//BGMを止める
		StopSoundMem(title_bgm_);
		mgr->changeScene(new ScenePlay());

	}
	//ゲームを終了
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_ESCAPE)) {
		DxLib_End();
	}
}

void SceneTitle::draw() {
	SetFontSize(50);
	DrawStringEx(500, 200, -1, "妖夢　百妖夜行");
	SetFontSize(20);
	DrawStringEx(525, 350, -1, "PLEASE ENTER KEY OR PAD KEY");
	DrawStringEx(1050, 700, -1, "ESCキーでゲームを終了");
}