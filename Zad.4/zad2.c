#include <stdio.h>

int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, left, mid - 1, x);

        return binarySearch(arr, mid + 1, right, x);
    }

    return -1;
}
int main() {
    int arr[] = {1, 4, 5, 8, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int result = binarySearch(arr, 0, n - 1, target);
    if (result != -1)
        printf("Element znajduje sie pod indeksem: %d\n", result);
    else
        printf("Element nie zostal znaleziony w tablicy.\n");
    return 0;
}
