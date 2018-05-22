/*
mvxxx 2018
https://github.com/mvxxx
*/
#pragma once

#include <map>
#include <memory>

#include <SDL.h>
#include <SDL_image.h>

#include "Config.hpp"

class GraphicManager
{
	/* ===Objects=== */
public:
protected:
private:
  std::map<mv::constants::texture::TEXTURE_ID, std::shared_ptr<SDL_Texture>> texturePack;
	/* ===Methods=== */
public:
  void loadTextures(const std::shared_ptr<SDL_Renderer>& renderer);
protected:
private:
  void loadSingleTexture(const std::shared_ptr<SDL_Renderer>& renderer, mv::constants::texture::TEXTURE_ID type);
};
