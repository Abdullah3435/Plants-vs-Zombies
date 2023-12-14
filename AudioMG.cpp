#include "AudioMG.hpp"
#include <iostream>
AudioManager* AudioManager::instance = nullptr;

LoadedSound::LoadedSound(Mix_Chunk* snd, int ch) : sound(snd), channel(ch) {}

AudioManager::AudioManager() {
    // Initialize SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        // Handle initialization failure
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
    }
    // Load and add sounds to the sound map
    addSound("bgMusic",loadSound(audiopaths.BG));
    addSound("chomp",loadSound(audiopaths.Chomp));
    addSound("hit",loadSound(audiopaths.Hit));
    addSound("Sunclick",loadSound(audiopaths.SunClick));
    
}

AudioManager::~AudioManager() {
    // Close SDL_mixer
    Mix_CloseAudio();
    // Free loaded sounds
    for (auto& pair : soundMap) {
        Mix_FreeChunk(pair.second);
    }
}

AudioManager* AudioManager::getInstance() {
    // Singleton pattern: Get or create the instance
    if (!instance) {
        instance = new AudioManager();
    }
    return instance;
}

void AudioManager::addSound(const std::string& soundName, Mix_Chunk* sound) {
    // Add a sound to the sound map
    soundMap[soundName] = sound;
}

Mix_Chunk* AudioManager::loadSound(const std::string& filePath) {
    // Load a sound file and return the Mix_Chunk pointer
    Mix_Chunk* sound = Mix_LoadWAV(filePath.c_str());
    if (sound) {
        return sound;
    } else {
        std::cerr << "Failed to load sound: " << filePath << " SDL_mixer Error: " << Mix_GetError() << std::endl;
        return nullptr;
    }
}

LoadedSound AudioManager::exportSound(const std::string& soundName) {
    // Export a sound by playing it on a new channel and returning the LoadedSound structure
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
    // Play a sound on a specified channel
    auto it = soundMap.find(soundName);
    if (it != soundMap.end()) {
        Mix_PlayChannel(channel, it->second, loops);
    } else {
        std::cerr << "Sound not found: " << soundName << std::endl;
    }
}

void AudioManager::playSoundOnLoop(const std::string& soundName, int channel) {
    // Play a sound on a specified channel in a loop
    playSound(soundName, channel, -1);
}

void AudioManager::stopSound(int channel) {
    // Stop the sound playing on the specified channel
    Mix_HaltChannel(channel);
}