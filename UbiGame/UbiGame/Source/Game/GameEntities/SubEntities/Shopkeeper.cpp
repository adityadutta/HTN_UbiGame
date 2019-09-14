#include "Shopkeeper.h"

#include "GameEngine/Util/AnimationManager.h"

Shopkeeper::Shopkeeper()
{
}

Shopkeeper::~Shopkeeper()
{
}

void Shopkeeper::OnAddToWorld()
{
	__super::OnAddToWorld();

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
