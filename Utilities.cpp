#include "Utilities.hpp"

#include "game.hpp"

bool Utilities::Delay(int delay)
{
    if (SelfCount == 0)
    {
        startTime = std::chrono::steady_clock::now();
    }
    std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
    std::chrono::duration<int, std::milli> elapsedMilliseconds =
        std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime);
    SelfCount ++;

    if (elapsedMilliseconds.count() > delay) {
        SelfCount = 0;
        return true;
    }
    return false;
  }

void Utilities::resettime()
{
    startTime = std::chrono::steady_clock::now();
    SelfCount = 0;
}

Utilities::Utilities()
{
    startTime = std::chrono::steady_clock::now();
}
// bool Utilities::Delay(int milliseconds) {
//     static auto lastTime = std::chrono::high_resolution_clock::now();

//     auto currentTime = std::chrono::high_resolution_clock::now();
//     auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastTime).count();

//     if (deltaTime >= milliseconds) {
//         lastTime = currentTime;
//         return true;
//     }

//     return false;
// }

  //----------------------------------GRID------------------------------------

  Grid::Grid(int width, int height, int rows, int cols, int xOffset, int yOffset)
    : width(width), height(height), rows(rows), cols(cols), xOffset(xOffset), yOffset(yOffset) {}

int Grid::calculateIndex(int x, int y) const {
    int xwidth = width / cols;
    int ywidth = height / rows;
    int col = (x - xOffset) / xwidth;
    int row = (y - yOffset) / ywidth;
    return row * cols + col;
}

bool Grid::isOccupied(int x, int y) const {
    int index = calculateIndex(x, y);
    auto it = gridData.find(index);
    return (it != gridData.end() && it->second);
}

void Grid::occupyBlock(int x, int y) {
    int index = calculateIndex(x, y);
    gridData[index] = true;
}

void Grid::unoccupyBlock(int x, int y) {
    int index = calculateIndex(x, y);
    gridData[index] = false;
}

std::pair<int, int> Grid::getCoordinates(int row, int col) const {
    int xwidth = width / cols;
    int ywidth = height / rows;
    int x = col * xwidth + xwidth / 2 + xOffset;
    int y = row * ywidth + ywidth / 2 + yOffset;
    return std::make_pair(x, y);
}

void Grid::printGrid() const {
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            int index = row * cols + col;
            std::cout << (gridData.find(index) != gridData.end() ? "X" : "-") << " ";
        }
        std::cout << std::endl;
    }
}





