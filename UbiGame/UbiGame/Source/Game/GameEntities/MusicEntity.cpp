#include "MusicEntity.h"

using namespace Game;

MusicEntity::MusicEntity()
{
	soundComp = static_cast<GameEngine::SoundComponent*>(AddComponent<GameEngine::SoundComponent>());
	soundComp->SetNumSimultaneousSounds(1);
	
	musicId = soundComp->LoadSoundFromFile("Resources/snd/music.wav");
}


MusicEntity::~MusicEntity()
{
}

void MusicEntity::OnAddToWorld()
{
	soundComp->PlaySound(musicId);
}
