cmake_minimum_required(VERSION 3.10)

project(JieEngine)

set(CMAKE_CXX_STANDARD 17)

if(CMAKE_HOST_APPLE) #MacOS

    include_directories(/usr/local/include/)

    link_directories(/usr/local/lib/)
    
    link_libraries(-lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf)

elseif(CMAKE_HOST_UNIX) #Linux
 
    link_libraries(-lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf)
 
elseif(CMAKE_HOST_WIN32) #Windows

    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        link_libraries(-lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf)
    else()
        link_libraries(-lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -mwindows)
    endif()

endif()

include_directories(${PROJECT_SOURCE_DIR}/JieEngine/Include/) #引擎头文件路径

file(GLOB JieEngine "${PROJECT_SOURCE_DIR}/JieEngine/Src/*.cpp") #引擎源文件路径

#Debug

include_directories(${PROJECT_SOURCE_DIR}/Test/Include/) #测试项目头文件路径

file(GLOB Test "${PROJECT_SOURCE_DIR}/Test/Src/*.cpp") #测试项目源文件路径

add_executable(${CMAKE_PROJECT_NAME} ${JieEngine} ${Test})

# if(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Release"))

#     add_executable(${CMAKE_PROJECT_NAME} ${JieEngine} ${PROJECT_SOURCE_DIR}/JieEngine/Main.cpp)

# endif()

# if(CMAKE_HOST_APPLE) #MacOS
#     target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/JieEngine/Lib/MacOS.a)
# elseif(CMAKE_HOST_UNIX) #Linux
#     target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/JieEngine/Lib/Linux.a)
# elseif(CMAKE_HOST_WIN32) #Windows
#     target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/JieEngine/Lib/Windows.a)
# endif()