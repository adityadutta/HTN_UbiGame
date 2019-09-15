#include "Shopkeeper.h"

#include "GameEngine/Util/AnimationManager.h"

using namespace Game;


Shopkeeper::Shopkeeper()
{
	//Render 
	m_renderComponent = static_cast<GameEngine::SpriteRenderComponent*>(AddComponent<GameEngine::SpriteRenderComponent>());
	m_renderComponent->SetTexture(GameEngine::eTexture::Shopkeeper);
	m_renderComponent->SetZLevel(2);

	//Collision
	collider = static_cast<GameEngine::CollidableComponent*>(AddComponent<GameEngine::CollidableComponent>());
	collider->SetTag("NPC");
}

Shopkeeper::~Shopkeeper()
{
}

void Shopkeeper::OnAddToWorld()
{
	__super::OnAddToWorld();

	if (uiEntity)
	{
		uiEntity->SetText("Hello! I am the Shopkeeper.");
		uiEntity->SetTextSize(18);
		uiEntity->SetColor(sf::Color::Yellow);
	}

	if (m_animComponent)
	{
		//m_animComponent->PlayAnim(GameEngine::EAnimationId::BirdIdle);
	}
}

void Shopkeeper::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}

void Shopkeeper::OnInteract()
{

}

void Shopkeeper::OnThreaten()
{

}

void Shopkeeper::OnArrest()
{

}
