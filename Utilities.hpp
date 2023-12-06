#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>
class Utilities
{
    
    private:
    int SelfCount = 0; 
    std::chrono::steady_clock::time_point startTime ;
  public:
  bool Delay(int delay);
  Utilities();
  
};

//-------------------------------------GRID----------------------------------------------



class Grid {
public:
    int width;
    int height;
    int rows;
    int cols;
    int xOffset;  // Global offset for the entire grid
    int yOffset;

private:
    std::unordered_map<int, bool> gridData;

public:
    // Constructor
    Grid(int width, int height, int rows, int cols, int xOffset = 0, int yOffset = 0);

    // Function to calculate grid index based on coordinates
    int calculateIndex(int x, int y) const;

    // Function to check if a block is occupied at given coordinates
    bool isOccupied(int x, int y) const;

    // Function to occupy a block at given coordinates
    void occupyBlock(int x, int y);

    // Function to unoccupy a block at given coordinates
    void unoccupyBlock(int x, int y);

    // Function to get the x and y coordinates of a specific block
    std::pair<int, int> getCoordinates(int row, int col) const;

    // Function to print the current state of the grid
    void printGrid() const;
};