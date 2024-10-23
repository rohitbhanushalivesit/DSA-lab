EXP1 stack using array
#include <stdio.h>
#include<stdbool.h>
#define max_size 10
int top=-1;
int stack[max_size];
void push(int x);
int pop();
void stack_top(int stack[]);
bool isEmpty(int stack[]);
bool isFull(int stack[]);
void push(int x){
 if (top==max_size-1){
 printf("Stack full, Overflow!");
 }
 else{
 top++;
 stack[top]=x;
 }
}
int pop(){
 int data;
 if (top==-1){
 printf("Stack empty, Underflow!");
 }
 else{
 data=stack[top];
 top--;
 return data;
 }
}
bool isEmpty(int stack[]){
 if (top==-1){
 return true;
 }
 return false;
}
bool isFull(int stack[]){
 if (top==max_size-1){
 return true;
 }
 else{
 return false;
 }
}
void stack_top(int stack[]){
 if (top==-1){
 printf("Stack is empty\n");
 }
 else{
 printf("top element is %d\n",stack[top]);
 }
}
int main(){
 int choice,x,y;
 
 do{
 printf("enter choice of operation:\n 1. Push\n 2. Pop\n 3. stack_Top\n 4. Stack_Empty\n 5. Stack_Full\n ");
 scanf("%d",&choice);
 switch(choice){
 case 1:
 printf("enter element to be inserted: ");
 scanf("%d",&x);
 push(x);
 break;
 case 2:
 y=pop();
 printf("Popped element is %d\n",y);
 break;
 case 3:
 stack_top(stack);
 break;
 case 4:
 if(isEmpty(stack)){
 printf("stack is empty\n");
 }
 else{
 printf("stack is not empty\n");
 }
 break;
 case 5:
 if(isFull(stack)){
 printf("stack is full\n");
 }
 else{
 printf("stack is not full\n");
 }
 break;
 }
 }
 while(choice!=0);
 return 0;
}



EXP 2 infix postfix
#include <stdio.h>
#include <ctype.h>
#define MAX 100
struct Stack {
 int top;
 char items[MAX];
};
void initstack(struct Stack *stack) {
 stack->top = -1;
}
int isEmpty(struct Stack *stack) {
 return stack->top == -1;
}
void push(struct Stack *stack, char op) {
 if (stack->top < (MAX - 1)) {
 stack->items[++stack->top] = op;
 } else {
 printf("Stack overflow\n");
 }}
char pop(struct Stack *stack) {
 if (!isEmpty(stack)) {
 return stack->items[stack->top--];
 } else {
 printf("Stack underflow\n");
 return '\0'; }}
int precedence(char op) {
 switch(op) {
 case '+':
 case '-':
 return 1;
 case '*':
 case '/':
 return 2;
 case '^':
 return 3;
 default:
 return 0; }}
int isoperand(char ch) {
 return isalnum(ch);}
void infixtopostfix(char *infix, char *postfix) {
 struct Stack stack;
 initstack(&stack);
 int i, k = 0;
 for (i = 0; infix[i]; ++i) {
 if (isoperand(infix[i])) {
 postfix[k++] = infix[i];}
 else if (infix[i] == '(') {
 push(&stack, infix[i]);}
 else if (infix[i] == ')') {
 while (!isEmpty(&stack) && stack.items[stack.top] != '(') {
 postfix[k++] = pop(&stack);}
 if (!isEmpty(&stack) && stack.items[stack.top] == '(') {
 pop(&stack); } } else { 
 while (!isEmpty(&stack) && precedence(infix[i]) <= precedence(stack.items[stack.top])) {
 postfix[k++] = pop(&stack); }
 push(&stack, infix[i]);}}
 
 while (!isEmpty(&stack)) {
 postfix[k++] = pop(&stack);
 }
 postfix[k] = '\0'; }
int main() {
 char infix[MAX], postfix[MAX];
 printf("Enter infix expression:\n");
 scanf("%s", infix); 
 infixtopostfix(infix, postfix);
 printf("Postfix expression is %s\n", postfix);
 return 0;
}



EXP 3 linear queue using array
#include <stdio.h>
#include<stdbool.h>
#define max_size 10
int queue[max_size];
int front=-1;
int rear=-1;
void enqueue(int x);
int dequeue();
bool isEmpty(int queue[]);
bool isFull(int queue[]);
int getfront(int queue[]);
int getrear(int queue[]);
void enqueue(int x){
 if (rear==max_size-1){
 printf("Queue is full!\n");
 }
 else if(front==-1 && rear==-1){
 front=rear=0;
 queue[rear]=x;
 }
 else{
 rear++;
 queue[rear]=x;
 
 }
}
int dequeue(){
 int data;
 if (front==-1 && rear==-1){
 printf("Queue is empty\n");
 }
 else if (front==rear){
 data=queue[front];
 front=rear=-1;
 return data;
 }
 else{
 data=queue[front];
 front++;
 return data;
 }
}
bool isEmpty(int queue[]){
 if (front==-1 && rear==-1){
 return true;
 }
 return false;
}
bool isFull(int queue[]){
 if (rear==max_size-1){
 return true;
 }
 else{
 return false;
 }
}
int getfront(int queue[]){
 if (front==-1 && rear==-1){
 printf("Queue is empty\n");
 }
 else{
 return queue[front];
 }
}
int getrear(int queue[]){
 if (front==-1 && rear==-1){
 printf("Queue is empty\n");
 }
 else{
 return queue[rear];
 }
}
int main(){
 int choice,x,y,a,b;
 do{
 printf("enter choice of operation:\n 1. Enqueue\n 2. Dequeue\n 3. Queue_Empty\n 4. Queue_Full\n 5. Get_front\n 6. Get_rear\n");
 scanf("%d",&choice);
 switch (choice){
 case 1:
 printf("enter element to be inserted:\n ");
 scanf("%d",&x);
 enqueue(x);
 break;
 case 2:
 y=dequeue();
 printf("Dequeued value is %d\n",y);
 break;
 case 3:
 if (isEmpty(queue)){
 printf("Queue is empty\n");
 }
 else{
 printf("Queue is not empty\n");
 }
 break;
 case 4:
 if(isFull(queue)){
 printf("Queue is full\n");
 }
 else{
 printf("Queue is not full\n");
 }
 break;
 case 5:
 a=getfront(queue);
 printf("element at front of queue is %d\n",a);
 break;
 case 6:
 b=getrear(queue);
 printf("element at rear of queue is %d\n",b);
 break;
 }
 }
 while(choice!=0);
 return 0;
}


EXP 4 circular queue
#include<stdio.h>
#include<stdbool.h>
#define max 10
int front=-1;
int rear=-1;
int cqueue[max];
bool isFull(int cqueue[]);
bool isEmpty(int cqueue[]);
void enqueue(int cqueue[],int value);
int dequeue(int cqueue[]);
int getFront(int cqueue[]);
int getRear(int cqueue[]);
bool isFull(int cqueue[]){
 if ((rear+1)%max==front){
 return true;
 }
 else{
 return false;
 }
}
bool isEmpty(int cqueue[]){
 if (front==-1 && rear==-1){
 return true;
 }
 else{
 return false;
 }
}
void enqueue(int cqueue[],int value){
 if ((rear+1)%max==front){
 printf("Queue is full\n");
 }
 else if (front==-1 && rear==-1){
 front=rear=0;
 
 }
 else{
 rear=(rear+1) % max;
 
 }
 
 cqueue[rear]=value;
 
}
int dequeue(int cqueue[]){
 if (front==-1 && rear==-1){
 printf("Queue is empty\n");
 }
 else if(front==rear){
 int data=cqueue[front];
 front=rear=-1;
 return data;
 }
 else{
 int data=cqueue[front];
 front=(front+1) %max;
 return data;
 }
 
}
int getFront(int cqueue[]){
 if (front==-1 && rear==-1){
 printf("Queue is empty\n");
 }
 else{
 return cqueue[front]; }
}
int getRear(int cqueue[]){
 if (front==-1 && rear==-1){
 printf("Queue is empty\n");
 }
 else{
 return cqueue[rear];}
}
int main(){
 int choice,value;
 do{
 printf("Enter choice:\n 1.isFull\n 2.isEmpty\n 3.Enqueue\n 4.Dequeue\n 5.getFront\n 6.getRear\n 0.exit\n");
 scanf("%d",&choice);
 switch(choice){
 case 1:
 if (isFull(cqueue)){
 printf("queue is full\n");}
 else{
 printf("queue is not full\n");}
 break;
 case 2:
 if (isEmpty(cqueue)){
 printf("queue is empty\n");
 }
 else{
 printf("queue is not empty\n");
 }
 break;
 case 3:
 printf("enter value to be added to circular queue: \n");
 scanf("%d",&value);
 enqueue(cqueue,value);
 break;
 case 4:
 int num=dequeue(cqueue);
 printf("dequeued value is %d\n",num);
 break;
 case 5:
 int f=getFront(cqueue);
 printf("element at front of queue is %d\n",f);
 break;
 case 6:
 int r=getRear(cqueue);
 printf("element at rear of queue is %d\n",r);
 break;}
 }
 while(choice!=0);
 return 0;}

 
EXP 5 singly ll
#include <stdio.h>
#include <stdlib.h>
struct node {
 int data;
 struct node *next;
};
struct node *createsll() {
 struct node *head = NULL;
 struct node *temp = NULL;
 struct node *newnode = NULL;
 int x;
 char ans;
 do {
 printf("Enter data for node: ");
 scanf("%d", &x);
 newnode = (struct node *)malloc(sizeof(struct node));
 newnode->data = x;
 newnode->next = NULL;
 if (head == NULL) {
 head = temp = newnode;
 } else {
 temp->next = newnode;
 temp = newnode;
 }
 printf("Do you want to add more nodes? (y/n): ");
 scanf(" %c", &ans);
 } while (ans == 'y');
 return head;
}
void display(struct node *head) {
 struct node *temp = head;
 if (temp == NULL) {
 printf("List is empty\n");
 } else {
 while (temp != NULL) {
 printf("%d -> ", temp->data);
 temp = temp->next;
 }
 printf("NULL\n");
 }
}
struct node *insertatbeginning(struct node *head) {
 struct node *newnode = (struct node *)malloc(sizeof(struct node));
 int x;
 printf("Enter data for node: ");
 scanf("%d", &x);
 newnode->data = x;
 newnode->next = head;
 head = newnode;
 return head;
}
struct node *insertinmiddle(struct node *head, int loc) {
 struct node *newnode = (struct node *)malloc(sizeof(struct node));
 struct node *temp = head;
 int x, i = 1;
 printf("Enter data for node: ");
 scanf("%d", &x);
 newnode->data = x;
 if (loc == 1) {
 newnode->next = head;
 head = newnode;
 } else {
 while (i < loc - 1 && temp != NULL) {
 temp = temp->next;
 i++;
 }
 if (temp == NULL) {
 printf("Location out of bounds\n");
 free(newnode);
 return head;
 }
 newnode->next = temp->next;
 temp->next = newnode;
 }
 return head;
}
struct node *insertatend(struct node *head) {
 struct node *newnode = (struct node *)malloc(sizeof(struct node));
 struct node *temp = head;
 int x;
 printf("Enter data for node: ");
 scanf("%d", &x);
 newnode->data = x;
 newnode->next = NULL;
 if (head == NULL) {
 head = newnode;
 } else {
 while (temp->next != NULL) {
 temp = temp->next;
 }
 temp->next = newnode;
 }
 return head;
}
struct node *deletefirstnode(struct node *head) {
 struct node *dnode;
 if (head == NULL) {
 printf("List is empty\n");
 return NULL;
 }
 dnode = head;
 head = head->next;
 free(dnode);
 return head;
}
struct node *deletemiddlenode(struct node *head, int loc) {
 struct node *temp = head;
 struct node *dnode;
 int i = 1;
 if (head == NULL) {
 printf("List is empty\n");
 return NULL;
 }
 if (loc == 1) {
 head = head->next;
 free(temp);
 return head;
 }
 while (i < loc - 1 && temp != NULL) {
 temp = temp->next;
 i++;
 }
 if (temp == NULL || temp->next == NULL) {
 printf("Location out of bounds\n");
 return head;
 }
 dnode = temp->next;
 temp->next = dnode->next;
 free(dnode);
 return head;
}
struct node *deletelastnode(struct node *head) {
 struct node *temp = head;
 struct node *dnode = NULL;
 if (head == NULL) {
 printf("List is empty\n");
 return NULL;
 }
 if (head->next == NULL) {
 free(head);
 return NULL;
 }
 while (temp->next->next != NULL) {
 temp = temp->next;
 }
 dnode = temp->next;
 temp->next = NULL;
 free(dnode);
 return head;
}
struct node *displayreverse(struct node *head) {
 struct node *prevnode = NULL;
 struct node *currentnode = head;
 struct node *nextnode = NULL;
 while (currentnode != NULL) {
 nextnode = currentnode->next;
 currentnode->next = prevnode;
 prevnode = currentnode;
 currentnode = nextnode;
 }
 head = prevnode;
 display(head);
 return head;
}
int main() {
 struct node *head = NULL;
 int choice, loc;
 while (1) {
 printf("1. Create list\n2. Display list\n3. Insert at beginning\n4. Insert in middle\n5. Insert at end\n6. Delete from beginning\n7. Delete 
from middle\n8. Delete from end\n9. Reverse list\n10. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 head = createsll();
 break;
 case 2:
 display(head);
 break;
 case 3:
 head = insertatbeginning(head);
 break;
 case 4:
 printf("Enter location to insert: ");
 scanf("%d", &loc);
 head = insertinmiddle(head, loc);
 break;
 case 5:
 head = insertatend(head);
 break;
 case 6:
 head = deletefirstnode(head);
 break;
 case 7:
 printf("Enter location to delete: ");
 scanf("%d", &loc);
 head = deletemiddlenode(head, loc);
 break;
 case 8:
 head = deletelastnode(head);
 break;
 case 9:
 head = displayreverse(head);
 break;
 case 10:
 exit(0);
 default:
 printf("Invalid choice\n");
 }
 }
 return 0;
}


EXP 6 ll stack implementation
#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node* next;
}node;
void push(struct node** top,int data);
void display(struct node* top);
int isempty(struct node* top);
int peek(struct node* top);
void push(struct node** top,int data){
 struct node* newnode=(struct node*)malloc(sizeof(node));
 if (!newnode){
 printf("Stack overflow\n");
 return;
 }
 newnode->data=data;
 newnode->next=*top;
 *top=newnode;
}
int isempty(struct node * top){
 return top==NULL;}
int pop (struct node ** top){
 if(isempty(*top)){
 printf("Stack underflow\n");
 return -1;
 }
 struct node* temp=*top;
 *top=(*top)->next;
 int popped=temp->data;
 free (temp);
 return popped;
}
int peek(struct node* top){
 if(isempty(top)){
 printf("stack is empty\n");
 return -1;
 }
 return top->data;
}
void display(struct node* top){ 
 struct node* temp=top;
 while(temp){
 printf("%d->",temp->data);
 temp=temp->next;}
 printf("NULL\n");
}
int main(){
 struct node* stack= NULL;
 int choice,value;
 do{
 printf("Menu:\n");
 printf("1. push\n");
 printf("2. pop\n");
 printf("3. peek\n");
 printf("4. display\n");
 printf("5. exit\n");
 printf("enter your choice : ");
 scanf("%d",&choice);
 switch(choice){
 case 1:
 printf("Enter the value to push: ");
 scanf("%d",&value);
 push(&stack,value);
 break;
 case 2:
 value=pop(&stack);
 if(value!=-1){
 printf("Popped value: %d\n",value);
 break;
 }
 case 3:
 value=peek(stack);
 if (value!=-1){
 printf("Top value : %d\n",value);
 }
 break;
 case 4:
 display(stack);
 break;
 case 5:
 printf("Exiting\n");
 break;
 default:
 printf("invalid choice, try again\n");
 }
 }while (choice!=5);
 return 0;
}


EXP 7 circular singly ll
#include <stdio.h>
#include <stdlib.h>
struct node {
 int data;
 struct node *next;
};
struct node* createscll() {
 struct node *head = NULL, *temp, *newnode;
 int x;
 char ans;
 do {
 printf("Enter data to node: ");
 scanf("%d", &x);
 newnode = (struct node *)malloc(sizeof(struct node));
 newnode->data = x;
 newnode->next = NULL;
 if (head == NULL) {
 head = newnode;
 newnode->next = head;
 } else {
 temp = head;
 while (temp->next != head) {
 temp = temp->next;
 }
 temp->next = newnode;
 newnode->next = head;
 }
 printf("Do you want to add more nodes? (y/n): ");
 scanf(" %c", &ans);
 } while (ans == 'y');
 return head;
}
void display(struct node *head) {
 struct node *temp = head;
 if (temp == NULL) {
 printf("List is empty\n");
 return;
 }
 do {
 printf("%d -> ", temp->data);
 temp = temp->next;
 } while (temp != head);
 printf("HEAD\n");
}
struct node* insertatbeginning(struct node *head) {
 struct node *newnode = (struct node *)malloc(sizeof(struct node));
 struct node *temp = head;
 int x;
 printf("Enter data for node: ");
 scanf("%d", &x);
 newnode->data = x;
 if (head == NULL) {
 newnode->next = newnode;
 head = newnode;
 } else {
 while (temp->next != head) {
 temp = temp->next;
 }
 newnode->next = head;
 temp->next = newnode;
 head = newnode;
 }
 return head;
}
struct node* insertinmiddle(struct node *head, int loc) {
 struct node *newnode = (struct node *)malloc(sizeof(struct node));
 struct node *temp = head;
 int x, i = 1;
 printf("Enter data for node: ");
 scanf("%d", &x);
 newnode->data = x;
 if (loc == 1) {
 return insertatbeginning(head);
 }
 while (i < loc - 1 && temp->next != head) {
 temp = temp->next;
 i++;
 }
 if (temp->next == head && i < loc - 1) {
 printf("Location out of bounds\n");
 free(newnode);
 return head;
 }
 newnode->next = temp->next;
 temp->next = newnode;
 return head;
}
struct node* insertatend(struct node *head) {
 struct node *newnode = (struct node *)malloc(sizeof(struct node));
 struct node *temp = head;
 int x;
 printf("Enter data for node: ");
 scanf("%d", &x);
 newnode->data = x;
 if (head == NULL) {
 newnode->next = newnode;
 head = newnode;
 } else {
 while (temp->next != head) {
 temp = temp->next;
 }
 temp->next = newnode;
 newnode->next = head;
 }
 return head;
}
struct node* deletefirstnode(struct node *head) {
 struct node *temp = head, *dnode;
 if (head == NULL) {
 printf("List is empty\n");
 return NULL;
 }
 if (head->next == head) {
 free(head);
 return NULL;
 }
 while (temp->next != head) {
 temp = temp->next;
 }
 dnode = head;
 head = head->next;
 temp->next = head;
 free(dnode);
 return head;
}
struct node* deletemiddlenode(struct node *head, int loc) {
 struct node *temp = head, *dnode;
 int i = 1;
 if (head == NULL) {
 printf("List is empty\n");
 return NULL;
 }
 if (loc == 1) {
 return deletefirstnode(head);
 }
 while (i < loc - 1 && temp->next != head) {
 temp = temp->next;
 i++;
 }
 if (temp->next == head || temp->next->next == head && i < loc - 1) {
 printf("Location out of bounds\n");
 return head;
 }
 dnode = temp->next;
 temp->next = dnode->next;
 free(dnode);
 return head;
}
struct node* deletelastnode(struct node *head) {
 struct node *temp = head, *dnode;
 if (head == NULL) {
 printf("List is empty\n");
 return NULL;
 }
 if (head->next == head) {
 free(head);
 return NULL;}
 while (temp->next->next != head) {
 temp = temp->next;
 }
 dnode = temp->next;
 temp->next = head;
 free(dnode);
 return head;
}
int main() {
 struct node *head = NULL;
 int choice, loc;
 while (1) {
 printf("\n1. Create circular linked list\n2. Display list\n3. Insert at beginning\n4. Insert in middle\n5. Insert at end\n6. Delete from 
beginning\n7. Delete from middle\n8. Delete from end\n9. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 head = createscll();
 break;
 case 2:
 display(head);
 break;
 case 3:
 head = insertatbeginning(head);
 break;
 case 4:
 printf("Enter location to insert: ");
 scanf("%d", &loc);
 head = insertinmiddle(head, loc);
 break;
 case 5:
 head = insertatend(head);
 break;
 case 6:
 head = deletefirstnode(head);
 break;
 case 7:
 printf("Enter location to delete: ");
 scanf("%d", &loc);
 head = deletemiddlenode(head, loc);
 break;
 case 8:
 head = deletelastnode(head);
 break;
 case 9:
 exit(0);
 default:
 printf("Invalid choice\n"); }
 }
 return 0;
}


EXP 8 circular doubly ll
#include <stdio.h>
#include <stdlib.h>
struct node {
 int data;
 struct node *next;
 struct node *prev;
};
struct node* createcdll() {
 struct node *head = NULL, *temp, *newnode;
 int x;
 char ans;
 do {
 printf("Enter data to node: ");
 scanf("%d", &x);
 newnode = (struct node *)malloc(sizeof(struct node));
 newnode->data = x;
 if (head == NULL) {
 head = newnode;
 head->next = head;
 head->prev = head;
 } else {
 temp = head->prev;
 temp->next = newnode;
 newnode->prev = temp;
 newnode->next = head;
 head->prev = newnode;
 }
 printf("Do you want to add more nodes? (y/n): ");
 scanf(" %c", &ans);
 } while (ans == 'y');
 return head;
}
void display(struct node *head) {
 struct node *temp = head;
 if (temp == NULL) {
 printf("List is empty\n");
 return;
 }
 do {
 printf("%d -> ", temp->data);
 temp = temp->next;
 } while (temp != head);
 printf("HEAD\n");
}
struct node* insertatbeginning(struct node *head) {
 struct node *newnode = (struct node *)malloc(sizeof(struct node));
 int x;
 printf("Enter data for node: ");
 scanf("%d", &x);
 newnode->data = x;
 if (head == NULL) {
 head = newnode;
 head->next = head;
 head->prev = head;
 } else {
 struct node *last = head->prev;
 newnode->next = head;
 newnode->prev = last;
 last->next = newnode;
 head->prev = newnode;
 head = newnode;
 }
 return head;
}
struct node* insertinmiddle(struct node *head, int loc) {
 struct node *newnode = (struct node *)malloc(sizeof(struct node));
 struct node *temp = head;
 int x, i = 1;
 printf("Enter data for node: ");
 scanf("%d", &x);
 newnode->data = x;
 if (loc == 1) {
 return insertatbeginning(head);
 }
 while (i < loc - 1 && temp->next != head) {
 temp = temp->next;
 i++;
 }
 if (temp->next == head && i < loc - 1) {
 printf("Location out of bounds\n");
 free(newnode);
 return head;
 }
 newnode->next = temp->next;
 newnode->prev = temp;
 temp->next->prev = newnode;
 temp->next = newnode;
 return head;
}
struct node* insertatend(struct node *head) {
 struct node *newnode = (struct node *)malloc(sizeof(struct node));
 int x;
 printf("Enter data for node: ");
 scanf("%d", &x);
 newnode->data = x;
 if (head == NULL) {
 head = newnode;
 head->next = head;
 head->prev = head;
 } else {
 struct node *last = head->prev;
 last->next = newnode;
 newnode->prev = last;
 newnode->next = head;
 head->prev = newnode;
 }
 return head;
}
struct node* deletefirstnode(struct node *head) {
 struct node *temp = head;
 if (head == NULL) {
 printf("List is empty\n");
 return NULL;
 }
 if (head->next == head) {
 free(head);
 return NULL;
 }
 struct node *last = head->prev;
 head = head->next;
 last->next = head;
 head->prev = last;
 free(temp);
 return head;
}
struct node* deletemiddlenode(struct node *head, int loc) {
 struct node *temp = head;
 int i = 1;
 if (head == NULL) {
 printf("List is empty\n");
 return NULL;
 }
 if (loc == 1) {
 return deletefirstnode(head);
 }
 while (i < loc && temp->next != head) {
 temp = temp->next;
 i++;
 }
 if (temp->next == head && i < loc) {
 printf("Location out of bounds\n");
 return head;
 }
 temp->prev->next = temp->next;
 temp->next->prev = temp->prev;
 free(temp);
 return head;
}
struct node* deletelastnode(struct node *head) {
 struct node *temp = head;
 if (head == NULL) {
 printf("List is empty\n");
 return NULL;
 }
 if (head->next == head) {
 free(head);
 return NULL;
 }
 struct node *last = head->prev;
 last->prev->next = head;
 head->prev = last->prev;
 free(last);
 return head;
}
int main() {
 struct node *head = NULL;
 int choice, loc;
 while (1) {
 printf("\n1. Create list\n2. Display list\n3. Insert at beginning\n4. Insert in middle\n5. Insert at end\n6. Delete from beginning\n7. 
Delete from middle\n8. Delete from end\n9. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 head = createcdll();
 break;
 case 2:
 display(head);
 break;
 case 3:
 head = insertatbeginning(head);
 break;
 case 4:
 printf("Enter location to insert: ");
 scanf("%d", &loc);
 head = insertinmiddle(head, loc);
 break;
 case 5:
 head = insertatend(head);
 break;
 case 6:
 head = deletefirstnode(head);
 break;
 case 7:
 printf("Enter location to delete: ");
 scanf("%d", &loc);
 head = deletemiddlenode(head, loc);
 break;
 case 8:
 head = deletelastnode(head);
 break;
 case 9:
 exit(0);
 default:
 printf("Invalid choice\n");}}
 return 0;
}


EXP 9 bst
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
 int data;
 struct Node* left;
 struct Node* right;
} BSTNode;
BSTNode* createNode(int data) {
 BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
 newNode->data = data;
 newNode->left = newNode->right = NULL;
 return newNode;
}
BSTNode* insertNode(BSTNode* root, int data) {
 if (root == NULL) {
 return createNode(data);
 }
 if (data < root->data) {
 root->left = insertNode(root->left, data);
 } else if (data > root->data) {
 root->right = insertNode(root->right, data); }
 return root;}
void inorderTraversal(BSTNode* root) {
 if (root != NULL) {
 inorderTraversal(root->left);
 printf("%d ", root->data);
 inorderTraversal(root->right);
 }}
void preorderTraversal(BSTNode* root) {
 if (root != NULL) {
 printf("%d ", root->data);
 preorderTraversal(root->left);
 preorderTraversal(root->right);
 }}
void postorderTraversal(BSTNode* root) {
 if (root != NULL) {
 postorderTraversal(root->left);
 postorderTraversal(root->right);
 printf("%d ", root->data);
 }}
int searchNode(BSTNode* root, int key) {
 if (root == NULL) {
 return 0; }
 if (root->data == key) {
 return 1; }
 if (key < root->data) {
 return searchNode(root->left, key);
 } else {
 return searchNode(root->right, key);
 }}
BSTNode* deleteNode(BSTNode* root, int key) {
 if (root == NULL)
 return root;
 if (key < root->data) {
 root->left = deleteNode(root->left, key);
 } else if (key > root->data) {
 root->right = deleteNode(root->right, key);
 } else {
 // Case 1: No child (Leaf node)
 if (root->left == NULL && root->right == NULL) {
 free(root);
 return NULL; }
 // Case 2: One child
 else if (root->left == NULL) {
 BSTNode* temp = root->right;
 free(root);
 return temp;
 } else if (root->right == NULL) {
 BSTNode* temp = root->left;
 free(root);
 return temp;
 }
 // Case 3: Two children - directly replace with the rightmost child from the left subtree
 else {
 BSTNode* parent = root;
 BSTNode* succ = root->left;
 while (succ->right != NULL) {
 parent = succ;
 succ = succ->right; }
 root->data = succ->data;
 if (parent != root) {
 parent->right = succ->left;
 } else {
 parent->left = succ->left; }
 free(succ);
 }}
 return root;
}
int main() {
 BSTNode* root = NULL;
 int choice, value;
 do {
 printf("1. Insert\n2. In-order Traversal\n3. Pre-order Traversal\n4. Post-order Traversal\n5. Search\n6.Delete\n7. Exit ");
 printf("\nEnter your choice:");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter value to insert: ");
 scanf("%d", &value);
 root = insertNode(root, value);
 break;
 case 2:
 printf("In-order Traversal: ");
 inorderTraversal(root);
 printf("\n");
 break;
 case 3:
 printf("Pre-order Traversal: ");
 preorderTraversal(root);
 printf("\n");
 break;
 case 4:
 printf("Post-order Traversal: ");
 postorderTraversal(root);
 printf("\n");
 break;
 case 5:
 printf("Enter value to search: ");
 scanf("%d", &value);
 if (searchNode(root, value))
 printf("Node found.\n");
 else
 printf("Node not found.\n");
 break;
 case 6:
 printf("Enter value to delete: ");
 scanf("%d", &value);
 root = deleteNode(root, value);
 break;
 case 7:
 exit(0);
 default:
 printf("Invalid choice!\n");
 } }
while(choice!=7);
 return 0;
}


EXP 10 avl
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
 int key;
 struct Node *left;
 struct Node *right;
 int height;
} Node;
int max(int a, int b) {
 return (a > b) ? a : b;
}
int height(Node *n) {
 if (n == NULL)
 return 0;
 return n->height;
}
Node *createNode(int key) {
 Node *node = (Node *)malloc(sizeof(Node));
 node->key = key;
 node->left = NULL;
 node->right = NULL;
 node->height = 1;
 return node;
}
Node *rightRotate(Node *y) {
 Node *x = y->left;
 Node *T2 = x->right;
 x->right = y;
 y->left = T2;
 y->height = max(height(y->left), height(y->right)) + 1;
 x->height = max(height(x->left), height(x->right)) + 1;
 return x;
}
Node *leftRotate(Node *x) {
 Node *y = x->right;
 Node *T2 = y->left;
 y->left = x;
 x->right = T2;
 x->height = max(height(x->left), height(x->right)) + 1;
 y->height = max(height(y->left), height(y->right)) + 1;
 return y;
}
int getBalance(Node *n) {
 if (n == NULL)
 return 0;
 return height(n->left) - height(n->right);
}
Node *insert(Node *node, int key) {
 if (node == NULL)
 return createNode(key);
 if (key < node->key)
 node->left = insert(node->left, key);
 else if (key > node->key)
 node->right = insert(node->right, key);
 else
 return node;
 node->height = 1 + max(height(node->left), height(node->right));
 int balance = getBalance(node);
 if (balance > 1 && key < node->left->key)
 return rightRotate(node);
 if (balance < -1 && key > node->right->key)
 return leftRotate(node);
 if (balance > 1 && key > node->left->key) {
 node->left = leftRotate(node->left);
 return rightRotate(node);
 }
 if (balance < -1 && key < node->right->key) {
 node->right = rightRotate(node->right);
 return leftRotate(node);
 }
 return node;
}
Node *minValueNode(Node *node) {
 Node *current = node;
 while (current->left != NULL)
 current = current->left;
 return current;
}
Node *deleteNode(Node *root, int key) {
 if (root == NULL)
 return root;
 if (key < root->key)
 root->left = deleteNode(root->left, key);
 else if (key > root->key)
 root->right = deleteNode(root->right, key);
 else {
 if ((root->left == NULL) || (root->right == NULL)) {
 Node *temp = root->left ? root->left : root->right;
 if (temp == NULL) {
 temp = root;
 root = NULL;
 } else
 *root = *temp;
 free(temp);
 } else {
 Node *temp = minValueNode(root->right);
 root->key = temp->key;
 root->right = deleteNode(root->right, temp->key);
 }
 }
 if (root == NULL)
 return root;
 root->height = 1 + max(height(root->left), height(root->right));
 int balance = getBalance(root);
 if (balance > 1 && getBalance(root->left) >= 0)
 return rightRotate(root);
 if (balance > 1 && getBalance(root->left) < 0) {
 root->left = leftRotate(root->left);
 return rightRotate(root);
 }
 if (balance < -1 && getBalance(root->right) <= 0)
 return leftRotate(root);
 if (balance < -1 && getBalance(root->right) > 0) {
 root->right = rightRotate(root->right);
 return leftRotate(root);
 }
 return root;
}
void preOrder(Node *root) {
 if (root != NULL) {
 printf("%d ", root->key);
 preOrder(root->left);
 preOrder(root->right);
 }
}
int main() {
 Node *root = NULL;
 root = insert(root, 10);
 root = insert(root, 20);
 root = insert(root, 30);
 root = insert(root, 40);
 root = insert(root, 50);
 root = insert(root, 25);
 printf("Preorder traversal of the AVL tree is:\n");
 preOrder(root);
 root = deleteNode(root, 10);
 printf("\nPreorder traversal after deletion of 10:\n");
 preOrder(root);
 return 0;
}


EXP 11 bfs dfs
#include <stdio.h>
#include <stdlib.h>
#define MAX 10 
int adjMatrix[MAX][MAX]; 
int visited[MAX]; 
void createGraph(int vertices);
void bfs(int start, int vertices);
void dfs(int start, int vertices);
void createGraph(int vertices) {
 int i, j;
 printf("Enter the adjacency matrix (1 for edge, 0 for no edge):\n");
 for (i = 0; i < vertices; i++) {
 for (j = 0; j < vertices; j++) {
 printf("Edge from %d to %d: ", i, j);
 scanf("%d", &adjMatrix[i][j]);
 }}}
void bfs(int start, int vertices) {
 int queue[MAX], front = -1, rear = -1;
 int visited[MAX] = {0}; 
 int i;
 printf("BFS Traversal starting from vertex %d: ", start);
 rear++;
 front++;
 queue[rear] = start;
 visited[start] = 1;
 while (front <= rear) {
 int current = queue[front++];
 printf("%d ", current);
 for (i = 0; i < vertices; i++) {
 if (adjMatrix[current][i] == 1 && !visited[i]) {
 queue[++rear] = i;
 visited[i] = 1;
 }}}
 printf("\n");}
void dfs(int start, int vertices) {
 printf("%d ", start);
 visited[start] = 1;
 for (int i = 0; i < vertices; i++) {
 if (adjMatrix[start][i] == 1 && !visited[i]) {
 dfs(i, vertices);
 }}}
int main() {
 int vertices, choice, startVertex;
 printf("Enter the number of vertices in the graph (<= %d): ", MAX);
 scanf("%d", &vertices);
 if (vertices > MAX) {
 printf("Number of vertices exceeds the limit.\n");
 return 0;
 }
 createGraph(vertices);
 do {
 printf("\nMenu:\n");
 printf("1. BFS\n");
 printf("2. DFS\n");
 printf("3. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter the starting vertex for BFS (0-%d): ", vertices - 1);
 scanf("%d", &startVertex);
 bfs(startVertex, vertices);
 break;
 case 2:
 printf("Enter the starting vertex for DFS (0-%d): ", vertices - 1);
 scanf("%d", &startVertex);
 // Reset visited array for DFS
 for (int i = 0; i < vertices; i++) {
 visited[i] = 0;
 }
 printf("DFS Traversal starting from vertex %d: ", startVertex);
 dfs(startVertex, vertices);
 printf("\n");
 break;
 case 3:
 printf("Exiting...\n");
 break;
 default:
 printf("Invalid choice!\n");
 }
 } while (choice != 3);
 return 0;
}


EXP 12 binary search
#include <stdio.h>
#include <string.h>
typedef struct {
 int id;
 char name[50];
} Employee;
int binary_search(Employee employees[], int size, int target_id) {
 int left = 0, right = size - 1;
 while (left <= right) {
 int mid = left + (right - left) / 2;
 if (employees[mid].id == target_id) {
 return mid; }
 if (employees[mid].id < target_id) {
 left = mid + 1; }
 else {
 right = mid - 1;
 } }
 return -1; }
int main() {
 Employee employees[] = {
 {101, "Alice Johnson"},
 {104, "Bob Smith"},
 {109, "Charlie Brown"},
 {115, "Diana Adams"},
 {120, "Edward Kim"} };
 int size = sizeof(employees) / sizeof(employees[0]);
 int target_id;
 printf("Enter employee ID to search: ");
 scanf("%d", &target_id);
 int result = binary_search(employees, size, target_id);
 if (result != -1) {
 printf("Employee found: ID = %d, Name = %s\n", employees[result].id, employees[result].name);
 } else {
 printf("Employee with ID %d not found.\n", target_id);}
 return 0;
}


EXP 13 selection bubble insertion
#include <stdio.h>
void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void displayArray(int arr[], int n);
// Selection Sort function
void selectionSort(int arr[], int n) {
 int i, j, minIndex, temp;
 for (i = 0; i < n - 1; i++) {
 minIndex = i;
 for (j = i + 1; j < n; j++) {
 if (arr[j] < arr[minIndex]) {
 minIndex = j;
 }
 }
 // Swap the found minimum element with the first element
 temp = arr[minIndex];
 arr[minIndex] = arr[i];
 arr[i] = temp;
 }
}
// Bubble Sort function
void bubbleSort(int arr[], int n) {
 int i, j, temp;
 for (i = 0; i < n - 1; i++) {
 for (j = 0; j < n - i - 1; j++) {
 if (arr[j] > arr[j + 1]) {
 // Swap arr[j] and arr[j+1]
 temp = arr[j];
 arr[j] = arr[j + 1];
 arr[j + 1] = temp;
 }
 }
 }
}
// Insertion Sort function
void insertionSort(int arr[], int n) {
 int i, key, j;
 for (i = 1; i < n; i++) {
 key = arr[i];
 j = i - 1;
 while (j >= 0 && arr[j] > key) {
 arr[j + 1] = arr[j];
 j = j - 1;
 }
 arr[j + 1] = key;
 }
}
// Function to display the array
void displayArray(int arr[], int n) {
 for (int i = 0; i < n; i++) {
 printf("%d ", arr[i]);
 }
 printf("\n");
}
int main() {
 int arr[100], n, choice;
 printf("Enter the number of elements in the array: ");
 scanf("%d", &n);
 printf("Enter the elements of the array: ");
 for (int i = 0; i < n; i++) {
 scanf("%d", &arr[i]);
 }
 while (1) {
 printf("\nMenu:\n");
 printf("1. Selection Sort\n");
 printf("2. Bubble Sort\n");
 printf("3. Insertion Sort\n");
 printf("4. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 selectionSort(arr, n);
 printf("Array after Selection Sort: ");
 displayArray(arr, n);
 break;
 case 2:
 bubbleSort(arr, n);
 printf("Array after Bubble Sort: ");
 displayArray(arr, n);
 break;
 case 3:
 insertionSort(arr, n);
 printf("Array after Insertion Sort: ");
 displayArray(arr, n);
 break;
 case 4:
 printf("Exiting...\n");
 return 0;
 default:
 printf("Invalid choice, please try again.\n");
 }
 }
 return 0;
}


EXP 14 merge quick sort
#include <stdio.h>
void mergeSort(int arr[], int l, int r);
void quickSort(int arr[], int low, int high);
void displayArray(int arr[], int n);
void merge(int arr[], int l, int m, int r);
int partition(int arr[], int low, int high);
// Merge Sort function
void mergeSort(int arr[], int l, int r) {
 if (l < r) {
 int m = l + (r - l) / 2; // Middle point
 mergeSort(arr, l, m); // Sort first half
 mergeSort(arr, m + 1, r); // Sort second half
 merge(arr, l, m, r); // Merge the two halves
 }
}
void merge(int arr[], int l, int m, int r) {
 int i, j, k;
 int n1 = m - l + 1;
 int n2 = r - m;
 
 int L[n1], R[n2];
 
 // Copy data to temporary arrays L[] and R[]
 for (i = 0; i < n1; i++)
 L[i] = arr[l + i];
 for (j = 0; j < n2; j++)
 R[j] = arr[m + 1 + j];
 i = 0; // Initial index of first subarray
 j = 0; // Initial index of second subarray
 k = l; // Initial index of merged subarray
 // Merge the temp arrays back into arr[l..r]
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
 // Copy the remaining elements of L[], if any
 while (i < n1) {
 arr[k] = L[i];
 i++;
 k++;
 }
 // Copy the remaining elements of R[], if any
 while (j < n2) {
 arr[k] = R[j];
 j++;
 k++;
 }
}
// Quick Sort function
void quickSort(int arr[], int low, int high) {
 if (low < high) {
 int pi = partition(arr, low, high);
 quickSort(arr, low, pi - 1);
 quickSort(arr, pi + 1, high);
 }
}
// Partition function used by Quick Sort
int partition(int arr[], int low, int high) {
 int pivot = arr[high];
 int i = (low - 1); // Index of smaller element
 for (int j = low; j <= high - 1; j++) {
 if (arr[j] <= pivot) {
 i++;
 int temp = arr[i];
 arr[i] = arr[j];
 arr[j] = temp;
 }
 }
 int temp = arr[i + 1];
 arr[i + 1] = arr[high];
 arr[high] = temp;
 return (i + 1);
}
// Function to display the array
void displayArray(int arr[], int n) {
 for (int i = 0; i < n; i++) {
 printf("%d ", arr[i]);
 }
 printf("\n");
}
int main() {
 int arr[100], n, choice;
 printf("Enter the number of elements in the array: ");
 scanf("%d", &n);
 printf("Enter the elements of the array: ");
 for (int i = 0; i < n; i++) {
 scanf("%d", &arr[i]);
 }
 while (1) {
 printf("\nMenu:\n");
 printf("1. Merge Sort\n");
 printf("2. Quick Sort\n");
 printf("3. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 mergeSort(arr, 0, n - 1);
 printf("Array after Merge Sort: ");
 displayArray(arr, n);
 break;
 case 2:
 quickSort(arr, 0, n - 1);
 printf("Array after Quick Sort: ");
 displayArray(arr, n);
 break;
 case 3:
 printf("Exiting...\n");
 return 0;
 default:
 printf("Invalid choice, please try again.\n");
 }
 }
 return 0;
}