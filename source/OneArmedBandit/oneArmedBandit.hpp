
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

class OneArmedBandit
{
	/* ===Objects=== */
public:
protected:
private:

  bool processing;
  float delayTime;
  float simulateTime;

  Troika<Troika<std::shared_ptr<mv::Entity>>> crystalStructure;

  std::shared_ptr<Scene> scene;
  std::shared_ptr<GraphicManager> graphicManager;
	/* ===Methods=== */
public:
  OneArmedBandit(float dTime, float sTime,const std::shared_ptr<Scene>& _scene,const std::shared_ptr<GraphicManager>& _graphicManager);
  bool startSimulate(); 
  void SetSimulateTime(float time);/*in seconds*/ 
  void setDelayTime(float time);/*in seconds*/
  bool getStatusOfProcessing(); 
  void initStructure(const std::vector<std::shared_ptr<mv::Entity>>& data);
  int multiplier(); /*temporarily this method is the most important part of this class*/
protected:
private:
};
