
#include <time.h>
#include <string>
#include <numbers>
#include <functional>
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "../game/common/gm_manager.h"
#include "../game/scene/scene_title.h"


int ary[3] = { 0 };

//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameStart() {
	srand(time(0));
	SetBackgroundColor(32, 32, 32);

	//LoadDivGraph("graphics/p1_right.png", 3, 3, 1, 46, 48, ary);

	GameManager::GetInstance(new SceneTitle());
}


//------------------------------------------------------------------------------------------------------------
// 毎フレーム実行されます
void gameMain(float delta_time) {
	GameManager::GetInstance()->update(delta_time);
	DrawFpsIndicator({ 10, DXE_WINDOW_HEIGHT - 10, 0 }, delta_time);

}

//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameEnd() {
	GameManager::GetInstance()->Destroy();
}
