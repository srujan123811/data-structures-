#include <stdio.h>
#define SIZE 10
int hashTable[SIZE];
void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}
int hash(int key) {
    return key % SIZE;
}
void insert(int key) {
    int index = hash(key);
    int i = 0;
    while (hashTable[(index + i) % SIZE] != -1 && i < SIZE) {
        i++;
    }
    if (i == SIZE) {
        printf("Hash Table Overflow, cannot insert %d\n", key);
    } else {
        hashTable[(index + i) % SIZE] = key;
        printf("%d inserted at index %d\n", key, (index + i) % SIZE);
    }
}
int search(int key) {
    int index = hash(key);
    int i = 0;
    while (hashTable[(index + i) % SIZE] != -1 && i < SIZE) {
        if (hashTable[(index + i) % SIZE] == key)
            return (index + i) % SIZE;
        i++;
    }
    return -1;
}
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: %d\n", i, hashTable[i]);
    }
}
int main() {
    int choice, key, pos;
    init();
    do {
        printf("\n--- Hash Table Menu ---\n");
        printf("1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                pos = search(key);
                if (pos != -1)
                    printf("%d found at index %d\n", key, pos);
                else
                    printf("%d not found in hash table\n", key);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
