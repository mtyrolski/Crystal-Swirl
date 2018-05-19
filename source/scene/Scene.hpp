/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <memory>
#include <SDL_render.h>
//#include <close_code.h>
//#include <SDL_quit.h>
#include <SDL.h>

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
protected:
private:
  Scene();
};