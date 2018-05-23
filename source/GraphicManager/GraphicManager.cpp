#include "GraphicManager.hpp"

void GraphicManager::loadTextures(const std::shared_ptr<SDL_Renderer>& renderer)
{
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::BUTTON_MINUS);
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::BUTTON_PLUS);
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::CREDITS);
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::CRYSTAL_BLUE);
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::CRYSTAL_GREEN);
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::CRYSTAL_RED);
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::PLAY);
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::PRIZE);
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::RATE);
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::BACKGROUND);
}

SDL_Texture* GraphicManager::get(mv::constants::texture::TEXTURE_ID type)
{
  return texturePack[type];
}

void GraphicManager::loadSingleTexture(const std::shared_ptr<SDL_Renderer>& renderer, mv::constants::texture::TEXTURE_ID type)
{
  std::string path = mv::constants::texture::texturePath.at(type);
  auto surface = IMG_Load(path.c_str());
  texturePack[type] = SDL_CreateTextureFromSurface(&*renderer, surface);
  SDL_FreeSurface(surface);
}
