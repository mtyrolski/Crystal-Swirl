/*
mvxxx 2018
https://github.com/mvxxx
*/

#include "Game.hpp"


void Game::run()
{
  init();

  while ( scene->isOpen() )
  {
    gameState->run();
  }
}

void Game::init()
{
  scene = std::make_shared<Scene>();
  gameState = std::make_shared<GameState>(scene);
}
