#pragma once

#include "Game/GameEntities/SuspectEntity.h"


namespace Game
{
	class Plaugedoctor : public SuspectEntity
	{
	public:
		Plaugedoctor();
		~Plaugedoctor();

		void OnAddToWorld();
		void OnRemoveFromWorld();
		void OnInteract();
		void OnThreaten();
		void OnArrest();
	};
}