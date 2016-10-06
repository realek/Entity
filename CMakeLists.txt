cmake_minimum_required(VERSION 3.6)
project(EntityFM)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
file(GLOB SOURCE_FILES
    "src/*.h"
    "src/*.hpp"
    "src/*.cpp"
)

# GLM -- on Windows: depends on env var: GLM_ROOT_DIR
find_package (glm REQUIRED)

IF(UNIX AND NOT APPLE)
    IF( glm_FOUND )
        INCLUDE_DIRECTORIES( ${GLM_INCLUDE_DIR} )
    ELSE( glm_FOUND )
        MESSAGE( STATUS "Failed to find GLM ----------------------")
    ENDIF( glm_FOUND )
ELSE(UNIX AND NOT APPLE)
    IF( GLM_FOUND )
        INCLUDE_DIRECTORIES( ${GLM_INCLUDE_DIR} )
    ELSE( GLM_FOUND )
        MESSAGE( STATUS "Failed to find GLM ----------------------")
    ENDIF( GLM_FOUND )
ENDIF(UNIX AND NOT APPLE)

add_executable(Entity ${SOURCE_FILES})