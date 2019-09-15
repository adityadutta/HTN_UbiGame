#include "AnimatedObjectEntity.h"

#include "GameEngine/Util/AnimationManager.h"


using namespace Game;

AnimatedObjectEntity::AnimatedObjectEntity()
{
	//Render 
	m_renderComponent = static_cast<GameEngine::SpriteRenderComponent*>(AddComponent<GameEngine::SpriteRenderComponent>());
	m_renderComponent->SetTexture(GameEngine::eTexture::Cow);
	m_renderComponent->SetZLevel(0);

	//Animation
	m_animComponent = static_cast<GameEngine::AnimationComponent*>(AddComponent<GameEngine::AnimationComponent>());
}


AnimatedObjectEntity::~AnimatedObjectEntity()
{

}


void AnimatedObjectEntity::OnAddToWorld()
{
	__super::OnAddToWorld();

	if (m_animComponent)
	{
		m_animComponent->PlayAnim(GameEngine::EAnimationId::CowAnim);
	}
}


void AnimatedObjectEntity::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}

