#include "Game/GameEntities/SuspectEntity.h"

class Shopkeeper : public SuspectEntity
{
public:
	Shopkeeper();
	~Shopkeeper();

	void OnAddToWorld();
	void OnRemoveFromWorld();
	void OnInteract();
	void OnThreaten();
	void OnArrest();
};
