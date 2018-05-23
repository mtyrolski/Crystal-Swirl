/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <memory>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "ecs/component/ProperBody.hpp"
#include "ecs/component/Clickable.hpp"
#include "ecs/entity/Entity.hpp"
#include "wrappers/Vector2.hpp"
#include "logger/Logger.hpp"
#include "Config.hpp"
 
/*
 * Class which manage scene, entities, rendering etc
 */
class Scene
{
	/* ===Objects=== */

private:
  // pointer to window of SDL game
  SDL_Window* window;

  // pointer to renderer of SDL
  SDL_Renderer* renderer;

  //flag which informs if mouse has been clicked
  bool mouseClicked = false;

  //this object is used when it is need to check properBody->wasClicked | Give coordinates of mouse
  Vector2<float> mousePosition;

  //State of window | Open or close
  bool opened;
	/* ===Methods=== */
public:
  Scene();
  ~Scene();

  /*
   * Window getter
   */
  SDL_Window* getWindow() const;

  /*
   * Renderer getter
   */
  SDL_Renderer* getRenderer() const;

  /*
   * returns state of window (open or close)
   */
  bool isOpen() const;

  /*
   * Checks events
   * Makes decisions
   */
  void pollEvents();

  /*
   * Clears window
   * Refresh objects
   */
  void clear(const std::vector<std::shared_ptr<mv::Entity>>& entities);

  /*
   *Returns true if mouse has been clicked
   * otherwise return false
   */
  bool mouseState() const;

  /*
   * Classic setter of mouse state
   */
  void setMouseState(bool flag);

  /*
   * Returns last position of mouse
   */
  const Vector2<float>& getMousePosition() const;
};