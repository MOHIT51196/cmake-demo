# Introduction to CMAKE

## CLASSIC WAY (WITHOUT CMAKE/MAKE)

### 1. Without library

#### Compile the code using paths
```
g++ -Wall ./Math/math.cpp main.cpp
```


### 2. With library

#### Create the library
```
cd Math/
g++ -c math.cpp -o math.o
g++ -shared -o libmath.so math.o  // donot forget to put lib word as prefix for library name
```

#### Compile the code libary
```
g++ -Wall -LMath/ main.cpp -o app -lmath  // -L specify library path and -l specify library name with prefix 'lib'
```

For more details refer to https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html


## Using CMAKE

### 1. Without Library

#### CMAKE file mentioning cpp(s) in add_executable

```
cmake_minimum_required(VERSION 3.15)

project(cmakedemo VERSION 1.2)

add_executable(${PROJECT_NAME} Math/math.cpp main.cpp)
```

### 2. With Library (pre-compiled)

Assuming that there is .so or .dll file present in the library directory. Following steps can working

#### CMAKE file linking libraries

```
cmake_minimum_required(VERSION 3.15)

project(cmakedemo VERSION 1.2)

add_executable(${PROJECT_NAME} main.cpp)

target_link_directories(${PROJECT_NAME} PUBLIC Math) # -L flag
target_link_libraries(${PROJECT_NAME} math) # -l flag
```
In this configuration, header file still needs to be included with a path ex. ```#include<Math/math.hpp>```
whereas, if header files are desired to be include with just names ex. ```#include<math.cpp>```, 
directories should be included

#### CMAKE file linking libraries with include directories

```
cmake_minimum_required(VERSION 3.15)

project(cmakedemo VERSION 1.2)

add_executable(${PROJECT_NAME} main.cpp)

target_link_directories(${PROJECT_NAME} PUBLIC Math) # -L flag
target_link_libraries(${PROJECT_NAME} math) # -l flag

target_include_directories(${PROJECT_NAME} PUBLIC Math)
```

### 3. With CMAKE supported Library 

No .so or .dll file is required , but a cmake library directory is required in these steps.

#### CMAKE file linking CMAKE library

Use ```add_subdirectory(...)``` to attach a cmake sub directory with the root directory

Add CMakeLists.txt to Library directory

```
cmake_minimum_required(VERSION 3.15)

add_library(math math.cpp)
```

Add CMakeLists.txt to Project directory

```
cmake_minimum_required(VERSION 3.15)

project(cmakedemo VERSION 1.2)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(Math)

target_link_directories(${PROJECT_NAME} PUBLIC Math) # -L flag
target_link_libraries(${PROJECT_NAME} math) # -l flag

target_include_directories(${PROJECT_NAME} PUBLIC Math)
```




# Inroduction to CPACK

## INSTALLATION OF EXECUTABLE

#### POINTS TO REMEMBER
1. /usr/include/ folder should contain the header files 
2. /usr/lib/ folder should contain the dynamic libraries such as .so/.dll/.lib files
3. /usr/bin/ folder should contain the executable



### CMakeLists.txt in Library directory

```
cmake_minimum_required(VERSION 3.15)

add_library(math math.cpp)

# Putting library in /usr/lib/ and header files in /usr/include/
install(TARGETS math DESTINATION lib)
install(FILES math.hpp DESTINATION include)
```

### CMakeLists.txt in Project directory

```
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
```