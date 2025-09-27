#include <stdio.h>
int main() {
    int arr[100], n, choice, pos, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    do {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter position and value: ");
                scanf("%d %d", &pos, &val);
                for (int i = n; i > pos; i--)
                    arr[i] = arr[i - 1];
                arr[pos] = val;
                n++;
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                for (int i = pos; i < n - 1; i++)
                    arr[i] = arr[i + 1];
                n--;
                break;
            case 3:
                printf("Array: ");
                for (int i = 0; i < n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;
        }
    } while (choice != 4);
    return 0;
}

