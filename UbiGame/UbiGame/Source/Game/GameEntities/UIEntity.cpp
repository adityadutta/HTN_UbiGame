#include "UIEntity.h"



Game::UIEntity::UIEntity()
{
	//TODO: Testing text comp
	testText = static_cast<GameEngine::TextComponent*>(AddComponent<GameEngine::TextComponent>());
	testText->SetFont("arial.ttf");
	testText->SetText("Hello World", 32, sf::Color::Red);
}


Game::UIEntity::~UIEntity()
{
	delete testText;
	testText = nullptr;
}
