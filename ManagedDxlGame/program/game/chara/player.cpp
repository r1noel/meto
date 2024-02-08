#include "../dxlib_ext/dxlib_ext.h"
#include "../common/gm_manager.h"
#include "../camera/camera.h"
#include "player.h"

Player::Player() {
	std::string files[DIR_MAX] = {
		"graphics/p1_right.png",
		"graphics/p1_left.png"
	 
	};

	for (int i = 0; i < DIR_MAX; ++i) {
		LoadDivGraph(files[i].c_str(), 3, 3, 1, 46, 48, anim_hdls_[i]);
	}
	
}


void Player::draw(const std::shared_ptr<Camera> camera) {

	tnl::Vector3 draw_pos = player_pos_ - camera->target_ + tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);		//カメラがプレイヤーを追従
	DrawStringEx(10, 20, -1, "プレイヤー.x = %f y = %f", player_pos_.x, player_pos_.y);
	DrawRotaGraph(draw_pos.x, draw_pos.y, 1.0f, 0, anim_hdls_[anim_ctrl_dir_][anim_ctr_frame_], true);							//プレイヤーの造形

	DrawBoxEx(draw_pos, width_, height_, false);
}
void Player::update(float delta_time) {

	GameManager* mgr = GameManager::GetInstance();

	anim_time_count_ += delta_time;
	if (anim_time_count_ > 0.1f) {
		anim_ctr_frame_++;
		anim_ctr_frame_ %= 3;

		anim_time_count_ = 0;
	}
	//プレイヤー操作
	if (tnl::Input::IsKeyDown(eKeys::KB_A)) {
		anim_ctrl_dir_ = DIR_LEFT;												//左向
		player_pos_.x -= 7.5f;													//左移動
	}
	if (tnl::Input::IsKeyDown(eKeys::KB_D)) {
		anim_ctrl_dir_ = DIR_RIGHT;												//右向
		player_pos_.x += 7.5f;													//右移動
	}
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_SPACE) && jump_count_ <= 1) {
		jump();																	//ジャンプ
	}
	if (tnl::Input::IsMouseTrigger(eMouseTrigger::IN_LEFT));					//攻撃

	if (tnl::Input::IsKeyDown(eKeys::KB_W) ){
		player_pos_.y -= 20.0f;
	}
	if (tnl::Input::IsKeyDown(eKeys::KB_S)) {
		player_pos_.y += 20.0f;
	}
	
		player_pos_.y += speed_;

	//ジャンプの落下処理
	drop_time_ += delta_time;
	speed_ += acceleration_ * drop_time_;
}
//ジャンプ機能
void Player::jump() {
	speed_ = -10.5f;
	jump_count_++;																//ジャンプ数のカウント
}
tnl::Vector3& Player::getPlayerPos() {

	return player_pos_;

}
int Player::getWidthSize() {

	return width_;

}
int Player::getHeightSize() {

	return height_;

}
int Player::getJumpCount() {

	return jump_count_ = 0;

}
float Player::getDropTime() {

	return drop_time_ = 0;

}
float Player::getSpeed() {

	return speed_ = 0;

}