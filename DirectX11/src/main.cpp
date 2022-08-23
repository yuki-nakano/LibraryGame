#include "Library/Library.h"

#include "Scene/SceneManager.h"

int WINAPI WinMain(
	_In_ HINSTANCE hInstace,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmpLine,
	_In_ int nCmdshow)
{
	// ライブラリ初期化
	if (!engine::Library::Init("test", 1080, 720)) { return 0; }

	Game::SceneManager* sceneManager = new Game::SceneManager();

	while (engine::Library::CheckMessage())
	{
		// ライブラリ更新
		engine::Library::Update();

		// 描画開始
		engine::Library::StartRendering();

		sceneManager->Update();

		//描画終了
		engine::Library::FinishRendering();
	}

	engine::Library::Release();
}
