cmake_minimum_required(VERSION 3.10)

project(YGODECK VERSION 1.0)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/bin)

# aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_FILE)
set(SRC_FILE ${PROJECT_SOURCE_DIR}/src/main.cpp ${PROJECT_SOURCE_DIR}/src/deck.cpp)
add_executable(ygodeck ${SRC_FILE})

set(SRC_FILE ${PROJECT_SOURCE_DIR}/src/test.cpp ${PROJECT_SOURCE_DIR}/src/deck.cpp)
add_executable(test ${SRC_FILE})
