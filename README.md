# CPP_LoadBalancing_algorithm
for term project

## project structure
```angular2html
.
├── al.pdf
├── document
│   └── sorting_list.md
├── README.md
├── scriptForRunning
│   └── setup_and_build.ps1
└── team_report_24
    ├── build
    │   ├── CMakeCache.txt
    │   ├── CMakeFiles
    │   │   ├── 3.28.3
    │   │   │   ├── CMakeCXXCompiler.cmake
    │   │   │   ├── CMakeDetermineCompilerABI_CXX.bin
    │   │   │   ├── CMakeSystem.cmake
    │   │   │   └── CompilerIdCXX
    │   │   │       ├── a.out
    │   │   │       ├── CMakeCXXCompilerId.cpp
    │   │   │       └── tmp
    │   │   ├── cmake.check_cache
    │   │   ├── CMakeConfigureLog.yaml
    │   │   ├── CMakeDirectoryInformation.cmake
    │   │   ├── CMakeScratch
    │   │   ├── CPP_LoadBalancing_algorithm.dir
    │   │   │   ├── build.make
    │   │   │   ├── cmake_clean.cmake
    │   │   │   ├── compiler_depend.make
    │   │   │   ├── compiler_depend.ts
    │   │   │   ├── DependInfo.cmake
    │   │   │   ├── depend.make
    │   │   │   ├── flags.make
    │   │   │   ├── jsonConverter.cpp.o
    │   │   │   ├── jsonConverter.cpp.o.d
    │   │   │   ├── link.txt
    │   │   │   ├── main.cpp.o
    │   │   │   ├── main.cpp.o.d
    │   │   │   ├── progress.make
    │   │   │   └── sortAlgorithm
    │   │   │       ├── greedySort.cpp.o
    │   │   │       ├── greedySort.cpp.o.d
    │   │   │       ├── heapSort.cpp.o
    │   │   │       ├── heapSort.cpp.o.d
    │   │   │       ├── mergeSort.cpp.o
    │   │   │       ├── mergeSort.cpp.o.d
    │   │   │       ├── quickSort.cpp.o
    │   │   │       └── quickSort.cpp.o.d
    │   │   ├── Makefile2
    │   │   ├── Makefile.cmake
    │   │   ├── pkgRedirects
    │   │   ├── progress.marks
    │   │   └── TargetDirectories.txt
    │   ├── cmake_install.cmake
    │   ├── CPP_LoadBalancing_algorithm
    │   └── Makefile
    ├── CMakeLists.txt
    ├── csvLoader.h
    ├── graphic.cpp
    ├── jsonConverter.cpp
    ├── jsonFile
    │   └── results.json
    ├── JsonSaver.h
    ├── main.cpp
    ├── README.md
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

15 directories, 59 files
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