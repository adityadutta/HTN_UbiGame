#pragma once
#include "GameEngine\EntitySystem\Entity.h"

#include <SFML/System/Vector2.hpp>
#include <vector>
#include "GameEntities/GroundEntity.h"
#include "GameEntities/AnimatedObjectEntity.h"
#include "GameEntities/NPCEntity.h"

namespace Game
{
	//Used for storing and controling all game related entities
	class PlayerEntity;	

	class GameBoard
	{
	public:
		GameBoard();
		virtual ~GameBoard();

		//Temp - for nice architecture this should be within some sort of IUpdatable interface that GameEngine handles (so that not only entities can be updated)
		void Update();
		void UpdateObstacles(float dt);
		void UpdatePlayerDying();
		void SpawnNewRandomObstacles();
		void SpawnNewRandomTiledObstacles();
		void SpawnNewObstacle(const sf::Vector2f& pos, const sf::Vector2f& size);

		void SpawnRandomObjects();

		bool IsGameOver() const { return m_isGameOver; }		

	protected:
		//Placeholder temp - should go to helpers or smth.
		float RandomFloatRange(float a, float b)
		{
			return ((b - a) * ((float)rand() / RAND_MAX)) + a;
		}

		void CreateBackGround();
		void UpdateBackGround();

		void CreateGround();
		//void UpdateGround();

		PlayerEntity* m_player;
		//GroundEntity* m_ground_1;
		//GroundEntity* m_ground_2;
		GameEngine::Entity* m_backGround;

		std::vector<GameEngine::Entity*> m_obstacles;
		float m_lastObstacleSpawnTimer;
		bool  m_isGameOver;

		AnimatedObjectEntity* cow;

		NPCEntity* blacksmith;
		NPCEntity* blacksmith2;

	};
}

