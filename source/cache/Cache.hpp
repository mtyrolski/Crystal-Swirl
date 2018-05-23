/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <vector>
#include <map>
#include <memory>

#include "logger/Logger.hpp"

namespace mv
{
  /*
   *Class to store resources with given types
   *You can change or expand it for other types
   */

  template < typename T = typename std::enable_if< std::is_base_of<sf::Texture, T>::value, T>::type>
  class Cache
  {
    /* ===Objects=== */
  private:

    /*
     *Container to store resources of T type
     */
    std::map<std::string, std::shared_ptr<T>> resources;
    /* ===Methods=== */
  public:

    /*
     *Returns pointer to resource
     *If it is first induction with given path, cache firstly will load it
     *Otherwise returns old resource
     */
    std::shared_ptr<T> get(const std::string& path);
  };

  template<typename T>
  inline std::shared_ptr<T> Cache<T>::get(const std::string & path)
  {

    if ( path.empty() )
    {
      Logger::Log("Cache can't find resource in empty path.", Logger::STREAM::BOTH, Logger::TYPE::WARNING);
    }

    {//Try find resource
      auto result = resources.find(path);
      if ( result != resources.end() )
        return result->second;
    }

    {//Try to load it
      T resource;

      if ( !resource.loadFromFile(path) )
      {
        Logger::Log("Cache can't find resource in this path.", Logger::STREAM::BOTH, Logger::TYPE::WARNING);
      }

      resources.emplace(path, std::make_shared<T>(resource));

      return resources[path];
    }
  }
}