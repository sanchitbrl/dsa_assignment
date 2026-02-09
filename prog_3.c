#include <stdio.h>
#include <stdlib.h>

// node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// function to create new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// insert node at end of list
void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// normal traversal (forward)
void forwardTraversal(Node *head) {
    printf("Forward Traversal: ");
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// reverse traversal using recursion
void reverseTraversal(Node *head) {
    if (head == NULL) {
        return;
    }
    
    // first go to end of list
    reverseTraversal(head->next);
    
    // then print while coming back
    printf("%d ", head->data);
}

// wrapper function for reverse traversal
void printReverse(Node *head) {
    printf("Reverse Traversal: ");
    reverseTraversal(head);
    printf("\n");
}

// display list
void displayList(Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// count nodes in list
int countNodes(Node *head) {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    Node *head = NULL;
    
    printf("Linked List - Reverse Traversal Demo\n");
    printf("=====================================\n\n");
    
    // insert elements
    printf("Inserting elements: 10, 20, 30, 40, 50\n\n");
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    
    // display list structure
    printf("Linked List Structure:\n");
    displayList(head);
    printf("\n");
    
    // show count
    printf("Total nodes: %d\n\n", countNodes(head));
    
    // forward traversal
    forwardTraversal(head);
    
    // reverse traversal
    printReverse(head);
    
    printf("\n");
    
    return 0;
}
