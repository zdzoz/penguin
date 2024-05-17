cmake_minimum_required(VERSION 3.22)
project(penguin VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED true)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

if (MSVC)
  message("TODO: fix fsanitize on windows")
  set(COMPILE_OPTS -Wall -Wextra -Wpedantic)
  # maybe need to disable ZI flag
  # set(COMPILE_OPTS -Wall -Wextra -Wpedantic -fsanitize=address,undefined)
  # set(LINK_OPTS -fsanitize=address,undefined)
elseif(APPLE)
  enable_language(OBJC OBJCXX)
  set(COMPILE_OPTS -Wall -Wextra -Wpedantic -fsanitize=address,undefined)
  set(LINK_OPTS -fsanitize=address,undefined)
else()
  set(COMPILE_OPTS -Wall -Wextra -Wpedantic -fsanitize=address,undefined)
  set(LINK_OPTS -fsanitize=address,undefined)
endif()

add_compile_options(${COMPILE_OPTS})
add_link_options(${LINK_OPTS})

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
