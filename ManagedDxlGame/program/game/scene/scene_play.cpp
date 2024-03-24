#include "../../dxlib_ext/dxlib_ext.h"
#include"../unl.h"
#include "scene_play.h"
#include "scene_title.h"
#include "../common/gm_manager.h"


ScenePlay::ScenePlay() {

	//マップ生成
	map_ = std::make_shared<Map>();

	enemies_ = std::make_shared<EnemyManager>();
	//プレイヤー生成
	player_ = std::make_shared<Player>();
	//カメラ生成
	camera_ = std::make_shared<Camera>(player_->getPlayerPos());

	////追尾エネミー生成
	//t_enemy_ = std::make_shared<TrackingEnemy>();
	////射撃エネミー生成
	//s_enemy_ = std::make_shared<ShootEnemy>();

	unl::jump_reset_flag_ = true;

}

ScenePlay::~ScenePlay() {



}

void ScenePlay::draw() {

	if (map_)map_->draw(camera_);
	if (enemies_)enemies_->draw(camera_);
	if (player_) player_->draw(camera_);


	//DrawStringEx(0, 400, -1, "up = %d", unl::jump_reset_flag_);
	//DrawStringEx(0, 450, -1, "side = %d", unl::side_flag_);
}

void ScenePlay::update(float delta_time) {

	//背景画像の表示
	DrawRotaGraph(630, 350, 1.0f, 0, map_->getGpcHdl(), true);
	//if (map_)map_->update(delta_time, camera_);
	if (enemies_) enemies_->update(delta_time);
	if (player_) player_->update(delta_time);
	if (camera_) camera_->update(delta_time,player_->getPlayerPos());
	//if (t_enemy_)t_enemy_->update(delta_time,camera_);
	//if (s_enemy_)s_enemy_->update(delta_time,camera_);


	tnl::Vector3 prev_pos = player_->getPlayerPos();
	int player_width = player_->getWidthSize();
	int player_height = player_->getHeightSize();

	//ステージとプレイヤーの当たり判定処理
	auto it = map_->map_list_.begin();
	while (it != map_->map_list_.end()) {
		if (unl::IsIntersectRectToCorrectPosition(
			player_->getPlayerPos(),
			prev_pos,
			player_width,
			player_height,
			(*it)->map_chip_pos_,
			map_->getWidth(),
			map_->getHeight())) {
			if (unl::jump_reset_flag_) {	

				player_->getJumpCount();
				// ジャンプをしていない時は数値を０にする
				player_->getDropTime();
				player_->getSpeed();

				if (!unl::side_flag_) {
					// ジャンプをしていない時は数値を０にする
					//player_->getDropTime();
					//player_->getSpeed();
				}
			}
		}
		it++;

	}
	
}
