/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

template <class T>
class Troika
{
public:
  Troika(const T& f, const T& s, const T& t)
    :first(f), second(s), third(t) {}
  Troika(){}

  T first;
  T second;
  T third;
};
