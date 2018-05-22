/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include "ecs/entity/Entity.hpp"
#include "OneArmedBandit/OneArmedBandit.hpp"

class MouseManager
{
	/* ===Objects=== */
public:
protected:
private:
	/* ===Methods=== */
public:
  void manage(const std::shared_ptr<Scene>& scene, const std::shared_ptr<OneArmedBandit>& bandit, const std::vector<std::shared_ptr<mv::Entity>>& entities);
protected:
private:
};
