/*
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return
the new head.

Example 1:
Input: 
head = [1,2,6,3,4,5,6], val = 6
Output: 
[1,2,3,4,5]

Example 2:
Input: 
head = [], val = 1
Output: 
[]

Example 3:
Input: 
head = [7,7,7,7], val = 7
Output: 
[]

Constraints:
The number of nodes in the list is in the range [0, 104].
1 <= Node.val <= 50
0 <= val <= 50
*/

#include <stdio.h>
#include <stdlib.h>
struct ListNode 
{
    int val;
    struct ListNode* next;
};
struct ListNode* removeElements(struct ListNode* head, int val) 
{
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* current = &dummy;
    while (current->next != NULL) 
    {
        if (current->next->val == val) 
        {
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } 
        else 
        {
            current = current->next;
        }
    }
    return dummy.next;
}

/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 6;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 3;
    head->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 4;
    head->next->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->next->next->val = 5;
    head->next->next->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->next->next->next->val = 6;
    head->next->next->next->next->next->next->next = NULL;
    int valToRemove = 6;
    struct ListNode* newHead = removeElements(head, valToRemove);
    struct ListNode* current = newHead;
    while (current != NULL) 
    {
        printf("%d ", current->val);
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }
    printf("\n");
    return 0;
}
*/