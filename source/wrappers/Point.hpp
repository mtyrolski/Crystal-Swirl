/*
mvxxx 2018
https://github.com/mvxxx
*/


#pragma once

template <class T>
class Point
{
public:
  T x;
  T y;

  Point(const T& _x, const T& _y)
    :x(_x), y(_y) {}

  Point()
  {}
};