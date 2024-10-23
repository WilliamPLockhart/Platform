#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>
#include <memory>
#include <thread>
#include <thread>
#include <mutex>
#include <condition_variable>

#ifdef DEBUG
#define DEBUG_LOG(msg) LOG_INFO(msg)
#else
#define DEBUG_LOG(msg) // No logging
#endif

#define ERROR_LOG(msg)                                \
    {                                                 \
        std::cerr << "Error: " << (msg) << std::endl; \
    }

#define ASSET_ERROR(str)                                       \
    {                                                          \
        std::cout << "Failed to load: " << (str) << std::endl; \
        RETURN_ERROR(STATUS_ERROR);                            \
    }

#define LOG_INFO(msg)                                 \
    {                                                 \
        std::cout << "[INFO] " << (msg) << std::endl; \
    }

#define LOG_WARN(msg)                                    \
    {                                                    \
        std::cout << "[WARNING] " << (msg) << std::endl; \
    }

#define LOG_ERROR(msg)                                 \
    {                                                  \
        std::cerr << "[ERROR] " << (msg) << std::endl; \
    }

#define SAFE_DELETE(ptr) \
    {                    \
        delete (ptr);    \
        (ptr) = nullptr; \
    }

enum ErrorCode
{
    STATUS_SUCCESS = 0,
    STATUS_ERROR = 1,
    STATUS_NOT_FOUND = 2,
    STATUS_INVALID_ARGUMENT = 3,
};
