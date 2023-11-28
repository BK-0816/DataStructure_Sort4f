#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int list[MAX_SIZE];
int n;

int comp_count = 0; // 비교 횟수 초기화
int move_count = 0; // 이동 횟수 초기화

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion_sort(int list[], int first, int last, int gap) {
    int i, j, key;

    for (i = first + gap; i <= last; i = i + gap) {
        key = list[i];
        comp_count++;

        for (j = i - gap; j >= first && key < list[j]; j = j - gap) {
            move_count++;
            list[j + gap] = list[j];
        }
        list[j + gap] = key;
    }
}

void shell_sort(int list[], int n, int num) {
    int i, gap;
    if (num == 19) {
        for (gap = n / 2; gap > 0; gap = gap / 2) {
            if ((gap % 2) == 0)
                gap++;
            print_array(list, n);
            for (i = 0; i < gap; i++) {
                insertion_sort(list, i, n - 1, gap);
            }
        }
    }
    else
        for (gap = n / 2; gap > 0; gap = gap / 2) {
            if ((gap % 2) == 0)
                gap++;
            for (i = 0; i < gap; i++) {
                insertion_sort(list, i, n - 1, gap);
            }
        }


}

int main(void) {
    int i;
    int totalComparisons = 0;
    int totalMoves = 0;
    n = MAX_SIZE;
    srand(time(NULL));

    // 20회 반복
    for (i = 0; i < 20; i++) {
        // 배열 초기화
        for (int j = 0; j < n; j++) {
            list[j] = rand() % 100;
        }
        if (i == 19) {
            printf("original list: ");
            print_array(list, n);
        }
        // 정렬 수행
        comp_count = 0;
        move_count = 0;
        shell_sort(list, n, i);

        // 각 반복에서의 비교 횟수와 이동 횟수를 누적
        totalComparisons += comp_count;
        totalMoves += move_count;
    }

    printf("Shell Sort: ");
    print_array(list, n);
    // 평균값 계산 및 출력
    int avgComparisons = totalComparisons / 20;
    int avgMoves = totalMoves / 20;

    printf("Average Comparisons: %d\n", avgComparisons);
    printf("Average Moves: %d\n", avgMoves);

    return 0;
}