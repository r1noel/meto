#include "../dxlib_ext/dxlib_ext.h"
#include "../common/gm_manager.h"
#include "../camera/camera.h"
#include "player.h"
#include "enemy.h"
#include "../unl.h"

Player::Player() {

	//アニメーション画像格納
	std::string files[DIR_MAX] = {
		"graphics/p1_right.png",
		"graphics/p1_left.png"
	 
	};
	//アニメーション画像読込
	for (int i = 0; i < DIR_MAX; ++i) {
		LoadDivGraph(files[i].c_str(), 3, 3, 1, 46, 48, anim_hdls_[i]);
	}
	//LoadDivGraph("graphics/btleffect1.png", 15, 5, 3,120, 120, atk_effect_hdl_);


}


void Player::draw(const Shared<Camera> camera) {

	if (death_flag_) {
		return;
	}

	tnl::Vector3 draw_pos = player_pos_ - camera->target_ + tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);		
	DrawStringEx(10, 20, -1, "プレイヤー.x = %f y = %f", player_pos_.x, player_pos_.y);
	DrawRotaGraph(draw_pos.x, draw_pos.y, 1.0f, 0, anim_hdls_[anim_ctrl_dir_][anim_ctr_frame_], true);							//プレイヤーの造形
	//DrawRotaGraph(draw_pos.x *1, draw_pos.y, 0.5f, 0, atk_effect_hdl_[effect_ctrl_fream_], true);

	DrawStringEx(0, 500, -1, "x = %d", xxx);
	//DrawBoxEx(draw_pos, width_, height_, false);

}

void Player::update(float delta_time) {
	xxx = player_pos_.x;

	xxx /= 48;

	if (death_flag_) {
		return;
	}


	//const int attack_effect_ = 15;
	
	//アニメーション再生
	anim_time_count_ += delta_time;
	if (anim_time_count_ > 0.1f) {
		anim_ctr_frame_++;
		anim_ctr_frame_ %= 3;

		anim_time_count_ = 0;
	}
	//プレイヤー操作
	if (tnl::Input::IsKeyDown(eKeys::KB_A)) {
		anim_ctrl_dir_ = DIR_LEFT;												//左向
		player_pos_.x -= 5.5f;													//左移動
	}
	if (tnl::Input::IsKeyDown(eKeys::KB_D)) {
		anim_ctrl_dir_ = DIR_RIGHT;												//右向
		player_pos_.x += 5.5f;													//右移動
	}
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_SPACE) && jump_count_ <= 1) {
		jump();																	//ジャンプ
	}
	//if (effect_flag_) {
		//effect_time_count_ += delta_time;		
	if (tnl::Input::IsMouseTrigger(eMouseTrigger::IN_LEFT)) {					//攻撃

		//if (effect_time_count_ > 0.1f) {
		//	effect_ctrl_fream_++;
		//	effect_ctrl_fream_ %= (attack_effect_ + 1);

		//	if (effect_ctrl_fream_ == attack_effect_) {
		//		effect_flag_ = false;
		//	}

		//	effect_time_count_ = 0;
		//}

	}
	//}
	//デバック用
	if (tnl::Input::IsKeyDown(eKeys::KB_W)) {
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

	speed_ = -10.0f;															//ジャンプの飛距離
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

	return jump_count_= 0;

}

float Player::getDropTime() {

	return drop_time_= 0;

}

float Player::getSpeed() {

	return speed_ = 0;

}

void Player::setDeathFlag(bool death_flag) {

	death_flag_ = death_flag;

}