#include "global.hpp"
class AssetManager
{
public:
    void loadAssets()
    {
        std::thread loader([this]()
                           {
             // Load images and sounds
             loadImages();
             loadSounds(); });
        loader.detach(); // Or manage the thread lifecycle appropriately
    }

private:
    void loadImages()
    {
        // Load image assets
    }

    void loadSounds()
    {
        // Load sound assets
    }
};
