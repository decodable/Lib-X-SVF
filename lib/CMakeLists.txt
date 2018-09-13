cmake_minimum_required (VERSION 2.6)
project (xsvf_player)

include_directories(${PROJECT_SOURCE_DIR}/../trunk)
add_library(xsvf_player xsvf_player_base.cc xsvf_player.cc xsvf_file_host.cc)
