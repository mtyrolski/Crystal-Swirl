/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <memory>
#include <vector>

#include "OneArmedBandit/oneArmedBandit.hpp"
#include "mouseManager/MouseManager.hpp"
#include "GraphicManager/GraphicManager.hpp"
#include "cache/Cache.hpp"
#include "scene/Scene.hpp"
#include "Math.hpp"


class GameState
{
  /* ===Objects=== */
public:
protected:
private:
  std::shared_ptr<Scene> scene;
  std::shared_ptr<GraphicManager> graphicManager;
  std::vector<std::shared_ptr<mv::Entity>> entities;
  MouseManager mouseManager;

  std::shared_ptr<OneArmedBandit> banditMachine;

  /* ===Methods=== */
public:
  GameState(const std::shared_ptr<Scene>& scenePtr);

  void onStart();
  void onStop();
  void run();
protected:
private:
  void initUI();
};