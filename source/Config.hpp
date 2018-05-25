/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <map>
#include <string>
#include <wrappers/Vector2.hpp>

namespace mv
{
  namespace constants
  {
    namespace loader
    {
      constexpr auto GRAPHIC_CONFIG = "source/data/config/graphic.txt";
      constexpr auto AUDIO_CONFIG = "source/data/config/audio.txt";
      constexpr auto TECHNICALITIES_CONFIG = "source/data/config/technicalities.txt";

      enum class MODE
      {
        GRAPHIC,
        AUDIO,
        TECHNICALITIES
      };
    }

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

      /*id/Key*/
      const std::map<TEXTURE_ID, std::string> textureKey
      {
        { TEXTURE_ID::BUTTON_PLUS,"PLUS" },
        { TEXTURE_ID::BUTTON_MINUS,"MINUS" },
        { TEXTURE_ID::CRYSTAL_RED,"CRYSTAL_RED" },
        { TEXTURE_ID::CRYSTAL_GREEN,"CRYSTAL_GREEN" },
        { TEXTURE_ID::CRYSTAL_BLUE,"CRYSTAL_BLUE" },
        { TEXTURE_ID::RATE,"RATE" },
        { TEXTURE_ID::PRIZE,"PRIZE" },
        { TEXTURE_ID::CREDITS,"CREDITS" },
        { TEXTURE_ID::PLAY,"PLAY" },
        { TEXTURE_ID::BACKGROUND, "BACKGROUND"}
      };

      constexpr auto BASIC_TEXTURE_PATH = "source/data/graphics/";
    }

    namespace font
    {
      constexpr auto FONT_PATH = "source/data/font/ARLRDBD.ttf";
      constexpr auto FONT_SIZE = 25;
      const SDL_Color FONT_COLOR = { 0,0,0 };
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