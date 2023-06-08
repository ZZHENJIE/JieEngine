cmake_minimum_required(VERSION 3.10)

project(JieEngine)

# link_libraries(-lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image) #Windows 有终端窗口
# link_libraries(-lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image -mwindows) #Windows 无终端窗口
link_libraries(-lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image) # Linux(Ubuntu)

add_executable(${CMAKE_PROJECT_NAME}
./JieEngine/

MainMapBackground.h MainMapStruct.h Main.cpp
)