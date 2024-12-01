# CPP_LoadBalancing_algorithm
for term project

## project structure
```text
.
├── document
├── scriptForRunning
│   └── setup_and_build.ps1
└── team_report_24
    ├── CMakeLists.txt
    ├── csvLoader.h
    ├── graphic.cpp
    ├── jsonConverter.cpp
    ├── jsonFile
    │   └── results.json
    ├── JsonSaver.h
    ├── main.cpp
    ├── sortAlgorithm
    │   ├── greedySort.cpp
    │   ├── greedySort.h
    │   ├── heapSort.cpp
    │   ├── heapSort.h
    │   ├── mergeSort.cpp
    │   ├── mergeSort.h
    │   ├── quickSort.cpp
    │   └── quickSort.h
    ├── traffic_data_set.csv
    └── trafficFlow.h
```


## Download and Install C++

### On Ubuntu
```bash
sudo apt update
sudo apt install g++
```

```cmake
cmake_minimum_required(VERSION 3.10)

# 프로젝트 이름 및 언어 설정
project(CPP_LoadBalancing_algorithm LANGUAGES CXX)

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 소스 파일 목록
set(SOURCES
        main.cpp
        trafficFlow.cpp
        csvLoader.cpp
        sortAlgorithm/quickSort.cpp
        sortAlgorithm/mergeSort.cpp
        sortAlgorithm/heapSort.cpp
        sortAlgorithm/greedySort.cpp
)

# 헤더 파일 경로 포함
include_directories(${CMAKE_SOURCE_DIR})

# 실행 파일 생성
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


## csv 파일 다운로드 
``` bash
# 윈도우는 직접 링크 클릭해서 다운로드 후 집어넣기  
wget https://file.nodove.com/d/file/traffic_data_set.csv
```