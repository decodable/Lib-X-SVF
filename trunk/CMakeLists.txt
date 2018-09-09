cmake_minimum_required (VERSION 2.6)
project (libxsvf)

add_library(xsvf tap.c statename.c memname.c svf.c xsvf.c scan.c play.c)
