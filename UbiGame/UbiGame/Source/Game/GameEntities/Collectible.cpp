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
	SetDialogue(name);
}

std::string Collectible::GetName()
{
	return name;
}
