#include "Scene.hpp"

std::shared_ptr<SDL_Window> Scene::getWindow()
{
  return window;
}

std::shared_ptr<SDL_Renderer> Scene::getRenderer()
{
  return renderer;
}

Scene::Scene()
{
  window = std::make_shared<SDL_Window>(SDL_CreateWindow("Crystal Swirl", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0));
  renderer = std::make_shared<SDL_Renderer>(SDL_CreateRenderer(&*window, -1, SDL_RENDERER_ACCELERATED));
}
