/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <memory>
#include <vector>

#include "OneArmedBandit/oneArmedBandit.hpp"
#include "ActionForwarder/ActionForwarder.hpp"
#include "GraphicManager/GraphicManager.hpp"
#include "textMachine/textMachine.hpp"
#include "cache/Cache.hpp"
#include "scene/Scene.hpp"
#include "Math.hpp"

/*
 * Main state
 */
class GameState
{
  /* ===Objects=== */
private:

  //Pointer to scene
  std::shared_ptr<Scene> scene;

  //Pointer to graphic manager
  std::shared_ptr<GraphicManager> graphicManager;

  //All entities which are under GameState control
  std::vector<std::shared_ptr<mv::Entity>> entities;

  //Helps in mediating between the mouse and Text Machine
  ActionForwarder actionForwarder;

  //Pointer to textMachine
  std::shared_ptr<TextMachine> textMachine;

  //Pointer to One Armed Bandit Machine
  std::shared_ptr<OneArmedBandit> banditMachine;

  /* ===Methods=== */
public:
  GameState(const std::shared_ptr<Scene>& scenePtr);

  /*
   *Loads texture, init UI, etc...
   */
  void onStart();

  /*
   * Checks events
   * drawing entities
   */
  void run();
protected:
private:

  /*
   * Inits UI
   */
  void initUI();
};