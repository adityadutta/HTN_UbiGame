#include "Collectible.h"
#include "GameEngine/GameEngineMain.h"


Collectible::Collectible()
{
}


Collectible::~Collectible()
{
}

void Collectible::OnInteract()
{
	GameEngine::GameEngineMain::GetInstance()->RemoveEntity(this);
}

void Collectible::SetName(std::string name_)
{
	name = name_;
	dialogues[0] = name;
	SetDialogue(0);
}

std::string Collectible::GetName()
{
	return name;
}
