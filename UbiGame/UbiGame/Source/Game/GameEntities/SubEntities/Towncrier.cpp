#include "Towncrier.h"

#include "GameEngine/Util/AnimationManager.h"

Towncrier::Towncrier()
{
}

Towncrier::~Towncrier()
{
}

void Towncrier::OnAddToWorld()
{
	__super::OnAddToWorld();

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
