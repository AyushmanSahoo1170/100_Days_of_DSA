/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order. 

Example 1:
Input: 
nums = [1,1,1,2,2,3], k = 2
Output: 
[1,2]

Example 2:
Input: 
nums = [1], k = 1
Output: 
[1]

Example 3:
Input: 
nums = [1,2,1,2,1,2,3,1,3,2], k = 2
Output: 
[1,2]

Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

#include <stdio.h>
#include <stdlib.h>
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize)
{
    int freq[20001] = {0};
    int next[20001];
    for(int i=0; i<numsSize; i++)
    {
        freq[nums[i] + 10000] = freq[nums[i] + 10000] + 1;
    }
    int* head = (int*)malloc(sizeof(int)*(numsSize + 1));
    for(int i=0; i<=numsSize; i++)
    {
        head[i] = -1;
    }
    for(int i=0; i<=20000; i++)
    {
        if(freq[i] > 0)
        {
            next[i] = head[freq[i]];
            head[freq[i]] = i;
        }
    }
    int* result = (int*)malloc(k * sizeof(int));
    int index = 0;
    for(int f=numsSize; f>=1 && index<k; f--)
    {
        int cur = head[f];
        while(cur != -1 && index<k)
        {
            result[index] = cur - 10000;
            index = index + 1;
            cur = next[cur];
        }
    }
    free(head);
    *returnSize = k;
    return result;
}