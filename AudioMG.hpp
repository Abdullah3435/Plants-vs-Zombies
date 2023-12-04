#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

struct AudioPaths
{
    string BG = "music/background2.wav";
    string Hit = "music/hit.wav";
    string Chomp = "music/chomp.wav";
    //add more paths here when needed
};

struct LoadedSound {
    Mix_Chunk* sound;
    int channel;
    

    LoadedSound(Mix_Chunk* snd, int ch);
};

class AudioManager {
private:
    static AudioManager* instance;
    std::unordered_map<std::string, Mix_Chunk*> soundMap;
    AudioPaths audiopaths;

    AudioManager();

public:
    ~AudioManager();

    static AudioManager* getInstance();

    void addSound(const std::string& soundName, Mix_Chunk* sound);

    Mix_Chunk* loadSound(const std::string& filePath);

    LoadedSound exportSound(const std::string& soundName);

    void playSound(const std::string& soundName, int channel = -1, int loops = 0);

    void playSoundOnLoop(const std::string& soundName, int channel = -1);

    void stopSound(int channel);

    // Additional functions if needed
};