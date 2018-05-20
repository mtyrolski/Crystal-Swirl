/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <SDL.h>

#include "cache/Cache.hpp"
#include "wrappers/Point.hpp"
#include "Config.hpp"
#include "Component.hpp"

class ProperBody : public mv::Component
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
  ProperBody(std::shared_ptr<mv::Entity> owner, const std::shared_ptr<mv::Cache<SDL_Texture>>& cache, type_id id, const Point<float>& position);
  void setType(const std::shared_ptr<mv::Cache<SDL_Texture>>& cache, type_id id);
  type_id getType();
protected:
private:
};

inline ProperBody::ProperBody(std::shared_ptr<mv::Entity> owner, const std::shared_ptr<mv::Cache<SDL_Texture>>& cache, type_id id, const Point<float>& position)
  :Component(owner),type(id)
{
  texture = cache->get(mv::constants::texture::texturePath[mv::constants::texture::TEXTURE_ID::BUTTON_PLUS]);
}

inline void ProperBody::setType(const std::shared_ptr<mv::Cache<SDL_Texture>>& cache, type_id id)
{

}

inline mv::constants::texture::TEXTURE_ID ProperBody::getType()
{
  return type;
}