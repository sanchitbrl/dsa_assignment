typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;
```

- `data`: stores the integer value
- `next`: points to the next node
- `prev`: points to the previous node

The doubly linked list lets you move both forward and backward through the list. Each node has two pointers instead of just one.

---

## Functions

### 1. `Node* createNode(int data)`
Creates a new node with the given data value. Sets next and prev to NULL initially.

### 2. `void insertAtEnd(Node **head, int data)`
Helper function to build the list. Adds new nodes at the end.

### 3. `void insertAfter(Node *prevNode, int data)`
**Main insert function** - inserts a new node after the given node.

Steps:
1. Check if prevNode exists
2. Create the new node
3. Update new node's next pointer
4. Update new node's prev pointer  
5. Update the next node's prev (if there is a next node)
6. Update prevNode's next

### 4. `void deleteNode(Node **head, Node *delNode)`
**Main delete function** - removes a node from the list.

Steps:
1. If deleting head, update head pointer
2. Update the next node's prev pointer
3. Update the previous node's next pointer
4. Free memory

### 5. `Node* findNode(Node *head, int data)`
Searches for a node with specific value. Returns the node if found, NULL if not found.

### 6. `void displayForward(Node *head)`
Prints the list from beginning to end using next pointers.

### 7. `void displayBackward(Node *head)`
Goes to the end first, then prints backward using prev pointers. Shows that we can traverse both ways!

### 8. `void displayStructure(Node *head)`
Shows a visual representation with arrows like: `10 <-> 20 <-> 30`

---

## Main Function Flow

1. Create empty list
2. Add initial values: 10, 20, 30, 40, 50
3. Do different operations:
   - Insert 25 after 20
   - Insert 45 after 40
   - Delete 30
   - Delete 10 (the head)
4. After each operation, show:
   - Structure with arrows
   - Forward list
   - Backward list

---

## Sample Output
```
Doubly Linked List Implementation
==================================

Creating initial list: 10, 20, 30, 40, 50

List Structure:
NULL <- 10 <-> 20 <-> 30 <-> 40 <-> 50 -> NULL
Forward: 10 20 30 40 50 
Backward: 50 40 30 20 10 

Operation: Insert 25 after node with value 20
Inserted 25 after 20

List Structure:
NULL <- 10 <-> 20 <-> 25 <-> 30 <-> 40 <-> 50 -> NULL
Forward: 10 20 25 30 40 50 
Backward: 50 40 30 25 20 10 

Operation: Insert 45 after node with value 40
Inserted 45 after 40

List Structure:
NULL <- 10 <-> 20 <-> 25 <-> 30 <-> 40 <-> 45 <-> 50 -> NULL
Forward: 10 20 25 30 40 45 50 
Backward: 50 45 40 30 25 20 10 

Operation: Delete node with value 30
Deleted node with data: 30

List Structure:
NULL <- 10 <-> 20 <-> 25 <-> 40 <-> 45 <-> 50 -> NULL
Forward: 10 20 25 40 45 50 
Backward: 50 45 40 25 20 10 

Operation: Delete node with value 10 (head node)
Deleted node with data: 10

List Structure:
NULL <- 20 <-> 25 <-> 40 <-> 45 <-> 50 -> NULL
Forward: 20 25 40 45 50 
Backward: 50 45 40 25 20


How It Works
Inserting After a Node:
When you insert a new node after an existing one, you need to update 4 pointers:

New node's next and prev
Previous node's next
Next node's prev (if there is one)

Deleting a Node:
To delete a node, you basically "bypass" it by connecting its neighbors directly:

Previous node's next → deleted node's next
Next node's prev → deleted node's prev
Then free() the memory

The cool thing about doubly linked lists is you can easily go both directions, which makes some operations faster than singly linked lists.