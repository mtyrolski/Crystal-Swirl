/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <string>
#include <memory>

#include <SDL_render.h>
#include <SDL_ttf.h>
#include <SDL.h>

#include "ecs/entity/Entity.hpp"
#include "wrappers/Vector2.hpp"

/*
 *component which is used for init, keep and display text
 */
class Text
{
	/* ===Objects=== */
private:
  
  // Pointer do SDL_Texture / Container of texture
  SDL_Texture* textTexture;

  // Rect which keep physical properties of texture
  SDL_Rect textRect;
	/* ===Methods=== */
public:

  /*
   *Initialise texture and its physical properties
   */
  void init(const std::string& fontPath, int fontSize, const std::string& message, const SDL_Color& color, SDL_Renderer* renderer);

  /*
   * Displays text on the screen
   */
  void display(SDL_Renderer* renderer) const;

  /*
   * Sets position of rect (which is equivalent with texture)
   */
  void setPosition(const Vector2<float>& position) ; 

  /*
   * Sets text and put it on texture
   */
  void setText(const std::string& fontPath, int fontSize, const std::string& message, const SDL_Color& color, SDL_Renderer* renderer);
 
  /*
   * Sets size of rect (which is equivalent with size of texture)
   */
  void setSize(const Vector2<float>& size);
private:

  /*
   * Creates texture and returns pointer to it.
   */
  SDL_Texture* getTextTexture(const std::string& fontPath, int fontSize, const std::string& message, const SDL_Color& color, SDL_Renderer* renderer) const;
};


