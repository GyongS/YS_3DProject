#ifndef ENGINEENUM_H
#define ENGINEENUM_H

namespace Engine
{
	enum class EDisplayMdoe
	{
		FullMode,
		WinMode
	};

	enum class ERenderID
	{
		Base,
		NonAlpha,
		Alpha,
		UI,
		WireFrame,
		Last,
		NumOfRenderID
	};

	enum class EColliderType
	{
		Point,
		Ray,
		Sphere,
		AABB,
		OBB,
		NumOfCT
	};

	enum class EComponentID
	{
		Transform,
		Graphics,
		Mesh,
		Texture,
		Physics,
		UI,
		RigidBody,
		Collider,
		Camera,
		NumOfEngineComponentID
	};

	enum CHANNELID
	{
		PLAYER,
		LAND_HUMAN,
		LAND,
		JUMP,
		DOOR,
		BOX,
		HAT,
		UI,
		BGM,
		MAXCHANNEL
	};
}
#endif // !ENGINEENUM_H
