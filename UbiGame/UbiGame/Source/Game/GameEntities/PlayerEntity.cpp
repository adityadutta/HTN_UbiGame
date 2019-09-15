#include "PlayerEntity.h"

#include "Game/GameComponents/PlayerSoundComponent.h"
#include "Game/GameComponents/PlayerCameraComponent.h"

#include "Game/GameComponents/PlayerCollisionComponent.h"
#include "GameEngine/EntitySystem/Components/ParticleEmitterComponent.h"
#include "GameEngine/EntitySystem/Components/SoundComponent.h"
#include "GameEngine/Util/AnimationManager.h"
#include "GameEngine/Util/CollisionManager.h"
#include "SuspectEntity.h"
#include <iostream>

using namespace Game;

PlayerEntity::PlayerEntity() : lastNPCRef(nullptr), isInteractKeyPressed(false), isThreatKeyPressed(false), isArrestKeyPressed(false)
{
	//Movement
	m_playerMovementComponent = static_cast<PlayerMovementComponent*>(AddComponent<PlayerMovementComponent>());

	//Movement
	pawnPhysicsComponent = static_cast<PawnPhysicsComponent*>(AddComponent<PawnPhysicsComponent>());

	//Render 
	m_renderComponent = static_cast<GameEngine::SpriteRenderComponent*>(AddComponent<GameEngine::SpriteRenderComponent>());
	m_renderComponent->SetTexture(GameEngine::eTexture::Player);
	m_renderComponent->SetZLevel(2);

	//Animation
	m_animComponent = static_cast<GameEngine::AnimationComponent*>(AddComponent<GameEngine::AnimationComponent>());

	//Collisions
	AddComponent<PlayerCollisionComponent>();

	//Sound
	GameEngine::SoundComponent* const soundComponent = static_cast<GameEngine::SoundComponent*>(AddComponent<GameEngine::SoundComponent>());
	soundComponent->SetNumSimultaneousSounds(2); // Hard coded 5 simultaneous sounds for the player

	AddComponent<PlayerSoundComponent>();

	//Camera control
	AddComponent<PlayerCameraComponent>();

	ui = new UIEntity();
	ui->SetText("Hello Adventure! I am NPC.\nHello");
	ui->SetTextSize(18);
	ui->SetColor(sf::Color::Green);
}


PlayerEntity::~PlayerEntity()
{

}


void PlayerEntity::OnAddToWorld()
{
	__super::OnAddToWorld();

	if (m_animComponent)
	{
		m_animComponent->PlayAnim(GameEngine::EAnimationId::None);
	}

	ui->AttachToEntity(this, -5.0f, -50.0f);
}


void PlayerEntity::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}

void PlayerEntity::Update()
{
	__super::Update();

	//Gamepad logic
	if (sf::Joystick::isConnected(0))
	{
		if (sf::Joystick::isButtonPressed(0, 1))
		{
			isInteractKeyPressed = true;
		}
		else
		{
			if (lastNPCRef && isInteractKeyPressed)
			{

				isInteractKeyPressed = false;
				lastNPCRef->OnInteract();
				//std::cout << "OnInteract\n";
			}

		}

		if (sf::Joystick::isButtonPressed(0, 3))
		{
			isThreatKeyPressed = true;
		}
		else 
		{
			//Threaten
			if (isThreatKeyPressed)
			{
				isThreatKeyPressed = false;
				if (SuspectEntity* se = dynamic_cast<SuspectEntity*>(lastNPCRef))
				{
					se->OnThreaten();
					//std::cout << "Threaten\n";
				}
			}
		}
		//Arrest
		if (sf::Joystick::isButtonPressed(0, 2))
		{
			isArrestKeyPressed = true;
		}
		else
		{
			if (isArrestKeyPressed)
			{
				isArrestKeyPressed = false;
				if (SuspectEntity* se = dynamic_cast<SuspectEntity*>(lastNPCRef))
				{
					se->OnArrest();
					//std::cout << "Arrest\n";
				}
			}
		}

	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			if (lastNPCRef && !isInteractKeyPressed)
			{
				isInteractKeyPressed = true;
				lastNPCRef->OnInteract();
			}
			else
			{
				isInteractKeyPressed = false;
			}
		}
	}
}
