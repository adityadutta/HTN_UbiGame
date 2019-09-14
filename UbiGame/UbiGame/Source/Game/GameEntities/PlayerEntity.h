#pragma once
#include "GameEngine\EntitySystem\Entity.h"
#include "GameEngine\EntitySystem\Components\AnimationComponent.h"
#include "GameEngine\EntitySystem\Components\SpriteRenderComponent.h"
#include "Game\GameComponents\PlayerMovementComponent.h"
#include "GameEngine/EntitySystem/Components/TextComponent.h"
#include "UIEntity.h"
#include "Game/GameComponents/PawnPhysicsComponent.h"
#include "NPCEntity.h"

namespace Game
{			

	class PlayerEntity : public GameEngine::Entity
	{
	public:
		PlayerEntity();
		~PlayerEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

		NPCEntity* lastNPCRef;

	protected:
		GameEngine::SpriteRenderComponent* m_renderComponent;		
		PlayerMovementComponent*	 m_playerMovementComponent;
		GameEngine::AnimationComponent* m_animComponent;
		PawnPhysicsComponent* pawnPhysicsComponent;

		//UI
		UIEntity* ui;
	};
}

