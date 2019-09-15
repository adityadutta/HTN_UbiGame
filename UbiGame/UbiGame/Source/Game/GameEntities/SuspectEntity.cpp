#include "SuspectEntity.h"

using namespace Game;

std::vector<std::string> dialogueOptions = {
	std::string("Hello! I am the Suspect."),
	std::string("I wouldnt know anything. \n You should ask someone else."),
	std::string("The Plague Doctor has been up to suspicious activity recently.\n You should talk to them"),
	std::string("The Plague Doctor would have done it!\n Leave me Alone."),
	std::string("I cannot say!\n You would have to arrest me!"),
	std::string("You have no grounds to force me!"),
	std::string("I am innocent!"),
	std::string("I would have gotten away with it!")
};

SuspectEntity::SuspectEntity()
{
	dialogues = dialogueOptions;
}


SuspectEntity::~SuspectEntity()
{
}
