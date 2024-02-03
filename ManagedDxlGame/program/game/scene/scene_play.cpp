#include "../../dxlib_ext/dxlib_ext.h"
#include "scene_play.h"
#include "scene_title.h"
#include "../common/gm_manager.h"


ScenePlay::ScenePlay() {
	//マップ生成
	map_ = std::make_shared<Map>();
	//プレイヤー生成
	player_ = std::make_shared<Player>();
	//カメラ生成
	camera_ = std::make_shared<Camera>();

}
ScenePlay::~ScenePlay() {



}

void ScenePlay::draw() {

	if (map_)map_->draw(camera_);
	if (player_) player_->draw(camera_);

	if (player_->getPlayerPos().y >= 550) {

	}

}

void ScenePlay::update(float delta_time) {

	DrawRotaGraph(630, 350, 1.0f, 0, map_->getGpcHdl(), true);
	if (map_)map_->update(delta_time, camera_);
	if (player_) player_->update(delta_time);
	if (camera_) camera_->update(delta_time,player_->getPlayerPos());


	tnl::Vector3 prev_pos = player_->getPlayerPos();
	int player_width = player_->getWidthSize();
	int player_height = player_->getHeightSize();


	
}
