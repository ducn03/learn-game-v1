cmake_minimum_required(VERSION 3.26)
project(LearnGame)

set(CMAKE_CXX_STANDARD 17)

# ================== ROOT PATH ==================
set(PROJECT_ROOT "${CMAKE_SOURCE_DIR}/..")
set(SRC_DIR "${PROJECT_ROOT}/src")
set(SFML_DIR "${PROJECT_ROOT}/lib/SFML-2.6.1")

# ================== INCLUDE ALL SUBDIRS ==================
macro(include_all_subdirs BASE_DIR)
    file(GLOB_RECURSE SUBDIRS RELATIVE ${BASE_DIR} ${BASE_DIR}/*)
    set(INCLUDE_DIRS "")
    foreach(DIR ${SUBDIRS})
        if(IS_DIRECTORY "${BASE_DIR}/${DIR}")
            list(APPEND INCLUDE_DIRS "${BASE_DIR}/${DIR}")
        endif()
    endforeach()
    include_directories(${INCLUDE_DIRS})
endmacro()

include_all_subdirs(${SRC_DIR})
include_directories(${SRC_DIR})

# ================== SFML ==================
include_directories(${SFML_DIR}/include)
link_directories(${SFML_DIR}/lib)

# ================== SOURCE FILES ==================
file(GLOB_RECURSE SOURCES ${SRC_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES}
        ../src/components/button/Button.h
        ../src/components/menu/Menu.cpp
        ../src/components/menu/Menu.h
        ../src/core/logger/Logger.h
        ../src/core/logger/Logger.cpp
        ../src/utils/TextUtils.h
        ../src/utils/TextUtils.cpp)

target_link_libraries(${PROJECT_NAME}
        sfml-graphics
        sfml-window
        sfml-system
)

# ================== COPY DLL ==================
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${SFML_DIR}/bin"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

# ================== VS WORKING DIR ==================
set_target_properties(${PROJECT_NAME} PROPERTIES
        VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_ROOT}"
)
