# CPP_LoadBalancing_algorithm
for term project

## Download and Install C++

### On Ubuntu
```bash
sudo apt update
sudo apt install g++
```

## On Windows 
[Download MinGW](https://sourceforge.net/projects/mingw-w64/)
```text
mingw-w64-install.exe

?? ? ???? ??
C:\MinGw\bin

cmd ??? g++ --version ?? ?? ??
```


# CMake

### On Ubuntu
```bash
sudo apt update
sudo apt-get install cmake
```

### On Windows  
[Download CMake](https://cmake.org/download/)
```text
cmake-3.21.3-windows-x86_64.msi

?? ? ???? ??
C:\Program Files\CMake\bin

cmd ??? cmake --version ?? ?? ??
```


```cmake
cmake_minimum_required(VERSION 3.10)

# ???? ?? ? ?? ??
project(CPP_LoadBalancing_algorithm LANGUAGES CXX)

# C++ ?? ??
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# ?? ?? ??
set(SOURCES
        main.cpp
        trafficFlow.cpp
        csvLoader.cpp
        sortAlgorithm/quickSort.cpp
        sortAlgorithm/mergeSort.cpp
        sortAlgorithm/heapSort.cpp
        sortAlgorithm/greedySort.cpp
)

# ?? ?? ?? ??
include_directories(${CMAKE_SOURCE_DIR})

# ?? ?? ??
add_executable(${PROJECT_NAME} ${SOURCES})
```

## install cmake
```bash
mdkir build
cd build
cmake ..
cmake --build .
./CPP_LoadBalancing_algorithm
```
