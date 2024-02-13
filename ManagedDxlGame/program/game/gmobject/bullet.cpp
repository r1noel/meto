#include "../dxlib_ext/dxlib_ext.h"
#include "bullet.h"

void Bullet::update(float delta_tiem) {

	//プレイヤーの位置情報取得
	tnl::Vector3 player_pos_ = player_->getPlayerPos();
	//射撃エネミーの位置情報取得
	tnl::Vector3 s_enemy_pos_ = s_enemy_->getS_EnemyPos();
	//プレイヤーの方向取得
	tnl::Vector3 b_direction = player_pos_ - s_enemy_pos_;
	//新しい弾を生成し、速度ベクトルを設定
	Shared<Bullet> newBullet =  std::make_shared<Bullet>(s_enemy_pos_);
	newBullet->setVelocity(b_direction * bullet_speed_);
}
void Bullet::draw() {

	DrawCircle(bullet_pos_.x, bullet_pos_.y, radius_, -1, false);

}