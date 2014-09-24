cmake_minimum_required(VERSION 2.8)
project(Stellarium::Blender)

if( NOT CMAKE_BUILD_TYPE )
  set( CMAKE_BUILD_TYPE Debug CACHE STRING
       "Choose the type of build, options are: None Debug Release RelWithDebInfo
MinSizeRel."
       FORCE )
endif()

find_package(Boost COMPONENTS log program_options REQUIRED)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
else()
    message("Boost not found on this system")
endif()

find_package(OpenCV REQUIRED)

include_directories(include)

set(sources
    src/main.cpp
    src/options.cpp)

add_executable(blender ${sources})
target_link_libraries(blender ${OpenCV_LIBS} ${Boost_LIBRARIES})