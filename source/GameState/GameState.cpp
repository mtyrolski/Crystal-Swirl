/*
mvxxx 2018
https://github.com/mvxxx
*/

#include "GameState.hpp"

GameState::GameState(std::shared_ptr<Scene> scenePtr)
  :scene(scenePtr)
{
  textureCache = std::make_shared<mv::Cache<SDL_Texture>>();
  this->onStart();
}

void GameState::onStart()
{
  /*ADD ENTITIES*/
  auto entity = std::make_shared<mv::Entity>();
  entity->addComponent<ProperBody>();
  entity->getComponent<ProperBody>()->setType(textureCache,mv::constants::texture::TEXTURE_ID::BUTTON_PLUS,scene->getRenderer());
  this->entities.emplace_back(entity);
}

void GameState::onStop()
{
  /*soon*/
}

void GameState::run()
{
  scene->pollEvents();
  scene->clear(entities);
}
