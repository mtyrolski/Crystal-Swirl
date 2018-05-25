/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once
#include <fstream>
#include <string>
#include <map>


#include "Config.hpp"


/*
* Class for loading data
*/
class Loader
{
  /* ===Objects=== */

  /*
  * Store often used data
  * Used only when storage mode is enabled
  * name(key) / data
  */
  std::map<std::string, std::string> storage;

  /* ===Methods=== */
public:

  /*
   * Recognizes the mode,
   * Searches for the key in the file,
   * Returns the value
   */
   std::string getPathOf(const std::string& name,
     const mv::constants::loader::CONFIG_MODE& configMode,
     const mv::constants::loader::STORAGE_MODE storageMode = mv::constants::loader::STORAGE_MODE::FREE);
private:

  /*
   * Searches for the key in the file,
   * Returns the value
   */
   std::string findValue(const std::string& name, const std::string& path);

};
