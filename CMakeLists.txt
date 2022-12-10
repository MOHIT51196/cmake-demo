cmake_minimum_required(VERSION 3.15)

# set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(cmakedemo VERSION 1.2)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(Math)

target_link_directories(${PROJECT_NAME} PUBLIC Math) # -L flag
target_link_libraries(${PROJECT_NAME} math) # -l flag

target_include_directories(${PROJECT_NAME} PUBLIC Math)

# Putting executable in /usr/bin/
install(TARGETS ${PROJECT_NAME} DESTINATION bin)