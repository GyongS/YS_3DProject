#include "stdafx.h"
#include "Stage3Scene.h"
#include "GameObject.h"
#include "ObjectFactory.h"
#include "ShaderManager.h"
#include "SceneManager.h"
#include "Layer.h"
#include "WndApp.h"
#include "LoadingScene.h"
#include "InputManager.h"
#include "SoundManager.h"
#include "EventScene.h"

CStage3Scene::CStage3Scene() : m_NextSceneDelay(0.f), m_InitRot(false)
{
}


CStage3Scene::~CStage3Scene()
{
	OnDestroy();
}

SHARED(Engine::CScene) CStage3Scene::Create(void)
{
	SHARED(CStage3Scene) pScene(new CStage3Scene, Engine::SmartDeleter<CStage3Scene>);
	Engine::CSceneManager::GetInstance()->SetSceneName(L"Stage3Scene");

	return pScene;
}

void CStage3Scene::Awake(void)
{
	__super::Awake();
	SetWindowText(Engine::GET_HANDLE, m_name.c_str());

	Engine::CSoundManager::GetInstance()->StopAll();
	Engine::CSoundManager::GetInstance()->PlayBGM(L"Amb.wav");

	InitLayers();
	InitPrototypes();
}

void CStage3Scene::Start(void)
{
	__super::Start();
	SceneLoad();

	SHARED(Engine::CGameObject) pObj = Engine::CObjectFactory::GetInstance()->AddClone(L"Player", L"Player", true);
	pObj->GetComponent<Engine::CTransformComponent>()->SetPosition(_float3(2.f, 2.f, 0.f));
	//pObj->GetComponent<Engine::CTransformComponent>()->SetPosition(_float3(14.f, 32.f, 16.f));

	m_pPlayer = pObj;

	pObj = Engine::CObjectFactory::GetInstance()->AddClone(L"NextScenePoint", L"NextScenePoint", true);
	pObj->GetComponent<Engine::CTransformComponent>()->SetPosition(_float3(6.f, 7.f, -11.f));
	pObj->GetComponent<Engine::CTransformComponent>()->SetScale(_float3(1.f, 1.f, 1.f));

	m_pMainCamera = Engine::ADD_CLONE(L"Camera", L"Camera", true)->GetComponent<Engine::CCameraComponent>();	


	pObj = Engine::CObjectFactory::GetInstance()->AddClone(L"Default", L"Default", true);
	pObj->GetComponent<Engine::CTransformComponent>()->SetScale(_float3(10.0f, 10.0f, 1.0f));
	pObj->AddComponent<Engine::CUIComponent>()->SetTextureKey(L"MousePointUI");

	pObj = Engine::CObjectFactory::GetInstance()->AddClone(L"Default", L"Default", true);
	pObj->AddComponent<CElevator>()->Init(4.f,4.f, -20.f);
	pObj->AddComponent<Engine::CColliderComponent>()->AddCollider(Engine::CAabbCollider::Create(_float3(1.f, 1.f, 1.f), FLOAT3_ZERO)); 
	pObj->GetComponent<Engine::CColliderComponent>()->SetColliderID(5);
	pObj->GetComponent<Engine::CTransformComponent>()->SetPosition(_float3(15.f, 30.f, 16.f));
	m_pElevator = pObj;

	if (m_pMainCamera->GetIsStarted())
	{
		m_pMainCamera->SetCameraEvent(false);
	}



}

_uint CStage3Scene::FixedUpdate(void)
{
	_uint event = NO_EVENT;
	if (event = __super::FixedUpdate())
		return event;

	if (m_pMainCamera->GetIsStarted() && !m_InitRot)
	{
		m_pMainCamera->GetTransform()->SetRotationY(D3DXToRadian(180.f));
		m_InitRot = true;
	}


	return event;
}

_uint CStage3Scene::Update(void)
{
	_uint event = NO_EVENT;
	if (event = __super::Update())
		return event;

	if (m_ShakeEvent)
	{
		m_NextSceneDelay += GET_DT;
		{
			if (m_NextSceneDelay > 3.f)
			{
				m_pMainCamera->GetTransform()->AddPositionY(-20 * GET_DT);
				m_pElevator->GetComponent<Engine::CTransformComponent>()->AddPositionY(-20 * GET_DT);

				if (m_pMainCamera->GetTransform()->GetPosition().y <= -3.f)
				{
					Engine::CSceneManager::GetInstance()->SceneChange(CEventScene::Create());
					m_NextSceneDelay = 0.f;
					return 0;
					/*m_ShakeEvent = false;
					m_pMainCamera->SetCameraEvent(false);*/
				}
			}
		}		
		m_pMainCamera->GetTransform()->SetPositionX(m_pPlayer->GetComponent<Engine::CTransformComponent>()->GetPosition().x + rand() % 2 * 0.5f);
		
		m_pMainCamera->GetTransform()->SetPositionZ(m_pPlayer->GetComponent<Engine::CTransformComponent>()->GetPosition().z + rand() % 2 * 0.5f);
	}

	if (Engine::CInputManager::GetInstance()->KeyDown(KEY_F1))
	{
		Engine::CSceneManager::GetInstance()->SceneChange(CLoadingScene::Create(ESceneID::Stage1));

	}
	else if (Engine::CInputManager::GetInstance()->KeyDown(KEY_F2))
	{
		Engine::CSceneManager::GetInstance()->SceneChange(CLoadingScene::Create(ESceneID::Stage2));

	}	

	return event;
}

_uint CStage3Scene::LateUpdate(void)
{
	_uint event = NO_EVENT;
	if (event = __super::LateUpdate())
		return event;


	return event;
}

void CStage3Scene::OnDestroy(void)
{
	__super::OnDestroy();
}

void CStage3Scene::OnEnable(void)
{

}

void CStage3Scene::OnDisable(void)
{
}

void CStage3Scene::InitLayers(void)
{
	AddLayer(L"Default");
	AddLayer(L"Player");
	AddLayer(L"Camera");
	AddLayer(L"EventBlock");
	AddLayer(L"NormalBlock");
	AddLayer(L"NextScenePoint");
}

void CStage3Scene::InitPrototypes(void)
{
}

HRESULT CStage3Scene::SceneLoad()
{
	SHARED(Engine::CGameObject) pObj = nullptr;

	// ¿©±â¼­ ºÎÅÍ ¼öÁ¤
	auto& UnitInfo = Engine::CSceneManager::GetInstance()->GetUnitInfo().begin();

	for (auto& it = UnitInfo; it != Engine::CSceneManager::GetInstance()->GetUnitInfo().end();)
	{
		if (it->wsObjectKey == L"WhiteBlock")
		{
			pObj = Engine::ADD_CLONE(L"NormalBlock", L"WhiteBlock", true);
			pObj->GetComponent<Engine::CTransformComponent>()->SetPosition(it->vPos);
			pObj->GetComponent<Engine::CTransformComponent>()->SetRotation(it->vRot);
		}
		else if (it->wsObjectKey == L"RedBlock")
		{
			pObj = Engine::ADD_CLONE(L"EventBlock", L"RedBlock", true);
			pObj->GetComponent<Engine::CTransformComponent>()->SetPosition(it->vPos);
			pObj->GetComponent<Engine::CTransformComponent>()->SetRotation(it->vRot);
		}
		else if (it->wsObjectKey == L"BlueBlock")
		{
			pObj = Engine::ADD_CLONE(L"EventBlock", L"BlueBlock", true);
			pObj->GetComponent<Engine::CTransformComponent>()->SetPosition(it->vPos);
			pObj->GetComponent<Engine::CTransformComponent>()->SetRotation(it->vRot);

		}
		else if (it->wsObjectKey == L"YellowBlock")
		{
			pObj = Engine::ADD_CLONE(L"EventBlock", L"YellowBlock", true);
			pObj->GetComponent<Engine::CTransformComponent>()->SetPosition(it->vPos);
			pObj->GetComponent<Engine::CTransformComponent>()->SetRotation(it->vRot);

		}
		else if (it->wsObjectKey == L"GreenBlock")
		{
			pObj = Engine::ADD_CLONE(L"EventBlock", L"GreenBlock", true);
			pObj->GetComponent<Engine::CTransformComponent>()->SetPosition(it->vPos);
			pObj->GetComponent<Engine::CTransformComponent>()->SetRotation(it->vRot);
		}

		++it;
	}

	return S_OK;
}