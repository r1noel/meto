#include "bullet.h"
#include "../chara/player.h"
#include "../chara/enemy.h"



EnemyBullet::EnemyBullet(tnl::Vector3 bulletpos, tnl::Vector3 targetpos) : e_bullet_pos_(bulletpos), target_pos_(targetpos){


	moveValue_ = tnl::Vector3::Normalize(target_pos_ - e_bullet_pos_) * e_bullet_speed_;


}

void EnemyBullet::update(float delta_time) {

	//プレイヤーの位置情報取得
	tnl::Vector3 player_pos_ = player_->getPlayerPos();
	//射撃エネミーの位置情報取得
	tnl::Vector3 s_enemy_pos_ = s_enemy_->getS_EnemyPos();
	//プレイヤーの方向取得
	tnl::Vector3 b_direction = player_pos_ - s_enemy_pos_;



}
void EnemyBullet::draw() {

	DrawCircle(e_bullet_pos_.x, e_bullet_pos_.y, radius_, -1, false);

}