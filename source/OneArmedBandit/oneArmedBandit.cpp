/*
mvxxx 2018
https://github.com/mvxxx
*/


#include "oneArmedBandit.hpp"

OneArmedBandit::OneArmedBandit(const std::shared_ptr<Loader>& loader, const std::shared_ptr<Scene>& _scene, const std::shared_ptr<GraphicManager>& _graphicManager)
  : scene(_scene), graphicManager(_graphicManager), processing(false)
{
  delayTime = std::atof(loader->getValueByKey("BANDIT_MACHINE_DELAY", mv::constants::loader::CONFIG_MODE::TECHNICALITIES).c_str());
  simulateTime = std::atof(loader->getValueByKey("BANDIT_MACHINE_SIMULATION_TIME", mv::constants::loader::CONFIG_MODE::TECHNICALITIES).c_str());
}

bool OneArmedBandit::startSimulate()
{
  if ( processing )
  {
    mv::Logger::Log(mv::constants::error::banditMachine::PROCESSING, mv::Logger::STREAM::CONSOLE, mv::Logger::TYPE::INFO);
    return false;
  }

  for ( auto&roll : crystalStructure )
    for ( auto&var : roll )
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

void OneArmedBandit::initStructure(
  const Vector2<int8_t>& crystalAmmount,
  std::vector<std::shared_ptr<mv::Entity>>& entities,
  const Vector2<float>& delta,
  const std::shared_ptr<Loader>& loader)
{
  using namespace mv::constants::loader;

  for ( int i = 0; i < crystalAmmount.x; i++ )
  {
    crystalStructure.emplace_back();
    for ( int j = 0; j < crystalAmmount.y; j++ )
    {
      auto entity = std::make_shared<mv::Entity>();
      entity->addComponent<ProperBody>();
      entity->getComponent<ProperBody>()->setSize({ static_cast<float>(std::atof(loader->getValueByKey("SYMBOL_SIZE_X",CONFIG_MODE::GRAPHIC).c_str())),static_cast<float>(std::atof(loader->getValueByKey("SYMBOL_SIZE_Y",CONFIG_MODE::GRAPHIC).c_str())) });
      entity->getComponent<ProperBody>()->setPosition({ delta.x*(i + 1),delta.y*(j + 1) });
      entity->getComponent<ProperBody>()->setType(graphicManager, mv::constants::texture::TEXTURE_ID(Math::random(3, 5)), scene->getRenderer());
      crystalStructure[i].emplace_back();
      crystalStructure[i][j] = entity;
      entities.emplace_back(entity);
    }
  }
}

float OneArmedBandit::multiplier(const std::shared_ptr<Loader>& loader)
{
  if ( crystalStructure.size() == 0 || crystalStructure.front().size() == 0 )
  {
    mv::Logger::Log(mv::constants::error::banditMachine::LACK_OF_SYMBOLS);
    return -1;
  }

  return std::atof(loader->getValueByKey("PRIZE_FACTOR",mv::constants::loader::CONFIG_MODE::TECHNICALITIES,mv::constants::loader::STORAGE_MODE::STORE).c_str()) * (multipyHorizontal() + multipyVertical());

}

int OneArmedBandit::multipyVertical()
{
  auto counter = 0;
  for ( auto& roll : crystalStructure )
  {
    bool lineUp = true;

    for ( int j = 1; j < roll.size(); j++ )
    {
      if ( roll[j]->getComponent<ProperBody>()->getType() != roll[j - 1]->getComponent<ProperBody>()->getType() )
      {
        lineUp = false;
        break;
      }
    }
    if ( lineUp )
      counter+=roll.size();
  }
  return counter;
}

int OneArmedBandit::multipyHorizontal()
{
  int ammountOfSymbolsInRoll = crystalStructure.front().size();
  auto counter = 0;
  for ( int j = 0; j < ammountOfSymbolsInRoll; j++ )
  {
    bool lineUp = true;
    for ( int i = 1; i < crystalStructure.size(); i++ )
    {
      if ( crystalStructure[i][j]->getComponent<ProperBody>()->getType() != crystalStructure[i - 1][j]->getComponent<ProperBody>()->getType() )
      {
        lineUp = false;
        break;
      }
    }
    if ( lineUp )
      counter += crystalStructure.size();
  }

  return counter;
}
