
/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <memory>

#include "wrappers/Troika.hpp"
#include "ecs/entity/Entity.hpp"
#include "ecs/component/ProperBody.hpp"

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
	/* ===Methods=== */
public:
  OneArmedBandit(float dTime, float sTime);
  bool startSimulate(); 
  void SetSimulateTime(float time);/*in seconds*/ 
  void setDelayTime(float time);/*in seconds*/
  bool getStatusOfProcessing(); 
  void initStructure(const std::vector<std::shared_ptr<mv::Entity>>& data);
  int multiplier(); /*temporarily this method is the most important part of this class*/
protected:
private:
};
