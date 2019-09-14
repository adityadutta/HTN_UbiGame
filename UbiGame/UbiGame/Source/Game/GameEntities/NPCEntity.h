#include <memory>

#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/AnimationComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

class NPCEntity : public GameEngine::Entity
{
public:
	NPCEntity();
	~NPCEntity();

	virtual void OnAddToWorld() = 0;                                                                                      
	virtual void OnRemoveFromWorld() = 0;
	virtual void OnInteract() = 0;

protected:
	std::unique_ptr<GameEngine::SpriteRenderComponent> m_renderComponent;
	std::unique_ptr<GameEngine::AnimationComponent> m_animComponent;
};

