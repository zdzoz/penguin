add_executable(${PROJECT_NAME}
    main.cpp
)

add_subdirectory(window)

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)

target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
