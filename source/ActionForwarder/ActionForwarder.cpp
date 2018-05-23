/*
mvxxx 2018
https://github.com/mvxxx
*/

#include "ActionForwarder.hpp"

void ActionForwarder::manage(const std::shared_ptr<Scene>& scene, const std::shared_ptr<OneArmedBandit>& bandit, const std::vector<std::shared_ptr<mv::Entity>>& entities, const std::shared_ptr<TextMachine>& textMachine, const std::shared_ptr<SDL_Renderer>& renderer)
{
  if ( scene->mouseState() )
  {
    for ( auto&var : entities )
    {
      if ( var->hasComponent<ProperBody>() )
      {
        auto PB = var->getComponent<ProperBody>();

        if ( var->hasComponent<Clickable>() )
          if ( var->getComponent<Clickable>()->wasClicked(scene->getMousePosition(), PB->getRect().x, PB->getRect().y, PB->getRect().w, PB->getRect().h) )
            switch ( PB->getType() )
            {
            case mv::constants::texture::TEXTURE_ID::BUTTON_PLUS:
              tryAdd(textMachine, renderer);
              break;

            case mv::constants::texture::TEXTURE_ID::BUTTON_MINUS:
              trySubtract(textMachine, renderer);
              break;

            case mv::constants::texture::TEXTURE_ID::PLAY:
              tryPlay(bandit, textMachine, renderer);
              break;

            default: break;
            }
      }
    }
    scene->setMouseState(false);
  }
}

bool ActionForwarder::tryAdd(const std::shared_ptr<TextMachine>& textMachine, const std::shared_ptr<SDL_Renderer>& renderer) const
{
  auto actualRate = textMachine->getValue(mv::constants::textTypes::TYPE::RATE);

  if ( actualRate + mv::constants::defaults::DELTA_RATE > textMachine->getValue(mv::constants::textTypes::TYPE::CREDITS) )
  {
    mv::Logger::Log(mv::constants::error::textMachine::NOT_ENOUGH_MONEY, mv::Logger::STREAM::CONSOLE, mv::Logger::TYPE::INFO);
    return false;
  }

  textMachine->setText(mv::constants::textTypes::TYPE::RATE, std::to_string(actualRate + mv::constants::defaults::DELTA_RATE), renderer);
  return true;
}

bool ActionForwarder::tryPlay(const std::shared_ptr<OneArmedBandit>& bandit, const std::shared_ptr<TextMachine>& textMachine, const std::shared_ptr<SDL_Renderer>& renderer) const
{
  auto actualRate = textMachine->getValue(mv::constants::textTypes::TYPE::RATE);
  auto actualMoney = textMachine->getValue(mv::constants::textTypes::TYPE::CREDITS);

  if ( actualMoney - actualRate < 0 || actualMoney == 0 )
  {
    mv::Logger::Log(mv::constants::error::textMachine::NOT_ENOUGH_MONEY, mv::Logger::STREAM::CONSOLE, mv::Logger::TYPE::INFO);
    return false;
  }

  bandit->startSimulate();

  if ( bandit->multiplier() == 0 )actualMoney -= actualRate;

  actualMoney += bandit->multiplier()*actualRate;

  textMachine->setText(mv::constants::textTypes::TYPE::PRIZE, std::to_string(bandit->multiplier()* actualRate), renderer);
  textMachine->setText(mv::constants::textTypes::TYPE::CREDITS, std::to_string(actualMoney), renderer);

  if ( actualRate > actualMoney )
    textMachine->setText(mv::constants::textTypes::TYPE::RATE, std::to_string(actualMoney), renderer);


  return true;
}

bool ActionForwarder::trySubtract(const std::shared_ptr<TextMachine>& textMachine, const std::shared_ptr<SDL_Renderer>& renderer) const
{
  auto actualRate = textMachine->getValue(mv::constants::textTypes::TYPE::RATE);

  if ( actualRate - mv::constants::defaults::DELTA_RATE < 0 )
  {
    mv::Logger::Log(mv::constants::error::textMachine::POSITIVE_RATE, mv::Logger::STREAM::CONSOLE, mv::Logger::TYPE::INFO);
    return false;
  }

  textMachine->setText(mv::constants::textTypes::TYPE::RATE, std::to_string(textMachine->getValue(mv::constants::textTypes::TYPE::RATE) - mv::constants::defaults::DELTA_RATE), renderer);
  return true;
}
