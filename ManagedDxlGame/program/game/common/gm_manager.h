#pragma once

class SceneBase;

class GameManager {
public:
	//インスタンスの取得（SceneBaseのstart_scene スタートシーン）
	static GameManager* GetInstance(SceneBase* start_scene = nullptr);
	static void Destroy();
	static GameManager* instance_;

	void  changeScene(SceneBase* next_scene);

	void update(float delta_time);

private:
	GameManager(SceneBase* start_scene);
	SceneBase* now_scene_ = nullptr;			//今のシーン
	SceneBase* next_scene_ = nullptr;			//次のシーン

};