/*
mvxxx 2018
https://github.com/mvxxx
*/

#include "ActionForwarder.hpp"

void ActionForwarder::manage(const std::shared_ptr<Scene>& scene,
  const std::shared_ptr<OneArmedBandit>& bandit,
  const std::vector<std::shared_ptr<mv::Entity>>& entities,
  const std::shared_ptr<TextMachine>& textMachine,
  const std::shared_ptr<Loader>& loader,
  const std::shared_ptr<AudioManager>& audioManager,
  SDL_Renderer* renderer)
{
  if ( scene->mouseState() )
  {
    audioManager->play(mv::constants::audio::AUDIO_ID::CLICK);

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
              tryAdd(textMachine, renderer, loader);
              break;

            case mv::constants::texture::TEXTURE_ID::BUTTON_MINUS:
              trySubtract(textMachine, renderer, loader);
              break;

            case mv::constants::texture::TEXTURE_ID::PLAY:
              tryPlay(bandit, textMachine, renderer, loader, audioManager);
              break;

            default: break;
            }
      }
    }
    scene->setMouseState(false);
  }
}

bool ActionForwarder::tryAdd(const std::shared_ptr<TextMachine>& textMachine, SDL_Renderer* renderer, const std::shared_ptr<Loader>& loader) const
{
  auto actualRate = textMachine->getValue(mv::constants::textTypes::TYPE::RATE);
  auto deltaRate = std::atoi(loader->getPathOf("DELTA_RATE", mv::constants::loader::CONFIG_MODE::TECHNICALITIES, mv::constants::loader::STORAGE_MODE::STORE).c_str());
 
  if ( actualRate + deltaRate > textMachine->getValue(mv::constants::textTypes::TYPE::CREDITS) )
  {
    mv::Logger::Log(mv::constants::error::textMachine::NOT_ENOUGH_MONEY, mv::Logger::STREAM::CONSOLE, mv::Logger::TYPE::INFO);
    return false;
  }

  textMachine->setText(mv::constants::textTypes::TYPE::RATE, std::to_string(actualRate + deltaRate), renderer);
  return true;
}

bool ActionForwarder::tryPlay(const std::shared_ptr<OneArmedBandit>& bandit, const std::shared_ptr<TextMachine>& textMachine, SDL_Renderer* renderer, const std::shared_ptr<Loader>& loader, const std::shared_ptr<AudioManager>& audioManager) const
{
  auto actualRate = textMachine->getValue(mv::constants::textTypes::TYPE::RATE);
  auto actualMoney = textMachine->getValue(mv::constants::textTypes::TYPE::CREDITS);

  if ( actualMoney - actualRate < 0 || actualMoney == 0 )
  {
    mv::Logger::Log(mv::constants::error::textMachine::NOT_ENOUGH_MONEY, mv::Logger::STREAM::CONSOLE, mv::Logger::TYPE::INFO);
    return false;
  }

  audioManager->play(mv::constants::audio::AUDIO_ID::PLAY);

  bandit->startSimulate();

  if ( bandit->multiplier() == 0 )actualMoney -= actualRate;

  actualMoney += bandit->multiplier()*actualRate;

  textMachine->setText(mv::constants::textTypes::TYPE::PRIZE, std::to_string(bandit->multiplier()* actualRate), renderer);
  textMachine->setText(mv::constants::textTypes::TYPE::CREDITS, std::to_string(actualMoney), renderer);

  if ( actualRate > actualMoney )
    textMachine->setText(mv::constants::textTypes::TYPE::RATE, std::to_string(actualMoney), renderer);


  return true;
}

bool ActionForwarder::trySubtract(const std::shared_ptr<TextMachine>& textMachine, SDL_Renderer* renderer, const std::shared_ptr<Loader>& loader) const
{
  auto actualRate = textMachine->getValue(mv::constants::textTypes::TYPE::RATE);
  auto deltaRate = std::atoi(loader->getPathOf("DELTA_RATE", mv::constants::loader::CONFIG_MODE::TECHNICALITIES, mv::constants::loader::STORAGE_MODE::STORE).c_str());
  if ( actualRate - deltaRate < 0 )
  {
    mv::Logger::Log(mv::constants::error::textMachine::POSITIVE_RATE, mv::Logger::STREAM::CONSOLE, mv::Logger::TYPE::INFO);
    return false;
  }

  textMachine->setText(mv::constants::textTypes::TYPE::RATE, std::to_string(textMachine->getValue(mv::constants::textTypes::TYPE::RATE) - deltaRate), renderer);
  return true;
}
