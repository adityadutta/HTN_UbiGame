#include "Game/GameEntities/NPCEntity.h"

class Plauged : public NPCEntity
{
public:
	Plauged();
	~Plauged();

	void OnAddToWorld();
	void OnRemoveFromWorld();
	void OnInteract();

};
