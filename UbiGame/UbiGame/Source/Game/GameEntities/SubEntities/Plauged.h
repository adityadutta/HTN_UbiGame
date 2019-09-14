#pragma once

#include "Game/GameEntities/NPCEntity.h"

namespace Game
{


	class Plauged : public NPCEntity
	{
	public:
		Plauged();
		~Plauged();

		void OnAddToWorld();
		void OnRemoveFromWorld();
		void OnInteract();

	};
}