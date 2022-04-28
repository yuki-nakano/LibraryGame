﻿/**
* @file Library.h
* @brief directX関数群
*/

#ifndef LIBRARY_H
#define LIBRARY_H

#include "DirectX/DirectXGraphics.h"
#include "DirectX/Graphics2D.h"
#include "Shader/ShaderManager.h"
#include "WindowsAPI/WindowsAPI.h"
#include "WindowsAPI/Input.h"
#include "WindowsAPI/Mouse.h"
#include "Model/ObjManager.h"
#include "DirectX/Camera.h"
#include "DirectX/Matrix.h"
#include "DirectX/DirectXUtility.h" 
#include "DirectX/DirectXTexture.h"

#include <memory>

namespace engine
{
	/**
	* @brief ライブラリクラス
	*/
	class Library
	{
	private:
		Library();

	public:
		/**
		* @brief ライブラリ初期化
		* @param window_name_　ウィンドウの名前
		* @param widht_ ウィンドウ横サイズ
		* @param height_ ウィンドウ縦サイズ
		* @return ライブラリの初期化成功時true
		* @note ゲームループ前に必ず1度呼び出す
		*/
		static bool Init(const std::string& window_name_, const int& widht_, const int& height_);

		/**
		* @brief ライブラリの解放
		*/
		static void Release();

		/**
		* @brief ライブラリの更新
		*/
		static void Update();

		//------------------------------------------------------------
		//   WindowsAPI
		//------------------------------------------------------------

		/**
		* @brief ゲームループごとに呼び出す
		* @return ループ終了時false
		*/
		static bool CheckMwssage() { return m_instance->window->CheckMessage(); }


		//------------------------------------------------------------
		//   Input
		//------------------------------------------------------------

		/**
		* @brief 使用するキーの登録
		* @param 登録するキーのリスト
		*/
		static void RegisterKey(std::vector<int> key_list_) { m_instance->input->RegisterKey(key_list_); }

		/**
		* @brief 指定されたキーが押されているか
		* @param キーの指定
		* @return 押されていたらtrue
		*/
		static bool IsHeldKey(int key_) { m_instance->input->IsHeldKey(key_); }

		/**
		* @brief 指定されたキーが押された瞬間なのか
		* @param キーの指定
		* @return 押された瞬間ならtrue
		*/
		static bool IsPushedKey(int key_) { m_instance->input->IsPushedKey(key_); }

		/**
		* @brief 指定されたキーが離されたか
		* @param キーの指定
		* @return 離されていたらtrue
		*/
		static bool IsRelesedKey(int key_) { return m_instance->input->IsRelesedKey(key_); }

		/**
		* @brief キーの状態の取得
		* @param キーの指定
		* @return キーの状態
		*/
		static KeyState GetKeyState(int key_) { return m_instance->input->GetKeyState(key_); }


		//------------------------------------------------------------
		//   mouse
		//------------------------------------------------------------

		/**
		* @brief マウスのx座標の取得
		* @return マウスのx座標
		*/
		long GetMousePosX() { return m_instance->mouse->GetPosX(); };

		/**
		* @brief マウスのy座標の取得
		* @return マウスのy座標
		*/
		long GetMousePosY() { return m_instance->mouse->GetPosY(); };


		//------------------------------------------------------------
		//   DirectXGraphics
		//------------------------------------------------------------

		/**
		* @brief レンダリングの開始
		* @note バッファの初期化
		*/
		static void StartRendering() { m_instance->graphics->StartRendering(); }

		/**
		* @brief レンダリングの終了
		* @note バッファの切り替え
		*/
		static void FinishRendering() { m_instance->graphics->FinishRendering(); }


		//------------------------------------------------------------
		//   ShaderManager
		//------------------------------------------------------------

		/**
		* @brief シェーダーの作成
		* @param file_name_ 読み込むシェーダーファイルパス
		* @param shader_name_ シェーダー呼び出し時の名前
		* @param shader_type_ シェーダーのタイプ
		*/
		static bool CreateShader(const std::string& file_name_, const std::string& shader_name_, const ShaderType& shader_type_) { return m_instance->shader->CreateShader(file_name_, shader_name_, shader_type_); }

		/**
		* @brief シェーダーの削除
		* @param shader_name_ CreateShader関数で登録した名前
		*/
		static void DeleteShader(const std::string& shader_name_) { m_instance->shader->DeleteShader(shader_name_); }

		/**
		* @brief シェーダーサイズの取得
		* @param shader_name_ CreateShader関数で登録した名前
		* @return シェーダーサイズ
		*/
		static long GetShaderSize(const std::string& shader_name_) { return m_instance->shader->GetShaderSize(shader_name_); }

		/**
		* @brief シェーダー情報の取得
		* @param shader_name_ CreateShader関数で登録した名前
		* @return シェーダー情報
		*/
		static std::string GetShaderData(const std::string& shader_name_) { return m_instance->shader->GetShaderData(shader_name_); }

		/**
		* @breif VertexShaderのInterfaceの取得
		* @param shder_name_
		*/
		static ID3D11VertexShader* GetVertexInterface(const std::string& shader_name_) { return m_instance->shader->GetVertexInterface(shader_name_); }

		/**
		* @breif PixelShaderのInterfaceの取得
		* @param shader_name_ CreateShader関数で登録した名前
		*/
		static ID3D11PixelShader* GetPixelInterface(const std::string& shader_name_) { return m_instance->shader->GetPixelInterface(shader_name_); }


		//------------------------------------------------------------
		//   Graphics2D
		//------------------------------------------------------------
		static void DrawPorigon(float pos_x_, float pos_y_, float width_, float height_, float angle_ = 0.0f) { m_instance->graphics2d->DrawPorigon(pos_x_, pos_y_, width_, height_, angle_); }

		static void DrawRect(float pos_x_, float pos_y_, float width_, float height_, float angle_) { m_instance->graphics2d->DrawRect(pos_x_, pos_y_, width_, height_, angle_); }

		//------------------------------------------------------------
		//   GraphicsTexture
		//------------------------------------------------------------

		static bool LoadTexture(const std::wstring& file_name_, const std::string& name_) { return m_instance->texture->LoadTexture(file_name_, name_); }

		static void DrawTexture(const std::string& name_, float pos_x_, float pos_y_, float width_, float height_, float angle_ = 0.0f) { m_instance->texture->DrawTexture(name_, pos_x_, pos_y_, width_, height_, angle_); }


		//------------------------------------------------------------
		//   Obj
		//------------------------------------------------------------

		/**
		* @brief objファイルの読み込み
		* @param file_name_ 読み込むobjファイルパス
		* @param name_　obj呼び出し時の名前
		* @return obj読み込み成功時true
		*/
		static bool LoadObj(const std::string& file_name_, const std::string& name_) { return m_instance->obj->LoadObj(file_name_, name_); };

		/**
		* @brief 読み込んだobjの削除
		* @param LoadObj関数で登録した名前
		*/
		static void DeleteObj(const std::string& name_) { m_instance->obj->DeleteObj(name_); };

		/**
		* @brief obj描画
		* @param obj呼び出し時の名前
		*/
		static void RenderObj(const std::string& name_, Vec3f pos_, Vec3f rote_, Vec3f scale_) { m_instance->obj->RenderObj(name_, pos_, rote_, scale_); }

		static void ReleseObj(const std::string& name_) { m_instance->obj->DeleteObj(name_); }

	private:
		/// インスタンス
		static Library* m_instance;

		WindowsAPI* window{ nullptr };
		InputManager* input{ nullptr };
		Mouse* mouse{ nullptr };
		DirectXGraphics* graphics{ nullptr };
		ShaderManager* shader{ nullptr };
		Graphics2D* graphics2d{ nullptr };
		DirectXTexture* texture{ nullptr };
		ObjManager* obj{ nullptr };
		Camera* camera{ nullptr };
		Matrix* matrix{ nullptr };
	};
}

#endif // !LIBRARY_H