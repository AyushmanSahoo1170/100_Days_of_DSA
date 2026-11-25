/*
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a
normal queue (push, peek, pop, and empty).
Implement the MyQueue class:
void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:
You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty
operations are valid. Depending on your language, the stack may not be supported natively. You may simulate a stack using a
list or deque (double-ended queue) as long as you use only a stack's standard operations.

Example 1:
Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]
Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false

Constraints:
1 <= x <= 9
At most 100 calls will be made to push, pop, peek, and empty.
All the calls to pop and peek are valid.

Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? In other words, performing
n operations will take overall O(n) time even if one of those operations may take longer.
*/

#include <stdbool.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
} Node;
typedef struct
{
    Node* top;
} Stack;
static void stackPush(Stack* s, int x)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = s->top;
    s->top = newNode;
}
static int stackPop(Stack* s)
{
    Node* temp = s->top;
    int data = temp->data;
    s->top = temp->next;
    free(temp);
    return data;
}
static int stackPeek(Stack* s)
{
    return s->top->data;
}
static bool stackEmpty(Stack* s)
{
    return s->top == NULL;
}
typedef struct
{
    Stack inStack;
    Stack outStack;
} MyQueue;
MyQueue* myQueueCreate()
{
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->inStack.top = NULL;
    obj->outStack.top = NULL;
    return obj;
}
static void transfer(MyQueue* obj)
{
    if (stackEmpty(&obj->outStack))
    {
        while (!stackEmpty(&obj->inStack))
        {
            stackPush(&obj->outStack, stackPop(&obj->inStack));
        }
    }
}
void myQueuePush(MyQueue* obj, int x)
{
    stackPush(&obj->inStack, x);
}
int myQueuePop(MyQueue* obj)
{
    transfer(obj);
    return stackPop(&obj->outStack);
}
int myQueuePeek(MyQueue* obj)
{
    transfer(obj);
    return stackPeek(&obj->outStack);
}
bool myQueueEmpty(MyQueue* obj)
{
    return stackEmpty(&obj->inStack) && stackEmpty(&obj->outStack);
}
void myQueueFree(MyQueue* obj)
{
    while (!stackEmpty(&obj->inStack))
    {
        stackPop(&obj->inStack);
    }
    while (!stackEmpty(&obj->outStack))
    {
        stackPop(&obj->outStack);
    }
    free(obj);
}