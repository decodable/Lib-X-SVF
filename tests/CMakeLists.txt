cmake_minimum_required (VERSION 2.6)
project (xsvf_player_test)

SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/trunk)
include_directories(${CMAKE_SOURCE_DIR}/lib)

link_directories(${CMAKE_BINARY_DIR}/trunk)
link_directories(${CMAKE_BINARY_DIR}lib)
link_directories(/usr/local/lib)

add_executable(svf_player_test svf_player_test.cc)

# do not line gtest
# https://github.com/google/googletest/issues/930
target_link_libraries(svf_player_test gmock_main xsvf_player xsvf pthread)

add_test(svf_player_test svf_player_test)
