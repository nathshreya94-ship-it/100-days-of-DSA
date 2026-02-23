#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int count = 0;

    int freq[20001] = {0};  
    int offset = 10000;     
    freq[offset] = 1;  
    
    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if(freq[prefixSum + offset] > 0) {
            count += freq[prefixSum + offset];
        }

        freq[prefixSum + offset]++;
    }

    printf("%d", count);

    return 0;
}