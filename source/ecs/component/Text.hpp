/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <string>
#include <memory>

#include <SDL.h>
#include <SDL_ttf.h>

#include "wrappers/Vector2.hpp"
#include "ecs/entity/Entity.hpp"

class Text
{
	/* ===Objects=== */
public:
protected:
private:
  std::shared_ptr<SDL_Texture> textTexture;
  SDL_Rect textRect;
	/* ===Methods=== */
public:
  void init(const std::string& fontPath, int fontSize, const std::string& message, const SDL_Color& color, const std::shared_ptr<SDL_Renderer>& renderer);
  void display(const std::shared_ptr<SDL_Renderer>& renderer);
  const std::shared_ptr<SDL_Texture>& loadFont(const std::string& fontPath, int fontSize, const std::string& message, const SDL_Color& color, const std::shared_ptr<SDL_Renderer>& renderer);
  void setPosition(const Vector2<float>& position);

protected:
private:
};


inline void Text::init(const std::string & fontPath, int fontSize, const std::string & message, const SDL_Color & color, const std::shared_ptr<SDL_Renderer>& renderer)
{
  textTexture = loadFont(fontPath, fontSize, message, color, renderer);
  SDL_QueryTexture(&*textTexture, nullptr, nullptr, &textRect.w, &textRect.h);
}

inline void Text::display(const std::shared_ptr<SDL_Renderer>& renderer)
{
  SDL_RenderCopy(&*renderer, &*textTexture, nullptr, &textRect);
}

inline const std::shared_ptr<SDL_Texture>& Text::loadFont(const std::string & fontPath, int fontSize, const std::string & message, const SDL_Color & color, const std::shared_ptr<SDL_Renderer>& renderer)
{
  TTF_Font* font = TTF_OpenFont(fontPath.c_str(), fontSize);
  auto textSurface = TTF_RenderText_Solid(font, message.c_str(), color);
  auto tempTexture = std::make_shared<SDL_Texture>(SDL_CreateTextureFromSurface(&*renderer, textSurface));
  SDL_FreeSurface(textSurface);
  return tempTexture;
}

inline void Text::setPosition(const Vector2<float>& position)
{
  textRect.x = position.x - textRect.w / 2.f;
  textRect.y = position.y - textRect.h / 2.f;
}
