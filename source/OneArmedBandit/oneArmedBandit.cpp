/*
mvxxx 2018
https://github.com/mvxxx
*/


#include "oneArmedBandit.hpp"

OneArmedBandit::OneArmedBandit(float dTime, float sTime)
  :delayTime(dTime), simulateTime(sTime)
{
}

bool OneArmedBandit::startSimulate()
{
  if ( processing )
  {
    //logger inf
    return false;
  }

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
  crystalStructure.first = { data[0],data[1],data[2] };
  crystalStructure.second = { data[2],data[3],data[4] };
  crystalStructure.third = { data[5],data[6],data[7] };
}

int OneArmedBandit::multiplier()
{
  auto counter = 0;
  if ( crystalStructure.first.first->getComponent<ProperBody>()->getType() == crystalStructure.first.second->getComponent<ProperBody>()->getType() &&
    crystalStructure.first.second->getComponent<ProperBody>()->getType() == crystalStructure.first.third->getComponent<ProperBody>()->getType() )
    counter++;

  if ( crystalStructure.second.first->getComponent<ProperBody>()->getType() == crystalStructure.second.second->getComponent<ProperBody>()->getType() &&
    crystalStructure.second.second->getComponent<ProperBody>()->getType() == crystalStructure.second.third->getComponent<ProperBody>()->getType() )
    counter++;

  if ( crystalStructure.third.first->getComponent<ProperBody>()->getType() == crystalStructure.third.second->getComponent<ProperBody>()->getType() &&
    crystalStructure.third.second->getComponent<ProperBody>()->getType() == crystalStructure.third.third->getComponent<ProperBody>()->getType() )
    counter++;

  return counter;
}
