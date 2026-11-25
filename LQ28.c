/*
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:
Input: 
head = [1,2,2,1]
Output: 
true

Example 2:
Input: 
head = [1,2]
Output: 
false

Constraints:
The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9

Follow up: Could you do it in O(n) time and O(1) space?
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct ListNode 
{
    int val;
    struct ListNode *next;
};
bool isPalindrome(struct ListNode* head) 
{
    if (head == NULL || head->next == NULL) 
    {
        return true;
    }
    struct ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *prev = NULL, *curr = slow, *next = NULL;
    while (curr != NULL) 
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    struct ListNode *firstHalf = head, *secondHalf = prev;
    while (secondHalf != NULL) 
    {
        if (firstHalf->val != secondHalf->val) 
        {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return true;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main() 
{
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 2;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 1;
    head->next->next->next->next = NULL;
    printf("%s\n", isPalindrome(head) ? "true" : "false");
    return 0;
}
*/