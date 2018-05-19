/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <wrappers/Point.hpp>

namespace mv
{
	namespace constants
	{
		namespace error
		{
			namespace scene
			{
				constexpr auto T_DOES_NOT_INHERT_FROM_DRAWABLE = "T doesn't inhert from sf::Drawable. It cannont be drawn by this method";
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
	}
}