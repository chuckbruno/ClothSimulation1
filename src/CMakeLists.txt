# CMakeList.txt : CMake project for ClothSimulation, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (ClothSimulation   "Vec2.h" "Stick.h" "Point.h" "Mouse.h" "Cloth.h" "Renderer.h" "Application.h" "Main.cpp" "Point.cpp" "Stick.cpp" "Renderer.cpp" "Mouse.cpp" "Cloth.cpp" "Application.cpp")

# TODO: Add tests and install targets if needed.
find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(ClothSimulation PRIVATE SDL2::SDL2 SDL2::SDL2main)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(ClothSimulation PRIVATE imgui::imgui)