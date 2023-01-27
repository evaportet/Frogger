#pragma once
#include <SDL_mixer.h>
#include <string>
#include <iostream>
#include <unordered_map>
#include <cassert>

#define AM AudioManager::GetInstance()

class AudioManager
{
private:
	std::unordered_map<std::string, Mix_Chunk*> sfx;
	std::unordered_map<std::string, Mix_Music*> music;

	bool muted;

	static AudioManager* instance;
	AudioManager();
	AudioManager(const AudioManager&) = delete; //constructor por copia -> borralo
	AudioManager& operator = (const AudioManager&) = delete; //no puedes copiarlo

public:
	static AudioManager* GetInstance();
	void LoadSFX(std::string name);
	void LoadMusic(std::string name);

	void UnLoadSFX(std::string name);
	void UnLoadMusic(std::string name);

	void PlaySFX(std::string name, int repetitions);
	void PlayMusic(std::string name);

	void SetMute(bool muted);
	bool GetMuted();
};