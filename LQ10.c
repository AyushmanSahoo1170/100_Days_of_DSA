/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many
times as it shows in both arrays and you may return the result in any order.

Example 1:
Input: 
nums1 = [1,2,2,1], nums2 = [2,2]
Output: 
[2,2]

Example 2:
Input: 
nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: 
[4,9]
Explanation: [9,4] is also accepted.

Constraints:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000

Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory
at once?
*/

#include <stdio.h>
#include <stdlib.h>
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) 
{
    int *result = (int *)malloc((nums1Size < nums2Size ? nums1Size : nums2Size) * sizeof(int));
    int k = 0;
    for (int i = 0; i < nums1Size; i++) 
    {
        for (int j = 0; j < nums2Size; j++) 
        {
            if (nums1[i] == nums2[j]) 
            {
                result[k++] = nums1[i];
                nums2[j] = -1;
                break;
            }
        }
    }
    *returnSize = k;
    return result;
}

/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n1, n2;
    printf("Enter number of elements in nums1 : ");
    scanf("%d", &n1);
    printf("Enter number of elements in nums2 : ");
    scanf("%d", &n2);
    int *nums1 = (int *)malloc(n1 * sizeof(int));
    int *nums2 = (int *)malloc(n2 * sizeof(int));
    if (nums1 == NULL || nums2 == NULL) 
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter the elements of nums1 separated by spaces : ");
    for (int i = 0; i < n1; i++) 
    {
        scanf("%d", &nums1[i]);
    }
    printf("Enter the elements of nums2 separated by spaces : ");
    for (int i = 0; i < n2; i++) 
    {
        scanf("%d", &nums2[i]);
    }
    int returnSize;
    int* result = intersect(nums1, n1, nums2, n2, &returnSize);
    printf("Intersection: ");
    for (int i = 0; i < returnSize; i++) 
    {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(nums1);
    free(nums2);
    free(result);
    return 0;
}
*/