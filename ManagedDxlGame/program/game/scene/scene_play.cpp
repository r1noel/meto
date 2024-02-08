#include "../../dxlib_ext/dxlib_ext.h"
#include"../unl.h"
#include "scene_play.h"
#include "scene_title.h"
#include "../common/gm_manager.h"


ScenePlay::ScenePlay() {
	//�}�b�v����
	map_ = std::make_shared<Map>();
	//�v���C���[����
	player_ = std::make_shared<Player>();
	//�J��������
	camera_ = std::make_shared<Camera>();

}
ScenePlay::~ScenePlay() {



}

void ScenePlay::draw() {

	if (map_)map_->draw(camera_);
	if (player_) player_->draw(camera_);

	if (player_->getPlayerPos().y >= 550) {

	}
}

void ScenePlay::update(float delta_time) {

	DrawRotaGraph(630, 350, 1.0f, 0, map_->getGpcHdl(), true);
	if (map_)map_->update(delta_time, camera_);
	if (player_) player_->update(delta_time);
	if (camera_) camera_->update(delta_time,player_->getPlayerPos());


	tnl::Vector3 prev_pos = player_->getPlayerPos();
	int player_width = player_->getWidthSize();
	int player_height = player_->getHeightSize();

	//�X�e�[�W�ƃv���C���[�̓����蔻�菈��
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
			// �W�����v�����Ă��Ȃ����͐��l���O�ɂ���
			player_->getDropTime();
			player_->getSpeed();
			player_->getJumpCount();
		}
		it++;
	}
	
	
}
