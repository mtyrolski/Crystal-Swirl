/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "GraphicManager/GraphicManager.hpp"
#include "wrappers/Vector2.hpp"
#include "cache/Cache.hpp"
#include "Config.hpp"

/*
 * Component which represents real body of object
 */
class ProperBody
{
  /* ===Objects=== */
private:
  using type_id = mv::constants::texture::TEXTURE_ID;

  // Rect which keep physical properties of texture  
  SDL_Rect rect;

  //Kind of properbody
  type_id type;

  //Pointer do SDL_Texture / Container of texture
  SDL_Texture* texture;

  /* ===Methods=== */
public:

  /*
   * Sets type of object
   */
  void setType(const std::shared_ptr<GraphicManager>& graphicManager, type_id id, SDL_Renderer* renderer);

  /*
   * Returns pointer to texture of proper body
   */
  SDL_Texture* getTexture() const;

  /*
   * Returns type of object
   */
  type_id getType() const;

  /*
   * Sets position of object
   */
  void setPosition(const Vector2<float>& position);

  /*
   * Sets size of object
   */
  void setSize(const Vector2<float>& size);

  /*
   * Moves rect
   */
  void move(const Vector2<float>& vector);

  /*
   * Return position of rect
   */
  const Vector2<float>& getPosition() const;

  /*
   * Returns rect which keep physical properties of texture
   */
  const SDL_Rect& getRect() const;

private:

  /*
   * Loads texture to and assign it to properbody's texture
   */
  void loadTexture(const std::shared_ptr<GraphicManager>& graphicManager, SDL_Renderer* renderer);
};

inline void ProperBody::setType(const std::shared_ptr<GraphicManager>& graphicManager, type_id id, SDL_Renderer* renderer)
{
  type = id;
  loadTexture(graphicManager, renderer);
}

inline SDL_Texture* ProperBody::getTexture() const
{
  return texture;
}

inline mv::constants::texture::TEXTURE_ID ProperBody::getType() const
{
  return type;
}

inline void ProperBody::loadTexture(const std::shared_ptr<GraphicManager>& graphicManager, SDL_Renderer* renderer)
{
  texture = graphicManager->get(type);
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
  this->setPosition({ pos.x + vector.x, pos.y + vector.y });
}

inline const Vector2<float>& ProperBody::getPosition() const
{
  return{ rect.x + rect.w / 2.f, rect.y + rect.h / 2.f };
}

inline const SDL_Rect & ProperBody::getRect() const
{
  return rect;
}
