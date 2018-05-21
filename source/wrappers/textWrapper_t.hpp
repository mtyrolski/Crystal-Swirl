/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <ecs/entity/Entity.hpp>

class textWrapper_t
{
public:

  textWrapper_t(const std::string& _text, const std::shared_ptr<mv::Entity> ent)
    :entity(ent),text(_text)
  {}

  std::shared_ptr<mv::Entity> entity;
  std::string text;
};