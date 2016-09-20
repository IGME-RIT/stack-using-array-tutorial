
if(WIN32)
cmake_minimum_required (VERSION 3.6)
else()
cmake_minimum_required (VERSION 3.0)
endif()

project(stack-using-array-tutorial)
add_executable(${PROJECT_NAME} StackUsingArray.cpp)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
