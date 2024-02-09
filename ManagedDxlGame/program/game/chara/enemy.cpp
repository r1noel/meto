#include "../dxlib_ext/dxlib_ext.h"
#include "enemy.h"
#include "../common/gm_manager.h"

TrackingEnemy::TrackingEnemy() {

	std::string files[DIR_MAX] = {

		"graphics/te_left.png",
		"graphics/te_right.png"

	};

	for (int i = 0; i < DIR_MAX; ++i) {
		LoadDivGraph(files[i].c_str(), 3, 3, 1, 32, 29, te_anim_hdls_[i]);
	}

	e_hp_ = 100;
	e_att_ = 10;

	player_ = std::make_shared<Player>();
}

void TrackingEnemy::draw() {

	DrawRotaGraph(te_pos_.x, te_pos_.y, 1.0f, 0, te_anim_hdls_[te_anim_ctrl_dir_][te_anim_ctr_frame_], true);
	DrawBoxEx(te_pos_, width_, height_, false);

}

void TrackingEnemy::update(float delta_time) {

	te_anim_time_count_ += delta_time;
	if (te_anim_time_count_ > 0.1f) {
		te_anim_ctr_frame_++;
		te_anim_ctr_frame_ %= 3;

		te_anim_time_count_ = 0;
	}

	//�v���C���[�ʒu�擾
	tnl::Vector3 player_pos_ = player_->getPlayerPos();
	//�v���C���[�̌����擾
	tnl::Vector3 direction = player_pos_ - te_pos_;
	//�x�N�g�����K���A�����ۑ�
	direction.Normalize(direction);
	//�G�̈ړ�
	te_pos_ += direction * e_move_speed_ * delta_time;
	//�o�ߎ���
	elapsed_time_ += delta_time;
	////�v���C���[�̃A�b�v�f�[�g�擾
	//player_->update(delta_time);

}