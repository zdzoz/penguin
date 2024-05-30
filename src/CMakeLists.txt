add_executable(${PROJECT_NAME}
    main.cpp
    window/window.h
)

if(APPLE)
    target_sources(${PROJECT_NAME} PRIVATE window/Apple/OsxWindow.mm)

elseif(WIN32)
    target_sources(${PROJECT_NAME} PRIVATE window/Win32/Win32Window.cpp)
endif()

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)

target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
