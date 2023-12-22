cmake_minimum_required(VERSION 3.12)

project(PZIX)

set(SOURCE_FILES
    src/core.cpp
    src/pzix.cpp
)

add_library(Pzix STATIC ${SOURCE_FILES})

target_include_directories(Pzix
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set(glm_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/glm)

target_include_directories(Pzix PRIVATE ${glm_INCLUDE_DIR})

target_include_directories(Pzix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_features(Pzix PRIVATE cxx_std_17)

enable_testing()

add_subdirectory(tests)
