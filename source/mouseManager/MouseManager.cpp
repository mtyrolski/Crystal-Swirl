#include "MouseManager.hpp"

void MouseManager::manage(const std::shared_ptr<Scene>& scene, const std::shared_ptr<OneArmedBandit>& bandit, const std::vector<std::shared_ptr<mv::Entity>>& entities, const std::shared_ptr<TextMachine>& textMachine, const std::shared_ptr<SDL_Renderer>& renderer)
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
          {
            auto actualRate = textMachine->getValue(mv::constants::textTypes::TYPE::RATE);

            switch ( PB->getType() )
            {
            case mv::constants::texture::TEXTURE_ID::BUTTON_PLUS:
            {
              if ( actualRate + mv::constants::defaults::DELTA_RATE > textMachine->getValue(mv::constants::textTypes::TYPE::CREDITS) )
              {
                mv::Logger::Log(mv::constants::error::textMachine::NOT_ENOUGH_MONEY, mv::Logger::STREAM::CONSOLE, mv::Logger::TYPE::INFO);
                break;
              }

              textMachine->setText(mv::constants::textTypes::TYPE::RATE, std::to_string(actualRate +mv::constants::defaults::DELTA_RATE),renderer);
              break;
            }

            case mv::constants::texture::TEXTURE_ID::BUTTON_MINUS:
            {
              if ( actualRate - mv::constants::defaults::DELTA_RATE < 0 )
              {
                mv::Logger::Log(mv::constants::error::textMachine::POSITIVE_RATE, mv::Logger::STREAM::CONSOLE, mv::Logger::TYPE::INFO);
                break;
              }
             
              textMachine->setText(mv::constants::textTypes::TYPE::RATE, std::to_string(textMachine->getValue(mv::constants::textTypes::TYPE::RATE) - mv::constants::defaults::DELTA_RATE), renderer);
              break;
            }

            case mv::constants::texture::TEXTURE_ID::PLAY:
            {      
              auto actualMoney = textMachine->getValue(mv::constants::textTypes::TYPE::CREDITS);
            
              if ( actualMoney - actualRate < 0 )
              {
                mv::Logger::Log(mv::constants::error::textMachine::NOT_ENOUGH_MONEY,mv::Logger::STREAM::CONSOLE,mv::Logger::TYPE::INFO);
                break;
              }

              actualMoney -= actualRate;
              bandit->startSimulate();
              actualMoney += bandit->multiplier()*actualRate;

              textMachine->setText(mv::constants::textTypes::TYPE::PRIZE, std::to_string(bandit->multiplier()* actualRate) , renderer);
              textMachine->setText(mv::constants::textTypes::TYPE::CREDITS, std::to_string(actualMoney), renderer);


              break;
            }

            default: break;
            }
          }
      }
    }
  }
    
  if ( scene->mouseState() )
    scene->setMouseState(false);
}
