cmake_minimum_required(VERSION 3.10)

# 프로젝트 이름 및 언어 설정
project(CPP_LoadBalancing_algorithm LANGUAGES CXX)

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 소스 파일 목록
set(SOURCES
        main.cpp
        sortAlgorithm/quickSort.cpp
        sortAlgorithm/mergeSort.cpp
        sortAlgorithm/heapSort.cpp
        sortAlgorithm/greedySort.cpp
        jsonConverter.cpp
)

# 헤더 파일 경로 포함
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/include)

# 실행 파일 생성
add_executable(${PROJECT_NAME} ${SOURCES})