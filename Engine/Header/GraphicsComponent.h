#ifndef GRAPHICSCOMPONENT_H
#define GRAPHICSCOMPONENT_H

BEGIN(Engine)
class CTransformComponent;
class CMeshComponent;
class CTextureComponent;
class ENGINE_DLL CGraphicsComponent final : public CSubComponent
{
public:
	explicit	CGraphicsComponent	(void);
			   ~CGraphicsComponent	(void);
public:
					SHARED(CComponent)	MakeClone		(CGameObject* pObject)	override;

					void				Awake			(void) override;
					void				Start			(SHARED(CComponent) spThis) override;

					_uint				FixedUpdate		(SHARED(CComponent) spThis) override;
					_uint				Update			(SHARED(CComponent) spThis) override;
					_uint				LateUpdate		(SHARED(CComponent) spThis) override;
					
					_uint				PreRender		(void);
					_uint				Render			(void);
					_uint				PostRender		(void);	

					void				OnDestroy		(void) override;

					void				OnDisable		(void) override;
					void				OnEnable		(void) override;

public:
	static const	EComponentID	m_s_componentID = EComponentID::Graphics;

protected:

	GETTOR			(SHARED(CMeshComponent),		m_pMesh,		nullptr,			Mesh)
	GETTOR			(SHARED(CTextureComponent),		m_pTexture,		nullptr,			Texture)
	GETTOR			(SHARED(CTransformComponent),	m_pTransform,	nullptr,			Transform)
	GETTOR_SETTOR	(ERenderID,						m_renderID,		ERenderID::Base,	RenderID)

	
};
END
#endif // !GRAPHICSCOMPONENT_H
