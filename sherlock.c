#include <stdio.h>

// Define the node structure for the linked list
typedef struct node_t {
    char alphabet;
    struct node_t* link;
} node_t;

int main() {
    // Initialize nodes (assuming the structure is defined as above)
    node_t l1 = {'F', NULL};
    node_t l2 = {'M', NULL};
    node_t l3 = {'A', NULL};
    node_t l4 = {'I', NULL};
    node_t l5 = {'K', NULL};
    node_t l6 = {'T', NULL};
    node_t l7 = {'N', NULL};
    node_t l8 = {'O', NULL};
    node_t l9 = {'R', NULL};

    // Build the linked list based on the given connections (assuming the arrows start from N)
    l3.link = &l1; // N -> F
    l1.link = &l8; // F -> O
    l8.link = &l9; // O -> R
    l9.link = &l2; // R -> M
    l2.link = &l4; // M -> A
    l4.link = &l7; // A -> T
    l7.link = &l5; // T -> I
    l5.link = &l6; // I -> K
    l6.link = &l3; // K -> A (loop back to A)

    // Access data starting from node l3 (letter N)
    node_t* current = &l3;
    char targetWord[] = "INFORMATIKA";
    int targetLength = sizeof(targetWord) - 1; // Excluding null terminator
    int count = 0;

    // Iterate through the linked list
    while (current != NULL && count < targetLength) {
        // Check if the current alphabet matches the expected alphabet from the target word
        if (current->alphabet == targetWord[count]) {
            // Print the current alphabet
            printf("%c", current->alphabet);
            // Move to the next alphabet in the target word
            count++;
        }
        // Move to the next node in the linked list
        current = current->link;
    }

    printf("\n"); // Add a newline for better formatting

    return 0;
}
