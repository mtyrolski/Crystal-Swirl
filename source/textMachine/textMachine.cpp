#include "textMachine.hpp"

TextMachine::TextMachine(uint16_t credits, uint16_t rate, const std::shared_ptr<SDL_Renderer>& renderer)
{
  init(credits, rate, renderer);
}

const std::string & TextMachine::getText(mv::constants::textTypes::TYPE type)
{
  return data[type].text;
}

void TextMachine::setText(mv::constants::textTypes::TYPE type, const std::string & text)
{
  data[type].text = text;
}

int TextMachine::getValue(mv::constants::textTypes::TYPE type)
{
  return std::atoi(data[type].text.c_str());
}

void TextMachine::display(const std::shared_ptr<SDL_Renderer>& renderer)
{
  for ( auto&var : data )
    var.second.entity->getComponent<Text>()->display(renderer);
}

void TextMachine::init(uint16_t credits, uint16_t rate, const std::shared_ptr<SDL_Renderer>& renderer)
{
  data = { {mv::constants::textTypes::TYPE::CREDITS, textWrapper_t(std::to_string(credits),std::make_shared<mv::Entity>()) },
         { mv::constants::textTypes::TYPE::PRIZE, textWrapper_t("0",std::make_shared<mv::Entity>())},
         {mv::constants::textTypes::TYPE::RATE, textWrapper_t(std::to_string(rate),std::make_shared<mv::Entity>())} };
  for ( auto&var : data )
  {
    var.second.entity->addComponent<Text>();
    var.second.entity->getComponent<Text>()->init(mv::constants::font::FONT_PATH, mv::constants::font::FONT_SIZE, data[var.first].text, mv::constants::font::FONT_COLOR, renderer);
  }
  using namespace mv::constants::defaults;
  //data[mv::constants::textTypes::TYPE::CREDITS].entity->getComponent<Text>()->setPosition({ 0.8375f*WINDOW_DIMENSIONS.x,0.866f*WINDOW_DIMENSIONS.y });
 // data[mv::constants::textTypes::TYPE::PRIZE].entity->getComponent<Text>()->setPosition({ 0.8375f*WINDOW_DIMENSIONS.x,0.783f*WINDOW_DIMENSIONS.y });
 // data[mv::constants::textTypes::TYPE::RATE].entity->getComponent<Text>()->setPosition({ 0.1875f*WINDOW_DIMENSIONS.x,0.833f*WINDOW_DIMENSIONS.y });

}
