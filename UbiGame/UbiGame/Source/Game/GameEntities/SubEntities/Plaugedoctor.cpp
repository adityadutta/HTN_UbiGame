#include "Plaugedoctor.h"

#include "GameEngine/Util/AnimationManager.h"

Plaugedoctor::Plaugedoctor()
{
}

Plaugedoctor::~Plaugedoctor()
{
}

void Plaugedoctor::OnAddToWorld()
{
	__super::OnAddToWorld();

	if (m_animComponent)
	{
		//m_animComponent->PlayAnim(GameEngine::EAnimationId::BirdIdle);
	}
}

void Plaugedoctor::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}

void Plaugedoctor::OnInteract()
{

}

void Plaugedoctor::OnThreaten()
{

}

void Plaugedoctor::OnArrest()
{

}
