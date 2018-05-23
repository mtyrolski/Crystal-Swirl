/*
mvxxx 2018
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
  /*
   * Class for giving a message
   */
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
		/* ===Methods=== */
	public:

    /*
     * Give a message
     */
		static void Log(const std::string&, const Logger::STREAM& = Logger::STREAM::CONSOLE, const Logger::TYPE& = Logger::TYPE::ERROR);
	private:

    /*
     * Broadcast message to different streams
     */
		static void sendMessage(const std::string& message, Logger::STREAM stream, std::string &prefix);

    /*
    * Broadcast message to console
    */
		static void consoleMessage(const std::string&message, std::string &prefix, std::time_t& time);

    /*
     * Broadcast message to file
     */
		static void fileMessage(const std::string&, std::string &prefix, std::time_t& time);

    /*
     * Adds prefix to message
     */
		static void setPrefix(Logger::TYPE type, std::string &prefix);
	};
}
