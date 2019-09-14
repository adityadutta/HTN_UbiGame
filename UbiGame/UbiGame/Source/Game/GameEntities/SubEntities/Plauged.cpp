#include "Plauged.h"

#include "GameEngine/Util/AnimationManager.h"

using namespace Game;

Plauged::Plauged()
{
}

Plauged::~Plauged()
{
}

void Plauged::OnAddToWorld()
{
	__super::OnAddToWorld();

	if (m_animComponent)
	{
		//m_animComponent->PlayAnim(GameEngine::EAnimationId::BirdIdle);
	}
}

void Plauged::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}

void Plauged::OnInteract()
{

}
