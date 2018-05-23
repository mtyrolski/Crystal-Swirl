/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <memory>

#include <SDL.h>

#include "GameState/GameState.hpp"
#include "scene/Scene.hpp"


/*
 * Class which manage the whole game process
 */
class Game
{	
  /* ===Objects=== */
public:
protected:
private:

  //Pointer to scene 
  std::shared_ptr<Scene> scene;

  //Pointer to the only state - gameState 
  std::shared_ptr<GameState> gameState;
  /* ===Methods=== */
public:
  /*
   * Main loop
   */
  void run();
protected:
private:
  /*
   * Initialise smart pointers
   * Method which need to be done on start
   */
  void init();
};