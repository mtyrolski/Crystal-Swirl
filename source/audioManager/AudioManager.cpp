/*
mvxxx 2018
https://github.com/mvxxx
*/

#include "AudioManager.hpp"

AudioManager::AudioManager()
{
  if ( Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1 )
  {
    //log o bledzie
  }
}

AudioManager::~AudioManager()
{

  Mix_FreeMusic(soundtrack);

  for(auto&var:soundData)
    Mix_FreeChunk(var.second);

  Mix_CloseAudio();
}

void AudioManager::loadAll(const std::shared_ptr<Loader> loader)
{
  soundtrack = Mix_LoadMUS(("source/data/audio/"+loader->getPathOf("SOUNDTRACK", mv::constants::loader::CONFIG_MODE::AUDIO)).c_str());

  loadSingleSound(mv::constants::audio::AUDIO_ID::CLICK, loader);
  loadSingleSound(mv::constants::audio::AUDIO_ID::PLAY, loader);
}

bool AudioManager::play(mv::constants::audio::AUDIO_ID)
{
  return false;
}

void AudioManager::loadSingleSound(mv::constants::audio::AUDIO_ID type, const std::shared_ptr<Loader>& loader)
{
  soundData[type] = Mix_LoadWAV(("source/data/audio/"+loader->getPathOf(mv::constants::audio::audioKey.at(type),mv::constants::loader::CONFIG_MODE::AUDIO)).c_str());
}
