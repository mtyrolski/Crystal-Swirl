
/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <memory>

#include "ecs/entity/Entity.hpp"
#include "ecs/component/ProperBody.hpp"
#include "GraphicManager/GraphicManager.hpp"
#include "scene/Scene.hpp"
#include "wrappers/Troika.hpp"
#include "Math.hpp"

/*
 *One armed bandit - manage the main mechanism of slot game
 */
class OneArmedBandit
{
	/* ===Objects=== */
private:

  //Wrapper which represents roll
  using RollWrapper_t = std::vector<std::shared_ptr<mv::Entity>>;

  //flag which will be used in future
  bool processing;

  //value which will be used in future
  float delayTime;

  //value which will be used in future
  float simulateTime;

  //container of rolls with symbols
  std::vector<RollWrapper_t> crystalStructure;

  //scene pointer
  std::shared_ptr<Scene> scene;

  //graphic pointer
  std::shared_ptr<GraphicManager> graphicManager;
	/* ===Methods=== */
public:
  OneArmedBandit(const std::shared_ptr<Loader>& loader,const std::shared_ptr<Scene>& _scene,const std::shared_ptr<GraphicManager>& _graphicManager);
 
  /*
   * Starts the process of simulating slot game
   */
  bool startSimulate(); 

  /*
   * will be used in future
   */
  void SetSimulateTime(float time);/*in seconds*/ 

   /*
    * will be used in future
    */
  void setDelayTime(float time);/*in seconds*/

  /*
   *Returns state of processing
   */
  bool getStatusOfProcessing() const;

  /*
   * Initialise structure, assign main pointers
   */
  void initStructure(
    const Vector2<int8_t>& crystalAmmount,
    std::vector<std::shared_ptr<mv::Entity>>& entities,
    const Vector2<float>& delta);

  /*
   * Checks result of game
   * temporarily this method is the most important part of this clas
   */
  float multiplier(const std::shared_ptr<Loader>& loader);

private:
  /*
   * Checks vertical axises
   */
  int multipyVertical();

  /*
   * Checks horizontal axises
   */
  int multipyHorizontal();
};
