#include "NPCEntity.h"

class SuspectEntity : public NPCEntity
{
public:
	SuspectEntity();
	~SuspectEntity();

	virtual void OnThreaten() = 0;
	virtual void OnArrest() = 0;
};

