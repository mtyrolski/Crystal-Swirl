/*
mvxxx 2018
https://github.com/mvxxx
*/

#include "Loader.hpp"

std::string Loader::getPathOf(const std::string& name,
  const mv::constants::loader::CONFIG_MODE& configMode,
  const mv::constants::loader::STORAGE_MODE storageMode)
{
  if ( storage[name] != "" )
    return storage[name];

  std::string data;

  switch ( configMode )
  {
  case mv::constants::loader::CONFIG_MODE::GRAPHIC:
    data = findValue(name, mv::constants::loader::GRAPHIC_CONFIG);
    break;

  case mv::constants::loader::CONFIG_MODE::AUDIO:
    data = findValue(name, mv::constants::loader::AUDIO_CONFIG);
    break;

  case mv::constants::loader::CONFIG_MODE::TECHNICALITIES:
    data = findValue(name, mv::constants::loader::TECHNICALITIES_CONFIG);
    break;
  }
  if ( storageMode == mv::constants::loader::STORAGE_MODE::STORE )
    storage[name] = data;

  return data;
}

std::string Loader::findValue(const std::string & name, const std::string & path)
{
  std::ifstream input(path);
  //logger_czy otworzono//

  std::string line;

  while ( std::getline(input, line) )
    if ( line.find(name, 0) != std::string::npos )
    {
      auto begin = line.find(' ') + 1;
      auto length = line.size() - begin;
      return  line.substr(begin, line.size() - begin);
    }

  //logger z flaga czy znaleziono albo i bez//
}
