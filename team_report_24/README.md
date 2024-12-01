# CPP_LoadBalancing_algorithm
for term project

## project structure
```text
.
??? document
??? scriptForRunning
?   ??? setup_and_build.ps1
??? team_report_24
    ??? CMakeLists.txt
    ??? csvLoader.h
    ??? graphic.cpp
    ??? jsonConverter.cpp
    ??? jsonFile
    ?   ??? results.json
    ??? JsonSaver.h
    ??? main.cpp
    ??? sortAlgorithm
    ?   ??? greedySort.cpp
    ?   ??? greedySort.h
    ?   ??? heapSort.cpp
    ?   ??? heapSort.h
    ?   ??? mergeSort.cpp
    ?   ??? mergeSort.h
    ?   ??? quickSort.cpp
    ?   ??? quickSort.h
    ??? traffic_data_set.csv
    ??? trafficFlow.h
```

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
include_directories(${CMAKE_SOURCE_DIR}/include)

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

## JSON for Modern C++ (nlohmann/json)
```bash
sudo apt-get update
sudo apt-get install nlohmann-json3-dev
```
## vcpkg install nlohmann-json
[vcpkg](https://github.com/microsoft/vcpkg)
```text
vcpkg install nlohmann-json
C:\vcpkg\installed\x64-windows\tools\install\include
```