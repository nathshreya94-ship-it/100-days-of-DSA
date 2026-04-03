#include <stdio.h>
#include <stdbool.h>

bool isComplete(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        if (2*i + 1 < n) {
            if (2*i + 2 >= n)
                continue;
        }
    }
    return true;
}

bool isMinHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        // Left child
        if (2*i + 1 < n && arr[i] > arr[2*i + 1])
            return false;

        if (2*i + 2 < n && arr[i] > arr[2*i + 2])
            return false;
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (isComplete(arr, n) && isMinHeap(arr, n))
        printf("YES");
    else
        printf("NO");

    return 0;
}