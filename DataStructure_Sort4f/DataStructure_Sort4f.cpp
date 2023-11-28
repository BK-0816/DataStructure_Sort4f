#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int list[MAX_SIZE];
int n;

int comp_count = 0; // �� Ƚ�� �ʱ�ȭ
int move_count = 0; // �̵� Ƚ�� �ʱ�ȭ

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

    // 20ȸ �ݺ�
    for (i = 0; i < 20; i++) {
        // �迭 �ʱ�ȭ
        for (int j = 0; j < n; j++) {
            list[j] = rand() % 100;
        }
        if (i == 19) {
            printf("original list: ");
            print_array(list, n);
        }
        // ���� ����
        comp_count = 0;
        move_count = 0;
        shell_sort(list, n, i);

        // �� �ݺ������� �� Ƚ���� �̵� Ƚ���� ����
        totalComparisons += comp_count;
        totalMoves += move_count;
    }

    printf("Shell Sort: ");
    print_array(list, n);
    // ��հ� ��� �� ���
    int avgComparisons = totalComparisons / 20;
    int avgMoves = totalMoves / 20;

    printf("Average Comparisons: %d\n", avgComparisons);
    printf("Average Moves: %d\n", avgMoves);

    return 0;
}