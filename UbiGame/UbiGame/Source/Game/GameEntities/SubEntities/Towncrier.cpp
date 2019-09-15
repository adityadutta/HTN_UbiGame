#include "Towncrier.h"

#include "GameEngine/Util/AnimationManager.h"

using namespace Game;


Towncrier::Towncrier()
{
	//Render 
	m_renderComponent = static_cast<GameEngine::SpriteRenderComponent*>(AddComponent<GameEngine::SpriteRenderComponent>());
	m_renderComponent->SetTexture(GameEngine::eTexture::Towncrier);
	m_renderComponent->SetZLevel(2);

	//Collision
	collider = static_cast<GameEngine::CollidableComponent*>(AddComponent<GameEngine::CollidableComponent>());
	collider->SetTag("NPC");
}

Towncrier::~Towncrier()
{
}

void Towncrier::OnAddToWorld()
{
	__super::OnAddToWorld();

	if (uiEntity)
	{
		uiEntity->SetText("Hello! I am the Town Crier.");
		uiEntity->SetTextSize(18);
		uiEntity->SetColor(sf::Color::Black);
	}

	if (m_animComponent)
	{
		//m_animComponent->PlayAnim(GameEngine::EAnimationId::BirdIdle);
	}
}

void Towncrier::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}

void Towncrier::OnInteract()
{

}

void Towncrier::OnThreaten()
{

}

void Towncrier::OnArrest()
{

}
