/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <memory>
#include <map>

#include <SDL_mixer.h>
#include <SDL.h>

#include "Loader/Loader.hpp"
#include "logger/Logger.hpp"

/*
 * Class for managing audio
 */
class AudioManager
{
	/* ===Objects=== */
private:
  //main music
  Mix_Music* soundtrack;

  //sounds storage
  std::map<mv::constants::audio::AUDIO_ID, Mix_Chunk*> soundData;
	/* ===Methods=== */
public:
  AudioManager(const std::shared_ptr<Loader>& loader);
  ~AudioManager();

  /*
   * Loads all sounds
   */
  void loadAll(const std::shared_ptr<Loader>& loader);

  /*
   * Tries to play a music/sound
   * Returns false if that music is being played now
   * Otherwise returns true 
   */
  bool play(mv::constants::audio::AUDIO_ID);

private:
  /*
   * Loads one sound
   */
  void loadSingleSound(mv::constants::audio::AUDIO_ID type, const std::shared_ptr<Loader>& loader);
};