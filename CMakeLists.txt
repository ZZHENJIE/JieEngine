cmake_minimum_required(VERSION 3.10)

project(JieEngine)

if(CMAKE_HOST_SYSTEM_NAME MATCHES "Linux") #Linux
 
    link_libraries(-lSDL2main -lDecrypt -lSDL2 -lSDL2_mixer -lSDL2_image)
 
elseif(CMAKE_HOST_SYSTEM_NAME MATCHES "Windows") #Windows
 
    link_libraries(-lmingw32 -lDecrypt -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image) #有终端窗口
    # link_libraries(-lmingw32 -lDecrypt -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image -mwindows) #无终端窗口

endif()

add_executable(${CMAKE_PROJECT_NAME}
MainMapBackground.h MainMapStruct.h Main.cpp
)