cmake_minimum_required(VERSION 3.21.2)
project(libzork LANGUAGES CXX)

find_library(YAML_CPP_LIB yaml-cpp REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.cc")

add_library(zork SHARED ${SOURCES})

target_compile_features(zork PRIVATE cxx_std_20)
target_compile_options(zork PRIVATE -Wall -Wextra -Werror -pedantic -Wold-style-cast)

target_link_options(zork PRIVATE "-Wl,--no-undefined")

target_include_directories(zork PUBLIC include src)
target_link_libraries(zork PRIVATE ${YAML_CPP_LIB})
