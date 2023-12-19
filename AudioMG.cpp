#include "AudioMG.hpp"
#include <iostream>
AudioManager* AudioManager::instance = nullptr;

LoadedSound::LoadedSound(Mix_Chunk* snd, int ch) : sound(snd), channel(ch) {}

AudioManager::AudioManager() {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        // Handle initialization failure
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
    }
    addSound("bgMusic",loadSound(audiopaths.BG));
    addSound("chomp",loadSound(audiopaths.Chomp));
    addSound("hit",loadSound(audiopaths.Hit));
    addSound("Sunclick",loadSound(audiopaths.SunClick));
    addSound("Won",loadSound(audiopaths.GameWon));
    addSound("Lost",loadSound(audiopaths.GameOver));
    addSound("Hugewave",loadSound(audiopaths.hugewave));
    
}

AudioManager::~AudioManager() {
    Mix_CloseAudio();
    for (auto& pair : soundMap) {
        Mix_FreeChunk(pair.second);
    }
}

AudioManager* AudioManager::getInstance() {
    if (!instance) {
        instance = new AudioManager();
    }
    return instance;
}

void AudioManager::addSound(const std::string& soundName, Mix_Chunk* sound) {
    soundMap[soundName] = sound;
}

Mix_Chunk* AudioManager::loadSound(const std::string& filePath) {
    Mix_Chunk* sound = Mix_LoadWAV(filePath.c_str());
    if (sound) {
        return sound;
    } else {
        std::cerr << "Failed to load sound: " << filePath << " SDL_mixer Error: " << Mix_GetError() << std::endl;
        return nullptr;
    }
}

LoadedSound AudioManager::exportSound(const std::string& soundName) {
    auto it = soundMap.find(soundName);
    if (it != soundMap.end()) {
        int channel = Mix_PlayChannel(-1, it->second, 0);
        return LoadedSound(it->second, channel);
    } else {
        std::cerr << "Sound not found: " << soundName << std::endl;
        return LoadedSound(nullptr, -1);
    }
}

void AudioManager::playSound(const std::string& soundName, int channel, int loops) {
    auto it = soundMap.find(soundName);
    if (it != soundMap.end()) {
        Mix_PlayChannel(channel, it->second, loops);
    } else {
        std::cerr << "Sound not found: " << soundName << std::endl;
    }
}

void AudioManager::playSoundOnLoop(const std::string& soundName, int channel) {
    playSound(soundName, channel, -1);
}

void AudioManager::stopSound(int channel) {
    Mix_HaltChannel(channel);
}