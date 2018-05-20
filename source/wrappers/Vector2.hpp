/*
mvxxx 2018
https://github.com/mvxxx
*/


#pragma once

template <class T>
class Vector2
{
public:
  T x;
  T y;

  Vector2(const T& _x, const T& _y)
    :x(_x), y(_y) {}

  Vector2()
  {}
};