#include "Game/GameEntities/SuspectEntity.h"

class Towncrier : public SuspectEntity
{
public:
	Towncrier();
	~Towncrier();

	void OnAddToWorld();
	void OnRemoveFromWorld();
	void OnInteract();
	void OnThreaten();
	void OnArrest();

};
