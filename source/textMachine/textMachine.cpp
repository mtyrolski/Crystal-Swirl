#include "textMachine.hpp"

TextMachine::TextMachine(uint16_t credits, uint16_t rate,  SDL_Renderer* renderer, const std::shared_ptr<Loader>& loaderPtr)
  :loader(loaderPtr)
{
  init(credits, rate, renderer);
}

const std::string & TextMachine::getText(mv::constants::textTypes::TYPE type)
{
  return data[type].text;
}

void TextMachine::setText(mv::constants::textTypes::TYPE type, const std::string & text, SDL_Renderer* renderer)
{
  using namespace mv::constants;
  data[type].text = text;
  data[type].entity->getComponent<Text>()->
      setText(loader->getPathOf("FONT_PATH",loader::CONFIG_MODE::GRAPHIC,loader::STORAGE_MODE::STORE), 
      std::atoi(loader->getPathOf("FONT_SIZE", loader::CONFIG_MODE::GRAPHIC, loader::STORAGE_MODE::STORE).c_str()),
      text,
      { static_cast<const uint8_t>(std::atoi(loader->getPathOf("FONT_COLOR_R", loader::CONFIG_MODE::GRAPHIC, loader::STORAGE_MODE::STORE).c_str())),
        static_cast<const uint8_t>(std::atoi(loader->getPathOf("FONT_COLOR_G", loader::CONFIG_MODE::GRAPHIC, loader::STORAGE_MODE::STORE).c_str())),
        static_cast<const uint8_t>(std::atoi(loader->getPathOf("FONT_COLOR_B", loader::CONFIG_MODE::GRAPHIC, loader::STORAGE_MODE::STORE).c_str())) },
      renderer);
}

int TextMachine::getValue(mv::constants::textTypes::TYPE type)
{
  return std::atoi(data[type].text.c_str());
}

void TextMachine::display(SDL_Renderer* renderer)
{
  for ( auto&var : data )
    var.second.entity->getComponent<Text>()->display(renderer);

  SDL_RenderPresent(renderer);
}

void TextMachine::init(uint16_t credits, uint16_t rate, SDL_Renderer* renderer)
{
  using namespace mv::constants;

  data = { {textTypes::TYPE::CREDITS, textWrapper_t(std::to_string(credits),std::make_shared<mv::Entity>()) },
         { textTypes::TYPE::PRIZE, textWrapper_t("----",std::make_shared<mv::Entity>())},
         {textTypes::TYPE::RATE, textWrapper_t(std::to_string(rate),std::make_shared<mv::Entity>())} };
  for ( auto&var : data )
  {
    var.second.entity->addComponent<Text>();
    var.second.entity->getComponent<Text>()->init(
      loader->getPathOf("FONT_PATH", loader::CONFIG_MODE::GRAPHIC, loader::STORAGE_MODE::STORE),
      std::atoi(loader->getPathOf("FONT_SIZE", loader::CONFIG_MODE::GRAPHIC, loader::STORAGE_MODE::STORE).c_str())
      , data[var.first].text,
      { static_cast<const uint8_t>(std::atoi(loader->getPathOf("FONT_COLOR_R", loader::CONFIG_MODE::GRAPHIC, loader::STORAGE_MODE::STORE).c_str())),
      static_cast<const uint8_t>(std::atoi(loader->getPathOf("FONT_COLOR_G", loader::CONFIG_MODE::GRAPHIC, loader::STORAGE_MODE::STORE).c_str())),
      static_cast<const uint8_t>(std::atoi(loader->getPathOf("FONT_COLOR_B", loader::CONFIG_MODE::GRAPHIC, loader::STORAGE_MODE::STORE).c_str())) },
      renderer);
  }

  const Vector2<float> WINDOW_DIMENSIONS =
  { static_cast<float>(std::atof(loader->getPathOf("WINDOW_DIMENSIONS_X", mv::constants::loader::CONFIG_MODE::TECHNICALITIES).c_str())),
    static_cast<float>(std::atof(loader->getPathOf("WINDOW_DIMENSIONS_Y", mv::constants::loader::CONFIG_MODE::TECHNICALITIES).c_str())) };


  data[textTypes::TYPE::CREDITS].entity->getComponent<Text>()->setPosition({ 0.8975f*WINDOW_DIMENSIONS.x,0.866f*WINDOW_DIMENSIONS.y });
  data[textTypes::TYPE::PRIZE].entity->getComponent<Text>()->setPosition({ 0.8975f*WINDOW_DIMENSIONS.x,0.783f*WINDOW_DIMENSIONS.y });
  data[textTypes::TYPE::RATE].entity->getComponent<Text>()->setPosition({ 0.1875f*WINDOW_DIMENSIONS.x,0.833f*WINDOW_DIMENSIONS.y });
}
