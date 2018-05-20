/*
mvxxx 2018
https://github.com/mvxxx
*/

#include "Scene.hpp"

Scene::~Scene()
{
  SDL_DestroyRenderer(&*renderer);
  SDL_DestroyWindow(&*window);
  IMG_Quit();
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

void Scene::clear(const std::vector<std::shared_ptr<mv::Entity>>& entities)
{
  SDL_SetRenderDrawColor(&*renderer, 0, 100, 100, 255);
  SDL_RenderClear(&*renderer);

  for ( auto&var : entities )
  {
    if ( var->hasComponent<ProperBody>() )
    {
      auto PB = var->getComponent<ProperBody>();
      SDL_RenderCopy(&*renderer, &*PB->getTexture(), nullptr, &PB->getRect());
    }
    
  }
  SDL_RenderPresent(&*renderer);
}

Scene::Scene()
  :opened(true)
{
  if ( IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG )
  {
    mv::Logger::Log(mv::constants::error::scene::FAILED_IMG, mv::Logger::STREAM::BOTH, mv::Logger::TYPE::ERROR);
  }
  window = std::shared_ptr<SDL_Window>(SDL_CreateWindow("Crystal Swirl", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mv::constants::defaults::WINDOW_DIMENSIONS.x, mv::constants::defaults::WINDOW_DIMENSIONS.y, 0));
  renderer = std::shared_ptr<SDL_Renderer>(SDL_CreateRenderer(&*window, -1, SDL_RENDERER_ACCELERATED));
}
