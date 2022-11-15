#include "ObjManager.h"

namespace engine
{
	ObjManager::~ObjManager()
	{
		for (auto itr = m_objList.begin(); itr != m_objList.end();)
		{
			delete itr->second;

			itr = m_objList.erase(itr);
		}
	}

	bool ObjManager::LoadObj(const std::string& file_name_, const std::string& name_)
	{
		Obj* obj = new Obj();

		if (!obj->Load(file_name_)) { return false; }

		m_objList.try_emplace(name_, obj);

		return true;
	}

	void ObjManager::DeleteObj(const std::string& name_)
	{
		delete m_objList.at(name_);

		m_objList.erase(name_);
	}

	void ObjManager::Render(const std::string& name_, Vec3f pos_, Vec3f rote_, Vec3f scale_)
	{
		m_objList.at(name_)->Render(pos_, rote_, scale_);
	}

	void ObjManager::RenderSetColor(const std::string& name_, const Vec3f& pos_, const Vec3f& rote_, const Vec3f& scale_, const Vec3f& color_, const float& alpha_)
	{
		m_objList.at(name_)->RenderSetColor(pos_, rote_, scale_, color_, alpha_);
	}

}