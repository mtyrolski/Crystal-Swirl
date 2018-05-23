/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <memory>

#include <SDL.h>

#include "GameState/GameState.hpp"
#include "scene/Scene.hpp"

class Game
{	
  /* ===Objects=== */
public:
protected:
private:
  std::shared_ptr<Scene> scene;
  std::shared_ptr<GameState> gameState;
  /* ===Methods=== */
public:
  void run();
protected:
private:
  void init();
};