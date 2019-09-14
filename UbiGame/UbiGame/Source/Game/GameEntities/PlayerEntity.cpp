#include "PlayerEntity.h"

#include "Game/GameComponents/PlayerSoundComponent.h"
#include "Game/GameComponents/PlayerCameraComponent.h"

#include "Game/GameComponents/PlayerCollisionComponent.h"
#include "GameEngine/EntitySystem/Components/ParticleEmitterComponent.h"
#include "GameEngine/EntitySystem/Components/SoundComponent.h"
#include "GameEngine/Util/AnimationManager.h"

using namespace Game;

PlayerEntity::PlayerEntity(): lastNPCRef(nullptr)
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
	
	//Particles
	GameEngine::ParticleEmitterComponent* emitterComponent = static_cast<GameEngine::ParticleEmitterComponent*>(AddComponent<GameEngine::ParticleEmitterComponent>());
	GameEngine::SParticleDefinition particleDef = GameEngine::SParticleDefinition(GameEngine::eTexture::Particles, 1, sf::Vector2f(32.f, 32.f), GameEngine::EAnimationId::Smoke, 1.f);
	emitterComponent->SetParticleDefinition(particleDef);


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
		m_animComponent->PlayAnim(GameEngine::EAnimationId::BirdIdle);
	}

	ui->AttachToEntity(this, -5.0f, -50.0f);
}


void PlayerEntity::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}
