/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "cache/Cache.hpp"
#include "wrappers/Vector2.hpp"
#include "Config.hpp"

class ProperBody
{
  /* ===Objects=== */
public:
protected:
private:
  using type_id = mv::constants::texture::TEXTURE_ID;
  SDL_Rect rect;
  type_id type;
  std::shared_ptr<SDL_Texture> texture;
  /* ===Methods=== */
public:
  void setType(const std::shared_ptr<mv::Cache<SDL_Texture>>& cache, type_id id, const std::shared_ptr<SDL_Renderer>& renderer);
  const std::shared_ptr<SDL_Texture>& getTexture();
  type_id getType();
protected:
private:
  void loadTexture(const std::shared_ptr<mv::Cache<SDL_Texture>>& cache, const std::shared_ptr<SDL_Renderer>& renderer);
  void setPosition(const Vector2<float>& position);
  void setSize(const Vector2<float>& size);
  void move(const Vector2<float>& vector);

  const Vector2<float>& getPosition();

};

inline void ProperBody::setType(const std::shared_ptr<mv::Cache<SDL_Texture>>& cache, type_id id, const std::shared_ptr<SDL_Renderer>& renderer)
{
  type = id;
  loadTexture(cache, renderer);
}

inline const std::shared_ptr<SDL_Texture>& ProperBody::getTexture()
{
  return texture;
}

inline mv::constants::texture::TEXTURE_ID ProperBody::getType()
{
  return type;
}

inline void ProperBody::loadTexture(const std::shared_ptr<mv::Cache<SDL_Texture>>& cache, const std::shared_ptr<SDL_Renderer>& renderer)
{
  std::string path = mv::constants::texture::texturePath.at(type);
  auto surface = IMG_Load(path.c_str());
  texture = std::shared_ptr<SDL_Texture>(SDL_CreateTextureFromSurface(&*renderer, surface));
  SDL_FreeSurface(surface);
}

inline void ProperBody::setPosition(const Vector2<float>& position)
{
  rect.x = position.x - rect.w / 2.f;
  rect.y = position.y - rect.h / 2.f;
}

inline void ProperBody::setSize(const Vector2<float>& size)
{
  rect.w = size.x;
  rect.h = size.y;
}

inline void ProperBody::move(const Vector2<float>& vector)
{
  auto pos = this->getPosition();
  this->setPosition({pos.x + vector.x, pos.y + vector.y});
}

inline const Vector2<float>& ProperBody::getPosition()
{
  return{ rect.x + rect.w / 2.f, rect.y + rect.h / 2.f };
}
