/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <memory>
#include "ecs/entity/Entity.hpp"
#include "logger/Logger.hpp"

namespace mv
{
  /*
  *Basic class to represent component in ECS design pattern
  */
  class Component
  {
    /* ===Objects=== */
  public:
  protected:
  private:

    /*
    *Pointer to owner
    *Entity can not be nullptr
    */
    std::shared_ptr<Entity> owner;
    /* ===Methods=== */
  public:

    /*
    *Constructor which checks correctness of pointer
    */
    Component(std::shared_ptr<Entity> ptr)
      :owner(ptr)
    {
      if ( ptr == nullptr )
        Logger::Log("Owner can not be nullptr!", Logger::STREAM::CONSOLE, Logger::TYPE::ERROR);
    }

    /*
    *Returns pointer to entity owner
    */
    std::shared_ptr<Entity> getOwner() const
    {
      return owner;
    }
  protected:
  private:
  };
}
