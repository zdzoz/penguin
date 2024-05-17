cmake_minimum_required(VERSION 3.22)
project(penguin VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED true)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_compile_options(-Wall -Wextra -Wpedantic)
if (MSVC)
  message("TODO: fix fsanitize on windows")
  # maybe need to disable ZI flag
  # add_compile_options(-fsanitize=address)
  # add_link_options(-fsanitize=address)
else()
  add_compile_options(-fsanitize=address,undefined)
  add_link_options(-fsanitize=address,undefined)
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  message(STATUS "Debug mode")
else()
  add_definitions(-DNDEBUG)
endif()

include(FetchContent)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt
  GIT_TAG        e69e5f977d458f2650bb346dadf2ad30c5320281 # 10.2.1
)
FetchContent_MakeAvailable(fmt)

message(STATUS "fmt succesfully installed in " ${fmt_SOURCE_DIR})

link_libraries(fmt)

add_subdirectory(src)
