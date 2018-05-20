/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include "wrappers/Vector2.hpp"

class Clickable
{
  /* ===Objects=== */
public:
protected:
private:
  /* ===Methods=== */
public:
  bool wasClicked(const Vector2<float>& mousePos,float x, float y, float w, float h);
protected:
private:
};

inline bool Clickable::wasClicked(const Vector2<float>& mousePos, float x, float y, float w, float h)
{
  return mousePos.x > x && mousePos.x < x +w &&
    mousePos.y > y && mousePos.y < y+ h ;
}