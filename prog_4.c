#include <stdio.h>
#include <stdlib.h>

// doubly linked list node structure
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// create new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// insert at end (helper function)
void insert_end(Node **head, int data) {
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
    newNode->prev = temp;
}

// insert after a given node
void insert_after(Node *prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    
    Node *newNode = createNode(data);
    
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    
    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }
    
    prevNode->next = newNode;
    
    printf("Inserted %d after %d\n", data, prevNode->data);
}

// delete a node
void deleteNode(Node **head, Node *delNode) {
    if (*head == NULL || delNode == NULL) {
        printf("Cannot delete - invalid node\n");
        return;
    }
    
    // if node to be deleted is head
    if (*head == delNode) {
        *head = delNode->next;
    }
    
    // change next only if node is not last
    if (delNode->next != NULL) {
        delNode->next->prev = delNode->prev;
    }
    
    // change prev only if node is not first
    if (delNode->prev != NULL) {
        delNode->prev->next = delNode->next;
    }
    
    printf("Deleted node with data: %d\n", delNode->data);
    free(delNode);
}

// find node with specific data
Node* findNode(Node *head, int data) {
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// display list forward
void displayForward(Node *head) {
    printf("Forward: ");
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// display list backward
void displayBackward(Node *head) {
    if (head == NULL) {
        printf("Backward: (empty)\n");
        return;
    }
    
    // go to end
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // print backward
    printf("Backward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// display list structure with links
void displayStructure(Node *head) {
    printf("List Structure:\n");
    printf("NULL <- ");
    Node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" <-> ");
        }
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

int main() {
    Node *head = NULL;
    
    printf("Doubly Linked List Implementation\n");
    printf("==================================\n\n");
    
    // create initial list
    printf("Creating initial list: 10, 20, 30, 40, 50\n\n");
    insert_end(&head, 10);
    insert_end(&head, 20);
    insert_end(&head, 30);
    insert_end(&head, 40);
    insert_end(&head, 50);
    
    displayStructure(head);
    displayForward(head);
    displayBackward(head);
    printf("\n");
    
    // insert after node with value 20
    printf("Operation: Insert 25 after node with value 20\n");
    Node *node = findNode(head, 20);
    if (node != NULL) {
        insert_after(node, 25);
    }
    printf("\n");
    
    displayStructure(head);
    displayForward(head);
    displayBackward(head);
    printf("\n");
    
    // insert after node with value 40
    printf("Operation: Insert 45 after node with value 40\n");
    node = findNode(head, 40);
    if (node != NULL) {
        insert_after(node, 45);
    }
    printf("\n");
    
    displayStructure(head);
    displayForward(head);
    displayBackward(head);
    printf("\n");
    
    // delete node with value 30
    printf("Operation: Delete node with value 30\n");
    node = findNode(head, 30);
    if (node != NULL) {
        deleteNode(&head, node);
    }
    printf("\n");
    
    displayStructure(head);
    displayForward(head);
    displayBackward(head);
    printf("\n");
    
    // delete node with value 10 (head)
    printf("Operation: Delete node with value 10 (head node)\n");
    node = findNode(head, 10);
    if (node != NULL) {
        deleteNode(&head, node);
    }
    printf("\n");
    
    displayStructure(head);
    displayForward(head);
    displayBackward(head);
    
    return 0;
}
