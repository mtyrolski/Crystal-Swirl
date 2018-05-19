/*
mvxxx 2018
https://github.com/mvxxx
*/

#include "Scene.hpp"

Scene::~Scene()
{
  SDL_DestroyRenderer(&*renderer);
  SDL_DestroyWindow(&*window);
  SDL_Quit();
}

std::shared_ptr<SDL_Window> Scene::getWindow()
{
  return window;
}

std::shared_ptr<SDL_Renderer> Scene::getRenderer()
{
  return renderer;
}

bool Scene::isOpen()
{
  return opened;
}

void Scene::pollEvents()
{

  SDL_Event event;

  if ( SDL_PollEvent(&event) )
  {
    switch ( event.type )
    {
    case SDL_QUIT:
      opened = false;
      break;

    default:
      break;
    }
  }

}

void Scene::clear()
{
  SDL_SetRenderDrawColor(&*renderer, 0, 0, 200, 255);
  SDL_RenderClear(&*renderer);
  SDL_RenderPresent(&*renderer);
}

Scene::Scene()
  :opened(true)
{
  window = std::shared_ptr<SDL_Window>(SDL_CreateWindow("Crystal Swirl", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mv::constants::defaults::WINDOW_DIMENSIONS.x, mv::constants::defaults::WINDOW_DIMENSIONS.y, 0));
  renderer = std::shared_ptr<SDL_Renderer>(SDL_CreateRenderer(&*window, -1, SDL_RENDERER_ACCELERATED));
}
