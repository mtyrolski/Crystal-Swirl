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
  /*
  0-8 - Crystals
  9 - PLUS
  10 - MINUS
  11 - RATE
  12 - PLAY
  13 - PRIZE
  14 - CREDITS
  */
  std::shared_ptr<mv::Entity> objects[15];

  for ( int i = 0; i < 15; i++ )
  {
    objects[i] = std::make_shared<mv::Entity>();
    objects[i]->addComponent<ProperBody>();
    if(i<11) objects[i]->getComponent<ProperBody>()->setSize({ 100,100 });
  }

  objects[0]->getComponent<ProperBody>()->setPosition({ 200,80 });
  objects[1]->getComponent<ProperBody>()->setPosition({ 390,80 });
  objects[2]->getComponent<ProperBody>()->setPosition({ 570,80 });
  objects[3]->getComponent<ProperBody>()->setPosition({ 200,230 });
  objects[4]->getComponent<ProperBody>()->setPosition({ 390,230 });
  objects[5]->getComponent<ProperBody>()->setPosition({ 570,230 });
  objects[6]->getComponent<ProperBody>()->setPosition({ 200,380 });
  objects[7]->getComponent<ProperBody>()->setPosition({ 390,380 });
  objects[8]->getComponent<ProperBody>()->setPosition({ 570,380 });

  objects[9]->getComponent<ProperBody>()->setType(textureCache, mv::constants::texture::TEXTURE_ID::BUTTON_PLUS, scene->getRenderer());
  objects[9]->getComponent<ProperBody>()->setPosition({ 260,500 });

  objects[10]->getComponent<ProperBody>()->setType(textureCache, mv::constants::texture::TEXTURE_ID::BUTTON_MINUS, scene->getRenderer());
  objects[10]->getComponent<ProperBody>()->setPosition({ 40,500 });
 
  objects[11]->getComponent<ProperBody>()->setType(textureCache, mv::constants::texture::TEXTURE_ID::RATE, scene->getRenderer());
  objects[11]->getComponent<ProperBody>()->setSize({ 170,100 });
  objects[11]->getComponent<ProperBody>()->setPosition({150,500 });

  objects[12]->getComponent<ProperBody>()->setType(textureCache, mv::constants::texture::TEXTURE_ID::PLAY, scene->getRenderer());
  objects[12]->getComponent<ProperBody>()->setSize({ 170,100 });
  objects[12]->getComponent<ProperBody>()->setPosition({ 400,500 });

  objects[13]->getComponent<ProperBody>()->setType(textureCache, mv::constants::texture::TEXTURE_ID::PRIZE, scene->getRenderer());
  objects[13]->getComponent<ProperBody>()->setSize({ 250,60 });
  objects[13]->getComponent<ProperBody>()->setPosition({670,470});

  objects[14]->getComponent<ProperBody>()->setType(textureCache, mv::constants::texture::TEXTURE_ID::CREDITS, scene->getRenderer());
  objects[14]->getComponent<ProperBody>()->setSize({ 250,60 });
  objects[14]->getComponent<ProperBody>()->setPosition({670,520});

  for ( int i = 0; i < 15; i++ )
  {
    if(i<9) objects[i]->getComponent<ProperBody>()->setType(textureCache, mv::constants::texture::TEXTURE_ID(Math::random(3, 5)), scene->getRenderer());
    entities.push_back(objects[i]);
  }
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
