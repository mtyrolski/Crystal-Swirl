#include "Text.hpp"

void Text::init(const std::string & fontPath, int fontSize, const std::string & message, const SDL_Color & color, const std::shared_ptr<SDL_Renderer>& renderer)
{
  textTexture = loadFont(fontPath, fontSize, message, color, renderer);
  SDL_QueryTexture(&*textTexture, nullptr, nullptr, &textRect.w, &textRect.h);
}

void Text::display(const std::shared_ptr<SDL_Renderer>& renderer)
{
  SDL_RenderCopy(&*renderer, &*textTexture, nullptr, &textRect);
}

SDL_Texture* Text::loadFont(const std::string & fontPath, int fontSize, const std::string & message, const SDL_Color & color, const std::shared_ptr<SDL_Renderer>& renderer)
{
  TTF_Font* font = TTF_OpenFont(fontPath.c_str(), fontSize);
  auto textSurface = TTF_RenderText_Solid(font, message.c_str(), color);
  auto tempTexture = SDL_CreateTextureFromSurface(&*renderer, textSurface);
  SDL_FreeSurface(textSurface);
  return tempTexture;
}

void Text::setPosition(const Vector2<float>& position)
{
  textRect.x = position.x - textRect.w / 2.f;
  textRect.y = position.y - textRect.h / 2.f;
}
