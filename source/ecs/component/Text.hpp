/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <string>
#include <memory>

#include <SDL.h>
#include <SDL_ttf.h>


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
  Text(const std::string& fontPath, int fontSize, const std::string& message, const SDL_Color& color, const std::shared_ptr<SDL_Renderer>& renderer);
  void display() const;
  std::shared_ptr<SDL_Texture> loadFont(const std::string& fontPath, int fontSize, const std::string& message, const SDL_Color& color, const std::shared_ptr<SDL_Renderer>& renderer);
protected:
private:
};


Text::Text(const std::string& fontPath, int fontSize, const std::string& message, const SDL_Color& color, const std::shared_ptr<SDL_Renderer>& renderer)
{
    textTexture = loadFont(fontPath,fontSize,message,color,renderer);
    SDL_QueryTexture(&*textTexture, nullptr, nullptr, &textRect.w, &textRect.h);
}

inline std::shared_ptr<SDL_Texture> Text::loadFont(const std::string & fontPath, int fontSize, const std::string & message, const SDL_Color & color, const std::shared_ptr<SDL_Renderer>& renderer)
{
  TTF_Font* font = TTF_OpenFont(fontPath.c_str(), fontSize);
  auto textSurface = TTF_RenderText_Solid(font, message.c_str(), color);
  auto textTexture = std::make_shared<SDL_Texture>(SDL_CreateTextureFromSurface(&*renderer, textSurface));
  SDL_FreeSurface(textSurface);
  return textTexture;
}
