/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <string>
#include <fstream>

#include "Config.hpp"


class Loader
{
  /* ===Methods=== */
public:

  /*
   * Recognizes the mode,
   * Searches for the key in the file,
   * Returns the value
   */
  const std::string& getPathOf(const std::string& name, const mv::constants::loader::MODE& mode);
private:

  /*
   * Searches for the key in the file,
   * Returns the value
   */
  const std::string& findValue(const std::string& name, const std::string& path);
};
