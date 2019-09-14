#pragma once

#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/TextComponent.h"

namespace  Game
{
	class UIEntity : public GameEngine::Entity
	{
	public:
		UIEntity();
		~UIEntity();

		//virtual void OnAddToWorld() override;
		//virtual void OnRemoveFromWorld() override;

	protected:
		GameEngine::TextComponent* testText;
	};
}
