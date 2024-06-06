#include "../../dxlib_ext/dxlib_ext.h"
#include "scene_gm_over.h"
#include "scene_title.h"
#include "../common/gm_manager.h"

SceneGameOver::SceneGameOver() {

	gm_over_gpc_hdl_ = LoadGraph("graphics/gameover.jpg");

}

void SceneGameOver::draw() {

	DrawRotaGraph(630, 350, 1.0f, 0, gm_over_gpc_hdl_, true);
	DrawStringEx(525, 350, -1, "Game Over");
	DrawStringEx(525, 550, -1, "Enter�L�[�Ŗ߂�");

}

void  SceneGameOver::update(float delta_time) {

	//�v���C�V�[���ֈړ�
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN) || tnl::Input::IsPadDownTrigger(ePad::KEY_MAX)) {
		auto mgr = GameManager::GetInstance();
	
		mgr->changeScene(new SceneTitle());

	}
	//�Q�[�����I��
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_ESCAPE)) {
		DxLib_End();
	}

}