/*
Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the
second middle node.

Example 1:
Input: 
head = [1,2,3,4,5]
Output: 
[3,4,5]
Explanation: 
The middle node of the list is node 3.

Example 2:
Input: 
head = [1,2,3,4,5,6]
Output: 
[4,5,6]
Explanation: 
Since the list has two middle nodes with values 3 and 4, we return the second one.

Constraints:
The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100
*/

#include <stdio.h>
#include <stdlib.h>
struct ListNode 
{
    int val;
    struct ListNode* next;
};
struct ListNode* middleNode(struct ListNode* head) 
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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
    struct ListNode* middle = middleNode(head);
    printf("Middle node value: %d\n", middle->val);
    struct ListNode* current = head;
    while (current != NULL) 
    {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}
*/