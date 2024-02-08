#include "../dxlib_ext/dxlib_ext.h"
#include "enemy.h"
#include "../common/gm_manager.h"

TrackingEnemy::TrackingEnemy() {

	e_hp_ = 100;
	e_att_ = 10;

	player_ = std::make_shared<Player>();
}

void TrackingEnemy::update(float delta_ime) {

	//プレイヤー位置取得
	tnl::Vector3 player_pos_ = player_->getPlayerPos();
	//プレイヤーの向き取得
	tnl::Vector3 direction = player_pos_ - te_pos_;
	//ベクトル正規化、向き保存
	direction.Normalize(direction);
	
}