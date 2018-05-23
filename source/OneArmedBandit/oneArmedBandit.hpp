
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
public:
protected:
private:
 
  //flag which will be used in future
  bool processing;

  //value which will be used in future
  float delayTime;

  //value which will be used in future
  float simulateTime;

  //Crystal pointer container
  Troika<Troika<std::shared_ptr<mv::Entity>>> crystalStructure;

  //scene pointer
  std::shared_ptr<Scene> scene;

  //graphic pointer
  std::shared_ptr<GraphicManager> graphicManager;
	/* ===Methods=== */
public:
  OneArmedBandit(float dTime, float sTime,const std::shared_ptr<Scene>& _scene,const std::shared_ptr<GraphicManager>& _graphicManager);
 
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
  void initStructure(const std::vector<std::shared_ptr<mv::Entity>>& data);

  /*
   * Checks result of game
   * temporarily this method is the most important part of this clas
   */
  int multiplier(); /*s*/
};
