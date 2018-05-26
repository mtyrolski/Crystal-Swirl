/*
mvxxx 2018
https://github.com/mvxxx
*/

#include "UILoader.hpp"

void UILoader::LoadUI(std::vector<std::shared_ptr<mv::Entity>>& entities, const std::shared_ptr<Loader>& loader,
  const std::shared_ptr<GraphicManager>& graphicManager, const std::shared_ptr<Scene>& scene, const std::shared_ptr<OneArmedBandit>& banditMachine)
{
  Vector2<float> windowSize = { static_cast<float>(std::atof(loader->getValueByKey("WINDOW_DIMENSIONS_X", mv::constants::loader::CONFIG_MODE::TECHNICALITIES).c_str())),
    static_cast<float>(std::atof(loader->getValueByKey("WINDOW_DIMENSIONS_Y", mv::constants::loader::CONFIG_MODE::TECHNICALITIES).c_str())) };

  loadBackground(entities, windowSize, graphicManager, scene, loader);
  loadTextBoxes(entities, windowSize, graphicManager, scene, loader);
  loadButtons(entities, windowSize, graphicManager, scene, loader);
  loadRolls(entities, loader, windowSize, graphicManager, scene, banditMachine);
}

void UILoader::loadButtons(std::vector<std::shared_ptr<mv::Entity>>& entities, const Vector2<float>& windowSize,
  const std::shared_ptr<GraphicManager>& graphicManager, const std::shared_ptr<Scene>& scene, const std::shared_ptr<Loader>& loader)
{
  using namespace mv::constants::loader;
  std::shared_ptr<mv::Entity> plus = std::make_shared<mv::Entity>();
  std::shared_ptr<mv::Entity> minus = std::make_shared<mv::Entity>();
  std::shared_ptr<mv::Entity> play = std::make_shared<mv::Entity>();

  play->addComponent<Clickable>();
  play->addComponent<ProperBody>();
  play->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID::PLAY, scene->getRenderer());
  play->getComponent<ProperBody>()->setSize({ static_cast<float>(std::atof(loader->getValueByKey("PLAY_SIZE_X",CONFIG_MODE::GRAPHIC).c_str())),static_cast<float>(std::atof(loader->getValueByKey("PLAY_SIZE_Y",CONFIG_MODE::GRAPHIC).c_str())) });
  play->getComponent<ProperBody>()->setPosition({ 0.5f*windowSize.x,0.833f*windowSize.y });

  plus->addComponent<Clickable>();
  plus->addComponent<ProperBody>();
  plus->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID::BUTTON_PLUS, scene->getRenderer());
  plus->getComponent<ProperBody>()->setSize({ static_cast<float>(std::atof(loader->getValueByKey("PLUS_SIZE_X",CONFIG_MODE::GRAPHIC).c_str())),static_cast<float>(std::atof(loader->getValueByKey("PLUS_SIZE_Y",CONFIG_MODE::GRAPHIC).c_str())) });
  plus->getComponent<ProperBody>()->setPosition({ 0.335f*windowSize.x,0.833f*windowSize.y });

  minus->addComponent<Clickable>();
  minus->addComponent<ProperBody>();
  minus->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID::BUTTON_MINUS, scene->getRenderer());
  minus->getComponent<ProperBody>()->setSize({ static_cast<float>(std::atof(loader->getValueByKey("MINUS_SIZE_X",CONFIG_MODE::GRAPHIC).c_str())),static_cast<float>(std::atof(loader->getValueByKey("MINUS_SIZE_Y",CONFIG_MODE::GRAPHIC).c_str())) });
  minus->getComponent<ProperBody>()->setPosition({ 0.05f*windowSize.x,0.833f*windowSize.y });

  entities.emplace_back(plus);
  entities.emplace_back(minus);
  entities.emplace_back(play);
}

void UILoader::loadTextBoxes(std::vector<std::shared_ptr<mv::Entity>>& entities, const Vector2<float>& windowSize,
  const std::shared_ptr<GraphicManager>& graphicManager, const std::shared_ptr<Scene>& scene, const std::shared_ptr<Loader>& loader)
{
  using namespace mv::constants::loader;
  std::shared_ptr<mv::Entity> rate = std::make_shared<mv::Entity>();
  rate->addComponent<ProperBody>();
  rate->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID::RATE, scene->getRenderer());
  rate->getComponent<ProperBody>()->setSize({ static_cast<float>(std::atof(loader->getValueByKey("RATE_SIZE_X",CONFIG_MODE::GRAPHIC).c_str())),static_cast<float>(std::atof(loader->getValueByKey("RATE_SIZE_Y",CONFIG_MODE::GRAPHIC).c_str())) });
  rate->getComponent<ProperBody>()->setPosition({ 0.1875f*windowSize.x,0.833f*windowSize.y });

  std::shared_ptr<mv::Entity> prize = std::make_shared<mv::Entity>();
  prize->addComponent<ProperBody>();
  prize->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID::PRIZE, scene->getRenderer());
  prize->getComponent<ProperBody>()->setSize({ static_cast<float>(std::atof(loader->getValueByKey("PRIZE_SIZE_X",CONFIG_MODE::GRAPHIC).c_str())),static_cast<float>(std::atof(loader->getValueByKey("PRIZE_SIZE_Y",CONFIG_MODE::GRAPHIC).c_str())) });
  prize->getComponent<ProperBody>()->setPosition({ 0.8375f*windowSize.x,0.783f*windowSize.y });

  std::shared_ptr<mv::Entity> credits = std::make_shared<mv::Entity>();
  credits->addComponent<ProperBody>();
  credits->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID::CREDITS, scene->getRenderer());
  credits->getComponent<ProperBody>()->setSize({ static_cast<float>(std::atof(loader->getValueByKey("CREDITS_SIZE_X",CONFIG_MODE::GRAPHIC).c_str())),static_cast<float>(std::atof(loader->getValueByKey("CREDITS_SIZE_Y",CONFIG_MODE::GRAPHIC).c_str())) });
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
    static_cast<int8_t>(std::atoi(loader->getValueByKey("ROLLS", mv::constants::loader::CONFIG_MODE::TECHNICALITIES).c_str())),
    static_cast<int8_t>(std::atoi(loader->getValueByKey("SYMBOLS", mv::constants::loader::CONFIG_MODE::TECHNICALITIES).c_str()))
  };

  float resolutionFactor = std::atof(loader->getValueByKey("RESOLUTION_FACTOR", mv::constants::loader::CONFIG_MODE::TECHNICALITIES).c_str());

  float delta_x = windowSize.x / (crystalAmmount.x + 1);
  float delta_y = (windowSize.y*resolutionFactor) / (crystalAmmount.y + 1);

  banditMachine->initStructure(crystalAmmount, entities, { delta_x, delta_y },loader);
  checkDimensions(entities.back(),{ delta_x, delta_y },loader);
}

void UILoader::loadBackground(std::vector<std::shared_ptr<mv::Entity>>& entities, const Vector2<float>& windowSize,
  const std::shared_ptr<GraphicManager>& graphicManager, const std::shared_ptr<Scene>& scene, const std::shared_ptr<Loader>& loader)
{
  std::shared_ptr<mv::Entity> background = std::make_shared<mv::Entity>();
  background->addComponent<ProperBody>();
  background->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID::BACKGROUND, scene->getRenderer());
  background->getComponent<ProperBody>()->setSize({ static_cast<float>(windowSize.x),static_cast<float>(windowSize.y) });
  background->getComponent<ProperBody>()->setPosition({ 0.5f*windowSize.x,0.5f*windowSize.y });
  entities.emplace_back(background);
}

void UILoader::checkDimensions(std::shared_ptr<mv::Entity> exampleSymbol, const Vector2<float>& delta, const std::shared_ptr<Loader>& loader)
{
  auto tolerance = std::atof(loader->getValueByKey("TOLERANCE", mv::constants::loader::CONFIG_MODE::TECHNICALITIES).c_str());
  std::vector<std::string> errors;
  bool flag_error = false;
  if ( exampleSymbol->getComponent<ProperBody>()->getRect().w*(1 + tolerance) > delta.x )
  {
    errors.emplace_back(mv::constants::error::UI::TOO_CLOSE_HORIZONTALLY);
    flag_error = true;
  }

  if ( exampleSymbol->getComponent<ProperBody>()->getRect().h*(1 + tolerance) > delta.y )
  {
    errors.emplace_back(mv::constants::error::UI::TOO_CLOSE_VERTICALLY);
    flag_error = true;
  }

  if ( flag_error )
  {
    for(auto&var:errors )
    {
      var.append(" ");
      var.append(mv::constants::error::UI::SOLUTION);
      mv::Logger::Log(var, mv::Logger::STREAM::CONSOLE, mv::Logger::TYPE::WARNING);
    }   
  }
 
}
