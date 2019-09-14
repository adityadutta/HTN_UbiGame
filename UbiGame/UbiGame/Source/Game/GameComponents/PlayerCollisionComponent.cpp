#include "PlayerCollisionComponent.h"
#include "GameEngine/GameEngineMain.h"



Game::PlayerCollisionComponent::PlayerCollisionComponent(): player(nullptr)
{
}


Game::PlayerCollisionComponent::~PlayerCollisionComponent()
{
}

void Game::PlayerCollisionComponent::OnAddToWorld()
{
	__super::OnAddToWorld();

	player = dynamic_cast<Game::PlayerEntity*>(GetEntity());
}

void Game::PlayerCollisionComponent::CheckCollisionTag(CollidableComponent* collidedComponent)
{
	__super::CheckCollisionTag(collidedComponent);

	if(collidedComponent->GetTag() == "Ground")
	{
		player->GetComponent<Game::PlayerMovementComponent>()->SetGrounded(true);
	}
	if(collidedComponent->GetTag() == "NPC")
	{
		//TODO: NPC interact logic
	}
}
