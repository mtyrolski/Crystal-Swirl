#include "Loader.hpp"

 std::string Loader::getPathOf(const std::string& name,const mv::constants::loader::MODE& mode)
{
  switch ( mode )
  {
  case mv::constants::loader::MODE::GRAPHIC:
    return findValue(name, mv::constants::loader::GRAPHIC_CONFIG);
    break;

  case mv::constants::loader::MODE::AUDIO:
    return findValue(name, mv::constants::loader::AUDIO_CONFIG);
    break;

  case mv::constants::loader::MODE::TECHNICALITIES:
    return findValue(name, mv::constants::loader::TECHNICALITIES_CONFIG);
    break;
  }
}

std::string Loader::findValue(const std::string & name, const std::string & path)
{
  std::ifstream input(path);
  //logger_czy otworzono//

  std::string line;

  while ( std::getline(input, line) ) 
    if ( line.find(name,0)!= std::string::npos ) 
    {
      auto begin = line.find(' ') + 1;
      auto length = line.size() - begin;
      return  line.substr(begin,line.size()-begin);
    }
  
  //logger z flaga czy znaleziono albo i bez//
}
