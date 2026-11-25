/*
Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array
contains less than two elements, return 0. You must write an algorithm that runs in linear time and uses linear extra space.

Example 1:
Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.

Example 2:
Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.

Constraints:
1 <= nums.length <= 105
0 <= nums[i] <= 109
*/

#include <stdio.h>
#include <stdlib.h>
int maximumGap(int* nums, int numsSize)
{
    if(numsSize < 2)
    {
        return 0;
    }
    int minVal = nums[0];
    int maxVal = nums[0];
    for(int i=0; i<numsSize; i++)
    {
        if(nums[i] < minVal)
        {
            minVal = nums[i];
        }
        if(nums[i] > maxVal)
        {
            maxVal = nums[i];
        }
    }
    if(minVal == maxVal)
    {
        return 0;
    }
    int bucketSize = (maxVal - minVal) / (numsSize - 1);
    if(bucketSize < 1)
    {
        bucketSize = 1;
    }
    int bucketCount = (maxVal - minVal) / bucketSize + 1;
    int* bucketMin = (int*)malloc(sizeof(int)*bucketCount);
    int* bucketMax = (int*)malloc(sizeof(int)*bucketCount);
    for(int i=0; i<bucketCount; i++)
    {
        bucketMin[i] = -1;
        bucketMax[i] = -1;
    }
    for(int i=0; i<numsSize; i++)
    {
        int b = (nums[i] - minVal) / bucketSize;
        if(bucketMin[b] == -1 || nums[i] < bucketMin[b])
        {
            bucketMin[b] = nums[i];
        }
        if(bucketMax[b] == -1 || nums[i] > bucketMax[b])
        {
            bucketMax[b] = nums[i];
        }
    }
    int answer = 0;
    int prevMax = minVal;
    for(int i=0; i<bucketCount; i++)
    {
        if(bucketMin[i] == -1)
        {
            continue;
        }
        if(bucketMin[i] - prevMax > answer)
        {
            answer = bucketMin[i] - prevMax;
        }
        prevMax = bucketMax[i];
    }
    free(bucketMin);
    free(bucketMax);
    return answer;
}