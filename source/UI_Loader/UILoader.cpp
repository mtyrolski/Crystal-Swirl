#include "UILoader.hpp"

void UILoader::LoadUI(std::vector<std::shared_ptr<mv::Entity>>& entities, const std::shared_ptr<Loader>& loader,
  const std::shared_ptr<GraphicManager>& graphicManager, const std::shared_ptr<Scene>& scene, const std::shared_ptr<OneArmedBandit>& banditMachine)
{
  Vector2<float> windowSize = { static_cast<float>(std::atof(loader->getPathOf("WINDOW_DIMENSIONS_X", mv::constants::loader::CONFIG_MODE::TECHNICALITIES).c_str())),
    static_cast<float>(std::atof(loader->getPathOf("WINDOW_DIMENSIONS_Y", mv::constants::loader::CONFIG_MODE::TECHNICALITIES).c_str())) };

  loadBackground(entities, windowSize, graphicManager, scene);
  loadTextBoxes(entities, windowSize, graphicManager, scene);
  loadButtons(entities, windowSize, graphicManager, scene);
  loadRolls(entities, loader, windowSize, graphicManager, scene, banditMachine);
}

void UILoader::loadButtons(std::vector<std::shared_ptr<mv::Entity>>& entities, const Vector2<float>& windowSize,
  const std::shared_ptr<GraphicManager>& graphicManager, const std::shared_ptr<Scene>& scene)
{
  std::shared_ptr<mv::Entity> plus = std::make_shared<mv::Entity>();
  std::shared_ptr<mv::Entity> minus = std::make_shared<mv::Entity>();
  std::shared_ptr<mv::Entity> play = std::make_shared<mv::Entity>();

  play->addComponent<Clickable>();
  play->addComponent<ProperBody>();
  play->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID::PLAY, scene->getRenderer());
  play->getComponent<ProperBody>()->setSize({ 170,100 });
  play->getComponent<ProperBody>()->setPosition({ 0.5f*windowSize.x,0.833f*windowSize.y });

  plus->addComponent<Clickable>();
  plus->addComponent<ProperBody>();
  plus->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID::BUTTON_PLUS, scene->getRenderer());
  plus->getComponent<ProperBody>()->setSize({ 100,100 });
  plus->getComponent<ProperBody>()->setPosition({ 0.325f*windowSize.x,0.833f*windowSize.y });

  minus->addComponent<Clickable>();
  minus->addComponent<ProperBody>();
  minus->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID::BUTTON_MINUS, scene->getRenderer());
  minus->getComponent<ProperBody>()->setSize({ 100,100 });
  minus->getComponent<ProperBody>()->setPosition({ 0.05f*windowSize.x,0.833f*windowSize.y });

  plus->getComponent<ProperBody>()->setSize({ 100,100 });
  entities.emplace_back(plus);
  entities.emplace_back(minus);
  entities.emplace_back(play);
}

void UILoader::loadTextBoxes(std::vector<std::shared_ptr<mv::Entity>>& entities, const Vector2<float>& windowSize,
  const std::shared_ptr<GraphicManager>& graphicManager, const std::shared_ptr<Scene>& scene)
{
  std::shared_ptr<mv::Entity> rate = std::make_shared<mv::Entity>();
  rate->addComponent<ProperBody>();
  rate->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID::RATE, scene->getRenderer());
  rate->getComponent<ProperBody>()->setSize({ 170,100 });
  rate->getComponent<ProperBody>()->setPosition({ 0.1875f*windowSize.x,0.833f*windowSize.y });

  std::shared_ptr<mv::Entity> prize = std::make_shared<mv::Entity>();
  prize->addComponent<ProperBody>();
  prize->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID::PRIZE, scene->getRenderer());
  prize->getComponent<ProperBody>()->setSize({ 250,60 });
  prize->getComponent<ProperBody>()->setPosition({ 0.8375f*windowSize.x,0.783f*windowSize.y });

  std::shared_ptr<mv::Entity> credits = std::make_shared<mv::Entity>();
  credits->addComponent<ProperBody>();
  credits->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID::CREDITS, scene->getRenderer());
  credits->getComponent<ProperBody>()->setSize({ 250,60 });
  credits->getComponent<ProperBody>()->setPosition({ 0.8375f*windowSize.x,0.866f*windowSize.y });

  entities.emplace_back(rate);
  entities.emplace_back(prize);
  entities.emplace_back(credits);
}

void UILoader::loadRolls(std::vector<std::shared_ptr<mv::Entity>>& entities, const std::shared_ptr<Loader>& loader,
  const Vector2<float>& windowSize, const std::shared_ptr<GraphicManager>& graphicManager,
  const std::shared_ptr<Scene>& scene, const std::shared_ptr<OneArmedBandit>& banditMachine)
{
  using RollWrapper_t = std::vector<std::shared_ptr<mv::Entity>>;

  Vector2<int8_t> crystalAmmount
  {
    static_cast<int8_t>(std::atoi(loader->getPathOf("ROLLS", mv::constants::loader::CONFIG_MODE::TECHNICALITIES).c_str())),
    static_cast<int8_t>(std::atoi(loader->getPathOf("SYMBOLS", mv::constants::loader::CONFIG_MODE::TECHNICALITIES).c_str()))
  };

  float gamePartOfWindow = std::atof(loader->getPathOf("GAME_PART", mv::constants::loader::CONFIG_MODE::TECHNICALITIES).c_str());

  float delta_x = windowSize.x / (crystalAmmount.x + 1);
  float delta_y = (windowSize.y*gamePartOfWindow) / (crystalAmmount.y + 1);

  banditMachine->initStructure(crystalAmmount, entities, { delta_x, delta_y });
}

void UILoader::loadBackground(std::vector<std::shared_ptr<mv::Entity>>& entities, const Vector2<float>& windowSize,
  const std::shared_ptr<GraphicManager>& graphicManager, const std::shared_ptr<Scene>& scene)
{
  std::shared_ptr<mv::Entity> background = std::make_shared<mv::Entity>();
  background->addComponent<ProperBody>();
  background->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID::BACKGROUND, scene->getRenderer());
  background->getComponent<ProperBody>()->setSize({ static_cast<float>(windowSize.x),static_cast<float>(windowSize.y) });
  background->getComponent<ProperBody>()->setPosition({ 0.5f*windowSize.x,0.5f*windowSize.y });
  entities.emplace_back(background);
}
