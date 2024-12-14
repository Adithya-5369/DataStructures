#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// Define the Double-Ended Stack structure
typedef struct DoubleEndedStack {
    Node *front;
    Node *rear;
} DoubleEndedStack;

// Initialize the Double-Ended Stack
DoubleEndedStack* initStack() {
    DoubleEndedStack *stack = (DoubleEndedStack *)malloc(sizeof(DoubleEndedStack));
    stack->front = stack->rear = NULL;
    return stack;
}

// Check if the stack is empty
int isEmpty(DoubleEndedStack *stack) {
    return stack->front == NULL;
}

// Push an element to the front
void pushFront(DoubleEndedStack *stack, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = stack->front;

    if (isEmpty(stack))
        stack->rear = newNode;
    else
        stack->front->prev = newNode;

    stack->front = newNode;
}

// Push an element to the rear
void pushRear(DoubleEndedStack *stack, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = stack->rear;

    if (isEmpty(stack))
        stack->front = newNode;
    else
        stack->rear->next = newNode;

    stack->rear = newNode;
}

// Pop an element from the front
int popFront(DoubleEndedStack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }

    Node *temp = stack->front;
    int value = temp->data;

    stack->front = stack->front->next;
    if (stack->front)
        stack->front->prev = NULL;
    else
        stack->rear = NULL;

    free(temp);
    return value;
}

// Pop an element from the rear
int popRear(DoubleEndedStack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }

    Node *temp = stack->rear;
    int value = temp->data;

    stack->rear = stack->rear->prev;
    if (stack->rear)
        stack->rear->next = NULL;
    else
        stack->front = NULL;

    free(temp);
    return value;
}

// Display the elements in the stack
void displayStack(DoubleEndedStack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }

    Node *temp = stack->front;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Free the memory used by the stack
void freeStack(DoubleEndedStack *stack) {
    while (!isEmpty(stack)) {
        popFront(stack);
    }
    free(stack);
}

int main() {
    DoubleEndedStack *stack = initStack();

    pushFront(stack, 10);
    pushRear(stack, 20);
    pushFront(stack, 5);
    displayStack(stack);

    printf("Popped from front: %d\n", popFront(stack));
    printf("Popped from rear: %d\n", popRear(stack));
    displayStack(stack);

    freeStack(stack);
    return 0;
}