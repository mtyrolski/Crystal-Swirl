/*
mvxxx 2018
https://github.com/mvxxx
*/


#include "oneArmedBandit.hpp"

OneArmedBandit::OneArmedBandit(float dTime, float sTime, const std::shared_ptr<Scene>& _scene, const std::shared_ptr<GraphicManager>& _graphicManager)
  :delayTime(dTime), simulateTime(sTime), scene(_scene),graphicManager(_graphicManager),processing(false)
{
}

bool OneArmedBandit::startSimulate()
{
  if ( processing )
  {
    //logger inf
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

bool OneArmedBandit::getStatusOfProcessing()
{
  return processing;
}

void OneArmedBandit::initStructure(const std::vector<std::shared_ptr<mv::Entity>>& data)
{
  crystalStructure.first = { data[1],data[2],data[3] };
  crystalStructure.second = { data[4],data[5],data[6] };
  crystalStructure.third = { data[7],data[8],data[9] };
}

int OneArmedBandit::multiplier()
{
  auto counter = 0;

  {//horizontal axis
    if ( crystalStructure.first.first->getComponent<ProperBody>()->getType() == crystalStructure.first.second->getComponent<ProperBody>()->getType() &&
      crystalStructure.first.second->getComponent<ProperBody>()->getType() == crystalStructure.first.third->getComponent<ProperBody>()->getType() )
      counter++;

    if ( crystalStructure.second.first->getComponent<ProperBody>()->getType() == crystalStructure.second.second->getComponent<ProperBody>()->getType() &&
      crystalStructure.second.second->getComponent<ProperBody>()->getType() == crystalStructure.second.third->getComponent<ProperBody>()->getType() )
      counter++;

    if ( crystalStructure.third.first->getComponent<ProperBody>()->getType() == crystalStructure.third.second->getComponent<ProperBody>()->getType() &&
      crystalStructure.third.second->getComponent<ProperBody>()->getType() == crystalStructure.third.third->getComponent<ProperBody>()->getType() )
      counter++;

  }

  {//vertical axis
    if ( crystalStructure.first.first->getComponent<ProperBody>()->getType() == crystalStructure.second.first->getComponent<ProperBody>()->getType() &&
      crystalStructure.second.first->getComponent<ProperBody>()->getType() == crystalStructure.third.first->getComponent<ProperBody>()->getType() )
      counter++;

    if ( crystalStructure.first.second->getComponent<ProperBody>()->getType() == crystalStructure.second.second->getComponent<ProperBody>()->getType() &&
      crystalStructure.second.second->getComponent<ProperBody>()->getType() == crystalStructure.third.second->getComponent<ProperBody>()->getType() )
      counter++;

    if ( crystalStructure.first.third->getComponent<ProperBody>()->getType() == crystalStructure.second.third->getComponent<ProperBody>()->getType() &&
      crystalStructure.second.third->getComponent<ProperBody>()->getType() == crystalStructure.third.third->getComponent<ProperBody>()->getType() )
      counter++;
  }

  return counter;
}
