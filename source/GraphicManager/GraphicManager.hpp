/*
mvxxx 2018
https://github.com/mvxxx
*/
#pragma once

#include <map>
#include <memory>

#include <SDL.h>
#include <SDL_image.h>

#include "Loader/Loader.hpp"
#include "logger/Logger.hpp"
#include "ConfigSrc.hpp"


/*
 * Class which represents container of textures
 */
class GraphicManager
{
	/* ===Objects=== */
private:

  //map which support finding a texture by TEXTURE_ID
  std::map<mv::constants::texture::TEXTURE_ID, SDL_Texture*> texturePack;
	/* ===Methods=== */
public:

  /*
   * Loads all textures
   */
  void loadTextures(SDL_Renderer* renderer, const std::shared_ptr<Loader>& loader);

  /*
   * Finds and returns texture with given ID
   */
  SDL_Texture* get(mv::constants::texture::TEXTURE_ID type);
private:

  /*
   * Loads one texture
   */
  void loadSingleTexture(SDL_Renderer* renderer, mv::constants::texture::TEXTURE_ID type, const std::shared_ptr<Loader>& loader);
};
