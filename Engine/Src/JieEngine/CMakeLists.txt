set(JieEngine_SOURCE_FILES
    JE_Unpack.cpp
    JE_Map.cpp
    JE_World.cpp
    JE_Entity.cpp
    JE_Box2DFunction.cpp
    JE_System.cpp
    JE.cpp
    JE_Compress.cpp
    JEAnimationSystem.cpp
    JEImageSystem.cpp
)

add_library(JieEngine STATIC ${JieEngine_SOURCE_FILES})
set_target_properties(JieEngine PROPERTIES OUTPUT_NAME "JieEngine")
set_target_properties(JieEngine PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
set_target_properties(JieEngine PROPERTIES PREFIX "lib")