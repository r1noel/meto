#include "../dxlib_ext/dxlib_ext.h"
#include "../common/gm_manager.h"
#include "enemy.h"



int TrackingEnemy::getAnimeHdls() {

	return te_anim_hdls_[te_anim_ctrl_dir_][te_anim_ctr_frame_];

}

void TrackingEnemy::draw(const Shared<Camera> camera) {
	
	//カメラの補正位置
	tnl::Vector3 draw_pos = e_draw_pos_ - camera->target_ + tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);
	
	//DrawStringEx(10, 80, -1, "Tエネミー.x = %f y = %f", draw_pos.x, draw_pos.y);

	DrawRotaGraph(draw_pos.x, draw_pos.y, 1, 0, te_anim_hdls_[0][0], true);

}

TrackingEnemy::TrackingEnemy(const tnl::Vector3& pos, int gpc_hdl) : EnemyBase(pos, gpc_hdl) {

	std::string files[TE_DIR_MAX] = {

	 "graphics/se_left.png",
	 "graphics/se_right.png"

	};

	for (int i = 0; i < TE_DIR_MAX; ++i) {
		LoadDivGraph(files[i].c_str(), 3, 3, 1, 32, 32, te_anim_hdls_[i]);
	}

	e_hp_ = 100;
	e_att_ = 10;
	e_move_speed_ = 1.0f;

	player_ = GameManager::GetInstance()->getPlayer();

}

void TrackingEnemy::update(float delta_time) {

	te_anim_time_count_ += delta_time;
	if (te_anim_time_count_ > 0.1f) {
		te_anim_ctr_frame_++;
		te_anim_ctr_frame_ %= 3;

		te_anim_time_count_ = 0;
	}


	if (player_) {

		float distance = GameManager::GetInstance()->GetPlayerDistance(e_draw_pos_);

		if (distance > DETECT_RANGE)
			return;

		//プレイヤー位置取得
		tnl::Vector3 player_pos_ = player_->getPlayerPos();
		//プレイヤーの向き取得
		tnl::Vector3 direction = player_pos_ - e_draw_pos_;
		//ベクトル正規化、向き保存
		direction.Normalize(direction);
		//敵の移動
		e_draw_pos_ += direction * e_move_speed_ * delta_time;
		//経過時間
		elapsed_time_ += delta_time;
		//プレイヤーのアップデート取得
		//player_->update(delta_time);
	}
	

}

void TrackingEnemy::Delete() {



}

int TrackingEnemy::getTeWidthSize() {

	return te_width_;

}

int TrackingEnemy::getTeHeightSize() {

	return te_height_;

}



//ShootEnemy::ShootEnemy() {
//
//	std::string files[SE_DIR_MAX] = {
//		"graphics/se_left.png",
//		"graphics/se_right.png"
//	};
//
//	for (int i = 0; i < SE_DIR_MAX; ++i) {
//		LoadDivGraph(files[i].c_str(), 3, 3, 1, 32, 32, se_anim_hdls_[i]);
//	}
//
//	e_hp_ = 125;
//	e_att_ = 15;
//
//	player_ = std::make_shared<Player>();
//	//m_chip_ = std::make_shared<MapChip>();
//
//}
//
//void ShootEnemy::draw(const Shared<Camera> camera) {
//
//	DrawRotaGraph(e_draw_pos_.x,e_draw_pos_.y, 1.0f, 0,0, se_anim_hdls_[se_anim_ctrl_dir_][se_anim_ctr_frame_], true);
//
//	DrawStringEx(10, 60, -1, "Sエネミー.x = %f y = %f", e_draw_pos_.x, e_draw_pos_.y);
//	DrawBoxEx(e_draw_pos_, se_width_, se_height_, false);
//
//
//	if (player_) {
//		tnl::Vector3 player_pos_ = player_->getPlayerPos();
//
//		e_bullet_list.emplace_back(new EnemyBullet(tnl::Vector3(e_draw_pos_.x, e_draw_pos_.y, 0), tnl::Vector3(player_pos_.x, player_pos_.y, 0)));
//	}
//}
//
//void ShootEnemy::update(float delta_time) {
//
//	se_anim_time_count_ += delta_time;
//	if (se_anim_time_count_ > 0.1f) {
//		se_anim_ctr_frame_++;
//		se_anim_ctr_frame_ %= 3;
//
//		se_anim_time_count_ = 0;
//	}
//
//	//EnemyBase::update(delta_time);
//}
//
//tnl::Vector3& ShootEnemy::getS_EnemyPos() {
//
//	return e_draw_pos_;
//
//}
