#pragma once
#include "NPCEntity.h"

namespace Game
{
	class SuspectEntity : public NPCEntity
	{
	public:
		SuspectEntity();
		~SuspectEntity();

		virtual void OnThreaten() = 0;
		virtual void OnArrest() = 0;
		bool randomInteractCheck();

	protected:
		bool randomInteractChecked;
		int randomFirstCheckIndex;
	};
}
