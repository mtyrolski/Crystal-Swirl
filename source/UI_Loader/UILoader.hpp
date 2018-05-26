/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include "GraphicManager/GraphicManager.hpp"
#include "OneArmedBandit/oneArmedBandit.hpp"
#include "ecs/component/ProperBody.hpp"
#include "ecs/component/text/Text.hpp"
#include "ecs/entity/Entity.hpp"
#include "scene/Scene.hpp"

/*
 * Supports creating UI
 */
class UILoader
{
	/* ===Methods=== */
public:

  /*
   * Receives files
   * Splits up the UI loading
   */
  void LoadUI(std::vector<std::shared_ptr<mv::Entity>>& entities, const std::shared_ptr<Loader>& loader, 
    const std::shared_ptr<GraphicManager>& graphicManager, const std::shared_ptr<Scene>& scene, const std::shared_ptr<OneArmedBandit>& banditMachine);
private:

  /*
   * Loads buttons: PLUS/MINUS/PLAY
   */
  void loadButtons(std::vector<std::shared_ptr<mv::Entity>>& entities, const Vector2<float>& windowSize,
    const std::shared_ptr<GraphicManager>& graphicManager, const std::shared_ptr<Scene>& scene, const std::shared_ptr<Loader>& loader);

  /* 
   * Loads textboxes: Prize, Credits, Last win
   */
  void loadTextBoxes(std::vector<std::shared_ptr<mv::Entity>>& entities, const Vector2<float>& windowSize,
    const std::shared_ptr<GraphicManager>& graphicManager, const std::shared_ptr<Scene>& scene, const std::shared_ptr<Loader>& loader);

  /* 
   * Loads Rolls: symbols
   */
  void loadRolls(std::vector<std::shared_ptr<mv::Entity>>& entities, const std::shared_ptr<Loader>& loader,
    const Vector2<float>& windowSize, const std::shared_ptr<GraphicManager>& graphicManager, const std::shared_ptr<Scene>& scene, const std::shared_ptr<OneArmedBandit>& banditMachine);

  /*
   * Loads background
   */
  void loadBackground(std::vector<std::shared_ptr<mv::Entity>>& entities, const Vector2<float>& windowSize,
    const std::shared_ptr<GraphicManager>& graphicManager, const std::shared_ptr<Scene>& scene, const std::shared_ptr<Loader>& loader);


  /*
   * Checks if elements are too close
   */
  void checkDimensions(std::shared_ptr<mv::Entity> exampleSymbol, const Vector2<float>& delta, const std::shared_ptr<Loader>& loader);
};