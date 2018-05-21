/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <memory>
#include <vector>

#include "Math.hpp"
#include "cache/Cache.hpp"
#include "scene/Scene.hpp"

class GameState
{
  /* ===Objects=== */
public:
protected:
private:
  std::shared_ptr<Scene> scene;
  std::shared_ptr<mv::Cache<SDL_Texture>> textureCache;
  std::vector<std::shared_ptr<mv::Entity>> entities;
  /* ===Methods=== */
public:
  GameState(std::shared_ptr<Scene> scenePtr);

  void onStart();
  void onStop();
  void run();
protected:
private:
  void initUI();
};