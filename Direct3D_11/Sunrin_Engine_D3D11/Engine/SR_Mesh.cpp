#include "SR_PCH.h"

#include "SR_Mesh.h"
#include "SR_App.h"
#include "SR_Converter.h"
#include "SR_RenderDescription.h"
#include "SR_Vector2.h"
#include "SR_Vector3.h"

namespace SunrinEngine
{

	SR_Mesh::SR_Mesh() noexcept :
		m_vertexCount		{ 0 },
		m_positionBuffer	{ nullptr },
		m_texCoordBuffer	{ nullptr },
		m_normalBuffer		{ nullptr },
		m_tangentBuffer		{ nullptr },
		m_binormalBuffer	{ nullptr }
	{

	}

	bool SR_Mesh::CreateMesh(const std::wstring & filePath)
	{
		FbxManager * fbxManager{ FbxManager::Create() };

		std::unique_ptr<FbxManager, std::function<void(FbxManager*)>> unique_fbxManager{
			fbxManager,
			[](FbxManager * p) { p->Destroy(); } };

		FbxIOSettings * fbxIOSettings = FbxIOSettings::Create(fbxManager, IOSROOT);

		fbxManager->SetIOSettings(fbxIOSettings);

		FbxScene * fbxScene{ FbxScene::Create(fbxManager, "MyScene") };

		FbxImporter * fbxImporter{ FbxImporter::Create(fbxManager, "MyImporter") };

		std::string path{ "Resources\\Meshes\\" + SR_Converter::ToAscii(filePath) };

		SR_LOG_RF_BOOL_AUTO(fbxImporter->Initialize(path.c_str(), -1, fbxManager->GetIOSettings()));
		SR_LOG_RF_BOOL_AUTO(fbxImporter->Import(fbxScene));

		fbxImporter->Destroy();

		std::vector<SR_Vector3> positions;
		std::vector<SR_Vector2> texCoords;
		std::vector<SR_Vector3> normals;
		std::vector<SR_Vector3> tangents;
		std::vector<SR_Vector3> binormals;

		FbxNode * rootNode{ fbxScene->GetRootNode() };

		for (int i{ 0 }; i < rootNode->GetChildCount(); ++i)
		{
			FbxNode * childNode{ rootNode->GetChild(i) };

			FbxNodeAttribute::EType attributeType{ childNode->GetNodeAttribute()->GetAttributeType() };

			switch (attributeType)
			{
				case FbxNodeAttribute::eMesh:
				{
					FbxMesh * fbxMesh{ reinterpret_cast<FbxMesh*>(childNode->GetNodeAttribute()) };

					FbxVector4 * controlPoints{ fbxMesh->GetControlPoints() };
					int vertexID{ 0 };

					for (int i{ 0 }; i < fbxMesh->GetPolygonCount(); ++i)
					{
						for (int j{ 0 }; j < fbxMesh->GetPolygonSize(i); ++j)
						{
							bool isBreak{ false };
							int index{ 0 };
							int controlPointIndex{ fbxMesh->GetPolygonVertex(i, j) };

							// Position
							positions.emplace_back(
								static_cast<float>(controlPoints[controlPointIndex].mData[0]),
								static_cast<float>(controlPoints[controlPointIndex].mData[1]),
								static_cast<float>(controlPoints[controlPointIndex].mData[2]));


							// TexCoord
							for (int k{ 0 }; k < fbxMesh->GetElementUVCount(); ++k)
							{
								FbxGeometryElementUV * fbxGeometryElementTexCoord{ fbxMesh->GetElementUV(k) };

								isBreak = false;
								index = 0;

								if (fbxGeometryElementTexCoord->GetMappingMode() == FbxGeometryElement::eByControlPoint) { index = controlPointIndex; }
								else if (fbxGeometryElementTexCoord->GetMappingMode() == FbxGeometryElement::eByPolygonVertex) { index = vertexID; }

								if (fbxGeometryElementTexCoord->GetReferenceMode() == FbxGeometryElement::eDirect) { index = index; }
								else if (fbxGeometryElementTexCoord->GetReferenceMode() == FbxGeometryElement::eIndexToDirect) { index = fbxGeometryElementTexCoord->GetIndexArray().GetAt(index); }

								FbxVector2 vector2{ fbxGeometryElementTexCoord->GetDirectArray().GetAt(index) };
								texCoords.emplace_back(
									static_cast<float>(vector2.mData[0]),
									static_cast<float>(vector2.mData[1]));
							}

							// Normal
							for (int k{ 0 }; k < fbxMesh->GetElementNormalCount(); ++k)
							{
								FbxGeometryElementNormal * fbxGeometryElementNormal{ fbxMesh->GetElementNormal(k) };

								isBreak = false;
								index = 0;

								if (fbxGeometryElementNormal->GetMappingMode() == FbxGeometryElement::eByControlPoint) { index = controlPointIndex; }
								else if (fbxGeometryElementNormal->GetMappingMode() == FbxGeometryElement::eByPolygonVertex) { index = vertexID; }

								if (fbxGeometryElementNormal->GetReferenceMode() == FbxGeometryElement::eDirect) { index = index; }
								else if (fbxGeometryElementNormal->GetReferenceMode() == FbxGeometryElement::eIndexToDirect) { index = fbxGeometryElementNormal->GetIndexArray().GetAt(index); }

								FbxVector4 vector3{ fbxGeometryElementNormal->GetDirectArray().GetAt(index) };
								normals.emplace_back(
									static_cast<float>(vector3.mData[0]),
									static_cast<float>(vector3.mData[1]),
									static_cast<float>(vector3.mData[2]));
							}

							// Tangent
							for (int k{ 0 }; k < fbxMesh->GetElementTangentCount(); ++k)
							{
								FbxGeometryElementTangent * fbxGeometryElementTangent{ fbxMesh->GetElementTangent(k) };

								isBreak = false;
								index = 0;

								if (fbxGeometryElementTangent->GetMappingMode() == FbxGeometryElement::eByControlPoint) { index = controlPointIndex; }
								else if (fbxGeometryElementTangent->GetMappingMode() == FbxGeometryElement::eByPolygonVertex) { index = vertexID; }

								if (fbxGeometryElementTangent->GetReferenceMode() == FbxGeometryElement::eDirect) { index = index; }
								else if (fbxGeometryElementTangent->GetReferenceMode() == FbxGeometryElement::eIndexToDirect) { index = fbxGeometryElementTangent->GetIndexArray().GetAt(index); }

								FbxVector4 vector3{ fbxGeometryElementTangent->GetDirectArray().GetAt(index) };
								tangents.emplace_back(
									static_cast<float>(vector3.mData[0]),
									static_cast<float>(vector3.mData[1]),
									static_cast<float>(vector3.mData[2]));
							}

							// Binormal
							for (int k{ 0 }; k < fbxMesh->GetElementBinormalCount(); ++k)
							{
								FbxGeometryElementBinormal * fbxGeometryElementBinormal{ fbxMesh->GetElementBinormal(k) };

								isBreak = false;
								index = 0;

								if (fbxGeometryElementBinormal->GetMappingMode() == FbxGeometryElement::eByControlPoint) { index = controlPointIndex; }
								else if (fbxGeometryElementBinormal->GetMappingMode() == FbxGeometryElement::eByPolygonVertex) { index = vertexID; }

								if (fbxGeometryElementBinormal->GetReferenceMode() == FbxGeometryElement::eDirect) { index = index; }
								else if (fbxGeometryElementBinormal->GetReferenceMode() == FbxGeometryElement::eIndexToDirect) { index = fbxGeometryElementBinormal->GetIndexArray().GetAt(index); }

								FbxVector4 vector3{ fbxGeometryElementBinormal->GetDirectArray().GetAt(index) };
								binormals.emplace_back(
									static_cast<float>(vector3.mData[0]),
									static_cast<float>(vector3.mData[1]),
									static_cast<float>(vector3.mData[2]));
							}

							++vertexID;
						}
					}
				}
				break;
				case FbxNodeAttribute::eMarker:
				case FbxNodeAttribute::eSkeleton:
				case FbxNodeAttribute::eNurbs:
				case FbxNodeAttribute::ePatch:
				case FbxNodeAttribute::eCamera:
				case FbxNodeAttribute::eLight:
				case FbxNodeAttribute::eLODGroup:
					break;
			}
		}

		SR_BufferDesc bufferDesc;
		bufferDesc.SetUsage(D3D11_USAGE_IMMUTABLE);
		bufferDesc.SetBindFlags(D3D11_BIND_VERTEX_BUFFER);

		D3D11_SUBRESOURCE_DATA subResourceData{ nullptr, 0, 0 };

		m_vertexCount = static_cast<unsigned>(positions.size());

		if (positions.size() > 0)
		{
			bufferDesc.SetByteWidth(sizeof(SR_Vector3) * m_vertexCount);

			subResourceData.pSysMem = &positions[0];
			SR_App::GetInstance()->GetGraphic().GetD3DDevice()->CreateBuffer(&bufferDesc.m_desc, &subResourceData, m_positionBuffer.GetAddressOf());
		}

		if (texCoords.size() > 0)
		{
			bufferDesc.SetByteWidth(sizeof(SR_Vector2) * m_vertexCount);

			subResourceData.pSysMem = &texCoords[0];
			SR_App::GetInstance()->GetGraphic().GetD3DDevice()->CreateBuffer(&bufferDesc.m_desc, &subResourceData, m_texCoordBuffer.GetAddressOf());
		}

		if (normals.size() > 0)
		{
			bufferDesc.SetByteWidth(sizeof(SR_Vector3) * m_vertexCount);

			subResourceData.pSysMem = &normals[0];
			SR_App::GetInstance()->GetGraphic().GetD3DDevice()->CreateBuffer(&bufferDesc.m_desc, &subResourceData, m_normalBuffer.GetAddressOf());
		}

		if (tangents.size() > 0)
		{
			bufferDesc.SetByteWidth(sizeof(SR_Vector3) * m_vertexCount);

			subResourceData.pSysMem = &tangents[0];
			SR_App::GetInstance()->GetGraphic().GetD3DDevice()->CreateBuffer(&bufferDesc.m_desc, &subResourceData, m_tangentBuffer.GetAddressOf());
		}

		if (binormals.size() > 0)
		{
			bufferDesc.SetByteWidth(sizeof(SR_Vector3) * m_vertexCount);

			subResourceData.pSysMem = &binormals[0];
			SR_App::GetInstance()->GetGraphic().GetD3DDevice()->CreateBuffer(&bufferDesc.m_desc, &subResourceData, m_binormalBuffer.GetAddressOf());
		}

		return true;
	}

}