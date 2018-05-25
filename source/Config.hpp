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
    namespace audio
    {
      enum class AUDIO_ID
      {
        SOUNDTRACK,
        CLICK,
        PLAY
      };

      const std::map<AUDIO_ID, std::string> audioKey
      {
        { AUDIO_ID::SOUNDTRACK,"SOUNDTRACK" },
        { AUDIO_ID::CLICK,"CLICK" },
        { AUDIO_ID::PLAY,"PLAY" },
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

    namespace textTypes
    {
      enum class TYPE
      {
        RATE,
        PRIZE,
        CREDITS
      };
    }

    namespace loader
    {
      constexpr auto GRAPHIC_CONFIG = "source/data/config/graphic.txt";
      constexpr auto AUDIO_CONFIG = "source/data/config/audio.txt";
      constexpr auto TECHNICALITIES_CONFIG = "source/data/config/technicalities.txt";

      enum class CONFIG_MODE
      {
        GRAPHIC,
        AUDIO,
        TECHNICALITIES
      };

      enum class STORAGE_MODE
      {
        STORE,
        FREE
      };
    }
  }
}