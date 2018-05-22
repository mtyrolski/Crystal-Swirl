/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <memory>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "logger/Logger.hpp"
#include "wrappers/Vector2.hpp"
#include "Config.hpp"
#include "ecs/entity/Entity.hpp"
#include "ecs/component/ProperBody.hpp"
#include "ecs/component/Clickable.hpp"
 


class Scene
{
	/* ===Objects=== */
public:
protected:
private:
  std::shared_ptr<SDL_Window> window;
  std::shared_ptr<SDL_Renderer> renderer;

  bool mouseClicked = false;

  //this object is used when it is need to check properBody->wasClicked
  Vector2<float> mousePosition;

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

  bool mouseState();
  void setMouseState(bool flag);

  const Vector2<float>& getMousePosition();
protected:
private:
};