#include "ShaderBase.h"

#include <fstream>
#include <sstream>

namespace engine
{
	ShaderBase::ShaderBase()
	{
	}

	ShaderBase::~ShaderBase()
	{
	}

	bool ShaderBase::LoadFile(const std::string& file_name_)
	{
		//std::fstream file(file_name_);
		//if (!file) { return false; }

		//file.seekp(0, std::ios_base::end);
		//m_size = file.tellp();

		//file.seekp(0, std::ios_base::beg);

		FILE* file = nullptr;
		fopen_s(&file, file_name_.c_str(), "rb");
		if (file == nullptr) { return false; }

		fseek(file, 0, SEEK_END);
		m_size = ftell(file);
		fseek(file, 0, SEEK_SET);

		m_data = new char[m_size];
		fread_s(m_data, m_size, m_size, 1, file);
		fclose(file);

		//struct stat sb {};
		//stat(file_name_.c_str(), &sb);
		//m_data.resize(sb.st_size);
		//fread_s(const_cast<char*>(m_data.data()), m_size, m_size, 1, file);
		//fclose(file);

		return true;
	}
}