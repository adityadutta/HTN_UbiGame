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
	uiEntity->SetText("");
	uiEntity->SetTextSize(18);
	uiEntity->SetColor(sf::Color::Green);
	uiEntity->AttachToEntity(this, ((float)(-GetSize().x) / 2), (float)(-GetSize().y*0.65));
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
		uiEntity->SetText("Hello Adventure! I am NPC.\nHello");
	}
}

void NPCEntity::HideDialogue()
{
	uiEntity->SetText("");
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
