#include "VertexShader.h"

namespace engine
{
	bool VertexShader::CreateShader()
	{
		if (FAILED(DirectXGraphics::GetInstance()->GetDevice()->CreateVertexShader(m_data, m_size, nullptr, &m_interface)))
		{
			return false;
		}

		return true;
	}

	void VertexShader::DeleteShader()
	{
		//delete[] m_data;

		if (m_interface != nullptr) { return; }
		m_interface->Release();
	}
}