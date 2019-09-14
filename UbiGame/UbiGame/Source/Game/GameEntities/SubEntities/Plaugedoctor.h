#include "Game/GameEntities/SuspectEntity.h"

class Plaugedoctor : public SuspectEntity
{
public:
	Plaugedoctor();
	~Plaugedoctor();

	void OnAddToWorld();
	void OnRemoveFromWorld();
	void OnInteract();
	void OnThreaten();
	void OnArrest();
};
