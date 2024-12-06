# CPP_LoadBalancing_algorithm
for term project

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
### **결과 분석 - 알고리즘 성능 비교**

| **알고리즘** | **응답 시간 (초)** | **메모리 사용량**          | **특징 및 최적화 가능성**                                                                          |
|--------------|---------------|----------------------------|----------------------------------------------------------------------------------------------------|
| **GreedySort** | -             | 약 100GB (동적 메모리 사용) | 힙을 사용하는 알고리즘으로 추가 메모리와 실행 시간이 균형 잡힘. 힙 크기 관리로 메모리 사용 최적화 가능. |
| **HeapSort**  | -         | 없음                       | 제자리 정렬로 추가 메모리를 사용하지 않음. 안정적인 응답 시간 제공.                              |
| **MergeSort** | -        | 약 2TB (새 배열 생성)       | 병합 과정에서 추가 메모리 많이 사용. 메모리 복사 비용 최적화 가능.                                 |
| **QuickSort** | -         | 없음                       | 평균적으로 가장 빠른 응답 시간. 분할 과정에서 랜덤 피벗 적용 시 불균형 문제 해결 가능.             |

---

### **그래프 및 시각 자료 추가 준비**
1. 응답 시간 비교 그래프
    - x축: 알고리즘
    - y축: 응답 시간 (초)

2. 메모리 사용량 비교 그래프
    - x축: 알고리즘
    - y축: 메모리 사용량 (GB)

--- 

이 표를 발표 자료에 추가하여 알고리즘별 장단점을 명확히 전달할 수 있습니다.