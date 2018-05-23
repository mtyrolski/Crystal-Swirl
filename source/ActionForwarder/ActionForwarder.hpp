/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include "ecs/entity/Entity.hpp"
#include "OneArmedBandit/OneArmedBandit.hpp"
#include "textMachine/textMachine.hpp"

class ActionForwarder
{
  /* ===Objects=== */
public:
protected:
private:
  /* ===Methods=== */
public:
  void manage(const std::shared_ptr<Scene>& scene,
    const std::shared_ptr<OneArmedBandit>& bandit,
    const std::vector<std::shared_ptr<mv::Entity>>& entities,
    const std::shared_ptr<TextMachine>& textMachine,
    const std::shared_ptr <SDL_Renderer> & renderer);
protected:
private:
  bool tryAdd(const std::shared_ptr<TextMachine>& textMachine, const std::shared_ptr<SDL_Renderer>& renderer);
  bool tryPlay(const std::shared_ptr<OneArmedBandit>& bandit, const std::shared_ptr<TextMachine>& textMachine, const std::shared_ptr<SDL_Renderer>& renderer);
  bool trySubtract(const std::shared_ptr<TextMachine>& textMachine, const std::shared_ptr<SDL_Renderer>& renderer);
};
