#include "MouseManager.hpp"

void MouseManager::manage(const std::shared_ptr<Scene>& scene, const std::shared_ptr<OneArmedBandit>& bandit, const std::vector<std::shared_ptr<mv::Entity>>& entities)
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
            switch ( PB->getType() )
            {
            case mv::constants::texture::TEXTURE_ID::BUTTON_PLUS:
            {
              mv::Logger::Log("PLUS HAS BEEN CLICKED!");
              break;
            }

            case mv::constants::texture::TEXTURE_ID::BUTTON_MINUS:
            {
              mv::Logger::Log("MINUS HAS BEEN CLICKED!");
              break;
            }

            case mv::constants::texture::TEXTURE_ID::PLAY:
            {
              bandit->startSimulate();
              mv::Logger::Log("PLAY HAS BEEN CLICKED!");
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
