#pragma once

#include "Scene.h"
class CStage3Scene final : public Engine::CScene
{
	SMART_DELETER_REGISTER;
private:
	explicit								CStage3Scene(void);
										   ~CStage3Scene(void);

public:
	static			SHARED(Engine::CScene)	Create				(void);

					void					Awake				(void) override;
					void					Start				(void) override;
																   
					_uint					FixedUpdate			(void) override;
					_uint					Update				(void) override;
					_uint					LateUpdate			(void) override;	
					
					void					OnDestroy			(void) override;

					void					OnEnable			(void) override;	 
					void					OnDisable			(void) override;

private:
					void					InitLayers			(void) override;
					void					InitPrototypes		(void) override;

private:
	HRESULT SceneLoad();
	SHARED(Engine::CGameObject) m_pPlayer;
	SHARED(Engine::CGameObject) m_pElevator;
	_float  m_NextSceneDelay;
	_bool   m_InitRot;

};

