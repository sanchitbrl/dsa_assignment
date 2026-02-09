# prog_3

## Data Structures Used

### Node Structure
```c
typedef struct Node {
    int data;
    struct Node *next;
} Node;
```
- **data**: Stores the integer value
- **next**: Pointer to the next node in the list

This is a singly linked list where each node points to the next node.

## Functions Implemented

### 1. `Node* createNode(int data)`
- Creates a new node with given data
- Allocates memory dynamically
- Returns pointer to new node

### 2. `void insertAtEnd(Node **head, int data)`
- Inserts a new node at the end of linked list
- If list is empty, makes new node the head
- Otherwise traverses to end and adds new node

### 3. `void forwardTraversal(Node *head)`
- Traverses list from head to end
- Prints all elements in normal order
- Uses iterative approach

### 4. `void reverseTraversal(Node *head)`
- **Main algorithm for reverse traversal**
- Uses recursion to traverse list
- Working:
  - Base case: if node is NULL, return
  - Recursive case: first call reverseTraversal for next node
  - Then print current node's data while returning
- This way, printing happens from end to start

### 5. `void printReverse(Node *head)`
- Wrapper function that calls reverseTraversal
- Adds proper formatting for output

### 6. `void displayList(Node *head)`
- Shows the structure of linked list
- Displays as: data -> data -> NULL

### 7. `int countNodes(Node *head)`
- Counts total number of nodes in list
- Returns the count

## Main Function Organization

1. Creates empty linked list (head = NULL)
2. Inserts 5 elements (10, 20, 30, 40, 50)
3. Displays the list structure
4. Shows total node count
5. Performs forward traversal
6. Performs reverse traversal using the algorithm

## Sample Output

```
Linked List - Reverse Traversal Demo
=====================================

Inserting elements: 10, 20, 30, 40, 50

Linked List Structure:
10 -> 20 -> 30 -> 40 -> 50 -> NULL

Total nodes: 5

Forward Traversal: 10 20 30 40 50 
Reverse Traversal: 50 40 30 20 10 
```

## How the Reverse Traversal Algorithm Works

The algorithm uses recursion:

```
reverseTraversal(10)
  |-> reverseTraversal(20)
       |-> reverseTraversal(30)
            |-> reverseTraversal(40)
                 |-> reverseTraversal(50)
                      |-> reverseTraversal(NULL) [returns]
                      print 50
                 print 40
            print 30
       print 20
  print 10
```

The recursion goes all the way to the end, then prints while coming back. This gives us reverse order without actually reversing the list structure.