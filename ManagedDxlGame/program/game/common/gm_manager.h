#pragma once

class SceneBase;
class Player;
class Map;
class MapChip;
class TrackingEnemy;
class EnemyManager;

class GameManager {
public:

	//インスタンスの取得（SceneBaseのstart_scene スタートシーン）
	static GameManager* GetInstance(SceneBase* start_scene = nullptr);
	static void Destroy();

	void  changeScene(SceneBase* next_scene);

	void update(float delta_time);

	Shared<Player> getPlayer();
	Shared<Map> getMap();
	Shared<EnemyManager> getEnemyManager();

	MapChip* getMapChip(int x, int y);

	//敵のポジションを取得してプレイヤーとの距離を返す関数
	float GetPlayerDistance(tnl::Vector3& enemyPos);

	//敵とプレイヤーの当たり判定
	bool isIntersectPlayerAndEnemy();

	//プレイヤー死亡関数
	void deathPlayer() {

	}

private:

	static GameManager* instance_;

	GameManager(SceneBase* start_scene);
	SceneBase* now_scene_ = nullptr;			//今のシーン
	SceneBase* next_scene_ = nullptr;			//次のシーン

	Shared<Player> player_ = nullptr;
	Shared<Map> map_ = nullptr;
	Shared<EnemyManager> enemyManager_ = nullptr;

};