#include "GraphicManager.hpp"

void GraphicManager::loadTextures(const std::shared_ptr<SDL_Renderer>& renderer)
{
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::BUTTON_MINUS);
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::BUTTON_PLUS);
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::CREDITS);
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::CRYSTAL_BLUE);
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::CRYSTAL_GREEN);
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::CRYSTAL_RED);
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::CREDITS);
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::PRIZE);
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::RATE);
}

void GraphicManager::loadSingleTexture(const std::shared_ptr<SDL_Renderer>& renderer, mv::constants::texture::TEXTURE_ID type)
{
  std::string path = mv::constants::texture::texturePath.at(type);
  auto surface = IMG_Load(path.c_str());
  texturePack[type] = std::make_shared<SDL_Texture>(SDL_CreateTextureFromSurface(&*renderer, surface));
  SDL_FreeSurface(surface);
}
