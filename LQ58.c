/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the
inorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]

Constraints:
1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
*/

#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* build(int* preorder, int* inorder, int* pos, int inLeft, int inRight, int* indexOf)
{
    if(inLeft > inRight)
    {
        return NULL;
    }
    int rootVal = preorder[*pos];
    *pos = *pos + 1;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = rootVal;
    int mid = indexOf[rootVal + 3000];
    node->left = build(preorder, inorder, pos, inLeft, mid - 1, indexOf);
    node->right = build(preorder, inorder, pos, mid + 1, inRight, indexOf);
    return node;
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    int indexOf[6001];
    for(int i=0; i<inorderSize; i++)
    {
        indexOf[inorder[i] + 3000] = i;
    }
    int pos = 0;
    return build(preorder, inorder, &pos, 0, inorderSize - 1, indexOf);
}