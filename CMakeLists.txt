cmake_minimum_required(VERSION 3.5.0)
project(platformer VERSION 0.1.0 LANGUAGES C CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the SDL2 package
find_package(SDL2 REQUIRED)

# Manually set SDL2_image include and library directories
include_directories(/usr/include/SDL2)
link_directories(/usr/lib/x86_64-linux-gnu)

# Add the executable    
file(GLOB assetsCPP "assets/*.cpp")
file(GLOB loadsCPP "loads/*.cpp")
file(GLOB levelCPP "levelState/*.cpp")
add_executable(platformer game.cpp main.cpp ${loadsCPP} ${levelCPP} ${assetsCPP})

# Define DEBUG flag for Debug configuration
target_compile_definitions(platformer PRIVATE $<$<CONFIG:Debug>:DEBUG>)

# Link the SDL libraries
target_link_libraries(platformer ${SDL2_LIBRARIES} SDL2_image SDL2_mixer SDL2_ttf)
