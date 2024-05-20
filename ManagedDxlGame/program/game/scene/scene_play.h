#pragma once
#include "../common/gm_scene_base.h"
#include "../gmobject/map.h"
#include "../chara/player.h"
#include "../chara/enemy_manager.h"

class ScenePlay : public SceneBase {
public:

	//�v���C�V�[���̃R���X�g���N�^
	ScenePlay();
	//�v���C�V�[���̃f�X�g���N�^
	virtual ~ScenePlay();
	void update(float delta_time) override;
	void draw() override;
	Shared<Camera> getCamera();

private:

	Shared<Map> map_ = nullptr;
	Shared<Player> player_ = nullptr;
	Shared<Camera> camera_ = nullptr;
	Shared<EnemyManager>enemies_ = nullptr;

};
