/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <memory>
#include <SDL_render.h>

class Scene
{
	/* ===Objects=== */
public:
protected:
private:
  std::shared_ptr<SDL_Window> window;
  std::shared_ptr<SDL_Renderer> renderer;
	/* ===Methods=== */
public:
  std::shared_ptr<SDL_Window> getWindow();
  std::shared_ptr<SDL_Renderer> getRenderer();
protected:
private:
  Scene();
};