#include "Blacksmith.h"

#include "GameEngine/Util/AnimationManager.h"

Blacksmith::Blacksmith()
{
}

Blacksmith::~Blacksmith()
{
}

void Blacksmith::OnAddToWorld()
{
	__super::OnAddToWorld();

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
