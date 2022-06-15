cmake_minimum_required(VERSION 3.10)

project(skeleton VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

# add the executable
#add_executable(skeleton src/skeleton.cpp)
add_executable(
                skeleton
                src/View/MyApp.cpp
                src/View/MyFrame.cpp
                src/View/MyControlPanel.cpp
                src/View/MyDrawingPanel.cpp
                src/Modele/Point.cpp
                src/Modele/Forme.cpp
                src/Modele/Cercle.cpp
                src/Modele/Rectangle.cpp
                )
target_link_libraries(skeleton ${wxWidgets_LIBRARIES})

#include_directories()
