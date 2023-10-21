cmake_minimum_required(VERSION 3.5)

project(plug LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(SUBHOOK_STATIC ON)

add_subdirectory(subhook)

include_directories(include)
add_compile_definitions(DEBUG=1)
set(SOURCES_PLUG
    "src/plug.cpp"
    "src/entry.cpp"
    "src/logger.cpp"
    "src/modules.cpp"
    "src/scanner.cpp"
)

add_library(plug SHARED ${SOURCES_PLUG})
target_link_libraries(plug subhook)
