/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include "wrappers/Vector2.hpp"

/*
 *component that manages clicks on a given object
 */
class Clickable
{
public:
  /*
   * Checks that owner of this object has been clicked
   */
  bool wasClicked(const Vector2<float>& mousePos,float x, float y, float w, float h) const;

};


/*
* Checks that owner of this object has been clicked
*/
inline bool Clickable::wasClicked(const Vector2<float>& mousePos, float x, float y, float w, float h) const
{
  return mousePos.x > x && mousePos.x < x +w &&
    mousePos.y > y && mousePos.y < y+ h ;
}