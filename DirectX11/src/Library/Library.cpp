#include "Library.h"

namespace engine
{
	Library* Library::m_instance = nullptr;

	Library::Library()
	{
		window = WindowsAPI::CreateInstance();
		input = InputManager::CreateInstance();
		mouse = Mouse::CreateInstance();
		graphics = DirectXGraphics::CreateInstance();
		camera = Camera::CreateInstance();
		matrix = Matrix::CreateInstance();
		shader = ShaderManager::CreateInstance();
		graphics2d = Graphics2D::CreateInstance();
		texture = DirectXTexture::CreateInstance();
		obj = ObjManager::CreateInstance();
	}

	bool Library::Init(const std::string& window_name_, const int& widht_, const int& height_)
	{
		m_instance = new Library;

		m_instance->window->Draw(window_name_, widht_, height_);

		Vec2f viewport(widht_, height_);

		m_instance->matrix->SetViewport(viewport);

		if (!m_instance->graphics->Init()) { return false; }

		if (!m_instance->shader->Init()) { return false; }

		m_instance->graphics2d->Init();

		m_instance->texture->Init();

		return true;
	}

	void Library::Release()
	{
		m_instance->graphics->Release();
	}

	void Library::Update()
	{
		m_instance->input->UpdateKeyState();

		m_instance->mouse->Update();
	}
}
