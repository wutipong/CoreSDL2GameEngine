#include "Audio.h"

AudioTrack::AudioTrack(const char* path)
{
	audio = Mix_LoadWAV(path);
	if(audio == NULL)
		std::cout << "Failed to load " << path << " : error - " << Mix_GetError() << std::endl;
}

AudioTrack::~AudioTrack()
{
	if(audio != NULL)
		Mix_FreeChunk(audio);
	audio = NULL;
}

void AudioTrack::SetVolume(int volume)
{
	if(audio != NULL)
		Mix_VolumeChunk(audio, volume);
}

void AudioTrack::Play()
{
	play(0);
}

void AudioTrack::Play(int loop_count)
{
	play(loop_count);
}

void AudioTrack::play(int loop_count)
{
	if(audio != NULL)
		Mix_PlayChannel(-1, audio, loop_count);
}

void AudioMusic::SetVolume(int volume)
{
	Mix_VolumeMusic(volume);
}

AudioMusic::AudioMusic(const char* path)
{
	audio = Mix_LoadMUS(path);
	if(audio == NULL)
		std::cout << "Failed to music load " << path << " : error - " << Mix_GetError() << std::endl;
}

AudioMusic::~AudioMusic()
{
	if(audio != NULL)
		Mix_FreeMusic(audio);
	audio = NULL;
}

void AudioMusic::Play()
{
	if(Mix_PlayingMusic() == 0)
		Mix_PlayMusic(audio, -1);
	else
		Mix_ResumeMusic();
}

void AudioMusic::Pause()
{
	Mix_PauseMusic();
}

void AudioMusic::Stop()
{
	Mix_HaltMusic();
}
