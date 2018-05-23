#include "textMachine.hpp"

TextMachine::TextMachine(uint16_t credits, uint16_t rate, const std::shared_ptr<SDL_Renderer>& renderer)
{
  init(credits, rate, renderer);
}

const std::string & TextMachine::getText(mv::constants::textTypes::TYPE type)
{
  return data[type].text;
}

void TextMachine::setText(mv::constants::textTypes::TYPE type, const std::string & text, const std::shared_ptr <SDL_Renderer> & renderer)
{
  data[type].text = text;
  data[type].entity->getComponent<Text>()->setText(mv::constants::font::FONT_PATH, mv::constants::font::FONT_SIZE, text, mv::constants::font::FONT_COLOR, renderer);
}

int TextMachine::getValue(mv::constants::textTypes::TYPE type)
{
  return std::atoi(data[type].text.c_str());
}

void TextMachine::display(const std::shared_ptr<SDL_Renderer>& renderer)
{
  for ( auto&var : data )
    var.second.entity->getComponent<Text>()->display(renderer);

  SDL_RenderPresent(&*renderer);
}

void TextMachine::init(uint16_t credits, uint16_t rate, const std::shared_ptr<SDL_Renderer>& renderer)
{
  using namespace mv::constants;

  data = { {textTypes::TYPE::CREDITS, textWrapper_t(std::to_string(credits),std::make_shared<mv::Entity>()) },
         { textTypes::TYPE::PRIZE, textWrapper_t("----",std::make_shared<mv::Entity>())},
         {textTypes::TYPE::RATE, textWrapper_t(std::to_string(rate),std::make_shared<mv::Entity>())} };
  for ( auto&var : data )
  {
    var.second.entity->addComponent<Text>();
    var.second.entity->getComponent<Text>()->init(mv::constants::font::FONT_PATH, mv::constants::font::FONT_SIZE, data[var.first].text, mv::constants::font::FONT_COLOR, renderer);
  }


  data[textTypes::TYPE::CREDITS].entity->getComponent<Text>()->setPosition({ 0.8975f*defaults::WINDOW_DIMENSIONS.x,0.866f*defaults::WINDOW_DIMENSIONS.y });
  data[textTypes::TYPE::PRIZE].entity->getComponent<Text>()->setPosition({ 0.8975f*defaults::WINDOW_DIMENSIONS.x,0.783f*defaults::WINDOW_DIMENSIONS.y });
  data[textTypes::TYPE::RATE].entity->getComponent<Text>()->setPosition({ 0.1875f*defaults::WINDOW_DIMENSIONS.x,0.833f*defaults::WINDOW_DIMENSIONS.y });
}
