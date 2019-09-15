#pragma once
#include "GameEngine\EntitySystem\Entity.h"
#include "GameEngine\EntitySystem\Components\AnimationComponent.h"
#include "GameEngine\EntitySystem\Components\SpriteRenderComponent.h"


namespace Game
{

	class AnimatedObjectEntity : public GameEngine::Entity
	{
	public:
		AnimatedObjectEntity();
		~AnimatedObjectEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

	protected:
		GameEngine::SpriteRenderComponent* m_renderComponent;
		GameEngine::AnimationComponent* m_animComponent;

	};
}

