#include "Utilities.hpp"

#include "game.hpp"

bool Utilities::Delay(int delay)
{
    // If it's the first call, record the start time
    if (SelfCount == 0)
    {
        startTime = std::chrono::steady_clock::now();
    }
    // Get the current time
    std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
    // Calculate elapsed time in milliseconds
    std::chrono::duration<int, std::milli> elapsedMilliseconds =
        std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime);
    SelfCount ++;

    // Check if the elapsed time exceeds the specified delay
    if (elapsedMilliseconds.count() > delay) {
        SelfCount = 0;
        return true;
    }
    return false;
  }
// Reset the time and count variables
void Utilities::resettime()
{
    startTime = std::chrono::steady_clock::now();
    SelfCount = 0;
}
// constructor for Utilities class
Utilities::Utilities()
{
    startTime = std::chrono::steady_clock::now();
}


  //----------------------------------GRID------------------------------------
// Constructor for the Grid class
Grid::Grid(int width, int height, int rows, int cols, int xOffset, int yOffset)
    : width(width), height(height), rows(rows), cols(cols), xOffset(xOffset), yOffset(yOffset) {}

// Calculate the index of a block in the grid
int Grid::calculateIndex(int x, int y) const {\
    // Calculate the column and row indices based on the block's position
    int xwidth = width / cols;
    int ywidth = height / rows;
    int col = (x - xOffset) / xwidth;
    int row = (y - yOffset) / ywidth;
    // Calculate and return the index in the grid
    return row * cols + col;
}

// Check if a block in the grid is occupied
bool Grid::isOccupied(int x, int y) const {
    // Calculate the index of the block
    int index = calculateIndex(x, y);
    // Check if the block is present in the gridData (occupied)
    auto it = gridData.find(index);
    return (it != gridData.end() && it->second);
}

// Check if a block in the grid is occupied
void Grid::occupyBlock(int x, int y) {
    // Calculate the index of the block
    int index = calculateIndex(x, y);
    // Set the gridData entry for the block to true (occupied)
    gridData[index] = true;
}

// Unoccupy a block in the grid
void Grid::unoccupyBlock(int x, int y) {
    // Calculate the index of the block
    int index = calculateIndex(x, y);
    // Set the gridData entry for the block to false (unoccupied)
    gridData[index] = false;
}

// Get the coordinates of a block in the grid
std::pair<int, int> Grid::getCoordinates(int row, int col) const {
    // Calculate the width of each column and height of each row
    int xwidth = width / cols;
    int ywidth = height / rows;
    // Calculate the screen coordinates of the center of the block
    int x = col * xwidth + xwidth / 2 + xOffset;
    int y = row * ywidth + ywidth / 2 + yOffset;
    return std::make_pair(x, y);
}

// Print the grid to the console
void Grid::printGrid() const {
    // Loop through each row
    for (int row = 0; row < rows; ++row) {
        // Loop through each column in the row
        for (int col = 0; col < cols; ++col) {
            int index = row * cols + col; // Calculate the index of the block
            std::cout << (gridData.find(index) != gridData.end() ? "X" : "-") << " ";// Print 'X' if the block is occupied, '-' otherwise
        }
        std::cout << std::endl; // Move to the next line for the next row
    }
}





