#include "assetManager.hpp"

assetManager::assetManager()
{
    DEBUG_LOG("Creating assetManager obj...");
    m_assets = new std::unordered_map<std::string, asset>;
}

assetManager::~assetManager()
{
    DEBUG_LOG("Destroying assetManager obj...");
    freeAllAssets();
    delete m_assets;
    m_assets = nullptr;
}

int assetManager::loadAsset(std::string titleKey, std::string fileName, SDL_Rect rect, int size)
{
    if (assetExists(titleKey))
        return STATUS_SUCCESS;

    // if all are negative then not enough data was provided
    if (rect.h == -1 && rect.w == -1 && rect.x == -1 && rect.y == -1 && size == -1)
    {
        return STATUS_ERROR;
    }
    // if size is -1 then texture is loaded
    else if (size == -1)
    {
        return loadImage(titleKey, fileName, rect);
    }
    // load the font
    else
    {
        return LoadFont(titleKey, fileName, size);
    }
}

int assetManager::loadImage(std::string titleKey, std::string fileName, SDL_Rect rect)
{
}

int assetManager::LoadFont(std::string titleKey, std::string fileName, int size)
{
    // check if the font already exists
    if (assetExists(titleKey))
    {
        return STATUS_SUCCESS;
    }

    // load font if not in map
    fileName = "text/" + fileName;
    TTF_Font *font = TTF_OpenFont(fileName.c_str(), size);
    if (!font)
    {
        DEBUG_LOG("Error loading font: " + fileName);
        DEBUG_LOG("SDL_ttf error: " + std::string(TTF_GetError()));
        DEBUG_LOG(fileName);
        return STATUS_ERROR;
    }

    // create struct and place in map
    asset *A = new asset;
    A->fileName = fileName;
    A->titleKey = titleKey;
    A->font = font;
    if (!A)
        return STATUS_ERROR;

    (*m_assets)[titleKey] = *A;
    return STATUS_SUCCESS;
}

bool assetManager::assetExists(const std::string &key)
{
    return m_assets->find(key) != m_assets->end();
}

void assetManager::freeAsset(std::string titleKey)
{
    // Find the asset in the map
    auto it = m_assets->find(titleKey);
    if (it == m_assets->end())
    {
        return;
    }

    asset &fAsset = it->second;
    if (fAsset.textSurface)
    {
        SDL_FreeSurface(fAsset.textSurface);
        fAsset.textSurface = nullptr;
    }
    if (fAsset.font)
    {
        TTF_CloseFont(fAsset.font);
        fAsset.font = nullptr;
    }

    if (fAsset.texture)
    {
        SDL_DestroyTexture(fAsset.texture);
    }

    // Remove the asset from the map
    m_assets->erase(it);
}

void assetManager::freeAllAssets()
{
    if (!m_assets)
        return;

    for (auto &pair : *m_assets)
    {
        asset &A = pair.second;
        if (A.textSurface)
        {
            SDL_FreeSurface(A.textSurface);
            A.textSurface = nullptr;
        }
        if (A.font)
        {
            TTF_CloseFont(A.font);
            A.font = nullptr;
        }
    }

    m_assets->clear();
}