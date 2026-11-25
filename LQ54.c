/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right,
then right to left for the next level and alternate between).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: [] 

Constraints:
The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
*/

#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    if (!root) 
    {
        *returnSize = 0;
        return NULL;
    }
    struct TreeNode* queue[2000];
    int **res = malloc(sizeof(int*) * 2000);
    *returnColumnSizes = malloc(sizeof(int) * 2000);
    int left = 0, right = 1;
    int level = 0;
    queue[0] = root;
    while (left < right) 
    {
        int levelSize = right - left;
        (*returnColumnSizes)[level] = levelSize;
        res[level] = malloc(sizeof(int) * levelSize);
        int currentLevelLeft = levelSize - 1;
        int currentLevelRight = 0;
        for (int i = 0; i < levelSize; i++) 
        {
            struct TreeNode* node = queue[left + i];
            if (level % 2 == 0) 
            {
                res[level][currentLevelRight++] = node->val;
            } 
            else 
            {
                res[level][currentLevelLeft--] = node->val;
            }
            if (node->left) queue[right++] = node->left;
            if (node->right) queue[right++] = node->right;
        }
        left = left + levelSize;
        level++;
    }
    *returnSize = level;
    return res;
}