/*
Given head, the head of a linked list, determine if the linked list has a cycle in it. There is a cycle in a linked list if
there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used
to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter. Return 
true if there is a cycle in the linked list. Otherwise, return false.

Example 1:
Input: 
head = [3,2,0,-4], pos = 1
Output: 
true
Explanation: 
There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:
Input: 
head = [1,2], pos = 0
Output: 
true
Explanation: 
There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:
Input: 
head = [1], pos = -1
Output: 
false
Explanation: 
There is no cycle in the linked list.

Constraints:
The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.

Follow up: Can you solve it using O(1) (i.e. constant) memory?
*/

#include <stdio.h>
#include <stdlib.h>
struct ListNode 
{
    int val;
    struct ListNode* next;
};
int hasCycle(struct ListNode* head) 
{
    if (head == NULL) 
    {
        return 0;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) 
        {
            return 1;
        }
    }
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
int main() 
{
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 3;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 0;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = -4;
    head->next->next->next->next = head->next; // Create a cycle
    int result = hasCycle(head);
    printf("%d\n", result); // Output: 1 (true)
    return 0;
}
*/