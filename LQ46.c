/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level
by level).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []

Constraints:
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
*/

#include <stdio.h>
#include <stdlib.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    if(root == NULL)
    {
        *returnColumnSizes = NULL;
        return NULL;
    }
    int** result = (int**)malloc(sizeof(int*)*2000);
    *returnColumnSizes = (int*)malloc(sizeof(int)*2000);
    int front = 0;
    int rear = 0;
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*2000);
    queue[rear] = root;
    rear = rear + 1;
    while(front < rear)
    {
        int size = rear - front;
        (*returnColumnSizes)[*returnSize] = size;
        result[*returnSize] = (int*)malloc(sizeof(int)*size);
        for(int i = 0; i < size; i++)
        {
            struct TreeNode* node = queue[front];
            front = front + 1;
            result[*returnSize][i] = node->val;
            if(node->left != NULL)
            {
                queue[rear] = node->left;
                rear = rear + 1;
            }
            if(node->right != NULL)
            {
                queue[rear] = node->right;
                rear = rear + 1;
            }
        }
        *returnSize = *returnSize + 1;
    }
    free(queue);
    return result;
}