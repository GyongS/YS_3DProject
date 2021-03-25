#include "stdafx.h"
#include "DongilScene.h"
//#include "GameObject.h"
//#include "ObjectFactory.h"
//#include "SceneManager.h"
//#include "Layer.h"
//
//#include "ColliderManager.h"
//
//CDongilScene::CDongilScene()
//{
//}
//
//
//CDongilScene::~CDongilScene()
//{
//}
//
//SHARED(Engine::CScene) CDongilScene::Create(void)
//{
//	SHARED(CDongilScene) pCLogoScene(new CDongilScene, Engine::SmartDeleter<CDongilScene>);
//	return pCLogoScene;
//}
//
//void CDongilScene::Awake(void)
//{
//	__super::Awake();
//
//	InitLayers();
//	InitPrototypes();
//}
//
//void CDongilScene::Start(void)
//{
//	__super::Start();
//
//	{
//		m_pMainCamera = Engine::ADD_CLONE(L"Camera", L"Camera", true)->GetComponent<Engine::CCameraComponent>();
//	}
//
//	{
//		SHARED(Engine::CGameObject) pObj = Engine::CObjectFactory::GetInstance()->AddClone(L"Player", L"Player", true);
//		pObj->GetComponent<Engine::CTransformComponent>()->SetPosition(_float3(4, 5, 3));
//	}
//
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			SHARED(Engine::CGameObject) pObj = Engine::CObjectFactory::GetInstance()->AddClone(L"NormalBlock", L"WhiteBlock", true);
//			pObj->GetComponent<Engine::CTransformComponent>()->SetPosition(_float3(1.f * i, 0, 1.f * j));
//		}
//	}
//
//	{
//		SHARED(Engine::CGameObject) pObj = Engine::CObjectFactory::GetInstance()->AddClone(L"Default", L"Default", true);
//		pObj->GetComponent<Engine::CTransformComponent>()->SetPosition(_float3(7, 0, 7));
//		pObj->AddComponent<Engine::CColliderComponent>()->AddCollider(Engine::CAabbCollider::Create(_float3(1, 2, 1), FLOAT3_ZERO));
//		pObj->GetComponent<Engine::CColliderComponent>()->SetColliderID(5);
//		pObj->AddComponent<CElevator>()->Init(4, 4, -10);
//	}
//
//	{
//		SHARED(Engine::CGameObject) pObj = Engine::CObjectFactory::GetInstance()->AddClone(L"Default", L"Default", true);
//		pObj->GetComponent<Engine::CTransformComponent>()->SetScale(_float3(10.0f, 10.0f, 1.0f));
//		pObj->GetComponent<Engine::CTransformComponent>()->SetPosition(_float3(0, 0, 1));
//		pObj->AddComponent<Engine::CUIComponent>()->SetTextureKey(L"MousePointUI");
//	}
//}
//
//_uint CDongilScene::FixedUpdate(void)
//{
//	__super::FixedUpdate();
//
//	return _uint();
//}
//
//_uint CDongilScene::Update(void)
//{
//	_uint event = 0;
//	if (event = __super::Update())
//		return event;
//
//	return event;
//
//}
//
//_uint CDongilScene::LateUpdate(void)
//{
//	_uint event = 0;
//	if (event = __super::LateUpdate())
//		return event;
//
//	return event;
//}
//
//void CDongilScene::OnDestroy(void)
//{
//	__super::OnDestroy();
//}
//
//void CDongilScene::OnEnable(void)
//{
//}
//
//void CDongilScene::OnDisable(void)
//{
//}
//
//void CDongilScene::InitLayers(void)
//{
//	AddLayer(L"Camera");
//	AddLayer(L"Player");
//	AddLayer(L"NormalBlock");
//	AddLayer(L"EventBlock");
//	AddLayer(L"Default");
//}
//
//void CDongilScene::InitPrototypes(void)
//{
//
//}