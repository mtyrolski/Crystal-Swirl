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


  typedef T* iterator;
  typedef const T* const_iterator;

  iterator begin() 
  {
    return &first;
  }
  const_iterator begin() const
  {
    return &first;
  }
  iterator end()
  {
    return &third+1;
  }
  const_iterator end() const 
  {
    return &third + 1;
  }
};
