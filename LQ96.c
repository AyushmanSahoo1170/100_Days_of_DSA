/*
Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where:
0 <= i < j < nums.length and
nums[i] > 2 * nums[j].

Example 1:
Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

Example 2:
Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1

Constraints:
1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1
*/

#include <stdio.h>
#include <stdlib.h>
int sortCount(int* nums, int* temp, int left, int right)
{
    if(left >= right)
    {
        return 0;
    }
    int mid = left + (right - left) / 2;
    int count = sortCount(nums, temp, left, mid) + sortCount(nums, temp, mid + 1, right);
    int j = mid + 1;
    for(int i=left; i<=mid; i++)
    {
        while(j <= right && (long long)nums[i] > 2LL * nums[j])
        {
            j = j + 1;
        }
        count = count + (j - (mid + 1));
    }
    int a = left;
    int b = mid + 1;
    int k = left;
    while(a <= mid && b <= right)
    {
        if(nums[a] <= nums[b])
        {
            temp[k] = nums[a];
            a = a + 1;
        }
        else
        {
            temp[k] = nums[b];
            b = b + 1;
        }
        k = k + 1;
    }
    while(a <= mid)
    {
        temp[k] = nums[a];
        a = a + 1;
        k = k + 1;
    }
    while(b <= right)
    {
        temp[k] = nums[b];
        b = b + 1;
        k = k + 1;
    }
    for(int i=left; i<=right; i++)
    {
        nums[i] = temp[i];
    }
    return count;
}
int reversePairs(int* nums, int numsSize)
{
    int* temp = (int*)malloc(sizeof(int)*numsSize);
    int result = sortCount(nums, temp, 0, numsSize - 1);
    free(temp);
    return result;
}