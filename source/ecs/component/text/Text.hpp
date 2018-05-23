/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <string>
#include <memory>

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_render.h>

#include "wrappers/Vector2.hpp"
#include "ecs/entity/Entity.hpp"

class Text
{
	/* ===Objects=== */
public:
protected:
private:
  SDL_Texture* textTexture;
  SDL_Rect textRect;
	/* ===Methods=== */
public:
  void init(const std::string& fontPath, int fontSize, const std::string& message, const SDL_Color& color, const std::shared_ptr<SDL_Renderer>& renderer);
  void display(const std::shared_ptr<SDL_Renderer>& renderer);
  void setPosition(const Vector2<float>& position);
  void setText(const std::string& fontPath, int fontSize, const std::string& message, const SDL_Color& color, const std::shared_ptr<SDL_Renderer>& renderer);
  void setSize(const Vector2<float>& size);
protected:
private:
  SDL_Texture* getTextTexture(const std::string& fontPath, int fontSize, const std::string& message, const SDL_Color& color, const std::shared_ptr<SDL_Renderer>& renderer);
};


