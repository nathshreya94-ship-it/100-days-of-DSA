#include <stdio.h>

int main() {
    int p, q;
    int a[100], b[100];
    int i = 0, j = 0;

    scanf("%d", &p);
    for (int k = 0; k < p; k++)
        scanf("%d", &a[k]);

    scanf("%d", &q);
    for (int k = 0; k < q; k++)
        scanf("%d", &b[k]);

    while (i < p && j < q) {
        if (a[i] <= b[j])
            printf("%d ", a[i++]);
        else
            printf("%d ", b[j++]);
    }

    while (i < p)
        printf("%d ", a[i++]);

    while (j < q)
        printf("%d ", b[j++]);

    return 0;
}
