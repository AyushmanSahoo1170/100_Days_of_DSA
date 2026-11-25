/*
You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its
parent, itself, and its immediate children. Return the minimum number of cameras needed to monitor all nodes of the tree.

Example 1:
Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.

Example 2:
Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid
configurations of camera placement.

Constraints:
The number of nodes in the tree is in the range [1, 1000].
Node.val == 0
*/

#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int dfs(struct TreeNode* node, int* cameras)
{
    if(node == NULL)
    {
        return 1;
    }
    int left = dfs(node->left, cameras);
    int right = dfs(node->right, cameras);
    if(left == 0 || right == 0)
    {
        *cameras = *cameras + 1;
        return 2;
    }
    if(left == 2 || right == 2)
    {
        return 1;
    }
    return 0;
}
int minCameraCover(struct TreeNode* root)
{
    int cameras = 0;
    if(dfs(root, &cameras) == 0)
    {
        cameras = cameras + 1;
    }
    return cameras;
}