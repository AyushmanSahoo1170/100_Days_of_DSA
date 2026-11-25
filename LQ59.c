/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the
postorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: inorder = [-1], postorder = [-1]
Output: [-1]

Constraints:
1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.
*/

#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* build(int* postorder, int* pos, int inLeft, int inRight, int* indexOf)
{
    if(inLeft > inRight)
    {
        return NULL;
    }
    int rootVal = postorder[*pos];
    *pos = *pos - 1;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = rootVal;
    int mid = indexOf[rootVal + 3000];
    node->right = build(postorder, pos, mid + 1, inRight, indexOf);
    node->left = build(postorder, pos, inLeft, mid - 1, indexOf);
    return node;
}
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize)
{
    int indexOf[6001];
    for(int i=0; i<inorderSize; i++)
    {
        indexOf[inorder[i] + 3000] = i;
    }
    int pos = postorderSize - 1;
    return build(postorder, &pos, 0, inorderSize - 1, indexOf);
}