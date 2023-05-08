//Name - Madhur Bajpai
//Reg. No. - 2022ca047
//Date - 23/03/2023

//Objective - Implementation of the tournament sort

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void tournamentSort(int arr[], int n) {
    int tree[2 * n - 1];
    for (int i = 0; i < n; i++) {
        tree[n - 1 + i] = i;
    }
    for (int i = n - 2; i >= 0; i--) {
        int left = tree[2 * i + 1];
        int right = tree[2 * i + 2];
        if (arr[left] > arr[right]) {
            tree[i] = left;
        } else {
            tree[i] = right;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int winner = tree[0];
        swap(&arr[winner], &arr[n - 1 - i]);
        int j = n - 2 - i;
        while (j > 0) {
            int parent = (j - 1) / 2;
            int sibling = (j % 2 == 0) ? j - 1 : j + 1;
            if (arr[tree[sibling]] > arr[tree[j]]) {
                j = sibling;
            }
            tree[parent] = tree[j];
            j = parent;
        }
        tree[0] = tree[1];
    }
}

int main() {
    int arr[] = {4, 1, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    tournamentSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}