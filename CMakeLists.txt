cmake_minimum_required(VERSION 3.10)

project(JieEngine)

include_directories(${PROJECT_SOURCE_DIR}/Engine/Include/) #引擎头文件

include_directories(${PROJECT_SOURCE_DIR}/Include/) #项目头文件路径

if(CMAKE_HOST_APPLE)

    link_directories(${PROJECT_SOURCE_DIR}/Engine/Lib/MacOS)

    include_directories(/usr/local/include/)

    link_directories(/usr/local/lib/)

elseif(CMAKE_HOST_UNIX)

    link_directories(${PROJECT_SOURCE_DIR}/Engine/Lib/Linux)

elseif(CMAKE_HOST_WIN32)

    link_directories(${PROJECT_SOURCE_DIR}/Engine/Lib/Windows)

    link_libraries(-lmingw32)

    if(CMAKE_BUILD_TYPE STREQUAL "Release")

        link_libraries(-mwindows)

    endif()

endif()

link_libraries(-lJieEngine -lBox2D -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf)

file(GLOB JieEngine "${PROJECT_SOURCE_DIR}/Src/*.cpp") #项目源文件路径

add_executable(${PROJECT_NAME} ${JieEngine})