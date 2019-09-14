#include "PlayerCollisionComponent.h"
#include "GameEngine/GameEngineMain.h"
#include "Game/GameEntities/NPCEntity.h"
#include "GameEngine/Util/CollisionManager.h"


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
		//TODO: NPC dialogue logic
		if(player->lastNPCRef)
		{
			GameEngine::CollisionManager::GetInstance()->RegisterCollidable(static_cast<CollidableComponent*>(collidedComponent));
		}
		player->lastNPCRef = static_cast<NPCEntity*>(collidedComponent->GetEntity());
		player->lastNPCRef->DisplayDialogue();
		GameEngine::CollisionManager::GetInstance()->UnRegisterCollidable(static_cast<CollidableComponent*>(collidedComponent));
	}
}
