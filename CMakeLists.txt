cmake_minimum_required(VERSION 3.10)

project(JieEngine)

# link_libraries(-lmingw32 -lSDL2main -lSDL2) #Windows 有终端窗口
# link_libraries(-lmingw32 -lSDL2main -lSDL2 -mwindows) #Windows 无终端窗口
link_libraries(-lSDL2main -lSDL2) # Linux(Ubuntu)

add_executable(${CMAKE_PROJECT_NAME}
./JieEngine/

MainMapBackground.h MainMapStruct.h Main.cpp
)