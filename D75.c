#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int maxLen = 0;

    // Hash map (simple array simulation)
    // Range assumption (-10000 to 10000)
    int hash[20001];
    for(int i = 0; i < 20001; i++) hash[i] = -1;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if(prefixSum == 0) {
            maxLen = i + 1;
        }

        int index = prefixSum + 10000;

        if(hash[index] != -1) {
            int len = i - hash[index];
            if(len > maxLen) {
                maxLen = len;
            }
        } else {
            hash[index] = i; // store first occurrence
        }
    }

    printf("%d\n", maxLen);

    return 0;
}