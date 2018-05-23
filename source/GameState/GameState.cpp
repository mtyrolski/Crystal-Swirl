/*
mvxxx 2018
https://github.com/mvxxx
*/

#include "GameState.hpp"

GameState::GameState(const std::shared_ptr<Scene>& scenePtr)
  :scene(scenePtr)
{
  graphicManager = std::make_shared<GraphicManager>();

  banditMachine = std::make_shared<OneArmedBandit>
    (mv::constants::defaults::BANDIT_MACHINE_DELAY,
      mv::constants::defaults::BANDIT_MACHINE_SIMULATION_TIME,
      scenePtr,
      graphicManager);

  textMachine = std::make_shared<TextMachine>(mv::constants::defaults::CREDITS,
    mv::constants::defaults::RATE,
    scenePtr->getRenderer());

  this->onStart();
}

void GameState::onStart()
{
  graphicManager->loadTextures(scene->getRenderer());
  initUI();
  banditMachine->initStructure(entities);
}
void GameState::onStop()
{
  /*soon*/
}

void GameState::run()
{
  scene->pollEvents();
  actionForwarder.manage(scene, banditMachine, entities,textMachine,scene->getRenderer());
  scene->clear(entities);
  textMachine->display(scene->getRenderer());
}

void GameState::initUI() /*TOXIC AREA - MUST BE REFACTORED*/
{
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
  const auto entityAmmount = 16;
  const auto crystalAmmount = 10;
  std::shared_ptr<mv::Entity> objects[entityAmmount];

  for ( int i = 0; i < entityAmmount; i++ )
  {
    objects[i] = std::make_shared<mv::Entity>();
    objects[i]->addComponent<ProperBody>();
    if ( i < crystalAmmount + 2 /* it will be refactored soon */ ) objects[i]->getComponent<ProperBody>()->setSize({ 100,100 });
  }
  using namespace mv::constants::defaults;

  objects[0]->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID::BACKGROUND, scene->getRenderer());
  objects[0]->getComponent<ProperBody>()->setSize({ static_cast<float>(WINDOW_DIMENSIONS.x),static_cast<float>(WINDOW_DIMENSIONS.y) });
  objects[0]->getComponent<ProperBody>()->setPosition({ 0.5f*WINDOW_DIMENSIONS.x,0.5f*WINDOW_DIMENSIONS.y });


  objects[1]->getComponent<ProperBody>()->setPosition({ 0.37f*WINDOW_DIMENSIONS.x,0.133f*WINDOW_DIMENSIONS.y });
  objects[2]->getComponent<ProperBody>()->setPosition({ 0.5175f*WINDOW_DIMENSIONS.x,0.133f*WINDOW_DIMENSIONS.y });
  objects[3]->getComponent<ProperBody>()->setPosition({ 0.6525f*WINDOW_DIMENSIONS.x,0.133f*WINDOW_DIMENSIONS.y });
  objects[4]->getComponent<ProperBody>()->setPosition({ 0.37f*WINDOW_DIMENSIONS.x,0.383f*WINDOW_DIMENSIONS.y });
  objects[5]->getComponent<ProperBody>()->setPosition({ 0.5175f*WINDOW_DIMENSIONS.x,0.383f*WINDOW_DIMENSIONS.y });
  objects[6]->getComponent<ProperBody>()->setPosition({ 0.6525f*WINDOW_DIMENSIONS.x,0.383f*WINDOW_DIMENSIONS.y });
  objects[7]->getComponent<ProperBody>()->setPosition({ 0.37f*WINDOW_DIMENSIONS.x,0.633f*WINDOW_DIMENSIONS.y });
  objects[8]->getComponent<ProperBody>()->setPosition({ 0.5175f*WINDOW_DIMENSIONS.x,0.633f*WINDOW_DIMENSIONS.y });
  objects[9]->getComponent<ProperBody>()->setPosition({ 0.6525f*WINDOW_DIMENSIONS.x,0.633f*WINDOW_DIMENSIONS.y });

  objects[10]->addComponent<Clickable>();
  objects[10]->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID::BUTTON_PLUS, scene->getRenderer());
  objects[10]->getComponent<ProperBody>()->setPosition({ 0.325f*WINDOW_DIMENSIONS.x,0.833f*WINDOW_DIMENSIONS.y });

  objects[11]->addComponent<Clickable>();
  objects[11]->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID::BUTTON_MINUS, scene->getRenderer());
  objects[11]->getComponent<ProperBody>()->setPosition({ 0.05f*WINDOW_DIMENSIONS.x,0.833f*WINDOW_DIMENSIONS.y });

  objects[12]->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID::RATE, scene->getRenderer());
  objects[12]->getComponent<ProperBody>()->setSize({ 170,100 });
  objects[12]->getComponent<ProperBody>()->setPosition({ 0.1875f*WINDOW_DIMENSIONS.x,0.833f*WINDOW_DIMENSIONS.y });

  objects[13]->addComponent<Clickable>();
  objects[13]->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID::PLAY, scene->getRenderer());
  objects[13]->getComponent<ProperBody>()->setSize({ 170,100 });
  objects[13]->getComponent<ProperBody>()->setPosition({ 0.5f*WINDOW_DIMENSIONS.x,0.833f*WINDOW_DIMENSIONS.y });

  objects[14]->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID::PRIZE, scene->getRenderer());
  objects[14]->getComponent<ProperBody>()->setSize({ 250,60 });
  objects[14]->getComponent<ProperBody>()->setPosition({ 0.8375f*WINDOW_DIMENSIONS.x,0.783f*WINDOW_DIMENSIONS.y });

  objects[15]->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID::CREDITS, scene->getRenderer());
  objects[15]->getComponent<ProperBody>()->setSize({ 250,60 });
  objects[15]->getComponent<ProperBody>()->setPosition({ 0.8375f*WINDOW_DIMENSIONS.x,0.866f*WINDOW_DIMENSIONS.y });

  for ( int i = 0; i < entityAmmount; i++ )
  {
    if ( i > 0 && i <= 9 ) objects[i]->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID(Math::random(3, 5)), scene->getRenderer());
    entities.push_back(objects[i]);
  }
}
