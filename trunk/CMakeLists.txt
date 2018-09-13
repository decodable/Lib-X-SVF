cmake_minimum_required (VERSION 2.6)
project (libxsvf)

add_library(xsvf tap.c statename.c memname.c svf.c xsvf.c scan.c play.c)

add_executable(xsvftool-gpio xsvftool-gpio.c)
target_link_libraries(xsvftool-gpio xsvf)
target_compile_definitions(xsvftool-gpio PUBLIC XSVFTOOL_RLMS_VLINE)

add_executable(xsvftool-gpio-dummy xsvftool-gpio.c)
target_link_libraries(xsvftool-gpio-dummy xsvf)
