add_executable(${PROJECT_NAME}
    main.cpp
    window.h window.cpp
)

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)
