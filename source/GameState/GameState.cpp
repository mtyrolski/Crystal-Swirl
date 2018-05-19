/*
mvxxx 2018
https://github.com/mvxxx
*/

#include "GameState.hpp"

GameState::GameState(std::shared_ptr<Scene> scenePtr)
  :scene(scenePtr)
{
  this->onStart();
}

void GameState::onStart()
{
  /*ADD ENTITIES*/
}

void GameState::onStop()
{
  /*soon*/
}

void GameState::run()
{
  scene->pollEvents();
  scene->clear();
}
