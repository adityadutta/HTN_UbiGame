#include "Blacksmith.h"

#include "GameEngine/Util/AnimationManager.h"


using namespace Game;

Blacksmith::Blacksmith()
{
	//Render 
	m_renderComponent = static_cast<GameEngine::SpriteRenderComponent*>(AddComponent<GameEngine::SpriteRenderComponent>());
	m_renderComponent->SetTexture(GameEngine::eTexture::Blacksmith);
	m_renderComponent->SetZLevel(2);

	//Collision
	collider = static_cast<GameEngine::CollidableComponent*>(AddComponent<GameEngine::CollidableComponent>());
	collider->SetTag("NPC");
}

Blacksmith::~Blacksmith()
{
}

void Blacksmith::OnAddToWorld()
{
	__super::OnAddToWorld();

	if (uiEntity)
	{
		uiEntity->SetText("Hello! I am the Blacksmith.");
		uiEntity->SetTextSize(18);
		uiEntity->SetColor(sf::Color::Blue);
	}

	if (m_animComponent)
	{
		//m_animComponent->PlayAnim(GameEngine::EAnimationId::BirdIdle);
	}
}

void Blacksmith::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}

void Blacksmith::OnInteract()
{

}

void Blacksmith::OnThreaten()
{

}

void Blacksmith::OnArrest()
{

}
