#pragma once
#include "../common/gm_scene_base.h"
#include "../gmobject/map.h"
#include "../chara/player.h"

class ScenePlay : public SceneBase {
public:
	//�v���C�V�[���̃R���X�g���N�^
	ScenePlay();
	//�v���C�V�[���̃f�X�g���N�^
	~ScenePlay();
	void update(float delta_time) override;
	void draw() override;


private:

	std::shared_ptr<Map> map_ = nullptr;
	std::shared_ptr<Player> player_ = nullptr;
	std::shared_ptr<Camera> camera_ = nullptr;
	
};
