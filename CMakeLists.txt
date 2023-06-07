cmake_minimum_required(VERSION 3.10)

project(JieEngine)

# link_libraries(-lmingw32 -lSDL2main -lSDL2) #Windows 有终端窗口
# link_libraries(-lmingw32 -lSDL2main -lSDL2 -mwindows) #Windows 无终端窗口
link_libraries(-lSDL2main -lSDL2) # Linux(Ubuntu)

add_executable(${CMAKE_PROJECT_NAME}
JieEngine.h Window.h Map.h 
MapBackground.h MapStruct.h Ui.h 
Component.h Animal.h Animation.h 
Still.h

./TestGame/Main.cpp
./TestGame/OneMapBackground.h
./TestGame/OneMapBackground.cpp
./TestGame/OneMapStruct.h
./TestGame/OneMapStruct.cpp
./TestGame/Player.h
./TestGame/Player.cpp
./TestGame/Barrier.h
)