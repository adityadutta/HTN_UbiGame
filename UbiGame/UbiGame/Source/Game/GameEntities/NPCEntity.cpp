#include "NPCEntity.h"
#include "GameEngine/GameEngineMain.h"

using namespace Game;

NPCEntity::NPCEntity(): uiActive(false), uiEntity(nullptr)
{
	
}


NPCEntity::~NPCEntity()
{
}

void NPCEntity::OnAddToWorld()
{
	__super::OnAddToWorld();

	uiEntity = new UIEntity();
	uiEntity->SetText("Hello Adventure! I am NPC.\nHello");
	uiEntity->SetTextSize(18);
	uiEntity->SetColor(sf::Color::Green);
}

void NPCEntity::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}

void NPCEntity::DisplayDialogue()
{
	if(!uiActive)
	{
		uiActive = true;
		uiEntity->AttachToEntity(this, -5.0f, -50.0f);
	}
}

void NPCEntity::HideDialogue()
{
	GameEngine::GameEngineMain::GetInstance()->RemoveEntity(uiEntity);
	uiActive = false;
}

void NPCEntity::SetDialogue(std::string dialogue_)
{
	uiEntity->SetText(dialogue_);
}

void NPCEntity::OnInteract()
{
	HideDialogue();
}
