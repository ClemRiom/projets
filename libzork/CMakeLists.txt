cmake_minimum_required(VERSION 3.21.2)
project(zorkxplorer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(libzork)

find_library(YAML_CPP_LIB yaml-cpp REQUIRED)

add_executable(zorkxplorer 
    src/main.cc 
    src/options.cc
)

target_compile_options(zorkxplorer PRIVATE -Wall -Wextra -Werror -pedantic -Wold-style-cast)

target_link_libraries(zorkxplorer PRIVATE zork ${YAML_CPP_LIB})

target_include_directories(zorkxplorer PRIVATE src)
