#include "GraphicManager.hpp"

void GraphicManager::loadTextures(SDL_Renderer* renderer, const std::shared_ptr<Loader>& loader)
{
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::BUTTON_MINUS, loader);
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::BUTTON_PLUS, loader);
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::CREDITS, loader);
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::SYMBOL_1, loader);
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::SYMBOL_2, loader);
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::SYMBOL_3, loader);
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::PLAY, loader);
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::PRIZE, loader);
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::RATE, loader);
  loadSingleTexture(renderer, mv::constants::texture::TEXTURE_ID::BACKGROUND, loader);
}

SDL_Texture* GraphicManager::get(mv::constants::texture::TEXTURE_ID type)
{
  return texturePack[type];
}

void GraphicManager::loadSingleTexture(SDL_Renderer* renderer, mv::constants::texture::TEXTURE_ID type, const std::shared_ptr<Loader>& loader)
{
  std::string path = mv::constants::texture::BASIC_TEXTURE_PATH + loader->getValueByKey(mv::constants::texture::textureKey.at(type), mv::constants::loader::CONFIG_MODE::GRAPHIC);
  auto surface = IMG_Load(path.c_str());
  texturePack[type] = SDL_CreateTextureFromSurface(&*renderer, surface);
  SDL_FreeSurface(surface);
}
