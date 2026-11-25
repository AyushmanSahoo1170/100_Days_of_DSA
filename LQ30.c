/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each
of their nodes contains a single digit. Add the two numbers and return the sum as a linked list. You may assume the two numbers
do not contain any leading zero, except the number 0 itself.

Example 1:
Input: 
l1 = [7,2,4,3], l2 = [5,6,4]
Output: 
[7,8,0,7]

Example 2:
Input: 
l1 = [2,4,3], l2 = [5,6,4]
Output: 
[8,0,7]

Example 3:
Input: 
l1 = [0], l2 = [0]
Output: 
[0]

Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

Follow up: Could you solve it without reversing the input lists?
*/

#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode* createNode(int val)
{
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val  = val;
    node->next = NULL;
    return node;
}
int getLength(struct ListNode* head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int len1 = getLength(l1);
    int len2 = getLength(l2);
    int stack1[101], stack2[101];
    int top1 = 0, top2 = 0;
    while (l1 != NULL)
    {
        stack1[top1++] = l1->val;
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        stack2[top2++] = l2->val;
        l2 = l2->next;
    }
    int carry = 0;
    struct ListNode* resultHead = NULL;
    while (top1 > 0 || top2 > 0 || carry != 0)
    {
        int sum = carry;
        if (top1 > 0) 
        {
            sum = sum + stack1[--top1]; 
        }
        if (top2 > 0) 
        {
            sum = sum + stack2[--top2];
        }
        carry = sum / 10;
        struct ListNode* newNode = createNode(sum % 10);
        newNode->next = resultHead;
        resultHead = newNode;
    }
    return resultHead;
}
void printList(struct ListNode* head)
{
    printf("[");
    while (head != NULL)
    {
        printf("%d", head->val);
        if (head->next != NULL) 
        {
            printf(",");
        }
        head = head->next;
    }
    printf("]\n");
}
void freeList(struct ListNode* head)
{
    struct ListNode* temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/*
int main()
{
    struct ListNode* l1 = createNode(7);
    l1->next = createNode(2);
    l1->next->next = createNode(4);
    l1->next->next->next = createNode(3);
    struct ListNode* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);
    printf("Test 1 : ");
    struct ListNode* r1 = addTwoNumbers(l1, l2);
    printList(r1);  
    freeList(l1); freeList(l2); freeList(r1);
    struct ListNode* l3 = createNode(2);
    l3->next = createNode(4);
    l3->next->next = createNode(3);
    struct ListNode* l4 = createNode(5);
    l4->next = createNode(6);
    l4->next->next = createNode(4);
    printf("Test 2 : ");
    struct ListNode* r2 = addTwoNumbers(l3, l4);
    printList(r2); 
    freeList(l3); freeList(l4); freeList(r2);
    struct ListNode* l5 = createNode(0);
    struct ListNode* l6 = createNode(0);
    printf("Test 3 : ");
    struct ListNode* r3 = addTwoNumbers(l5, l6);
    printList(r3); 
    freeList(l5); freeList(l6); freeList(r3);
    return 0;
}
*/