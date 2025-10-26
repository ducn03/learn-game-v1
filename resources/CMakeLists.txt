cmake_minimum_required(VERSION 3.26)
project(LearnGame)

set(CMAKE_CXX_STANDARD 17)

# Đường dẫn gốc
set(PROJECT_ROOT "${CMAKE_SOURCE_DIR}/..")

# SFML
set(SFML_DIR "${PROJECT_ROOT}/lib/SFML-2.6.1")

# ========== DEBUG ==========
message(STATUS "=== DEBUG INFO ===")
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "PROJECT_ROOT: ${PROJECT_ROOT}")
message(STATUS "SFML_DIR: ${SFML_DIR}")

# Kiểm tra từng thư mục
if(EXISTS "${PROJECT_ROOT}")
    message(STATUS "✓ PROJECT_ROOT exists")
else()
    message(FATAL_ERROR "✗ PROJECT_ROOT NOT found: ${PROJECT_ROOT}")
endif()

if(EXISTS "${SFML_DIR}")
    message(STATUS "✓ SFML_DIR exists")
else()
    message(FATAL_ERROR "✗ SFML_DIR NOT found: ${SFML_DIR}")
endif()

if(EXISTS "${SFML_DIR}/include/SFML/Graphics.hpp")
    message(STATUS "✓ SFML Graphics.hpp found")
else()
    message(FATAL_ERROR "✗ SFML Graphics.hpp NOT found")
endif()

if(EXISTS "${PROJECT_ROOT}/src/main.cpp")
    message(STATUS "✓ main.cpp found")
else()
    message(FATAL_ERROR "✗ main.cpp NOT found")
endif()

if(EXISTS "${PROJECT_ROOT}/src/Game.cpp")
    message(STATUS "✓ Game.cpp found")
else()
    message(FATAL_ERROR "✗ Game.cpp NOT found")
endif()

message(STATUS "==================")
# ========== END DEBUG ==========

# Include directories
include_directories(${PROJECT_ROOT}/include)
include_directories(${SFML_DIR}/include)

# Link directories
link_directories(${SFML_DIR}/lib)

# Source files
set(SOURCES
        ${PROJECT_ROOT}/src/main.cpp
        ${PROJECT_ROOT}/src/Game.cpp
)

# Tạo executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link SFML
target_link_libraries(${PROJECT_NAME}
        sfml-graphics
        sfml-window
        sfml-system
)

# Copy DLL
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${SFML_DIR}/bin"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

# Working directory
set_target_properties(${PROJECT_NAME} PROPERTIES
        VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_ROOT}"
)