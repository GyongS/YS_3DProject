#ifndef ENGINESTRUCTURE_H
#define ENGINESTRUCTURE_H


namespace Engine
{
	typedef struct _CustomVertex
	{
		_float3	position;
		_float3 normal;
		_float2	uv;
	}CUSTOM_VERTEX;
	const _uint customFVF = D3DFVF_XYZ | D3DFVF_TEX1 | D3DFVF_NORMAL;

	typedef struct _MeshData
	{
		LPDIRECT3DVERTEXBUFFER9 vertexBuffer;
		_uint vertexCount;
		_uint vertexSize;
		_uint faceCount; //== PolygonCount == triangleCount
		_uint FVF;
		_uint vertexNumInFace;

		LPDIRECT3DINDEXBUFFER9 indexBuffer;
		D3DFORMAT indexFormat;
		_uint indexSize;
	}MESH_DATA;

	typedef struct _TexData
	{
		LPDIRECT3DTEXTURE9 pTexture;
		D3DXIMAGE_INFO imageInfo;
	}TEXTURE_DATA;

	typedef struct _BOOL3
	{
		_BOOL3(bool x, bool y, bool z)
		{
			x = x;
			y = y;
			z = z;
		}

		bool x;
		bool y;
		bool z;
	}BOOL3;

	typedef struct _Face
	{
		_uint vertexIndex[3];
		_uint uvIndex[3];
		_uint normIndex[3];
	}FACE;

	typedef struct _Text
	{
		std::wstring	m_message;
		D3DXVECTOR3		m_position;
		D3DXCOLOR		m_color;
		bool			m_isVisible;
	}TEXT;

	typedef struct _tagUnitInfo
	{
		std::wstring wsObjectKey;
		_float3 vPos;
		_float3 vRot;
		_float3 vScale;
	}UNITINFO;
}
#endif // !ENGINESTRUCTURE_H

