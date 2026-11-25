/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:
MinStack() initializes the stack object.
void push(int value) pushes the element value onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Example 1:
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]
Output
[null,null,null,null,-3,null,0,-2]
Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

Constraints:
-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    int min;
    struct Node* next;
} Node;
typedef struct 
{
    Node* head;
} MinStack;
MinStack* minStackCreate() 
{
    MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
    stack->head = NULL;
    return stack;
}
void minStackPush(MinStack* obj, int val) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    
    if (obj->head == NULL) 
    {
        newNode->min = val;
    } 
    else 
    {
        newNode->min = (val < obj->head->min) ? val : obj->head->min;
    }
    newNode->next = obj->head;
    obj->head = newNode;
}
void minStackPop(MinStack* obj) 
{
    if (obj->head != NULL) 
    {
        Node* temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    }
}
int minStackTop(MinStack* obj) 
{
    if (obj->head != NULL) 
    {
        return obj->head->data;
    }
    return -1;
}
int minStackGetMin(MinStack* obj) 
{
    if (obj->head != NULL) 
    {
        return obj->head->min;
    }
    return -1;
}
void minStackFree(MinStack* obj) 
{
    while (obj->head != NULL) 
    {
        Node* temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    }
    free(obj);
}