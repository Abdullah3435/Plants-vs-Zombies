#include <SDL.h>
#include <SDL_image.h>

struct Unit {
    SDL_Rect srcRect;
    SDL_Rect moverRect;
};

class Animation {
private:
    SDL_Texture* spriteSheet;
    int frameWidth, frameHeight;
    int totalFrames;
    int currentFrame;
    int animationSpeed; // in milliseconds
    int lastFrameChangeTime;

    //Change by ashba
    float delay_ms;

public:
    Animation(SDL_Renderer* renderer, const char* imagePath, int totalFrames, int speed, int width, int height) :
        spriteSheet(nullptr), totalFrames(totalFrames), currentFrame(0),
        animationSpeed(speed), lastFrameChangeTime(0), frameWidth(width), frameHeight(height) {

        spriteSheet = loadTexture(renderer, imagePath);
    }

    ~Animation() {
        SDL_DestroyTexture(spriteSheet);
    }

    SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* imagePath) {
        SDL_Surface* loadedSurface = IMG_Load(imagePath);
        if (loadedSurface == nullptr) {
            // Handle error
            return nullptr;
        }

        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        SDL_FreeSurface(loadedSurface);

        return texture;
    }

    Unit getNextFrame() {
        Unit unit;
        unit.srcRect.x = currentFrame * frameWidth;
        unit.srcRect.y = 0;
        unit.srcRect.w = frameWidth;
        unit.srcRect.h = frameHeight;

        unit.moverRect.x = 0; // Set the destination rect position (x-coordinate)
        unit.moverRect.y = 0; // Set the destination rect position (y-coordinate)
        unit.moverRect.w = frameWidth; // Set the width of the destination rect
        unit.moverRect.h = frameHeight; // Set the height of the destination rect

        return unit;
    }

    void update() {
        int currentTime = SDL_GetTicks();

        if (currentTime > lastFrameChangeTime + animationSpeed) {
            lastFrameChangeTime = currentTime;
            currentFrame = (currentFrame + 1) % totalFrames;
        }
    }
};

