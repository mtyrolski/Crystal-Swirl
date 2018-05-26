/*
mvxxx 2018
https://github.com/mvxxx
*/

#include "GameState.hpp"

GameState::GameState(const std::shared_ptr<Scene>& scenePtr)
  :scene(scenePtr)
{
  loader = std::make_shared<Loader>();
  scene->create(loader);
  graphicManager = std::make_shared<GraphicManager>();
  audioManager = std::make_shared<AudioManager>(loader);
  banditMachine = std::make_shared<OneArmedBandit>(loader, scenePtr, graphicManager);

  textMachine = std::make_shared<TextMachine>
    ( std::atoi(loader->getPathOf("CREDITS",mv::constants::loader::CONFIG_MODE::TECHNICALITIES).c_str()),
      std::atoi(loader->getPathOf("RATE", mv::constants::loader::CONFIG_MODE::TECHNICALITIES).c_str()),
    scenePtr->getRenderer(),
    loader);

  this->onStart();
}

void GameState::onStart()
{
  graphicManager->loadTextures(scene->getRenderer(),loader);
  audioManager->play(mv::constants::audio::AUDIO_ID::SOUNDTRACK);
  initUI();
}

void GameState::run()
{
  scene->pollEvents();
  actionForwarder.manage(scene, banditMachine, entities,textMachine,loader,audioManager,scene->getRenderer());
  scene->clear(entities);
  textMachine->display(scene->getRenderer());
}

void GameState::initUI()
{
  UILoader uiLoader;
  uiLoader.LoadUI(entities, loader, graphicManager, scene,banditMachine);
  int t = 5;
}
