#include <stdio.h>
int main() {
    int n;
    printf("Enter how many numbers: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Even numbers: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0)
            printf("%d ", arr[i]);
    }
    printf("\nOdd numbers: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0)
            printf("%d ", arr[i]);
    }
    return 0;
}

