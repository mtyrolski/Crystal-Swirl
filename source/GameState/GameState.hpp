/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <memory>

#include "scene/Scene.hpp"

class GameState
{
  /* ===Objects=== */
public:
protected:
private:
  std::shared_ptr<Scene> scene;
  /* ===Methods=== */
public:
  GameState(std::shared_ptr<Scene> scenePtr);

  void onStart();
  void onStop();
  void run();
protected:
private:
};