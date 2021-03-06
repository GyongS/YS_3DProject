#include "stdafx.h"
#include "EditorScene.h"
#include "GameObject.h"
#include "ObjectFactory.h"

#include "InputManager.h"
#include "TextureStore.h"
#include "Layer.h"
#include "MainFrm.h"
#include "ObjectListView.h"
#include "Hierarchy.h"
#include "EditorView.h"
#include "SceneManager.h"

CEditorScene::CEditorScene()
{
}

CEditorScene::~CEditorScene()
{
}

SHARED(Engine::CScene) CEditorScene::Create(void)
{
	SHARED(CEditorScene) pCLogoScene(new CEditorScene, Engine::SmartDeleter<CEditorScene>);

	return pCLogoScene;
}

void CEditorScene::Awake(void)
{
	__super::Awake();
	InitLayers();
	InitPrototypes();
}

void CEditorScene::Start(void)
{
	__super::Start();

	m_pMain = dynamic_cast<CMainFrame*>(::AfxGetApp()->GetMainWnd());
	m_pEditorView = dynamic_cast<CEditorView*>(m_pMain->m_mainSplitter.GetPane(0, 0));
	m_pListView = dynamic_cast<CHierarchy*>(m_pMain->m_FirstSplitter.GetPane(0, 0));

	m_pMainCamera = Engine::ADD_CLONE(L"Camera", L"Camera", false)->GetComponent<Engine::CCameraComponent>();
	

	SHARED(Engine::CGameObject) pObj = Engine::ADD_CLONE(L"NormalBlock", L"WhiteBlock", false);

	m_pEditorView->Set_CubeData(pObj);
}

_uint CEditorScene::FixedUpdate(void)
{
	return _uint();
}

_uint CEditorScene::Update(void)
{
	_uint event = NO_EVENT;
	if (event = __super::Update())
		return event;

	m_pMainCamera->CameraMove();
	
	if (Engine::IMKEY_PRESS(KEY_RBUTTON))
	{
		if (Engine::IMKEY_DOWN(KEY_RBUTTON))
		{
			POINT curPt;
			GetCursorPos(&curPt);
			m_pMainCamera->SetCenterPt(curPt);
			
		}
		m_pMainCamera->CameraRotation();
	}
	

}

_uint CEditorScene::LateUpdate(void)
{
	_uint event = NO_EVENT;
	if (event = __super::LateUpdate())
		return event;


	return event;
}

void CEditorScene::OnDestroy(void)
{
	__super::OnDestroy();

}

void CEditorScene::OnEnable(void)
{
}

void CEditorScene::OnDisable(void)
{
}

void CEditorScene::InitLayers(void)
{
	AddLayer(L"Camera");
	AddLayer(L"NormalBlock");
}

void CEditorScene::InitPrototypes(void)
{
	SHARED(Engine::CGameObject) pCamera = Engine::CGameObject::Create(L"Camera", L"Camera", false);
	pCamera->AddComponent<Engine::CTransformComponent>();
	pCamera->GetComponent<Engine::CTransformComponent>()->SetPosition(_float3(0, 0, -5));
	pCamera->AddComponent<Engine::CCameraComponent>();
	Engine::CObjectFactory::GetInstance()->AddPrototype(pCamera);

	SHARED(Engine::CGameObject) pWhiteBlock = Engine::CGameObject::Create(L"NormalBlock", L"WhiteBlock", false);
	pWhiteBlock->AddComponent<Engine::CMeshComponent>();
	pWhiteBlock->AddComponent<Engine::CTextureComponent>();
	pWhiteBlock->AddComponent<Engine::CTransformComponent>();
	pWhiteBlock->AddComponent<Engine::CGraphicsComponent>();
	Engine::CObjectFactory::GetInstance()->AddPrototype(pWhiteBlock);

}




