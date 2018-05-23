/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <vector>
#include <memory>

#include "wrappers/componentWrapper.hpp"

namespace mv
{
  /*
   *Basic class to represent entity in ECS design pattern
   */
  class Entity
  {
    /* ===Objects=== */
  public:
  protected:
  private:
    /*
     *Wrapper to storing components
     *Apart from main component it has got also informations about it
     *(More informations in wrapper's file)
     */
    std::vector<componentWrapper_t> componentWrappers;
    /* ===Methods=== */
  public:
    /*
     * Returns pointer to component with given type
     * If it does not exist, returns nullptr
     */
    template<class T>
    std::shared_ptr<T> getComponent() const;

    /*
     * Adds component with given type
     * Returns true if the operation was successful
     * Returns false if component with given type already exists
     */
    template<class T>
    bool addComponent();

    /*
     * Returns false if component with given type already not exist
     * Othewrise returns false
     */
    template<class T>
    bool hasComponent();

    /*
    * Remove component with given type
    * Returns true if the operation was successful
    * Returns false if component with given does not exist
    */
    template<class T>
    bool removeComponent();
  protected:
  private:
  };

  template<class T>
  inline std::shared_ptr<T> Entity::getComponent() const
  {
    for ( auto&cw : componentWrappers )
      if ( cw.id == typeid(T).hash_code() )
        return std::static_pointer_cast<T>(cw.component);

    return nullptr;
  }

  template<class T>
  inline bool Entity::addComponent()
  {
    for ( auto&cw : componentWrappers )
      if ( cw.id == typeid(T).hash_code() )
        return false;

    componentWrappers.push_back(componentWrapper_t(std::make_shared<T>(), typeid(T).hash_code()));

    return true;
  }

  template<class T>
  inline bool Entity::hasComponent()
  {

    for ( auto&cw : componentWrappers )
    {
      if ( cw.id == typeid(T).hash_code() )
      {
        return true;
      }
    }
    return false;
  }

  template<class T>
  inline bool Entity::removeComponent()
  {
    for ( auto itr = componentWrappers.begin(); itr != componentWrappers.end(); ++itr )
    {
      if ( itr->id == typeid(T).hash_code() )
      {
        componentWrappers.erase(itr);
        return true;
      }
    }
    return false;
  }
}