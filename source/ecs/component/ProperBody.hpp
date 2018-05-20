/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "cache/Cache.hpp"
#include "wrappers/Point.hpp"
#include "Config.hpp"

class ProperBody
{
  /* ===Objects=== */
public:
protected:
private:
  using type_id = mv::constants::texture::TEXTURE_ID;

  type_id type;
  std::shared_ptr<SDL_Texture> texture;
  /* ===Methods=== */
public:
  void setType(/*const std::shared_ptr<mv::Cache<SDL_Texture>>& cache, */type_id id, const std::shared_ptr<SDL_Renderer>& renderer);
  const std::shared_ptr<SDL_Texture>& getTexture();
  type_id getType();
protected:
private:
  void loadTexture(/*const std::shared_ptr<mv::Cache<SDL_Texture>>& cache,*/ const std::shared_ptr<SDL_Renderer>& renderer);
};

inline void ProperBody::setType(/*const std::shared_ptr<mv::Cache<SDL_Texture>>& cache,*/ type_id id, const std::shared_ptr<SDL_Renderer>& renderer)
{
  type = id;
  loadTexture(/*cache,*/renderer);
}

inline const std::shared_ptr<SDL_Texture>& ProperBody::getTexture()
{
  return texture;
}

inline mv::constants::texture::TEXTURE_ID ProperBody::getType()
{
  return type;
}

inline void ProperBody::loadTexture(/*const std::shared_ptr<mv::Cache<SDL_Texture>>& cache,*/ const std::shared_ptr<SDL_Renderer>& renderer)
{
  std::string path = "source/data/graphics/plus.png";
  auto surface = IMG_Load(path.c_str());
  texture = std::shared_ptr<SDL_Texture>(SDL_CreateTextureFromSurface(&*renderer, surface));
  SDL_FreeSurface(surface);
}
