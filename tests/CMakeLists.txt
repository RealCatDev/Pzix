cmake_minimum_required(VERSION 3.12)

project(PzixTests)

include_directories(${PZIX_INCLUDE_DIRS})

set(TEST_SOURCE_FILES
    test.cpp
)

add_executable(${PROJECT_NAME} ${TEST_SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} Pzix ${GTEST_MAIN_LIBRARIES})

set(glm_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/glm)

target_include_directories(${PROJECT_NAME} PRIVATE ${glm_INCLUDE_DIR})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

enable_testing()

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})