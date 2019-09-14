#pragma once
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "Game/GameEntities/PlayerEntity.h"

namespace Game
{

	class PlayerCollisionComponent : public GameEngine::CollidablePhysicsComponent
	{
	public:
		PlayerCollisionComponent();
		~PlayerCollisionComponent();

		virtual void OnAddToWorld() override;

		virtual void CheckCollisionTag(std::string tagToCompare_) override;

	private:
		Game::PlayerEntity* player;
	};

}
