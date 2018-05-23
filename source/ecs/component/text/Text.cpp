/*
mvxxx 2018
https://github.com/mvxxx
*/

#include "Text.hpp"

void Text::init(const std::string & fontPath, int fontSize, const std::string & message, const SDL_Color & color, SDL_Renderer* renderer)
{
  textTexture = getTextTexture(fontPath, fontSize, message, color, renderer);
  SDL_QueryTexture(&*textTexture, nullptr, nullptr, &textRect.w, &textRect.h);
}

void Text::display(SDL_Renderer* renderer) const
{
  SDL_RenderCopy(&*renderer, &*textTexture, nullptr, &textRect);
}

SDL_Texture* Text::getTextTexture(const std::string & fontPath, int fontSize, const std::string & message, const SDL_Color & color, SDL_Renderer* renderer) const
{
  TTF_Font* font = TTF_OpenFont(fontPath.c_str(), fontSize);
  auto textSurface = TTF_RenderText_Solid(font, message.c_str(), color);
  auto tempTexture = SDL_CreateTextureFromSurface(&*renderer, textSurface);
  SDL_FreeSurface(textSurface);
  TTF_CloseFont(font);
  return tempTexture;
}

void Text::setPosition(const Vector2<float>& position)
{
  textRect.x = position.x - textRect.w / 2.f;
  textRect.y = position.y - textRect.h / 2.f;
}

void Text::setText(const std::string & fontPath, int fontSize, const std::string & message, const SDL_Color & color, SDL_Renderer* renderer)
{
  textTexture = getTextTexture(fontPath, fontSize, message, color, renderer);
}

void Text::setSize(const Vector2<float>& size)
{
  textRect.w = size.x;
  textRect.h = size.y;
}
