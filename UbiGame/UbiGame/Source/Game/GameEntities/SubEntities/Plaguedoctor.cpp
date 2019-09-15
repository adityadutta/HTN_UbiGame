#include "Plaguedoctor.h"

#include "GameEngine/Util/AnimationManager.h"

using namespace Game;


Plaguedoctor::Plaguedoctor()
{
	//Render 
	m_renderComponent = static_cast<GameEngine::SpriteRenderComponent*>(AddComponent<GameEngine::SpriteRenderComponent>());
	m_renderComponent->SetTexture(GameEngine::eTexture::PlagueDoctor);
	m_renderComponent->SetZLevel(2);

	//Collision
	collider = static_cast<GameEngine::CollidableComponent*>(AddComponent<GameEngine::CollidableComponent>());
	collider->SetTag("NPC");
}

Plaguedoctor::~Plaguedoctor()
{
}

void Plaguedoctor::OnAddToWorld()
{
	__super::OnAddToWorld();

	if (uiEntity)
	{
		uiEntity->SetText("Hello! I am the Plague Doctor.");
		uiEntity->SetTextSize(18);
		uiEntity->SetColor(sf::Color::Red);
	}

	if (m_animComponent)
	{
		//m_animComponent->PlayAnim(GameEngine::EAnimationId::BirdIdle);
	}
}

void Plaguedoctor::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}

void Plaguedoctor::OnInteract()
{
	if (uiEntity)
	{
		uiEntity->SetText("");
	}
}

void Plaguedoctor::OnThreaten()
{
	if (uiEntity)
	{
		uiEntity->SetText("");
	}
}

void Plaguedoctor::OnArrest()
{
	if (uiEntity)
	{
		uiEntity->SetText("");
	}
}
