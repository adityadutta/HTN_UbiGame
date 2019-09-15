#pragma once
#include "NPCEntity.h"

class Collectible : public Game::NPCEntity
{
public:
	Collectible();
	~Collectible();

	virtual void OnInteract() override;

	void SetName(std::string name_);
	std::string GetName();

private:
	std::string name;
};

