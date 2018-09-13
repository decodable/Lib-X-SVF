cmake_minimum_required (VERSION 2.6)
project (xsvf_player_test)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(${CMAKE_SOURCE_DIR}/trunk)
include_directories(${CMAKE_SOURCE_DIR}/lib)

link_directories(${CMAKE_BINARY_DIR}/trunk)
link_directories(${CMAKE_BINARY_DIR}lib)

add_executable(xsvf_player_test svf_player_test.cc)
target_link_libraries(xsvf_player_test xsvf_player xsvf gmock GTest::GTest GTest::Main pthread)
