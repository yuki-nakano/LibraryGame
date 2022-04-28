#include "Library/Library.h"

int WINAPI WinMain(
	HINSTANCE hInstace,
	HINSTANCE hPrevInstance,
	LPSTR lpCmpLine,
	int nCmdshow)
{
	// ライブラリ初期化
	if (!engine::Library::Init("test", 640, 480)) { return 0; }
	engine::Library::LoadObj("res/hikouki.obj", "hikouki");

	engine::Vec3f pos(0, -10, 0);
	engine::Vec3f rote(-20, 0, -30);
	engine::Vec3f scale(1, 1, 1);

	while (engine::Library::CheckMwssage())
	{
		// ライブラリ更新
		engine::Library::Update();

		// 描画開始
		engine::Library::StartRendering();

		//engine::Library::DrawRect(0, 0, 100, 100, 0.0f);

		rote.y += 0.01f;

		engine::Library::RenderObj("hikouki", pos, rote, scale);

		//描画終了
		engine::Library::FinishRendering();
	}

	engine::Library::ReleseObj("hikouki");

	engine::Library::Release();
}
