#include "../dxlib_ext/dxlib_ext.h"
#include "enemy.h"
#include "../common/gm_manager.h"

TrackingEnemy::TrackingEnemy() {

	e_hp_ = 100;
	e_att_ = 10;

	player_ = std::make_shared<Player>();
}

void TrackingEnemy::update(float delta_ime) {

	//�v���C���[�ʒu�擾
	tnl::Vector3 player_pos_ = player_->getPlayerPos();
	//�v���C���[�̌����擾
	tnl::Vector3 direction = player_pos_ - te_pos_;
	//�x�N�g�����K���A�����ۑ�
	direction.Normalize(direction);
	
}