#include "../../dxlib_ext/dxlib_ext.h"
#include"../unl.h"
#include "scene_play.h"
#include "scene_title.h"
#include "../common/gm_manager.h"
#include <math.h>

ScenePlay::ScenePlay() {

	auto gameManager = GameManager::GetInstance();

	//�}�b�v����
	map_ = gameManager->getMap();

	enemies_ = gameManager->getEnemyManager();

	//�v���C���[����
	player_ = gameManager->getPlayer();

	//�J��������
	camera_ = std::make_shared<Camera>(player_->getPlayerPos());

	unl::jump_reset_flag_ = true;

}

ScenePlay::~ScenePlay() {



}

void ScenePlay::draw() {

	if (map_)map_->draw(camera_);
	if (enemies_)enemies_->draw(camera_);
	if (player_) player_->draw(camera_);


	//DrawStringEx(0, 400, -1, "up = %d", unl::jump_reset_flag_);
	//DrawStringEx(0, 450, -1, "side = %d", unl::side_flag_);
}

void ScenePlay::update(float delta_time) {

	tnl::Vector3 prev_pos = player_->getPlayerPos();

	//�w�i�摜�̕\��
	DrawRotaGraph(630, 350, 1.0f, 0, map_->getGpcHdl(), true);
	//if (map_)map_->update(delta_time, camera_);
	if (enemies_) enemies_->update(delta_time);
	if (player_) player_->update(delta_time);
	if (camera_) camera_->update(delta_time,player_->getPlayerPos());

	int player_width = player_->getWidthSize();
	int player_height = player_->getHeightSize();
	


	//�X�e�[�W�ƃv���C���[�̓����蔻�菈��
	auto it = map_->map_list_.begin();
	while (it != map_->map_list_.end()) {

		int chipNum = (*it)->GetChipNum();

		if (chipNum == 98 || chipNum == 99) {
			it++;
			continue;
		}

		//�v���C���[�ƃ}�b�v�`�b�v�̓����蔻��␳
		if (unl::IsIntersectRectToCorrectPosition(
			player_->getPlayerPos(),
			prev_pos,
			player_width,
			player_height,
			(*it)->map_chip_pos_,
			map_->getWidth(),
			map_->getHeight())) {
			if (unl::jump_reset_flag_) {	

				player_->getJumpCount();
				// �W�����v�����Ă��Ȃ����͐��l���O�ɂ���
				player_->getDropTime();
				player_->getSpeed();

				if (!unl::side_flag_) {
					// �W�����v�����Ă��Ȃ����͐��l���O�ɂ���
					//player_->getDropTime();
					//player_->getSpeed();
				}
			}
		}
		it++;

	}
	
}

Shared<Camera> ScenePlay::getCamera() {
	return camera_;
}
