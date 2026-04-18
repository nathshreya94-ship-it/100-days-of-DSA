#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[n][50];

    for(int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    // Count frequencies
    int count[n];
    for(int i = 0; i < n; i++) {
        count[i] = 1;
        for(int j = i + 1; j < n; j++) {
            if(strcmp(names[i], names[j]) == 0) {
                count[i]++;
                // Mark duplicate as counted
                strcpy(names[j], "");
            }
        }
    }

    // Find max votes
    int maxVotes = 0;
    char winner[50];

    for(int i = 0; i < n; i++) {
        if(strlen(names[i]) == 0) continue;

        if(count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        }
        else if(count[i] == maxVotes) {
            // Lexicographically smaller
            if(strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}