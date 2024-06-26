#include "../../dxlib_ext/dxlib_ext.h"
#include "scene_title.h"
#include "scene_play.h"
#include "../common/gm_manager.h"

SceneTitle::SceneTitle() {

	//wiæÇ
	title_gpc_hdl_ = LoadGraph("graphics/bone285.jpg");
	//BGMÇ
	title_bgm_ = LoadSoundMem("sound/gravity.wav");
	//BGM[vÄ¶
	PlaySoundMem(title_bgm_, DX_PLAYTYPE_LOOP, true);

}

void SceneTitle::update(float delta_time) {

	//vCV[ÖÚ®
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN) || tnl::Input::IsPadDownTrigger(ePad::KEY_MAX)) {
		auto mgr = GameManager::GetInstance();
		//BGMð~ßé
		StopSoundMem(title_bgm_);
		mgr->changeScene(new ScenePlay());

	}
	//Q[ðI¹
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_ESCAPE)) {
		DxLib_End();
	}

}

void SceneTitle::draw() {

	//wiæ\¦
	DrawRotaGraph(630, 350, 1.0f, 0, title_gpc_hdl_, true);
	//SetFontSize(50);
	DrawStringEx(500, 200, -1, "d²@Sdés");
	//SetFontSize(20);
	DrawStringEx(525, 350, -1, "PLEASE ENTER KEY OR PAD KEY");
	DrawStringEx(1050, 700, -1, "ESCL[ÅQ[ðI¹");

}