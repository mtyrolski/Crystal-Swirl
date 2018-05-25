/*
mvxxx 2018
https://github.com/mvxxx
*/

#include "Scene.hpp"

Scene::~Scene()
{
  SDL_DestroyRenderer(&*renderer);
  SDL_DestroyWindow(&*window);
  TTF_Quit();
  IMG_Quit();
  SDL_Quit();
}

void Scene::create(const std::shared_ptr<Loader>& loader)
{
  if ( IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG )
    mv::Logger::Log(mv::constants::error::scene::FAILED_IMG, mv::Logger::STREAM::BOTH, mv::Logger::TYPE::ERROR);


  if ( TTF_Init() == -1 )
    mv::Logger::Log(mv::constants::error::scene::FAILED_TTF, mv::Logger::STREAM::BOTH, mv::Logger::TYPE::ERROR);

  window = SDL_CreateWindow("Crystal Swirl", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, std::atoi(loader->getPathOf("WINDOW_DIMENSIONS_X", mv::constants::loader::CONFIG_MODE::TECHNICALITIES).c_str()), std::atoi(loader->getPathOf("WINDOW_DIMENSIONS_Y", mv::constants::loader::CONFIG_MODE::TECHNICALITIES).c_str()), 0);
  renderer = SDL_CreateRenderer(&*window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Window* Scene::getWindow() const
{
  return window;
}

SDL_Renderer* Scene::getRenderer() const
{
  return renderer;
}

bool Scene::isOpen() const
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


    case SDL_MOUSEBUTTONDOWN:
      if ( event.button.button == SDL_BUTTON_LEFT )
      {
        mouseClicked = true;
        mousePosition = { static_cast<float>(event.button.x),static_cast<float>(event.button.y) };
        break;
      }

    case SDL_KEYDOWN:
      if ( event.key.keysym.scancode == SDL_SCANCODE_ESCAPE )
      {
        opened = false;
        break;
        }
         
    default:
      break;
    }
  }
}

void Scene::clear(const std::vector<std::shared_ptr<mv::Entity>>& entities)
{
  SDL_RenderClear(renderer);

  for ( auto&var : entities )
  {
    if ( var->hasComponent<ProperBody>() )
    {
      auto PB = var->getComponent<ProperBody>();
      SDL_RenderCopy(renderer, PB->getTexture(), nullptr, &PB->getRect());    
    }
  }
}

bool Scene::mouseState() const
{
  return mouseClicked;
}

void Scene::setMouseState(bool flag)
{
  mouseClicked = flag;
}

const Vector2<float>& Scene::getMousePosition() const
{
  return mousePosition;
}

Scene::Scene()
  :opened(true)
{
}
