/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <map>
#include <string>

#include <SDL_render.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL.h>

#include "ecs/component/text/Text.hpp"
#include "wrappers/textWrapper_t.hpp"
#include "ecs/entity/Entity.hpp"
#include "Config.hpp"

/*
 * Class which manages each text on the screen
 */
class TextMachine
{
  /* ===Objects=== */
private:

  //cointainer to keep text data
  std::map<mv::constants::textTypes::TYPE, textWrapper_t> data;
  /* ===Methods=== */
public:
  TextMachine(uint16_t credits, uint16_t rate, SDL_Renderer* renderer);

  /*
   * Returns text | classic getter
   */
  const std::string& getText(mv::constants::textTypes::TYPE type);

  /*
   *  Sets text | classic setter
   */
  void setText(mv::constants::textTypes::TYPE type, const std::string& text, SDL_Renderer* renderer);
 
  /*
   * Returns value from text with given type
   */
  int getValue(mv::constants::textTypes::TYPE type);

  /*
   * Display all texts
   */
  void display(SDL_Renderer* renderer);
private:

  /*
   * Initialise data
   */
  void init(uint16_t credits, uint16_t rate, SDL_Renderer* renderer);
};
