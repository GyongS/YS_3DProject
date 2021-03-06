#include "EngineStdafx.h"
#include "ShaderManager.h"
#include "TextureShader.h"
#include "Shader.h"

USING(Engine)
IMPLEMENT_SINGLETON(CShaderManager)
void CShaderManager::Awake()
{
	__super::Awake();
}


void CShaderManager::Start()
{	
	AddShader(CTextureShader::Create());
}

void CShaderManager::OnDestroy()
{
	for (auto& shader : m_mShaders)
		delete shader.second;

	m_mShaders.clear();	
}

void CShaderManager::OnEnable()
{
}

void CShaderManager::OnDisable()
{
}

HRESULT CShaderManager::AddShader(CShader* pShader)
{
	if (m_mShaders.find(pShader->GetObjectKey()) == m_mShaders.end())
		m_mShaders[pShader->GetObjectKey()] = pShader;
	else
		MSG_BOX(__FILE__, L"Shader already exist in AddShader");

	return S_OK;
}

CShader* CShaderManager::GetShader(std::wstring shaderKey)
{	
	return m_mShaders[shaderKey];
}


//LPD3DXMESH CShaderManager::LoadModel(const char* filename)
//{
//	LPD3DXMESH ret = NULL;
//	if (FAILED(D3DXLoadMeshFromX(StrToWStr(filename).c_str(), D3DXMESH_SYSTEMMEM, CGraphicsManager::GetInstance()->GetDevice(), NULL, NULL, NULL, NULL, &ret)))
//	{
//		OutputDebugString(L"모델 로딩 실패: ");
//		OutputDebugString(StrToWStr(filename).c_str());
//		OutputDebugString(L"\n");
//	};
//
//	return ret;
//}

