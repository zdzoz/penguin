target_sources(${PROJECT_NAME} PRIVATE window.h)

if(APPLE)
    target_sources(${PROJECT_NAME} PRIVATE Apple/OsxWindow.mm)
elseif(WIN32)
    target_sources(${PROJECT_NAME} PRIVATE Win32/Win32Window.cpp)
endif()
