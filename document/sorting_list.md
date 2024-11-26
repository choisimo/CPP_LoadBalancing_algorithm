
| **알고리즘**         | **핵심 개념**                                                                 | **특징 및 차이점**                                                                                         |
|----------------------|------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------|
| **Greedy Sort**      | 탐욕적 선택으로 가장 작은/큰 요소를 반복적으로 선택.                         | 국소적 선택 반복. 매 단계에서 비교적 단순하지만, 전역 최적성을 보장하려면 문제 구조가 적합해야 함.            |
| **Merge Sort**       | 배열을 재귀적으로 분할한 뒤 병합하며 정렬.                                   | 안정적이고, 항상 \(O(n \log n)\) 보장. Greedy와 다르게 병합 단계에서 추가적인 작업 수행.                     |
| **Quick Sort**       | 피벗을 기준으로 작은 값과 큰 값을 분할 후 재귀적 정렬.                      | 불안정하지만 평균 \(O(n \log n)\). Greedy Sort보다 더 복잡한 분할 과정.                                      |
| **Heap Sort**        | 힙 구조를 활용하여 최대값/최소값을 정렬.                                     | Greedy와 유사하게 "최댓값/최솟값 선택" 느낌이 있으나, 힙 자료구조를 사용.                                   |
| **Bubble Sort**      | 인접한 요소를 비교하며 교환, 한 번 순회마다 가장 큰 값을 뒤로 보냄.          | Greedy에 비해 단순하고 느림. 반복적으로 가장 큰 값을 "탐욕적"으로 정렬하는 방식이 Greedy와 유사.             |
| **Insertion Sort**   | 현재 요소를 이미 정렬된 부분에 삽입.                                         | Greedy처럼 각 단계에서 작은 요소를 정렬된 부분으로 삽입. 그러나 전체적으로는 국소적 최적화에만 의존하지 않음. |
| **Selection Sort**   | 가장 작은/큰 요소를 선택하여 정렬된 영역에 삽입.                              | Greedy와 가장 비슷. 하지만 Selection Sort는 전체에서 최소/최대 탐색, Greedy는 문제에 따라 더 간단히 설계 가능.|
| **Shell Sort**       | 삽입 정렬의 개선 버전. 간격을 두어 부분 리스트를 삽입 정렬 후, 최종 정렬. | 삽입 정렬의 단점을 보완. Greedy와는 거리가 있음.                                                              |
| **Counting Sort**    | 정수의 개수를 세어 정렬.                                                   | Greedy와 거리가 있음.                                                                                       |
| **Radix Sort**       | 자릿수를 기준으로 정렬.                                                     | Greedy와 거리가 있음.                                                                                       |
| **Bucket Sort**      | 구간을 나누어 정렬.                                                         | Greedy와 거리가 있음.                                                                                       |
| **Topological Sort** | 방향 그래프의 정점을 순서대로 나열.                                         | Greedy와 거리가 있음.                                                                                       |
| **Cycle Sort**       | 정렬된 부분을 찾아 삽입.                                                    | Greedy와 거리가 있음.                                                                                       |
| **Cocktail Sort**    | 버블 정렬의 개선 버전. 양방향으로 정렬.                                     | Greedy와 거리가 있음.                                                                                       |
| **Gnome Sort**       | 인접한 요소를 비교하며 교환.                                                 | Greedy와 거리가 있음.                                                                                       |
| **Comb Sort**        | 버블 정렬의 개선 버전. 간격을 두어 정렬.                                    | Greedy와 거리가 있음.                                                                                       |
| **Pancake Sort**     | 뒤집기 연산을 통해 정렬.                                                    | Greedy와 거리가 있음.                                                                                       |
| **Bogo Sort**        | 무작위로 정렬 후, 정렬되었는지 확인.                                        | Greedy와 거리가 있음.                                                                                       |
| **Stooge Sort**      | 3분할 정렬.                                                                | Greedy와 거리가 있음.                                                                                       |
| **Bitonic Sort**     | 비트단위로 정렬.                                                            | Greedy와 거리가 있음.                                                                                       |
| **Bozo Sort**        | 무작위로 정렬 후, 정렬되었는지 확인.                                        | Greedy와 거리가 있음.                                                                                       |
| **Odd-Even Sort**    | 홀수/짝수 인덱스를 비교하며 정렬.                                           | Greedy와 거리가 있음.                                                                                       |
| **Stable Sort**      | 동일한 값에 대해 순서를 보존.                                               | Greedy와 거리가 있음.                                                                                       |
| **In-Place Sort**    | 추가 메모리를 사용하지 않고 정렬.                                           | Greedy와 거리가 있음.                                                                                       |
| **External Sort**    | 외부 저장소를 사용한 정렬.                                                  | Greedy와 거리가 있음.                                                                                       |
| **Adaptive Sort**    | 입력에 따라 성능이 변화.                                                    | Greedy와 거리가 있음.                                                                                       |
| **Natural Sort**     | 사람이 정렬한 것과 유사하게 정렬.                                           | Greedy와 거리가 있음.                                                                                       |
| **Timsort**          | Merge Sort와 Insertion Sort를 결합한 하이브리드 정렬.                       | Greedy와 거리가 있음.                                                                                       |
| **Introsort**        | Quick Sort와 Heap Sort를 결합한 하이브리드 정렬.                            | Greedy와 거리가 있음.                                                                                       |
| **Block Sort**       | 블록 단위로 정렬.                                                           | Greedy와 거리가 있음.                                                                                       |
| **Spreadsort**       | 특정한 상황에서 빠른 정렬을 보장.                                           | Greedy와 거리가 있음.                                                                                       |
| **Patience Sort**    | 카드 게임 솔리테어를 모방한 정렬.                                           | Greedy와 거리가 있음.                                                                                       |
| **Library Sort**     | 삽입 정렬과 힙 정렬을 결합한 하이브리드 정렬.                              | Greedy와 거리가 있음.                                                                                       |
| **Smoothsort**       | 힙 정렬의 개선 버전.                                                         | Greedy와 거리가 있음.                                                                                       |
| **Spaghetti Sort**   | 무작위로 정렬 후, 정렬되었는지 확인.                                        | Greedy와 거리가 있음.                                                                                       |
| **Stupid Sort**      | 무작위로 정렬 후, 정렬되었는지 확인.                                        | Greedy와 거리가 있음.                                                                                       |
| **Slowsort**         | 무작위로 정렬 후, 정렬되었는지 확인.                                        | Greedy와 거리가 있음.                                                                                       |
| **Bead Sort**        | 중력을 이용한 정렬.                                                         | Greedy와 거리가 있음.                                                                                       |
| **Binary Tree Sort** | 이진 트리를 이용한 정렬.                                                    | Greedy와 거리가 있음.                                                                                       |
| **Bose-Nelson Sort** | 비트 연산을 이용한 정렬.                                                    | Greedy와 거리가 있음.                                                                                       |
| **Burstsort**        | 블록 단위로 정렬.                                                           | Greedy와 거리가 있음.                                                                                       |
| **Cubesort**         | 큐브 단위로 정렬.                                                           | Greedy와 거리가 있음.                                                                                       |
| **Flashsort**        | 특정한 상황에서 빠른 정렬을 보장.                                           | Greedy와 거리가 있음.                                                                                       |
| **Fractalsort**      | 재귀적으로 정렬.                                                           | Greedy와 거리가 있음.                                                                                       |
| **Gapped Insertion Sort** | 삽입 정렬의 개선 버전. 간격을 두어 정렬.                                | Greedy와 거리가 있음.                                                                                       |
| **Library Sort**     | 삽입 정렬과 힙 정렬을 결합한 하이브리드 정렬.                              | Greedy와 거리가 있음.                                                                                       |
| **Patience Sort**    | 카드 게임 솔리테어를 모방한 정렬.                                           | Greedy와 거리가 있음.                                                                                       |
| **Smoothsort**       | 힙 정렬의 개선 버전.                                                         | Greedy와 거리가 있음.                                                                                       |
