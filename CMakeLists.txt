cmake_minimum_required(VERSION 3.10)

project(JieEngine)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/JieEngine)

if(CMAKE_HOST_WIN32)

    link_libraries(-lmingw32 -lDecrypt -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf)

else()

    link_libraries(-lDecrypt -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf)

endif()

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/JieEngine/Src/*.cpp" "${PROJECT_SOURCE_DIR}/JieEngine/System/*.cpp")

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} 
Main.cpp
)