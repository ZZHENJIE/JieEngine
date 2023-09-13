cmake_minimum_required(VERSION 3.10)

project(JieEngineDemo)

include_directories(${PROJECT_SOURCE_DIR}/Engine/Include/)
file(GLOB Box2D "${PROJECT_SOURCE_DIR}/Engine/Src/Box2D/*.cpp")
file(GLOB JieEngine "${PROJECT_SOURCE_DIR}/Engine/Src/JieEngine/*.cpp")

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_subdirectory(${PROJECT_SOURCE_DIR}/Engine/Src/JieEngine)
    add_subdirectory(${PROJECT_SOURCE_DIR}/Engine/Src/Box2D)
endif()

if(CMAKE_HOST_APPLE)
    include_directories(/usr/local/include/)
    link_directories(/usr/local/lib/)
elseif(CMAKE_HOST_WIN32)
    link_libraries(-lmingw32)
endif()

link_libraries(-lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf)

include_directories(${PROJECT_SOURCE_DIR}/Include/) #项目头文件路径
file(GLOB JieEngineDemo "${PROJECT_SOURCE_DIR}/Src/*.cpp") #项目引擎文件路径

add_executable(${PROJECT_NAME} ${Box2D} ${JieEngine} ${JieEngineDemo})