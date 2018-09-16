cmake_minimum_required (VERSION 2.6)
project (xsvf)

include (CTest)

find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)
if (CMAKE_CXX_CPPCHECK)
    list(
        APPEND CMAKE_CXX_CPPCHECK 
            "--enable=warning"
            "--inline-suppr"
            "--suppressions-list=${CMAKE_SOURCE_DIR}/CppCheckSuppressions.txt"
    )
endif()

add_subdirectory(trunk)
add_subdirectory(lib)
add_subdirectory(tests)
