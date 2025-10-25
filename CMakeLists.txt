cmake_minimum_required(VERSION 3.16)
project(FiguresProject LANGUAGES CXX)

# ------------------- Стандарт языка -------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ------------------- Флаги компиляции -------------------
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror=maybe-uninitialized")

# ------------------- Пути -------------------
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

# ------------------- Исходники библиотеки -------------------
set(SOURCES
    ${SRC_DIR}/figure.cpp
    ${SRC_DIR}/rectangle.cpp
    ${SRC_DIR}/trapezoid.cpp
    ${SRC_DIR}/rhombus.cpp
)

# ------------------- Библиотека -------------------
add_library(FiguresLib STATIC ${SOURCES})
target_include_directories(FiguresLib PUBLIC ${INCLUDE_DIR})

# ------------------- Исполняемый файл -------------------
add_executable(FiguresMain main.cpp)
target_link_libraries(FiguresMain PRIVATE FiguresLib)

# ------------------- GoogleTest -------------------
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.0
    TLS_VERIFY false
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests
    ${CMAKE_SOURCE_DIR}/test/tests01.cpp
)
target_link_libraries(tests PRIVATE FiguresLib gtest_main)
add_test(NAME FiguresTests COMMAND tests)
