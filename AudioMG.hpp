#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

//struct for audio paths
struct AudioPaths
{
    string BG = "music/background2.wav";
    string Hit = "music/hit.wav";
    string Chomp = "music/chomp.wav";
    string SunClick =  "music/sun.wav";
    string GameOver = "music/gameover.wav";
    string GameWon = "music/win.wav";
    string hugewave = "music/hugewave.wav";
    //add more paths here when needed
};

//struct to load file paths
struct LoadedSound {
    Mix_Chunk* sound;
    int channel;
    

    LoadedSound(Mix_Chunk* snd, int ch);
};


class AudioManager {
private:
    // Singleton instance
    static AudioManager* instance;
    // Map to store loaded sound chunks
    std::unordered_map<std::string, Mix_Chunk*> soundMap;
    // Structure to hold file paths for audio resources
    AudioPaths audiopaths;
    //private constructor
    AudioManager();

public:
    ~AudioManager();
    // Get the singleton instance of AudioManager
    static AudioManager* getInstance();

    void addSound(const std::string& soundName, Mix_Chunk* sound);
    // Load a sound from file and add it to the map
    Mix_Chunk* loadSound(const std::string& filePath);

    LoadedSound exportSound(const std::string& soundName);

    void playSound(const std::string& soundName, int channel = -1, int loops = 0);

    void playSoundOnLoop(const std::string& soundName, int channel = -1);

    void stopSound(int channel);

    // Additional functions if needed
};