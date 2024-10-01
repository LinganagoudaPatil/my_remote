#include <stdio.h>
#include <string.h>

#define MAX_NAMES 100
#define MAX_NAME_LENGTH 50

// Function to perform binary search
int binarySearch(char names[][MAX_NAME_LENGTH], int left, int right, const char *target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Compare the middle name with the target name
        int result = strcmp(names[mid], target);

        // Check if target is present at mid
        if (result == 0) {
            return mid; // Name found
        }

        // If target is greater, ignore left half
        if (result < 0) {
            left = mid + 1;
        }
        // If target is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }
    return -1; // Name not found
}

int main() {
    char names[MAX_NAMES][MAX_NAME_LENGTH] = {
        "Alice", "Bob", "Charlie", "David", "Eva",
        "Frank", "Grace", "Hannah", "Irene", "Jack",
        "Kate", "Liam", "Mona", "Nina", "Oscar"
    };
    
    int n = 15; // Number of names in the list
    char target[MAX_NAME_LENGTH];

    // Input the name to search
    printf("Enter the name to search: ");
    fgets(target, sizeof(target), stdin);
    target[strcspn(target, "\n")] = 0; // Remove newline character

    // Perform binary search
    int result = binarySearch(names, 0, n - 1, target);

    // Output result
    if (result != -1) {
        printf("Name '%s' found at index %d.\n", target, result);
    } else {
        printf("Name '%s' not found in the list.\n", target);
    }

    return 0;
}
