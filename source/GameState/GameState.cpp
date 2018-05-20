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
 /*IT WILL BE REFACTOR*/
  /*const in future*/
  std::shared_ptr<mv::Entity> objects[11];

  for ( int i = 0; i < 11; i++ )
  {
    objects[i] = std::make_shared<mv::Entity>();
    objects[i]->addComponent<ProperBody>();
    objects[i]->getComponent<ProperBody>()->setSize({ 100,100 });
    if ( i < 9 )
    {
      objects[i]->getComponent<ProperBody>()->setType(textureCache, mv::constants::texture::TEXTURE_ID::CRYSTAL_RED, scene->getRenderer());
      objects[i]->getComponent<ProperBody>()->setPosition({ 0.167f*mv::constants::defaults::WINDOW_DIMENSIONS.x*(2 * (i % 3) + 1),0.167f*mv::constants::defaults::WINDOW_DIMENSIONS.y*(2 * (i / 3) + 1) });
      this->entities.push_back(objects[i]);
    }   
  }

  objects[9]->getComponent<ProperBody>()->setType(textureCache, mv::constants::texture::TEXTURE_ID::BUTTON_PLUS, scene->getRenderer());
  objects[9]->getComponent<ProperBody>()->setPosition({100.f,mv::constants::defaults::WINDOW_DIMENSIONS.y - 100.f });

  objects[10]->getComponent<ProperBody>()->setType(textureCache, mv::constants::texture::TEXTURE_ID::BUTTON_MINUS, scene->getRenderer());
  objects[10]->getComponent<ProperBody>()->setPosition({ mv::constants::defaults::WINDOW_DIMENSIONS.x - 100.f,mv::constants::defaults::WINDOW_DIMENSIONS.y - 100.f });
  entities.push_back(objects[9]);
  entities.push_back(objects[10]);

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
