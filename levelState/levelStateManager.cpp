#include "levelStateManager.hpp"
#include "../assets/assetManager.hpp"
levelState::levelState(assetManager *m_assetManager)
    : m_assetManager(m_assetManager), // Use initialization list to set m_assetManager
      m_window(new window),
      m_map(new map),
      m_monster(new monster),
      m_npc(new npc),
      m_eventHandler(new eventHandler),
      m_hero(new hero),
      m_loadAssetQueue(new std::queue<assetInfo *>())
{
    DEBUG_LOG("Creating levelStateManager obj...");
    m_levelStateStatus = STATUS_SUCCESS;
    if (m_window->getWindowStatus() == STATUS_ERROR)
        m_levelStateStatus = STATUS_ERROR;
}

levelState::~levelState()
{
    if (m_window)
    {
        delete m_window;
    }

    if (m_map)
    {
        delete m_map;
    }

    if (m_monster)
    {
        delete m_monster;
    }

    if (m_npc)
    {
        delete m_npc;
    }

    if (m_eventHandler)
    {
        delete m_eventHandler;
    }

    if (m_hero)
    {
        delete m_hero;
    }

    while (!m_loadAssetQueue->empty())
    {
        auto *currentAsset = m_loadAssetQueue->front();
        delete currentAsset;
        m_loadAssetQueue->pop();
        delete currentAsset;
        currentAsset = nullptr;
    }
    delete m_loadAssetQueue;
    m_loadAssetQueue = nullptr;

    DEBUG_LOG("All levelstate objects freed...");
}

void levelState::updateMangaer(bool *exitFlag)
{

    while (!m_eventHandler->inputQueue.empty())
    {
        eventHandler::inputs I = m_eventHandler->inputQueue.front();
        m_eventHandler->inputQueue.pop();
        switch (I)
        {
        case eventHandler::INPUT_EXIT:
            *exitFlag = true;

        default:
            break;
        }
    }
    // goes through stack and requests assetmanger to load asset
    requestAssets();
}

void levelState::requestAssets()
{
    while (!m_loadAssetQueue->empty())
    {
        auto *top = m_loadAssetQueue->front();
        m_loadAssetQueue->pop();

        // if empty field skip
        if (!top->titleKey.size() || !top->fileName.size())
            continue;

        if (top->rect == nullptr && top->size != nullptr)
        {
            SDL_Rect r = {-1, 1, -1, -1};
            m_assetManager->loadAsset(top->titleKey, top->fileName, r, *top->size);
        }
        else if (top->rect != nullptr && top->size == nullptr)
        {
            m_assetManager->loadAsset(top->titleKey, top->fileName, *top->rect, -1);
        }
    }
}