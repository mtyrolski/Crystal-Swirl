/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <memory>
#include <SDL_image.h>
#include <SDL.h>

#include "logger/Logger.hpp"
#include "wrappers/Vector2.hpp"
#include "Config.hpp"
#include "ecs/entity/Entity.hpp"
#include "ecs/component/ProperBody.hpp"


class Scene
{
	/* ===Objects=== */
public:
protected:
private:
  std::shared_ptr<SDL_Window> window;
  std::shared_ptr<SDL_Renderer> renderer;

  bool opened;
	/* ===Methods=== */
public:
  Scene();
  ~Scene();

  std::shared_ptr<SDL_Window> getWindow();
  std::shared_ptr<SDL_Renderer> getRenderer();

  bool isOpen();

  void pollEvents();
  void clear(const std::vector<std::shared_ptr<mv::Entity>>& entities);
protected:
private:
};