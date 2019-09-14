#include "Game/GameEntities/SuspectEntity.h"

class Blacksmith : public SuspectEntity
{
public:
	Blacksmith();
	~Blacksmith();

	void OnAddToWorld();
	void OnRemoveFromWorld();
	void OnInteract();
	void OnThreaten();
	void OnArrest();

};
