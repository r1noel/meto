#include "../../dxlib_ext/dxlib_ext.h"
#include "scene_title.h"
#include "scene_play.h"
#include "../common/gm_manager.h"

SceneTitle::SceneTitle() {

	//�w�i�摜�Ǎ�
	title_gpc_hdl_ = LoadGraph("graphics/bone285.jpg");
	//BGM�Ǎ�
	title_bgm_ = LoadSoundMem("sound/gravity.wav");
	//BGM���[�v�Đ�
	PlaySoundMem(title_bgm_, DX_PLAYTYPE_LOOP, true);
}

void SceneTitle::update(float delta_time) {

	//�w�i�摜�\��
	DrawRotaGraph(630, 350, 1.0f, 0, title_gpc_hdl_, true);
	//�v���C�V�[���ֈړ�
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN) || tnl::Input::IsPadDownTrigger(ePad::KEY_MAX)) {
		auto mgr = GameManager::GetInstance();
		//BGM���~�߂�
		StopSoundMem(title_bgm_);
		mgr->changeScene(new ScenePlay());

	}
	//�Q�[�����I��
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_ESCAPE)) {
		DxLib_End();
	}
}

void SceneTitle::draw() {
	SetFontSize(50);
	DrawStringEx(500, 200, -1, "�d���@�S�d��s");
	SetFontSize(20);
	DrawStringEx(525, 350, -1, "PLEASE ENTER KEY OR PAD KEY");
	DrawStringEx(1050, 700, -1, "ESC�L�[�ŃQ�[�����I��");
}