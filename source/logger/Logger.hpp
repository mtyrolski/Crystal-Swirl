/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <ctime>


namespace mv
{
	class Logger
	{
		/* ===Objects=== */
	public:
		enum class STREAM
		{
			CONSOLE = 0,
			FILE = 1,
			BOTH = 2
		};

		enum class TYPE
		{
			INFO = 0,
			SUGGESTION = 1,
			WARNING = 2,
			ERROR = 3
		};
	protected:
	private:
		/* ===Methods=== */
	public:
		static void Log(const std::string&, const Logger::STREAM& = Logger::STREAM::CONSOLE, const Logger::TYPE& = Logger::TYPE::ERROR);
	protected:
	private:

		static void sendMessage(const std::string& message, Logger::STREAM stream, std::string &prefix);

		static void consoleMessage(const std::string&message, std::string &prefix, std::time_t& time);

		static void fileMessage(const std::string&, std::string &prefix, std::time_t& time);

		static void setPrefix(Logger::TYPE type, std::string &prefix);
	};
}
