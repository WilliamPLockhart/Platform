#pragma once
#include "../global.hpp"
#include <unordered_map>
// #include "image/"
// #include "sound/"

struct asset
{
    std::string titleKey = "";
    std::string fileName = "";
    SDL_Surface *textSurface = nullptr;
    SDL_Texture *texture = nullptr;
    TTF_Font *font = nullptr;
};

class assetManager
{
public:
    assetManager();
    ~assetManager();

    // determines whether or not to use loadimage, font, or sound
    int loadAsset(std::string titleKey, std::string fileName, SDL_Rect rect = {-1, -1, -1, -1}, int size = -1);

    // places the image into m_assets
    int loadImage(std::string titleKey, std::string fileName, SDL_Rect rect);

    // places the font into m_assets
    int LoadFont(std::string titleKey, std::string fileName, int size = 28);

    // removes asset from m_assets
    void freeAsset(std::string titleKey);

    void freeAllAssets();

    bool assetExists(const std::string &key);

private:
    std::unordered_map<std::string, asset> *m_assets;
};
