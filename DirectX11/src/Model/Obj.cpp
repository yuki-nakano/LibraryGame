#include "Obj.h"

#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <array>

namespace engine
{
	ObjManager::ObjManager(DirectXGraphics* direct_graphics_)
		:m_device(direct_graphics_->GetDevice())
		, m_context(direct_graphics_->GetContext())
	{
	}

	ObjManager::~ObjManager()
	{
	}

	bool ObjManager::LoadObj(const std::string& name_, const std::string& file_name_)
	{
		ObjData objData;

		if (bufferData.find(name_) != bufferData.end()) { return false; }
		bufferData[name_];

		if (!AnalyzeData(file_name_, objData)) { return false; }

		if (!CreateVertexBuffer(name_, objData)) { return false; }



		return true;
	}

	void ObjManager::RenderObj(const std::string& name_)
	{
		UINT strides = sizeof(vecesData);
		UINT offsets = 0;
		m_context->IASetVertexBuffers(0, 1, &bufferData.at(name_).vertexBuffer, &strides, &offsets);
	}

	bool ObjManager::AnalyzeData(const std::string& file_name_, ObjData& obj_data_)
	{
		std::ifstream file(file_name_);
		if (!file) { return false; }

		ObjData objData{};

		std::string str{};
		while (std::getline(file, str))
		{
			std::stringstream ss{ str };
			std::string key{};
			std::getline(ss, key, ' ');

			if (key.compare("#") == 0)
			{
				continue;
			}
			else if (key.compare("v") == 0)
			{
				vecesData vertex{};
				std::string num{};
				int count{ 0 };
				while (std::getline(ss, num, ' '))
				{
					vertex[count] = std::atoi(num.c_str());
					count++;
				}
				objData.vecesDataList.push_back(vertex);
			}
			else if (key.compare("vn") == 0)
			{
				nomalData normal{};
				std::string num{};
				int count{ 0 };
				while (std::getline(ss, num, ' '))
				{
					normal[count] = std::atoi(num.c_str());
					count++;
				}
				objData.nomalDataList.push_back(normal);
			}
			else if (key.compare("f") == 0)
			{
				elementsData elements{};
				std::string data{};
				int count{ 0 };
				while (std::getline(ss, data, ' '))
				{
					std::stringstream data_ss{ data };
					std::string num;
					while (std::getline(data_ss, num, '/'))
					{
						elements[count / 3][count % 3] = std::atoi(num.c_str());
						count++;
					}
				}
				objData.elementsDataList.push_back(elements);
			}
		}

		obj_data_ = objData;
		return false;
	}

	bool ObjManager::CreateVertexBuffer(const std::string& name_, ObjData& obj_data_)
	{
		D3D11_BUFFER_DESC vertexBuffer;
		vertexBuffer.ByteWidth = sizeof(vecesData) * obj_data_.vecesDataList.size();
		vertexBuffer.Usage = D3D11_USAGE_DEFAULT;
		vertexBuffer.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		vertexBuffer.CPUAccessFlags = 0;
		vertexBuffer.MiscFlags = 0;
		vertexBuffer.StructureByteStride = sizeof(vecesData);

		D3D11_SUBRESOURCE_DATA vertexSubresData;
		vertexSubresData.pSysMem = &obj_data_.vecesDataList;
		vertexSubresData.SysMemPitch = 0;
		vertexSubresData.SysMemSlicePitch = 0;

		if (FAILED(m_device->CreateBuffer(&vertexBuffer, &vertexSubresData, &bufferData.at(name_).vertexBuffer)))
		{
			return false;
		}

		return true;
	}

	bool ObjManager::CreateIndexBuffer()
	{
		D3D11_BUFFER_DESC indexBuffer;
		indexBuffer.ByteWidth;
		indexBuffer.Usage = D3D11_USAGE_DEFAULT;
		indexBuffer.BindFlags = D3D11_BIND_INDEX_BUFFER;
		indexBuffer.CPUAccessFlags = 0;
		indexBuffer.MiscFlags = 0;
		indexBuffer.StructureByteStride;

		return true;
	}
}