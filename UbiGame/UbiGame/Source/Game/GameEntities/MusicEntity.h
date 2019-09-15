#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SoundComponent.h"

namespace Game
{

	class MusicEntity : public GameEngine::Entity
	{
	public:
		MusicEntity();
		~MusicEntity();

		virtual void OnAddToWorld() override;

	private:
		GameEngine::SoundComponent* soundComp;

		GameEngine::SoundManager::SoundId musicId;
	};

}
