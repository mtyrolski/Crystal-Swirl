/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <map>
#include <string>

#include <SDL_image.h>

#include "ecs/entity/Entity.hpp"
#include "ecs/component/Text.hpp"
#include "wrappers/textWrapper_t.hpp"
#include "Config.hpp"

class TextMachine
{
	/* ===Objects=== */
public:
protected:
private:
  std::map<mv::constants::textTypes::TYPE, textWrapper_t> data;
	/* ===Methods=== */
public:
  TextMachine(uint16_t credits,uint16_t rate, const std::shared_ptr<SDL_Renderer>& renderer);

  const std::string& getText(mv::constants::textTypes::TYPE type);
  void setText(mv::constants::textTypes::TYPE type, const std::string& text);
  unsigned int getValue(mv::constants::textTypes::TYPE type);

  void display(const std::shared_ptr<SDL_Renderer>& renderer);
protected:
private:
  void init(uint16_t credits, uint16_t rate, const std::shared_ptr<SDL_Renderer>& renderer);
};
