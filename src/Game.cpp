#include "Game.h"

#include <iostream>

#include "string"

namespace game
{
	const int screenWidth = 800;
	const int screenHeight = 400;
	const std::string gameTitle = "Game";
	const Color backgroundColor = BLACK;

	Game::Game()
	{
		form::Rectangle body = form::Rectangle({0,0}, 10, 15);

		entities[0] = new entity::Entity(body);
		entities[1] = new entity::Entity(body);
	}
	void Game::run()
	{
		InitWindow(screenWidth, screenHeight, gameTitle.c_str());

		while (!WindowShouldClose())
		{
			std::cout << entities[0]->body.isColRect(entities[1]->body);
		}

		CloseWindow();
	}

	void Game::update()
	{

	}

	void Game::draw()
	{
		BeginDrawing();
		ClearBackground(backgroundColor);

		EndDrawing();
	}
}