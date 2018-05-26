/*
mvxxx 2018
https://github.com/mvxxx
*/


#include "oneArmedBandit.hpp"

OneArmedBandit::OneArmedBandit(const std::shared_ptr<Loader>& loader, const std::shared_ptr<Scene>& _scene, const std::shared_ptr<GraphicManager>& _graphicManager)
  : scene(_scene), graphicManager(_graphicManager), processing(false)
{
  delayTime = std::atof(loader->getPathOf("BANDIT_MACHINE_DELAY", mv::constants::loader::CONFIG_MODE::TECHNICALITIES).c_str());
  simulateTime = std::atof(loader->getPathOf("BANDIT_MACHINE_SIMULATION_TIME", mv::constants::loader::CONFIG_MODE::TECHNICALITIES).c_str());
}

bool OneArmedBandit::startSimulate()
{
  if ( processing )
  {
    mv::Logger::Log(mv::constants::error::banditMachine::PROCESSING, mv::Logger::STREAM::CONSOLE, mv::Logger::TYPE::INFO);
    return false;
  }

  for ( auto&line : crystalStructure )
    for ( auto&var : line )
      var->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID(Math::random(3, 5)), scene->getRenderer());

}

void OneArmedBandit::SetSimulateTime(float time)
{
  simulateTime = time;
}

void OneArmedBandit::setDelayTime(float time)
{
  delayTime = time;
}

bool OneArmedBandit::getStatusOfProcessing() const
{
  return processing;
}

void OneArmedBandit::initStructure(const Vector2<float>& windowSize,
  const Vector2<int8_t>& crystalAmmount,
  float gamePartOfWindow,
  std::vector<std::shared_ptr<mv::Entity>>& entities,
  const Vector2<float>& delta)
{
  for ( int i = 0; i < crystalAmmount.x; i++ )
  {
    crystalStructure.emplace_back();
    for ( int j = 0; j < crystalAmmount.y; j++ )
    {
      auto entity = std::make_shared<mv::Entity>();
      entity->addComponent<ProperBody>();
      entity->getComponent<ProperBody>()->setSize({ 100,100 });
      entity->getComponent<ProperBody>()->setPosition({ delta.x*(i + 1),delta.y*(j + 1) });
      entity->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID(Math::random(3, 5)), scene->getRenderer());
      crystalStructure[i].emplace_back();
      crystalStructure[i][j] = entity;
      entities.emplace_back(entity);
    }
  }
}

int OneArmedBandit::multiplier()
{
  auto counter = 0;



  return counter;
}
