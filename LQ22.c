/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: 
head = [1,2,3,4,5]
Output: 
[5,4,3,2,1]

Example 2:
Input: 
head = [1,2]
Output: 
[2,1]

Example 3:
Input: 
head = []
Output: 
[]
 
Constraints:
The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
*/

#include <stdio.h>
#include <stdlib.h>
struct ListNode 
{
    int val;
    struct ListNode* next;
};
struct ListNode* reverseList(struct ListNode* head) 
{
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) 
    {
        struct ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
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
    head->next->next->val = 3;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    head->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = NULL;
    struct ListNode* reversedHead = reverseList(head);
    struct ListNode* current = reversedHead;
    while (current != NULL) 
    {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
    
    return 0;
}
*/