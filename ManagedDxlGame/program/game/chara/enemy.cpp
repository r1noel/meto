#include "../dxlib_ext/dxlib_ext.h"
#include "../common/gm_manager.h"
#include "enemy.h"

TrackingEnemy::TrackingEnemy() {

	std::string files[TE_DIR_MAX] = {

		"graphics/te_left.png",
		"graphics/te_right.png"

	};

	for (int i = 0; i < TE_DIR_MAX; ++i) {
		LoadDivGraph(files[i].c_str(), 3, 3, 1, 32, 32, te_anim_hdls_[i]);
	}

	e_hp_ = 100;
	e_att_ = 10;
	e_move_speed_ = 1.0f;

	player_ = std::make_shared<Player>();


}

int TrackingEnemy::getAnimeHdls() {

	return te_anim_hdls_[te_anim_ctrl_dir_][te_anim_ctr_frame_];

}

void TrackingEnemy::draw(const Shared<Camera> camera) {
	
	//�����@��ԍŌ�ɔԍ����������ꏊ��BOX�����\������Ă���H
	DrawBoxEx(e_draw_pos_, te_width_, te_height_, false);
	DrawStringEx(10, 80, -1, "T�G�l�~�[.x = %f y = %f", e_draw_pos_.x, e_draw_pos_.y);

}

void TrackingEnemy::update(float delta_time) {

	te_anim_time_count_ += delta_time;
	if (te_anim_time_count_ > 0.1f) {
		te_anim_ctr_frame_++;
		te_anim_ctr_frame_ %= 3;

		te_anim_time_count_ = 0;
	}

	//EnemyBase::update(delta_time);

	if (player_) {

		//�v���C���[�ʒu�擾
		tnl::Vector3 player_pos_ = player_->getPlayerPos();
		//�v���C���[�̌����擾
		tnl::Vector3 direction = player_pos_ - e_draw_pos_;
		//�x�N�g�����K���A�����ۑ�
		direction.Normalize(direction);
		//�G�̈ړ�
		e_draw_pos_ += direction * e_move_speed_ * delta_time;
		//�o�ߎ���
		elapsed_time_ += delta_time;
		//�v���C���[�̃A�b�v�f�[�g�擾
		//player_->update(delta_time);
	}
	

}

void TrackingEnemy::Delete() {



}

ShootEnemy::ShootEnemy() {

	std::string files[SE_DIR_MAX] = {
		"graphics/se_left.png",
		"graphics/se_right.png"
	};

	for (int i = 0; i < SE_DIR_MAX; ++i) {
		LoadDivGraph(files[i].c_str(), 3, 3, 1, 32, 32, se_anim_hdls_[i]);
	}

	e_hp_ = 125;
	e_att_ = 15;

	player_ = std::make_shared<Player>();
	//m_chip_ = std::make_shared<MapChip>();

}

void ShootEnemy::draw(const Shared<Camera> camera) {

	DrawRotaGraph(e_draw_pos_.x,e_draw_pos_.y, 1.0f, 0,0, se_anim_hdls_[se_anim_ctrl_dir_][se_anim_ctr_frame_], true);
	//�����@��ԍŌ�ɔԍ����������ꏊ��BOX�����\������Ă���H
	DrawStringEx(10, 60, -1, "S�G�l�~�[.x = %f y = %f", e_draw_pos_.x, e_draw_pos_.y);
	DrawBoxEx(e_draw_pos_, se_width_, se_height_, false);


	if (player_) {
		tnl::Vector3 player_pos_ = player_->getPlayerPos();

		e_bullet_list.emplace_back(new EnemyBullet(tnl::Vector3(e_draw_pos_.x, e_draw_pos_.y, 0), tnl::Vector3(player_pos_.x, player_pos_.y, 0)));
	}
}

void ShootEnemy::update(float delta_time) {

	se_anim_time_count_ += delta_time;
	if (se_anim_time_count_ > 0.1f) {
		se_anim_ctr_frame_++;
		se_anim_ctr_frame_ %= 3;

		se_anim_time_count_ = 0;
	}

	//EnemyBase::update(delta_time);
}

tnl::Vector3& ShootEnemy::getS_EnemyPos() {

	return e_draw_pos_;

}
