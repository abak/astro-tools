include_directories(include)

set(sources
    src/main.cpp
    src/options.cpp
    src/processor.cpp)

add_executable(blender ${sources})
target_link_libraries(blender ${OpenCV_LIBS} ${Boost_LIBRARIES})