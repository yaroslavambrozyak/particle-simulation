cmake_minimum_required(VERSION 3.16)
project(particleSim LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

include_directories(src)

add_executable(particleSim 
src/main.cpp 
src/world/world.h 
src/world/world.cpp 
src/simulation.h 
src/simulation.cpp 
src/screen.h 
src/screen.cpp 
 
src/particle/particle.h 
src/particle/particle.cpp 
src/particle/sand.h 
src/particle/sand.cpp 
src/world/world_cell.h
src/world/world_cell.cpp 
src/editor/brush.h 
src/editor/editor.h 
src/editor/editor.cpp
)

target_link_libraries(particleSim PRIVATE sfml-graphics)
target_compile_features(particleSim PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET particleSim
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:particleSim>
        VERBATIM)
endif()
