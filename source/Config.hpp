/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <map>
#include <string>
#include <wrappers/Vector2.hpp>

namespace mv
{
  namespace constants
  {
    namespace error
    {
      namespace scene
      {
        constexpr auto FAILED_IMG = "Failed to init SDL_Image";
        constexpr auto FAILED_TTF = "Failed to init SDL_TTF";
      }

      namespace soundObject
      {
        constexpr auto ALREADY_EXIST = "Sound with given name already exists";
        constexpr auto DOES_NOT_EXIST_IN_SYSTEM = "Sound with given doesn't exist in system";
      }

      namespace banditMachine
      {
        constexpr auto PROCESSING = "You can't start new simulate because bandit machine is processing now.";
      }

      namespace textMachine
      {
        constexpr auto NOT_ENOUGH_MONEY = "You have't got enough money to do that.";
        constexpr auto POSITIVE_RATE = "Rate must be positive value";
      }
    }

    namespace defaults
    {
      constexpr auto EMPTY = "EMPTY";
      constexpr auto UNNAMED = "unnamed";
      const Vector2<int> WINDOW_DIMENSIONS = { 800,600 };
      constexpr auto BANDIT_MACHINE_DELAY = 0.5f;
      constexpr auto BANDIT_MACHINE_SIMULATION_TIME = 3.f;
      constexpr auto CREDITS = 1000;
      constexpr auto RATE = 50;
      constexpr auto DELTA_RATE = 50;
    }

    namespace texture
    {
      enum class TEXTURE_ID
      {
        BUTTON_PLUS,
        BUTTON_MINUS,
        RATE,
        CRYSTAL_RED,
        CRYSTAL_GREEN,
        CRYSTAL_BLUE,
        PRIZE,
        CREDITS,
        PLAY,
        BACKGROUND
      };
      /*id/path*/
      const std::map<TEXTURE_ID, std::string> texturePath
      {
        { TEXTURE_ID::BUTTON_PLUS,"source/data/graphics/plus.png" },
        { TEXTURE_ID::BUTTON_MINUS,"source/data/graphics/minus.png" },
        { TEXTURE_ID::CRYSTAL_RED,"source/data/graphics/crystal_red.png" },
        { TEXTURE_ID::CRYSTAL_GREEN,"source/data/graphics/crystal_green.png" },
        { TEXTURE_ID::CRYSTAL_BLUE,"source/data/graphics/crystal_blue.png" },
        { TEXTURE_ID::RATE,"source/data/graphics/rate.png" },
        { TEXTURE_ID::PRIZE,"source/data/graphics/prize.png" },
        { TEXTURE_ID::CREDITS,"source/data/graphics/credits.png" },
        { TEXTURE_ID::PLAY,"source/data/graphics/play.png" },
        { TEXTURE_ID::BACKGROUND, "source/data/graphics/background.png"}
      };
    }

    namespace font
    {
      constexpr auto FONT_PATH = "source/data/font/ARLRDBD.ttf";
      constexpr auto FONT_SIZE = 25;
      const SDL_Color FONT_COLOR = { 0,0,0};
    }

    namespace textTypes
    {
      enum class TYPE
      {
        RATE,
        PRIZE,
        CREDITS
      };
    }
  }
}