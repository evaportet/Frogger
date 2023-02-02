#include "AudioManager.h"

AudioManager* AudioManager::instance = nullptr;

AudioManager::AudioManager()
{
	assert(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) != -1);
						 //frequency
	LoadSFX("Dead");
	LoadSFX("Jump");
	LoadMusic("GameplayMusic");
	LoadMusic("MenuMusic");
	LoadSFX("GetEnd");
	
	muted = false;
}

AudioManager* AudioManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new AudioManager();
	}

	return instance;
}

void AudioManager::LoadSFX(std::string name)
{
	//comprobamos que no esté cargado
	assert(sfx.find(name) == sfx.end());

	//cargamos al audio
	Mix_Chunk* loadedChunk = Mix_LoadWAV(("resources/Audio/" + name + ".wav").c_str());

	assert(loadedChunk != nullptr); //xcopy

	sfx.emplace(name, loadedChunk);
}

void AudioManager::LoadMusic(std::string name)
{
	//comprobamos que no esté cargado
	assert(music.find(name) == music.end());

	//cargamos al audio
	Mix_Music* loadedMusic = Mix_LoadMUS(("resources/Audio/" + name + ".wav").c_str());

	assert(loadedMusic != nullptr);

	music.emplace(name, loadedMusic);
}

void AudioManager::UnLoadSFX(std::string name)
{
	assert(sfx.find(name) != sfx.end());

	Mix_FreeChunk(sfx[name]);
	sfx.erase(name);
}

void AudioManager::UnLoadMusic(std::string name)
{
	assert(music.find(name) != music.end());

	Mix_FreeMusic(music[name]);
	music.erase(name);
}

void AudioManager::PlaySFX(std::string name, int repetitions)
{
	assert(sfx.find(name) != sfx.end()); 

	if (!muted)
	Mix_PlayChannel(-1, sfx[name], repetitions);
				

}

void AudioManager::PlayMusic(std::string name)
{
	assert(music.find(name) != music.end()); 

	if (!muted)
	Mix_FadeInMusic(music[name], -1, 200);
								     //ms de fade in
}

void AudioManager::SetMute(bool muted)
{
	if (muted)
	{
		if(this->muted)
		return;

		Mix_Volume(-1, 0);
		Mix_VolumeMusic(0);
		this->muted = true;
	}
	else
	{
		if (!this->muted)
			return;
		Mix_Volume(-1, MIX_MAX_VOLUME);
		Mix_VolumeMusic(MIX_MAX_VOLUME);
		this->muted = false;
	}
}

bool AudioManager::GetMuted()
{
	return muted;
}
