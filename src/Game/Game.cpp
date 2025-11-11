#include "Game/Game.h"

#include <iostream>
#include <string>

#include "Screen/Screen.h"
#include "Game/Entities/Obstacle/Obstacle.h"
#include "Game/Entities/Collectible/AddLife/AddLife.h"
#include "Game/Entities/Collectible/AddScore/AddScore.h"
#include "Game/Entities/Collectible/MultiplyScore/MultiplyScore.h"
#include "Game/Entities/Collectible/AddStep/AddStep.h"

namespace game
{
	const int maxCollectibles = 15;
	const int maxObstacles = 20;

	const std::string gameTitle = "Game";
	const Color backgroundColor = BLACK;

	const Color playerColor = WHITE;

	void Game::update()
	{
		player->move();

		for (int i = 0; i < entities.size(); i++)
		{
			if (player->isCol(entities[i]))
			{
				player->onColEntity(entities[i]);

				entity::Entity* playerPointer = dynamic_cast<entity::Entity*>(player);

				entities[i]->onColEntity(playerPointer);
			}
		}

		for (int i = 0; i < collectibles.size(); i++)
		{
			if (!collectibles[i]->getIsOn())
			{
				do
				{
					collectibles[i]->reset(getRandomPos());

				} while (!isValidPlacement(collectibles[i]));
			}
		}

		if (!player->getIsAlive() || player->getMovesLeft() <= 0)
		{
			gameLost = true;
		}
	}

	void Game::draw()
	{
		BeginDrawing();
		ClearBackground(backgroundColor);

		player->draw();

		for (int i = 0; i < entities.size(); i++)
		{
			entities[i]->draw();
		}

		drawHUD();

		EndDrawing();
	}

	void Game::drawHUD()
	{
		std::string livesText = "Lives ";
		livesText = livesText + std::to_string(player->getLives()) + " / " + std::to_string(player->getMaxLives());

		std::string movesLeftText = "Moves left ";
		movesLeftText = movesLeftText + std::to_string(player->getMovesLeft());

		std::string scoreText = "Score ";
		scoreText = scoreText + std::to_string(player->getScore());

		DrawText(livesText.c_str(), 25, 25, 10, WHITE);
		DrawText(movesLeftText.c_str(), screen::width - 100, 25, 10, WHITE);
		DrawText(scoreText.c_str(), screen::width / 2, 25, 10, WHITE);
	}

	bool Game::isValidPlacement(entity::Entity* ent)
	{
		for (int i = 0; i < entities.size(); i++)
		{
			if (ent->isCol(entities[i]) && ent != entities[i])
			{
				return false;
			}
		}

		if (ent->isCol(player))
		{
			return false;
		}

		return true;
	}

	Vector2 Game::getRandomPos()
	{
		return { static_cast<float>(GetRandomValue(0, screen::width - 15)), static_cast<float>(GetRandomValue(0, screen::height - 15)) };
	}

	void Game::result()
	{
		if (IsKeyPressed(KEY_ENTER))
		{
			isGameRunning = false;
		}

		BeginDrawing();
		ClearBackground(backgroundColor);

		DrawText("GAME OVER", 150, 100, 30, WHITE);

		std::string livesText = "Lives: " + std::to_string(player->getLives()) + " / " + std::to_string(player->getMaxLives());
		DrawText(livesText.c_str(), 200, 175, 10, WHITE);

		std::string scoreText = "Score: " + std::to_string(player->getScore());
		DrawText(scoreText.c_str(), 200, 200, 10, WHITE);

		std::string moveLeftText = "MovesLeft: " + std::to_string(player->getMovesLeft());
		DrawText(moveLeftText.c_str(), 200, 225, 10, WHITE);

		std::string collectedCollectiblesText = "Collected Collectibles: " + std::to_string(player->getCollectedCollectibles());
		DrawText(collectedCollectiblesText.c_str(), 200, 250, 10, WHITE);

		DrawText("Press ENTER to exit", 300, 300, 10, WHITE);

		EndDrawing();
	}

	Game::Game()
	{
		SetRandomSeed(unsigned int(time(0)));

		isGameRunning = true;
		gameLost = false;

		player = new player::Player({ 240,195 }, playerColor);

		//Init collectibles
		for (int i = 0; i < maxCollectibles; i++)
		{
			entity::Entity* randomNewCollectible;

			bool isValidCollectible = true;

			do
			{
				isValidCollectible = true;

				Vector2 randomPos = getRandomPos();

				switch (GetRandomValue(1, collectible::maxCollectibleTypes))
				{
				case 1:
					randomNewCollectible = new addScore::AddScore(randomPos);
					break;

				case 2:
					randomNewCollectible = new multiplyScore::MultiplyScore(randomPos);
					break;

				case 3:
					randomNewCollectible = new addLife::AddLife(randomPos);
					break;

				case 4:
					randomNewCollectible = new addStep::AddStep(randomPos);
					break;

				default:
					randomNewCollectible = new addScore::AddScore(randomPos);
					break;

					break;
				}

				entity::Entity* toEntity = dynamic_cast<entity::Entity*>(randomNewCollectible);

				if (!isValidPlacement(toEntity))
				{
					isValidCollectible = false;
					delete randomNewCollectible;
				}

			} while (!isValidCollectible);

			entities.push_back(randomNewCollectible);

			collectible::Collectible* toCollectible = dynamic_cast<collectible::Collectible*>(randomNewCollectible);

			collectibles.push_back(toCollectible);
		}

		Vector2 playerPos = player->getBody().pos;

		//Init obstacles
		for (int i = 0; i < maxObstacles; i++)
		{
			obstacle::Obstacle* newObstacle;
			Vector2 randomPos;

			bool isValidObstacle = true;

			do
			{
				isValidObstacle = true;

				randomPos = getRandomPos();
				newObstacle = new obstacle::Obstacle(randomPos);

				if (!isValidPlacement(newObstacle))
				{
					isValidObstacle = false;
					delete newObstacle;
				}

			} while (!isValidObstacle);

			entities.push_back(newObstacle);
		}
	}

	Game::~Game()
	{
		for (int i = 0; i < entities.size(); i++)
		{
			delete entities[i];
			entities[i] = nullptr;
		}
	}

	void Game::run()
	{
		InitWindow(screen::width, screen::height, gameTitle.c_str());

		while (!WindowShouldClose() && isGameRunning)
		{
			if (!gameLost)
			{
				update();
				draw();
			}
			else
			{
				result();
			}
		}

		result();

		CloseWindow();
	}
}