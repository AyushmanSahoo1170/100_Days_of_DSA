/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:
Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [4,2,6,5,7,1,3,9,8]

Example 3:
Input: root = []
Output: []

Example 4:
Input: root = [1]
Output: [1]

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

Follow up: Recursive solution is trivial, could you do it iteratively?
*/

#include <stdio.h>
#include <stdlib.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int* result = (int*)malloc(sizeof(int)*101);
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*101);
    int top = 0;
    int index = 0;
    struct TreeNode* cur = root;
    while(cur != NULL || top > 0)
    {
        while(cur != NULL)
        {
            stack[top] = cur;
            top = top + 1;
            cur = cur->left;
        }
        top = top - 1;
        cur = stack[top];
        result[index] = cur->val;
        index = index + 1;
        cur = cur->right;
    }
    free(stack);
    *returnSize = index;
    return result;
}