cmake_minimum_required(VERSION 3.15)

add_library(math math.cpp)

# Putting library in /usr/lib/ and header files in include/
install(TARGETS math DESTINATION lib)
install(FILES math.hpp DESTINATION include)