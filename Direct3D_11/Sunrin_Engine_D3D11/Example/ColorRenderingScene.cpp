#include "SR_PCH.h"

#include "ColorRenderingScene.h"

namespace Example
{

	ColorRenderingScene::ColorRenderingScene() :
		SR_GameScene(L"ColorRenderingScene")
	{

	}

	bool ColorRenderingScene::OnEnter()
	{
		std::cout << "ColorRenderingScene - Enter" << std::endl;

		return true;
	}

	bool ColorRenderingScene::OnExit()
	{
		std::cout << "ColorRenderingScene - Exit" << std::endl;

		return true;
	}

	bool ColorRenderingScene::Initialize()
	{
		std::cout << "ColorRenderingScene - Initialize" << std::endl;

		SR_RF_BOOL(CreateResources());

		m_colorEntity = AddEntity(new ColorEntity(this, L"ColorEntity"));
		SR_RF_BOOL(m_colorEntity->Initialize(
			m_mesh,
			m_vertexShader,
			m_pixelShader,
			m_vs_matrixBuffer));

		m_cameraEntity = AddEntity(new CameraEntity(this, L"CameraEntity"));
		SR_RF_BOOL(m_cameraEntity->Initialize(
			SR_App::GetInstance()->GetGraphic().GetSwapChainRenderTargetView(),
			SR_App::GetInstance()->GetGraphic().GetSwapChainDepthStencilView(),
			m_depthStencilState,
			m_blendState,
			m_rasterizerState,
			SR_App::GetInstance()->GetGraphic().GetSwapChainViewport(),
			m_clearColor));

		m_cameraEntity->GetTransform()->SetPositionZ(-30.0f);
		m_cameraEntity->FindComponent<DefaultCamera>()->SetViewWidth(static_cast<float>(SR_App::GetInstance()->GetClientWidth()));
		m_cameraEntity->FindComponent<DefaultCamera>()->SetViewHeight(static_cast<float>(SR_App::GetInstance()->GetClientHeight()));

		return true;
	}

	bool ColorRenderingScene::Update()
	{
		if (SR_App::GetInstance()->GetInput().KeyPressing(SR_KeyCode::W))
		{
			m_colorEntity->GetTransform()->AddRotationX(-90.0f * SR_App::GetInstance()->GetTime().GetDeltaTime());
		}
		if (SR_App::GetInstance()->GetInput().KeyPressing(SR_KeyCode::A))
		{
			m_colorEntity->GetTransform()->AddRotationY(90.0f * SR_App::GetInstance()->GetTime().GetDeltaTime());
		}
		if (SR_App::GetInstance()->GetInput().KeyPressing(SR_KeyCode::S))
		{
			m_colorEntity->GetTransform()->AddRotationX(90.0f * SR_App::GetInstance()->GetTime().GetDeltaTime());
		}
		if (SR_App::GetInstance()->GetInput().KeyPressing(SR_KeyCode::D))
		{
			m_colorEntity->GetTransform()->AddRotationY(-90.0f * SR_App::GetInstance()->GetTime().GetDeltaTime());
		}

		if (SR_App::GetInstance()->GetInput().KeyPressing(SR_KeyCode::Up))
		{
			m_colorEntity->GetTransform()->AddPositionY(10.0f * SR_App::GetInstance()->GetTime().GetDeltaTime());
		}
		if (SR_App::GetInstance()->GetInput().KeyPressing(SR_KeyCode::Left))
		{
			m_colorEntity->GetTransform()->AddPositionX(-10.0f * SR_App::GetInstance()->GetTime().GetDeltaTime());
		}
		if (SR_App::GetInstance()->GetInput().KeyPressing(SR_KeyCode::Down))
		{
			m_colorEntity->GetTransform()->AddPositionY(-10.0f * SR_App::GetInstance()->GetTime().GetDeltaTime());
		}
		if (SR_App::GetInstance()->GetInput().KeyPressing(SR_KeyCode::Right))
		{
			m_colorEntity->GetTransform()->AddPositionX(10.0f * SR_App::GetInstance()->GetTime().GetDeltaTime());
		}
		if (SR_App::GetInstance()->GetInput().KeyPressing(SR_KeyCode::Q))
		{
			m_colorEntity->GetTransform()->AddPositionZ(-5.0f * SR_App::GetInstance()->GetTime().GetDeltaTime());
		}
		if (SR_App::GetInstance()->GetInput().KeyPressing(SR_KeyCode::E))
		{
			m_colorEntity->GetTransform()->AddPositionZ(5.0f * SR_App::GetInstance()->GetTime().GetDeltaTime());
		}

		return true;
	}

	bool ColorRenderingScene::FixedUpdate()
	{
		return true;
	}

	bool ColorRenderingScene::LateUpdate()
	{
		return true;
	}

	bool ColorRenderingScene::CreateResources()
	{
		SR_RF_BOOL(GetResourceGenerator().CreateMesh(L"cube.fbx", &m_mesh));
		SR_InputElement inputElement;
		inputElement.AddElement("POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0);
		SR_RF_BOOL(GetResourceGenerator().CreateVertexShader(L"color_render_vs.hlsl", nullptr, nullptr, inputElement.m_descs, &m_vertexShader));
		SR_RF_BOOL(GetResourceGenerator().CreatePixelShader(L"color_render_ps.hlsl", nullptr, nullptr, &m_pixelShader));
		SR_BufferDesc bufferDesc;
		bufferDesc.SetUsage(D3D11_USAGE_DYNAMIC);
		bufferDesc.SetBindFlags(D3D11_BIND_CONSTANT_BUFFER);
		bufferDesc.SetCPUAccessFlags(D3D11_CPU_ACCESS_WRITE);
		bufferDesc.SetByteWidth(sizeof(ColorPass::VS_MatrixBuffer));
		SR_RF_BOOL(GetResourceGenerator().CreateBuffer(&bufferDesc.m_desc, nullptr, &m_vs_matrixBuffer));

		SR_DepthStencilDesc depthStencilDesc;
		SR_RF_BOOL(GetResourceGenerator().CreateDepthStencilState(&depthStencilDesc.m_desc, &m_depthStencilState));
		SR_BlendDesc blendDesc;
		SR_RF_BOOL(GetResourceGenerator().CreateBlendState(&blendDesc.m_desc, &m_blendState));
		SR_RasterizerDesc rasterizerDesc;
		SR_RF_BOOL(GetResourceGenerator().CreateRasterizerState(&rasterizerDesc.m_desc, &m_rasterizerState));
		SR_RF_BOOL(GetResourceGenerator().CreateVector4(0.0f, 0.0f, 1.0f, 1.0f, &m_clearColor));

		return true;
	}

}