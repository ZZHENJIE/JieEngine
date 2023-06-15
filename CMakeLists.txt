cmake_minimum_required(VERSION 3.10)

project(JieEngine)

set(CMAKE_CXX_STANDARD 11)

if(CMAKE_HOST_APPLE) #MacOS

    include_directories(/usr/local/include/)

    link_directories(/usr/local/lib/)
    
    link_libraries(-lSDL2main -lDecrypt -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf)

elseif(CMAKE_HOST_UNIX) #Linux
 
    link_libraries(-lSDL2main -lDecrypt -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf)
 
elseif(CMAKE_HOST_WIN32) #Windows
 
    link_libraries(-lmingw32 -lDecrypt -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf) #有终端窗口
    # link_libraries(-lmingw32 -lDecrypt -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -mwindows) #无终端窗口

endif()

add_executable(${CMAKE_PROJECT_NAME}
Main.cpp
MainMapStruct.h
)