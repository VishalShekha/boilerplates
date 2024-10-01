#include <stdio.h>
#include <stdlib.h>

// Structure for doubly linked list node
typedef struct ll {
    int ele;
    struct ll* next;
    struct ll* prev;
} list;

// Function to add a node at the end of the list
void addLast(list* header, list* newNode) {
    list* temp = header->prev; // The last node before the header
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = header; // Link the new node to the header
    header->prev = newNode; // Update the header's prev pointer
}

// Function to delete the first node of the list
void deleteFirst(list* header) {
    if (header->next == header) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    list* temp = header->next; // First node
    header->next = temp->next;
    temp->next->prev = header;
    printf("Deleted element: %d\n", temp->ele);
    free(temp);
}

// Function to peek (print) the first element of the list
void peekFirst(list* header) {
    if (header->next == header) {
        printf("List is empty.\n");
        return;
    }
    printf("First element: %d\n", header->next->ele);
}

// Function to print all elements in the list
void printList(list* header) {
    if (header->next == header) {
        printf("List is empty.\n");
        return;
    }
    list* temp = header->next;
    printf("List elements: ");
    while (temp != header) {
        printf("%d ", temp->ele);
        temp = temp->next;
    }
    printf("\n");
}

// Function to find an element in the list
list* Find(list* header, int e) {
    list* temp = header->next;
    while (temp != header) {
        if (temp->ele == e) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL; // Element not found
}

int main() {
    int n;
    printf("Enter the number of elements to add initially: ");
    scanf("%d", &n);

    // Initialize the header node for the doubly linked list (circular)
    list* header = (list*)malloc(sizeof(list)); // Header node (dummy node)
    header->next = header; // Points to itself initially (empty list)
    header->prev = header; // Points to itself initially (empty list)

    // Adding initial elements to the list
    for (int i = 0; i < n; i++) {
        int x;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &x);
        list* newNode = (list*)malloc(sizeof(list)); // Create new node
        newNode->ele = x;
        newNode->next = NULL;
        newNode->prev = NULL;
        addLast(header, newNode); // Add to the end of the list
    }

    while (1) {
        printf("\nEnter the operation to be done\n1.Add Element\n2.Delete First Element\n3.Peek First Element\n4.Print List\n5.Find Element\n6.Exit\n: ");
        int op;
        scanf("%d", &op);

        switch (op) {
            case 1: {
                printf("Enter the element to be added: ");
                int x;
                scanf("%d", &x);
                list* newNode = (list*)malloc(sizeof(list)); 
                newNode->ele = x;
                newNode->next = NULL;
                newNode->prev = NULL;
                addLast(header, newNode); // Add to the end of the list
                break;
            }
            case 2: 
                deleteFirst(header); // Delete the first element
                break;

            case 3: 
                peekFirst(header); // Peek at the first element
                break;

            case 4: 
                printList(header); // Print the entire list
                break;

            case 5: {
                printf("Enter the element to find: ");
                int e;
                scanf("%d", &e);
                list* found = Find(header, e); // Search for the element
                if (found != NULL)
                    printf("Element %d found.\n", e);
                else
                    printf("Element %d not found.\n", e);
                break;
            }
            case 6: 
                return 0; // Exit the program

            default: 
                printf("Enter a valid number.\n");
                break;
        }
    }

    return 0;
}
