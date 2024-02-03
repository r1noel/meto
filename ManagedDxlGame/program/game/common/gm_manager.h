#pragma once

class SceneBase;

class GameManager {
public:
	//�C���X�^���X�̎擾�iSceneBase��start_scene �X�^�[�g�V�[���j
	static GameManager* GetInstance(SceneBase* start_scene = nullptr);
	static void Destroy();
	static GameManager* instance_;

	void  changeScene(SceneBase* next_scene);

	void update(float delta_time);

private:
	GameManager(SceneBase* start_scene);
	SceneBase* now_scene_ = nullptr;			//���̃V�[��
	SceneBase* next_scene_ = nullptr;			//���̃V�[��

};