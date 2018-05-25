/*
mvxxx 2018
https://github.com/mvxxx
*/

#include "AudioManager.hpp"

AudioManager::AudioManager(const std::shared_ptr<Loader>& loader)
{
  if ( Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1 )
  {
    //log o bledzie
  }

  loadAll(loader);
}

AudioManager::~AudioManager()
{

  Mix_FreeMusic(soundtrack);

  for ( auto&var : soundData )
    Mix_FreeChunk(var.second);

  Mix_CloseAudio();
}

void AudioManager::loadAll(const std::shared_ptr<Loader>& loader)
{
  soundtrack = Mix_LoadMUS(("source/data/audio/" + loader->getPathOf("SOUNDTRACK", mv::constants::loader::CONFIG_MODE::AUDIO)).c_str());

  loadSingleSound(mv::constants::audio::AUDIO_ID::CLICK, loader);
  loadSingleSound(mv::constants::audio::AUDIO_ID::PLAY, loader);
}

bool AudioManager::play(mv::constants::audio::AUDIO_ID id)
{
  switch ( id )
  {


  case mv::constants::audio::AUDIO_ID::SOUNDTRACK:
  {
    if ( Mix_PlayingMusic() == 0 )
    {
      if ( Mix_PlayMusic(soundtrack, -1) == -1 )
        return true;
    }
    else return false;
    break;
  }

  default:
    Mix_PlayChannel(-1, soundData[id], 0);
    break;
  }

  return true;
}

void AudioManager::loadSingleSound(mv::constants::audio::AUDIO_ID type, const std::shared_ptr<Loader>& loader)
{
  soundData[type] = Mix_LoadWAV(("source/data/audio/" + loader->getPathOf(mv::constants::audio::audioKey.at(type), mv::constants::loader::CONFIG_MODE::AUDIO)).c_str());
}
