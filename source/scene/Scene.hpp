/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <memory>
#include <SDL.h>

#include "wrappers/Point.hpp"
#include "Config.hpp"

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
  void clear();
protected:
private:
};