#pragma once

class SceneBase;
class Player;
class Map;
class MapChip;
class TrackingEnemy;
class EnemyManager;

class GameManager {
public:

	//�C���X�^���X�̎擾�iSceneBase��start_scene �X�^�[�g�V�[���j
	static GameManager* GetInstance(SceneBase* start_scene = nullptr);
	static void Destroy();

	void  changeScene(SceneBase* next_scene);

	void update(float delta_time);

	Shared<Player> getPlayer();
	Shared<Map> getMap();
	Shared<EnemyManager> getEnemyManager();

	MapChip* getMapChip(int x, int y);

	//�G�̃|�W�V�������擾���ăv���C���[�Ƃ̋�����Ԃ��֐�
	float GetPlayerDistance(tnl::Vector3& enemyPos);

	//�G�ƃv���C���[�̓����蔻��
	bool isIntersectPlayerAndEnemy();

	//�v���C���[���S�֐�
	void deathPlayer() {

	}

private:

	static GameManager* instance_;

	GameManager(SceneBase* start_scene);
	SceneBase* now_scene_ = nullptr;			//���̃V�[��
	SceneBase* next_scene_ = nullptr;			//���̃V�[��

	Shared<Player> player_ = nullptr;
	Shared<Map> map_ = nullptr;
	Shared<EnemyManager> enemyManager_ = nullptr;

};