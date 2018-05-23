/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include "ecs/entity/Entity.hpp"
#include "OneArmedBandit/OneArmedBandit.hpp"
#include "textMachine/textMachine.hpp"


/*
 * Class that mediates between the mouse and Text Machine
 */
class ActionForwarder
{
  /* ===Methods=== */
public:
  /*
   * Huge method which is used for making decision,
   * which action need to be done depends on mouse click
   */
  void manage(const std::shared_ptr<Scene>& scene,
    const std::shared_ptr<OneArmedBandit>& bandit,
    const std::vector<std::shared_ptr<mv::Entity>>& entities,
    const std::shared_ptr<TextMachine>& textMachine,
    const std::shared_ptr <SDL_Renderer> & renderer);
private:

  /*
   *This method try to increase rate value.
   *Returns false if it can not be.
   *Returns true if it is done.
   */
  bool tryAdd(const std::shared_ptr<TextMachine>& textMachine, const std::shared_ptr<SDL_Renderer>& renderer) const;
  
  /*
   *This method try to run mechanism of game
   *Returns false if it can not be.
   *Returns true if it is done.
  */
  bool tryPlay(const std::shared_ptr<OneArmedBandit>& bandit, const std::shared_ptr<TextMachine>& textMachine, const std::shared_ptr<SDL_Renderer>& renderer) const;
 
  /*
  *This method try to substract rate value
  *Returns false if it can not be.
  *Returns true if it is done.
  */
  bool trySubtract(const std::shared_ptr<TextMachine>& textMachine, const std::shared_ptr<SDL_Renderer>& renderer) const;
};
