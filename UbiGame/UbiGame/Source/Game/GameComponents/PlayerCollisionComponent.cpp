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

void Game::PlayerCollisionComponent::CheckCollisionTag(std::string tagToCompare_)
{
	__super::CheckCollisionTag(tagToCompare_);

	if(tagToCompare_ == "Ground")
	{
		player->GetComponent<Game::PlayerMovementComponent>()->SetGrounded(true);
	}
	if(tagToCompare_ == "NPC")
	{
		//TODO: NPC interact logic
	}
}
