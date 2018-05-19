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

Scene::Scene()
  :opened(true)
{
  window = std::make_shared<SDL_Window>(SDL_CreateWindow("Crystal Swirl", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0));
  renderer = std::make_shared<SDL_Renderer>(SDL_CreateRenderer(&*window, -1, SDL_RENDERER_ACCELERATED));
}
