1)Write a program to implement push and display operations on stack using Array
#include <stdio.h>
#define MAX 5 // Define the maximum size of the stack
int stack[MAX], top = -1;
// Function to push an element onto the stack
void push(int value) {
if (top == MAX - 1) {
printf("Stack Overflow! Unable to push %d\n", value);
} else {
top++;
stack[top] = value;
printf("%d pushed onto the stack.\n", value);
}
}
// Function to display the elements of the stack
void display() {
if (top == -1) {
printf("Stack is empty.\n");
} else {
printf("Stack elements: ");
for (int i = top; i >= 0; i--) {
printf("%d ", stack[i]);
}
printf("\n");
}
}
int main() {
int choice, value;
while (1) {
printf("\n1. Push\n2. Display\n3. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter the value to push: ");
scanf("%d", &value);
push(value);
break;
case 2:
display();
break;
case 3:
return 0;
default:
printf("Invalid choice. Please try again.\n");
}
}
}


2)Write a program to implement pop and peek operations on stack using Linked List
#include <stdio.h>
#include <stdlib.h>
// Define a Node structure
struct Node {
int data;
struct Node* next;
};
// Top pointer to point to the top of the stack
struct Node* top = NULL;
// Function to push an element onto the stack
void push(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
if (!newNode) {
printf("Heap Overflow! Unable to push %d\n", value);
return;
}
newNode->data = value;
newNode->next = top;
top = newNode;
printf("%d pushed onto the stack.\n", value);
}
// Function to pop the top element from the stack
void pop() {
if (top == NULL) {
printf("Stack Underflow! Unable to pop.\n");
} else {
struct Node* temp = top;
printf("%d popped from the stack.\n", top->data);
top = top->next;
free(temp);
}
}
// Function to peek at the top element of the stack
void peek() {
if (top == NULL) {
printf("Stack is empty. Nothing to peek.\n");
} else {
printf("Top element is: %d\n", top->data);
}
}
// Function to display the stack
void display() {
if (top == NULL) {
printf("Stack is empty.\n");
} else {
struct Node* temp = top;
printf("Stack elements: ");
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}
}
int main() {
int choice, value;
while (1) {
printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter the value to push: ");
scanf("%d", &value);
push(value);
break;
case 2:
pop();
break;
case 3:
peek();
break;
case 4:
display();
break;
case 5:
return 0;
default:
printf("Invalid choice. Please try again.\n");
}
}
}


3)Write a program to implement insert and display operations on a linear queue.
#include <stdio.h>
#define MAX 5 // Define the maximum size of the queue
int queue[MAX];
int front = -1, rear = -1;
// Function to insert (enqueue) an element into the queue
void insert(int value) {
if (rear == MAX - 1) {
printf("Queue Overflow! Unable to insert %d\n", value);
} else {
if (front == -1) {
front = 0; // Set front to 0 if inserting the first element
}
rear++;
queue[rear] = value;
printf("%d inserted into the queue.\n", value);
}
}
// Function to display the elements of the queue
void display() {
if (front == -1 || front > rear) {
printf("Queue is empty.\n");
} else {
printf("Queue elements: ");
for (int i = front; i <= rear; i++) {
printf("%d ", queue[i]);
}
printf("\n");
}
}
int main() {
int choice, value;
while (1) {
printf("\n1. Insert\n2. Display\n3. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter the value to insert: ");
scanf("%d", &value);
insert(value);
break;
case 2:
display();
break;
case 3:
return 0;
default:
printf("Invalid choice. Please try again.\n");
}
}
}


4)Write a program to implement delete and display operations on a circular queue using
Array.
#include <stdio.h>
#define MAX 5 // Define the maximum size of the queue
int queue[MAX];
int front = -1, rear = -1;
// Function to delete (dequeue) an element from the queue
void delete() {
if (front == -1) {
printf("Queue Underflow! Unable to delete.\n");
} else {
printf("%d deleted from the queue.\n", queue[front]);
if (front == rear) { // Only one element was in the queue
front = -1;
rear = -1;
} else {
front = (front + 1) % MAX; // Circular increment of front
}
}
}
// Function to display the elements of the queue
void display() {
if (front == -1) {
printf("Queue is empty.\n");
} else {
printf("Queue elements: ");
int i = front;
while (i != rear) {
printf("%d ", queue[i]);
i = (i + 1) % MAX; // Circular increment of i
}
printf("%d\n", queue[rear]); // Print the last element
}
}
int main() {
int choice;
while (1) {
printf("\n1. Delete\n2. Display\n3. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
delete();
break;
case 2:
display();
break;
case 3:
return 0;
default:
printf("Invalid choice. Please try again.\n");
}
}
}


5)Write a program to perform following operations on SLL
1. create a LL(Insert)
2. reverse
3. Display/Traverse
#include <stdio.h>
#include <stdlib.h>
// Define a Node structure
struct Node {
int data;
struct Node* next;
};
// Head pointer to point to the start of the linked list
struct Node* head = NULL;
// Function to insert a new node at the end of the linked list
void insert(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->next = NULL;
if (head == NULL) {
head = newNode;
} else {
struct Node* temp = head;
while (temp->next != NULL) {
temp = temp->next;
}
temp->next = newNode;
}
printf("%d inserted into the linked list.\n", value);
}
// Function to reverse the linked list
void reverse() {
struct Node *prev = NULL, *current = head, *next = NULL;
while (current != NULL) {
next = current->next; // Store next node
current->next = prev; // Reverse current node's pointer
prev = current; // Move pointers one position ahead
current = next;
}
head = prev;
printf("Linked list reversed.\n");
}
// Function to display/traverse the linked list
void display() {
if (head == NULL) {
printf("The linked list is empty.\n");
} else {
struct Node* temp = head;
printf("Linked list elements: ");
while (temp != NULL) {
printf("%d -> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
}
}
int main() {
int choice, value;
while (1) {
printf("\n1. Insert\n2. Reverse\n3. Display\n4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter the value to insert: ");
scanf("%d", &value);
insert(value);
break;
case 2:
reverse();
break;
case 3:
display();
break;
case 4:
return 0;
default:
printf("Invalid choice. Please try again.\n");
}
}
}


6)Write a program to perform following operations on SLL (Any Two)
1. create a LL(Insert)
2. Sort it
3. Display/Traverse
#include <stdio.h>
#include <stdlib.h>
// Define a Node structure
struct Node {
int data;
struct Node* next;
};
// Head pointer to point to the start of the linked list
struct Node* head = NULL;
// Function to insert a new node at the end of the linked list
void insert(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->next = NULL;
if (head == NULL) {
head = newNode;
} else {
struct Node* temp = head;
while (temp->next != NULL) {
temp = temp->next;
}
temp->next = newNode;
}
printf("%d inserted into the linked list.\n", value);
}
// Function to sort the linked list using Bubble Sort
void sort() {
if (head == NULL || head->next == NULL) {
return; // If the list is empty or has only one node, it's already sorted
}
struct Node *i, *j;
int temp;
for (i = head; i != NULL; i = i->next) {
for (j = i->next; j != NULL; j = j->next) {
if (i->data > j->data) {
// Swap the data of nodes
temp = i->data;
i->data = j->data;
j->data = temp;
}
}
}
printf("Linked list sorted.\n");
}
// Function to display/traverse the linked list
void display() {
if (head == NULL) {
printf("The linked list is empty.\n");
} else {
struct Node* temp = head;
printf("Linked list elements: ");
while (temp != NULL) {
printf("%d -> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
}
}
int main() {
int choice, value;
while (1) {
printf("\n1. Insert\n2. Sort\n3. Display\n4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter the value to insert: ");
scanf("%d", &value);
insert(value);
break;
case 2:
sort();
break;
case 3:
display();
break;
case 4:
return 0;
default:
printf("Invalid choice. Please try again.\n");
}
}
}


7)Write a program to perform following operations on SLL
1. Create a LL(Insert)
2. Delete a node
3. Display/Traverse
#include <stdio.h>
#include <stdlib.h>
// Define a Node structure
struct Node {
int data;
struct Node* next;
};
// Head pointer to point to the start of the linked list
struct Node* head = NULL;
// Function to insert a new node at the end of the linked list
void insert(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->next = NULL;
if (head == NULL) {
head = newNode;
} else {
struct Node* temp = head;
while (temp->next != NULL) {
temp = temp->next;
}
temp->next = newNode;
}
printf("%d inserted into the linked list.\n", value);
}
// Function to sort the linked list using Bubble Sort
void sort() {
if (head == NULL || head->next == NULL) {
return; // If the list is empty or has only one node, it's already sorted
}
struct Node *i, *j;
int temp;
for (i = head; i != NULL; i = i->next) {
for (j = i->next; j != NULL; j = j->next) {
if (i->data > j->data) {
// Swap the data of nodes
temp = i->data;
i->data = j->data;
j->data = temp;
}
}
}
printf("Linked list sorted.\n");
}
// Function to display/traverse the linked list
void display() {
if (head == NULL) {
printf("The linked list is empty.\n");
} else {
struct Node* temp = head;
printf("Linked list elements: ");
while (temp != NULL) {
printf("%d -> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
}
}
int main() {
int choice, value;
while (1) {
printf("\n1. Insert\n2. Sort\n3. Display\n4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter the value to insert: ");
scanf("%d", &value);
insert(value);
break;
case 2:
sort();
break;
case 3:
display();
break;
case 4:
return 0;
default:
printf("Invalid choice. Please try again.\n");
}
}
}


8)Write a program to implement stack operations using SLL
#include <stdio.h>
#include <stdlib.h>
// Define a Node structure
struct Node {
int data;
struct Node* next;
};
// Top pointer to point to the top of the stack
struct Node* top = NULL;
// Function to push an element onto the stack
void push(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
if (!newNode) {
printf("Heap Overflow! Unable to push %d\n", value);
return;
}
newNode->data = value;
newNode->next = top;
top = newNode;
printf("%d pushed onto the stack.\n", value);
}
// Function to pop the top element from the stack
void pop() {
if (top == NULL) {
printf("Stack Underflow! Unable to pop.\n");
} else {
struct Node* temp = top;
printf("%d popped from the stack.\n", top->data);
top = top->next;
free(temp);
}
}
// Function to display the elements of the stack
void display() {
if (top == NULL) {
printf("Stack is empty.\n");
} else {
struct Node* temp = top;
printf("Stack elements: ");
while (temp != NULL) {
printf("%d -> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
}
}
int main() {
int choice, value;
while (1) {
printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter the value to push: ");
scanf("%d", &value);
push(value);
break;
case 2:
pop();
break;
case 3:
display();
break;
case 4:
return 0;
default:
printf("Invalid choice. Please try again.\n");
}
}
}


9)Write a program to evaluate Prefix / Postfix expressions.
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 100 // Maximum size of the stack
// Stack structure
int stack[MAX];
int top = -1;
// Function to push an element onto the stack
void push(int value) {
if (top == MAX - 1) {
printf("Stack Overflow!\n");
} else {
stack[++top] = value;
}
}
// Function to pop an element from the stack
int pop() {
if (top == -1) {
printf("Stack Underflow!\n");
exit(1); // Terminate the program if stack is empty
} else {
return stack[top--];
}
}
// Function to evaluate a Postfix expression
int evaluatePostfix(char* exp) {
int i = 0, op1, op2, result;
// Traverse the expression from left to right
while (exp[i] != '\0') {
if (isdigit(exp[i])) {
// If the character is a digit, push it onto the stack (convert char to int)
push(exp[i] - '0');
} else {
// If the character is an operator, pop two elements from the stack
op2 = pop();
op1 = pop();
switch (exp[i]) {
case '+':
result = op1 + op2;
break;
case '-':
result = op1 - op2;
break;
case '*':
result = op1 * op2;
break;
case '/':
result = op1 / op2;
break;
default:
printf("Invalid operator encountered.\n");
exit(1);
}
// Push the result back onto the stack
push(result);
}
i++;
}
// The final result will be at the top of the stack
return pop();
}
int main() {
char exp[MAX];
printf("Enter a Postfix expression: ");
scanf("%s", exp);
int result = evaluatePostfix(exp);
printf("The result of the Postfix expression is: %d\n", result);
return 0;
}

#include <stdio.h>
#include <ctype.h>   // for isdigit()
#include <string.h>  // for strlen()
#include <stdlib.h>  // for atoi()

#define MAX 100

// Stack structure
typedef struct {
    int data[MAX];
    int top;
} Stack;

// Initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Push an element onto the stack
void push(Stack* s, int value) {
    if (s->top < MAX - 1) {
        s->data[++(s->top)] = value;
    } else {
        printf("Stack overflow\n");
    }
}

// Pop an element from the stack
int pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    } else {
        printf("Stack underflow\n");
        return -1;  // Return -1 if the stack is empty
    }
}

// Function to evaluate a prefix expression
int evaluatePrefix(char* expr) {
    Stack s;
    initStack(&s);
    
    int length = strlen(expr);
    
    // Scan the expression from right to left
    for (int i = length - 1; i >= 0; i--) {
        // Skip spaces
        if (isspace(expr[i])) {
            continue;
        }

        // If the character is a digit, handle multi-digit numbers
        if (isdigit(expr[i])) {
            int num = 0, place = 1;

            // Collect all digits of the number (handling multi-digit numbers)
            while (i >= 0 && isdigit(expr[i])) {
                num += (expr[i] - '0') * place;
                place *= 10;
                i--;
            }

            i++; // Correct i decrement due to extra step in while loop
            push(&s, num);
        }
        // If the character is an operator
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            // Pop two elements from the stack
            int operand1 = pop(&s);
            int operand2 = pop(&s);
            
            // Perform the operation and push the result back onto the stack
            switch (expr[i]) {
                case '+':
                    push(&s, operand1 + operand2);
                    break;
                case '-':
                    push(&s, operand1 - operand2);
                    break;
                case '*':
                    push(&s, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0) {
                        push(&s, operand1 / operand2);
                    } else {
                        printf("Error: Division by zero\n");
                        return -1;
                    }
                    break;
            }
        }
    }
    
    // The final result will be the only element left in the stack
    return pop(&s);
}

int main() {
    char expr[MAX];
    
    // Example prefix expression: +*562
    printf("Enter a prefix expression: ");
    scanf("%[^\n]", expr);  // Reads the entire line including spaces
    
    int result = evaluatePrefix(expr);
    if (result != -1) {
        printf("Result of the prefix expression is: %d\n", result);
    }
    
    return 0;
}



10)write a program to perform following operations on circular SLL
1. Insert a node
2. Delete a node
3. Display/Traverse
#include <stdio.h>
#include <stdlib.h>
// Define a Node structure
struct Node {
int data;
struct Node* next;
};
// Pointer to keep track of the last node in the circular linked list
struct Node* last = NULL;
// Function to insert a node at the end of the circular singly linked list
void insert(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
if (last == NULL) {
// If the list is empty, the new node will point to itself
newNode->next = newNode;
last = newNode;
} else {
// Insert the new node after the last node
newNode->next = last->next;
last->next = newNode;
last = newNode;
}
printf("%d inserted into the list.\n", value);
}
// Function to delete a node from the circular singly linked list
void delete(int value) {
if (last == NULL) {
printf("The list is empty. Deletion is not possible.\n");
return;
}
struct Node* temp = last->next;
struct Node* prev = last;
// If the node to be deleted is the only node
if (last == last->next && last->data == value) {
free(last);
last = NULL;
printf("%d deleted from the list.\n", value);
return;
}
// If the node to be deleted is the first node
if (temp->data == value) {
prev->next = temp->next;
free(temp);
printf("%d deleted from the list.\n", value);
return;
}
// Traverse the list to find the node to delete
do {
if (temp->data == value) {
prev->next = temp->next;
free(temp);
printf("%d deleted from the list.\n", value);
return;
}
prev = temp;
temp = temp->next;
} while (temp != last->next);
printf("Node with value %d not found.\n", value);
}
// Function to display/traverse the circular singly linked list
void display() {
if (last == NULL) {
printf("The list is empty.\n");
return;
}
struct Node* temp = last->next;
printf("List elements: ");
do {
printf("%d -> ", temp->data);
temp = temp->next;
} while (temp != last->next);
printf("HEAD\n");
}
int main() {
int choice, value;
while (1) {
printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter the value to insert: ");
scanf("%d", &value);
insert(value);
break;
case 2:
printf("Enter the value to delete: ");
scanf("%d", &value);
delete(value);
break;
case 3:
display();
break;
case 4:
return 0;
default:
printf("Invalid choice. Please try again.\n");
}
}
}


11)Write a program to perform following operations on DLL
1. Insert a node
2. Delete a node
3. Display/Traverse
#include <stdio.h>
#include <stdlib.h>
// Define a Node structure for the Doubly Linked List
struct Node {
int data;
struct Node* prev;
struct Node* next;
};
// Head pointer to point to the first node of the DLL
struct Node* head = NULL;
// Function to insert a node at the end of the doubly linked list
void insert(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->next = NULL;
newNode->prev = NULL;
if (head == NULL) {
// If the list is empty, make the new node the head
head = newNode;
} else {
struct Node* temp = head;
// Traverse to the last node
while (temp->next != NULL) {
temp = temp->next;
}
temp->next = newNode;
newNode->prev = temp;
}
printf("%d inserted into the list.\n", value);
}
// Function to delete a node from the doubly linked list
void delete(int value) {
if (head == NULL) {
printf("The list is empty. Deletion is not possible.\n");
return;
}
struct Node* temp = head;
// If the node to be deleted is the head node
if (head->data == value) {
head = head->next;
if (head != NULL) {
head->prev = NULL;
}
free(temp);
printf("%d deleted from the list.\n", value);
return;
}
// Traverse the list to find the node to delete
while (temp != NULL && temp->data != value) {
temp = temp->next;
}
if (temp == NULL) {
printf("Node with value %d not found.\n", value);
return;
}
// Adjust the links and delete the node
if (temp->next != NULL) {
temp->next->prev = temp->prev;
}
if (temp->prev != NULL) {
temp->prev->next = temp->next;
}
free(temp);
printf("%d deleted from the list.\n", value);
}
// Function to display/traverse the doubly linked list
void display() {
if (head == NULL) {
printf("The list is empty.\n");
return;
}
struct Node* temp = head;
printf("List elements: ");
while (temp != NULL) {
printf("%d <-> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
}
int main() {
int choice, value;
while (1) {
printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter the value to insert: ");
scanf("%d", &value);
insert(value);
break;
case 2:
printf("Enter the value to delete: ");
scanf("%d", &value);
delete(value);
break;
case 3:
display();
break;
case 4:
return 0;
default:
printf("Invalid choice. Please try again.\n");
}
}
}


12)Write a program to perform following operations on BST (Any two)
1. Insert a node 2. Delete a node 3. postorder traversal
#include <stdio.h>
#include <stdlib.h>
// Define the structure for a BST node
struct Node {
int data;
struct Node* left;
struct Node* right;
};
// Function to create a new node
struct Node* createNode(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->left = newNode->right = NULL;
return newNode;
}
// Function to insert a node into the BST
struct Node* insert(struct Node* root, int value) {
if (root == NULL) {
return createNode(value);
}
if (value < root->data) {
root->left = insert(root->left, value);
} else if (value > root->data) {
root->right = insert(root->right, value);
}
return root;
}
// Function to find the minimum value node in the BST
struct Node* findMin(struct Node* root) {
while (root->left != NULL) {
root = root->left;
}
return root;
}
// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int value) {
if (root == NULL) {
return root;
}
// Traverse the tree to find the node to delete
if (value < root->data) {
root->left = deleteNode(root->left, value);
} else if (value > root->data) {
root->right = deleteNode(root->right, value);
} else {
// Node with only one child or no child
if (root->left == NULL) {
struct Node* temp = root->right;
free(root);
return temp;
} else if (root->right == NULL) {
struct Node* temp = root->left;
free(root);
return temp;
}
// Node with two children: Get the inorder successor (smallest in the right subtree)
struct Node* temp = findMin(root->right);
root->data = temp->data; // Copy the inorder successor's data
root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
}
return root;
}
// Function for postorder traversal of the BST
void postorderTraversal(struct Node* root) {
if (root != NULL) {
postorderTraversal(root->left);
postorderTraversal(root->right);
printf("%d ", root->data);
}
}
int main() {
struct Node* root = NULL;
int choice, value;
while (1) {
printf("\n1. Insert\n2. Delete\n3. Postorder Traversal\n4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter the value to insert: ");
scanf("%d", &value);
root = insert(root, value);
printf("%d inserted into the BST.\n", value);
break;
case 2:
printf("Enter the value to delete: ");
scanf("%d", &value);
root = deleteNode(root, value);
printf("%d deleted from the BST.\n", value);
break;
case 3:
printf("Postorder Traversal: ");
postorderTraversal(root);
printf("\n");
break;
case 4:
return 0;
default:
printf("Invalid choice. Please try again.\n");
}
}
}


13)Write a program to perform following operations on BST
1. Insert a node 2. Inorder traversal
#include <stdio.h>
#include <stdlib.h>
// Define the structure for a BST node
struct Node {
int data;
struct Node* left;
struct Node* right;
};
// Function to create a new node
struct Node* createNode(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->left = newNode->right = NULL;
return newNode;
}
// Function to insert a node into the BST
struct Node* insert(struct Node* root, int value) {
if (root == NULL) {
return createNode(value);
}
if (value < root->data) {
root->left = insert(root->left, value);
} else if (value > root->data) {
root->right = insert(root->right, value);
}
return root;
}
// Function for inorder traversal of the BST
void inorderTraversal(struct Node* root) {
if (root != NULL) {
inorderTraversal(root->left); // Visit left subtree
printf("%d ", root->data); // Visit node
inorderTraversal(root->right); // Visit right subtree
}
}
int main() {
struct Node* root = NULL; // Initialize the root of the BST
int choice, value;
while (1) {
printf("\n1. Insert\n2. Inorder Traversal\n3. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter the value to insert: ");
scanf("%d", &value);
root = insert(root, value);
printf("%d inserted into the BST.\n", value);
break;
case 2:
printf("Inorder Traversal: ");
inorderTraversal(root);
printf("\n");
break;
case 3:
return 0;
default:
printf("Invalid choice. Please try again.\n");
}
}
}


14)Write a program to perform following operations on BST (Any two)
1. Insert a node 2. preorder traversal
#include <stdio.h>
#include <stdlib.h>
// Define the structure for a BST node
struct Node {
int data;
struct Node* left;
struct Node* right;
};
// Function to create a new node
struct Node* createNode(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->left = newNode->right = NULL;
return newNode;
}
// Function to insert a node into the BST
struct Node* insert(struct Node* root, int value) {
if (root == NULL) {
return createNode(value);
}
if (value < root->data) {
root->left = insert(root->left, value);
} else if (value > root->data) {
root->right = insert(root->right, value);
}
return root;
}
// Function for preorder traversal of the BST
void preorderTraversal(struct Node* root) {
if (root != NULL) {
printf("%d ", root->data); // Visit node
preorderTraversal(root->left); // Visit left subtree
preorderTraversal(root->right); // Visit right subtree
}
}
int main() {
struct Node* root = NULL; // Initialize the root of the BST
int choice, value;
while (1) {
printf("\n1. Insert\n2. Preorder Traversal\n3. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter the value to insert: ");
scanf("%d", &value);
root = insert(root, value);
printf("%d inserted into the BST.\n", value);
break;
case 2:
printf("Preorder Traversal: ");
preorderTraversal(root);
printf("\n");
break;
case 3:
return 0;
default:
printf("Invalid choice. Please try again.\n");
}
}
}


15)Write a program to implement a merge sort algorithm.
#include <stdio.h>
#include <stdlib.h>
// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right) {
int i, j, k;
int n1 = mid - left + 1; // Size of left subarray
int n2 = right - mid; // Size of right subarray
// Create temporary arrays
int* L = (int*)malloc(n1 * sizeof(int));
int* R = (int*)malloc(n2 * sizeof(int));
// Copy data to temporary arrays
for (i = 0; i < n1; i++)
L[i] = arr[left + i];
for (j = 0; j < n2; j++)
R[j] = arr[mid + 1 + j];
// Merge the temporary arrays back into arr[left..right]
i = 0; // Initial index of first subarray
j = 0; // Initial index of second subarray
k = left; // Initial index of merged subarray
while (i < n1 && j < n2) {
if (L[i] <= R[j]) {
arr[k] = L[i];
i++;
} else {
arr[k] = R[j];
j++;
}
k++;
}
// Copy remaining elements of L[] if any
while (i < n1) {
arr[k] = L[i];
i++;
k++;
}
// Copy remaining elements of R[] if any
while (j < n2) {
arr[k] = R[j];
j++;
k++;
}
// Free the allocated memory
free(L);
free(R);
}
// Function to implement merge sort
void mergeSort(int arr[], int left, int right) {
if (left < right) {
int mid = left + (right - left) / 2; // Avoid overflow
// Sort first and second halves
mergeSort(arr, left, mid);
mergeSort(arr, mid + 1, right);
// Merge the sorted halves
merge(arr, left, mid, right);
}
}
// Function to print the array
void printArray(int arr[], int size) {
for (int i = 0; i < size; i++)
printf("%d ", arr[i]);
printf("\n");
}
// Main function
int main() {
int arr[] = {38, 27, 43, 3, 9, 82, 10};
int arr_size = sizeof(arr) / sizeof(arr[0]);
printf("Given array is: \n");
printArray(arr, arr_size);
mergeSort(arr, 0, arr_size - 1);
printf("\nSorted array is: \n");
printArray(arr, arr_size);
return 0;
}


16)Write a program to perform following operations on BST
1. Insert a node 2. postorder traversal
#include <stdio.h>
#include <stdlib.h>
// Define the structure for a BST node
struct Node {
int data;
struct Node* left;
struct Node* right;
};
// Function to create a new node
struct Node* createNode(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->left = newNode->right = NULL;
return newNode;
}
// Function to insert a node into the BST
struct Node* insert(struct Node* root, int value) {
if (root == NULL) {
return createNode(value);
}
if (value < root->data) {
root->left = insert(root->left, value);
} else if (value > root->data) {
root->right = insert(root->right, value);
}
return root;
}
// Function for postorder traversal of the BST
void postorderTraversal(struct Node* root) {
if (root != NULL) {
postorderTraversal(root->left); // Visit left subtree
postorderTraversal(root->right); // Visit right subtree
printf("%d ", root->data); // Visit node
}
}
int main() {
struct Node* root = NULL; // Initialize the root of the BST
int choice, value;
while (1) {
printf("\n1. Insert\n2. Postorder Traversal\n3. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter the value to insert: ");
scanf("%d", &value);
root = insert(root, value);
printf("%d inserted into the BST.\n", value);
break;
case 2:
printf("Postorder Traversal: ");
postorderTraversal(root);
printf("\n");
break;
case 3:
return 0;
default:
printf("Invalid choice. Please try again.\n");
}
}
}


17)Write a program to implement Depth first search Algorithm using adjacency matrix.
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
// Function to perform DFS
void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int visited[], int vertex, int numVertices)
{
// Mark the current vertex as visited
visited[vertex] = 1;
printf("%d ", vertex);
// Explore all the adjacent vertices
for (int i = 0; i < numVertices; i++) {
if (graph[vertex][i] == 1 && !visited[i]) {
DFS(graph, visited, i, numVertices);
}
}
}
int main() {
int graph[MAX_VERTICES][MAX_VERTICES] = {0}; // Adjacency matrix
int visited[MAX_VERTICES] = {0}; // Visited array
int numVertices, edges, v1, v2;
// Input number of vertices
printf("Enter the number of vertices: ");
scanf("%d", &numVertices);
// Input number of edges
printf("Enter the number of edges: ");
scanf("%d", &edges);
// Input edges
printf("Enter the edges (v1 v2) format:\n");
for (int i = 0; i < edges; i++) {
scanf("%d %d", &v1, &v2);
graph[v1][v2] = 1; // Mark the edge from v1 to v2
graph[v2][v1] = 1; // Mark the edge from v2 to v1 (for undirected graph)
}
// Perform DFS starting from vertex 0
printf("Depth First Search starting from vertex 0:\n");
DFS(graph, visited, 0, numVertices);
printf("\n");
return 0;
}


18)Write a program to implement a selection sort algorithm.
#include <stdio.h>
// Function to perform selection sort
void selectionSort(int arr[], int n) {
int i, j, minIndex, temp;
// One by one move the boundary of the sorted subarray
for (i = 0; i < n - 1; i++) {
minIndex = i; // Assume the first element is the minimum
// Find the minimum element in the unsorted array
for (j = i + 1; j < n; j++) {
if (arr[j] < arr[minIndex]) {
minIndex = j; // Update minIndex if a smaller element is found
}
}
// Swap the found minimum element with the first element
if (minIndex != i) {
temp = arr[i];
arr[i] = arr[minIndex];
arr[minIndex] = temp;
}
}
}
// Function to print the array
void printArray(int arr[], int size) {
for (int i = 0; i < size; i++) {
printf("%d ", arr[i]);
}
printf("\n");
}
// Main function
int main() {
int arr[] = {64, 25, 12, 22, 11};
int n = sizeof(arr) / sizeof(arr[0]);
printf("Given array is: \n");
printArray(arr, n);
selectionSort(arr, n);
printf("Sorted array is: \n");
printArray(arr, n);
return 0;
}


19)Conversion of Infix Expression to Postfix Expression Using Stack
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
// Stack structure
struct Stack {
int top;
char items[MAX];
};
// Function to create a stack
struct Stack* createStack() {
struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
s->top = -1;
return s;
}
// Function to check if the stack is empty
int isEmpty(struct Stack* s) {
return s->top == -1;
}
// Function to push an item to the stack
void push(struct Stack* s, char item) {
if (s->top < MAX - 1) {
s->items[++(s->top)] = item;
} else {
printf("Stack overflow\n");
}
}
// Function to pop an item from the stack
char pop(struct Stack* s) {
if (!isEmpty(s)) {
return s->items[(s->top)--];
} else {
printf("Stack underflow\n");
return '\0'; // Return null character on underflow
}
}
// Function to return the top item of the stack without removing it
char peek(struct Stack* s) {
if (!isEmpty(s)) {
return s->items[s->top];
} else {
return '\0'; // Return null character if stack is empty
}
}
// Function to check the precedence of operators
int precedence(char operator) {
switch (operator) {
case '+':
case '-':
return 1;
case '*':
case '/':
return 2;
case '^':
return 3;
default:
return 0;
}
}
// Function to convert infix expression to postfix
void infixToPostfix(const char* infix, char* postfix) {
struct Stack* s = createStack();
int i = 0, k = 0;
while (infix[i] != '\0') {
if (isalnum(infix[i])) { // If the character is an operand
postfix[k++] = infix[i];
} else if (infix[i] == '(') {
push(s, infix[i]);
} else if (infix[i] == ')') {
while (!isEmpty(s) && peek(s) != '(') {
postfix[k++] = pop(s);
}
pop(s); // Remove '(' from stack
} else { // If the character is an operator
while (!isEmpty(s) && precedence(peek(s)) >= precedence(infix[i])) {
postfix[k++] = pop(s);
}
push(s, infix[i]);
}
i++;
}
// Pop all remaining operators from the stack
while (!isEmpty(s)) {
postfix[k++] = pop(s);
}
postfix[k] = '\0'; // Null terminate the postfix expression
free(s); // Free allocated memory for stack
}
// Main function
int main() {
char infix[MAX], postfix[MAX];
printf("Enter an infix expression: ");
fgets(infix, MAX, stdin); // Read the infix expression
// Remove newline character if present
size_t len = strlen(infix);
if (len > 0 && infix[len - 1] == '\n') {
infix[len - 1] = '\0';
}
infixToPostfix(infix, postfix);
printf("Postfix expression: %s\n", postfix);
return 0;
}


20)Conversion of Infix Expression to Postfix Expression Using Stack
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
// Stack structure
struct Stack {
int top;
char items[MAX];
};
// Function to create a stack
struct Stack* createStack() {
struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
s->top = -1;
return s;
}
// Function to check if the stack is empty
int isEmpty(struct Stack* s) {
return s->top == -1;
}
// Function to push an item to the stack
void push(struct Stack* s, char item) {
if (s->top < MAX - 1) {
s->items[++(s->top)] = item;
} else {
printf("Stack overflow\n");
}
}
// Function to pop an item from the stack
char pop(struct Stack* s) {
if (!isEmpty(s)) {
return s->items[(s->top)--];
} else {
printf("Stack underflow\n");
return '\0'; // Return null character on underflow
}
}
// Function to return the top item of the stack without removing it
char peek(struct Stack* s) {
if (!isEmpty(s)) {
return s->items[s->top];
} else {
return '\0'; // Return null character if stack is empty
}
}
// Function to check the precedence of operators
int precedence(char operator) {
switch (operator) {
case '+':
case '-':
return 1;
case '*':
case '/':
return 2;
case '^':
return 3;
default:
return 0;
}
}
// Function to convert infix expression to postfix
void infixToPostfix(const char* infix, char* postfix) {
struct Stack* s = createStack();
int i = 0, k = 0;
while (infix[i] != '\0') {
if (isalnum(infix[i])) { // If the character is an operand (number or letter)
postfix[k++] = infix[i];
} else if (infix[i] == '(') {
push(s, infix[i]);
} else if (infix[i] == ')') {
while (!isEmpty(s) && peek(s) != '(') {
postfix[k++] = pop(s);
}
pop(s); // Remove '(' from stack
} else { // If the character is an operator
while (!isEmpty(s) && precedence(peek(s)) >= precedence(infix[i])) {
postfix[k++] = pop(s);
}
push(s, infix[i]);
}
i++;
}
// Pop all remaining operators from the stack
while (!isEmpty(s)) {
postfix[k++] = pop(s);
}
postfix[k] = '\0'; // Null terminate the postfix expression
free(s); // Free allocated memory for stack
}
// Main function
int main() {
char infix[MAX], postfix[MAX];
printf("Enter an infix expression: ");
fgets(infix, MAX, stdin); // Read the infix expression
// Remove newline character if present
size_t len = strlen(infix);
if (len > 0 && infix[len - 1] == '\n') {
infix[len - 1] = '\0';
}
infixToPostfix(infix, postfix);
printf("Postfix expression: %s\n", postfix);
return 0;
}


21)Write a program to implement Breadth first search Algorithm using adjacency matrix.
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
// Function to perform BFS
void BFS(int graph[MAX_VERTICES][MAX_VERTICES], int visited[], int startVertex, int
numVertices) {
int queue[MAX_VERTICES], front = -1, rear = -1;
visited[startVertex] = 1; // Mark the starting vertex as visited
queue[++rear] = startVertex; // Enqueue the starting vertex
printf("Breadth First Search starting from vertex %d:\n", startVertex);
while (front < rear) {
front++; // Dequeue the front vertex
int currentVertex = queue[front];
printf("%d ", currentVertex);
// Explore all adjacent vertices of the dequeued vertex
for (int i = 0; i < numVertices; i++) {
if (graph[currentVertex][i] == 1 && !visited[i]) {
visited[i] = 1; // Mark the vertex as visited
queue[++rear] = i; // Enqueue the vertex
}
}
}
}
int main() {
int graph[MAX_VERTICES][MAX_VERTICES] = {0}; // Adjacency matrix
int visited[MAX_VERTICES] = {0}; // Visited array
int numVertices, edges, v1, v2;
// Input number of vertices
printf("Enter the number of vertices: ");
scanf("%d", &numVertices);
// Input number of edges
printf("Enter the number of edges: ");
scanf("%d", &edges);
// Input edges
printf("Enter the edges (v1 v2) format:\n");
for (int i = 0; i < edges; i++) {
scanf("%d %d", &v1, &v2);
graph[v1][v2] = 1; // Mark the edge from v1 to v2
graph[v2][v1] = 1; // Mark the edge from v2 to v1 (for undirected graph)
}
// Perform BFS starting from vertex 0 (you can change this if needed)
BFS(graph, visited, 0, numVertices);
printf("\n");
return 0;
}


22)Write a program to implement a Quick sort algorithm.
#include <stdio.h>
// Function to swap two elements
void swap(int* a, int* b) {
int temp = *a;
*a = *b;
*b = temp;
}
// Partition function to find the pivot and partition the array
int partition(int arr[], int low, int high) {
int pivot = arr[high]; // Choosing the rightmost element as pivot
int i = (low - 1); // Index of the smaller element
for (int j = low; j < high; j++) {
// If current element is smaller than or equal to pivot
if (arr[j] <= pivot) {
i++; // Increment index of smaller element
swap(&arr[i], &arr[j]); // Swap arr[i] and arr[j]
}
}
swap(&arr[i + 1], &arr[high]); // Place pivot at the correct position
return (i + 1); // Return the index of the pivot
}
// Quick Sort function
void quickSort(int arr[], int low, int high) {
if (low < high) {
// pi is partitioning index, arr[pi] is now at the right place
int pi = partition(arr, low, high);
// Recursively sort elements before and after partition
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
}
}
// Function to print the array
void printArray(int arr[], int size) {
for (int i = 0; i < size; i++) {
printf("%d ", arr[i]);
}
printf("\n");
}
// Main function
int main() {
int arr[] = {10, 7, 8, 9, 1, 5}; // Sample array
int n = sizeof(arr) / sizeof(arr[0]); // Size of the array
printf("Unsorted array: \n");
printArray(arr, n);
quickSort(arr, 0, n - 1); // Call to quickSort
printf("Sorted array: \n");
printArray(arr, n); // Print the sorted array
return 0;
}


23)Write a program to implement an Insertion sort algorithm.
#include <stdio.h>
// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
for (int i = 1; i < n; i++) {
int key = arr[i]; // Element to be inserted
int j = i - 1;
// Move elements of arr[0..i-1] that are greater than key
// to one position ahead of their current position
while (j >= 0 && arr[j] > key) {
arr[j + 1] = arr[j];
j--;
}
arr[j + 1] = key; // Insert the key at its correct position
}
}
// Function to print the array
void printArray(int arr[], int n) {
for (int i = 0; i < n; i++) {
printf("%d ", arr[i]);
}
printf("\n");
}
// Main function
int main() {
int arr[] = {12, 11, 13, 5, 6}; // Sample array
int n = sizeof(arr) / sizeof(arr[0]); // Size of the array
printf("Unsorted array: \n");
printArray(arr, n);
insertionSort(arr, n); // Call to Insertion Sort
printf("Sorted array: \n");
printArray(arr, n); // Print the sorted array
return 0;
}


24)Write a program to implement a Selection sort algorithm.
#include <stdio.h>
// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
for (int i = 0; i < n - 1; i++) {
int minIndex = i; // Assume the minimum is the first element
// Find the index of the minimum element in the unsorted portion
for (int j = i + 1; j < n; j++) {
if (arr[j] < arr[minIndex]) {
minIndex = j; // Update minIndex if a smaller element is found
}
}
// Swap the found minimum element with the first element
if (minIndex != i) {
int temp = arr[i];
arr[i] = arr[minIndex];
arr[minIndex] = temp;
}
}
}
// Function to print the array
void printArray(int arr[], int n) {
for (int i = 0; i < n; i++) {
printf("%d ", arr[i]);
}
printf("\n");
}
// Main function
int main() {
int arr[] = {64, 25, 12, 22, 11}; // Sample array
int n = sizeof(arr) / sizeof(arr[0]); // Size of the array
printf("Unsorted array: \n");
printArray(arr, n);
selectionSort(arr, n); // Call to Selection Sort
printf("Sorted array: \n");
printArray(arr, n); // Print the sorted array
return 0;
}