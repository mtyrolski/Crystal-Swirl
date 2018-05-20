/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <map>
#include <string>
#include <wrappers/Point.hpp>

namespace mv
{
	namespace constants
	{
		namespace error
		{
			namespace scene
			{
        constexpr auto FAILED_IMG = "Failed to init SDL_Image";
      }

			namespace fileManager
			{
				constexpr auto PATH_IS_NOT_CORRET = "Given path is not correct";
			}

			namespace singleton
			{
				constexpr auto SINGLETON_NOT_INITED = "Singleon must be inited!";
				constexpr auto SINGLETON_INITED = "Singleon has been inited before";
			}

			namespace soundObject
			{
				constexpr auto ALREADY_EXIST = "Sound with given name already exists";
				constexpr auto DOES_NOT_EXIST_IN_SYSTEM = "Sound with given doesn't exist in system";
			}
		}

		namespace defaults
		{
			constexpr auto EMPTY = "EMPTY";
			constexpr auto UNNAMED = "unnamed";
			const Point<int> WINDOW_DIMENSIONS = { 800,600 };
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
        CREDITS
      };
      /*id/path*/
      const std::map<TEXTURE_ID, std::string> texturePath
      {
        {TEXTURE_ID::BUTTON_PLUS,"source/data/graphics/plus.png"}
      };
    }
	}
}