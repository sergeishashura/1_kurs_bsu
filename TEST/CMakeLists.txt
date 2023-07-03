cmake_minimum_required(VERSION 3.0.0)
project(laba2_2_Cmake VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(laba2_2_Cmake main.cpp List.cpp)
set_target_properties(laba2_2_Cmake PROPERTIES CXX_EXTENSIONS OFF)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
