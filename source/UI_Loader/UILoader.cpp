#include "UILoader.hpp"

void UILoader::LoadUI(std::vector<std::shared_ptr<mv::Entity>>& entities, const std::shared_ptr<Loader>& loader, const std::shared_ptr<GraphicManager>& graphicManager, const std::shared_ptr<Scene>& scene)
{
  Vector2<float> windowSize = { static_cast<float>(std::atof(loader->getPathOf("WINDOW_DIMENSIONS_X", mv::constants::loader::CONFIG_MODE::TECHNICALITIES).c_str())),
    static_cast<float>(std::atof(loader->getPathOf("WINDOW_DIMENSIONS_Y", mv::constants::loader::CONFIG_MODE::TECHNICALITIES).c_str())) };

  loadBackground(entities, windowSize, graphicManager, scene);
  loadTextBoxes(entities, windowSize, graphicManager, scene);
  loadButtons(entities, windowSize, graphicManager, scene);
  loadRolls(entities, loader, windowSize, graphicManager, scene);
}

void UILoader::loadButtons(std::vector<std::shared_ptr<mv::Entity>>& entities, const Vector2<float>& windowSize,
  const std::shared_ptr<GraphicManager>& graphicManager, const std::shared_ptr<Scene>& scene)
{
  std::shared_ptr<mv::Entity> plus = std::make_shared<mv::Entity>();
  std::shared_ptr<mv::Entity> minus = std::make_shared<mv::Entity>();
  std::shared_ptr<mv::Entity> play = std::make_shared<mv::Entity>();

  play->addComponent<Clickable>();
  play->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID::PLAY, scene->getRenderer());
  play->getComponent<ProperBody>()->setSize({ 170,100 });
  play->getComponent<ProperBody>()->setPosition({ 0.5f*windowSize.x,0.833f*windowSize.y });

  plus->addComponent<Clickable>();
  plus->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID::BUTTON_PLUS, scene->getRenderer());
  plus->getComponent<ProperBody>()->setPosition({ 0.325f*windowSize.x,0.833f*windowSize.y });

  minus->addComponent<Clickable>();
  minus->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID::BUTTON_MINUS, scene->getRenderer());
  minus->getComponent<ProperBody>()->setPosition({ 0.05f*windowSize.x,0.833f*windowSize.y });

  entities.emplace_back(plus);
  entities.emplace_back(minus);
  entities.emplace_back(play);
}

void UILoader::loadTextBoxesstd::vector<std::shared_ptr<mv::Entity>>& entities, const Vector2<float>& windowSize,
const std::shared_ptr<GraphicManager>& graphicManager, const std::shared_ptr<Scene>& scene)
{
std::shared_ptr<mv::Entity> rate = std::make_shared<mv::Entity>();

rate->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID::RATE, scene->getRenderer());
rate->getComponent<ProperBody>()->setSize({ 170,100 });
rate->getComponent<ProperBody>()->setPosition({ 0.1875f*windowSize.x,0.833f*windowSize.y });

}

void UILoader::loadRolls(std::vector<std::shared_ptr<mv::Entity>>& entities, const std::shared_ptr<Loader>& loader,
  const Vector2<float>& windowSize, const std::shared_ptr<GraphicManager>& graphicManager, const std::shared_ptr<Scene>& scene)
{
}

void UILoader::loadBackground(std::vector<std::shared_ptr<mv::Entity>>& entities, const Vector2<float>& windowSize,
  const std::shared_ptr<GraphicManager>& graphicManager, const std::shared_ptr<Scene>& scene)
{
  std::shared_ptr<mv::Entity> background = std::make_shared<mv::Entity>();
  background->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID::BACKGROUND, scene->getRenderer());
  background->getComponent<ProperBody>()->setSize({ static_cast<float>(windowSize.x),static_cast<float>(windowSize.y) });
  background->getComponent<ProperBody>()->setPosition({ 0.5f*windowSize.x,0.5f*windowSize.y });
  entities.emplace_back(background);
}
