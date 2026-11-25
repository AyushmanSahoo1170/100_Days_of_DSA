/*
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and
the median is the mean of the two middle values.
For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:
MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

Example 1:
Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]
Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0

Constraints:
-105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.

Follow up:
If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int *low;
    int lowSize;
    int *high;
    int highSize;
} MedianFinder;
static void heapPush(int *h, int *size, int val)
{
    int i = *size;
    h[i] = val;
    *size = *size + 1;
    while(i > 0)
    {
        int parent = (i - 1) / 2;
        if(h[parent] <= h[i])
        {
            break;
        }
        int temp = h[parent];
        h[parent] = h[i];
        h[i] = temp;
        i = parent;
    }
}
static int heapPop(int *h, int *size)
{
    int top = h[0];
    *size = *size - 1;
    h[0] = h[*size];
    int i = 0;
    while(1)
    {
        int child = 2*i + 1;
        if(child >= *size)
        {
            break;
        }
        if(child + 1 < *size && h[child + 1] < h[child])
        {
            child = child + 1;
        }
        if(h[i] <= h[child])
        {
            break;
        }
        int temp = h[i];
        h[i] = h[child];
        h[child] = temp;
        i = child;
    }
    return top;
}
MedianFinder* medianFinderCreate()
{
    MedianFinder *obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->low = (int*)malloc(sizeof(int)*50001);
    obj->high = (int*)malloc(sizeof(int)*50001);
    obj->lowSize = 0;
    obj->highSize = 0;
    return obj;
}
void medianFinderAddNum(MedianFinder* obj, int num)
{
    heapPush(obj->low, &obj->lowSize, -num);
    int moved = -heapPop(obj->low, &obj->lowSize);
    heapPush(obj->high, &obj->highSize, moved);
    if(obj->highSize > obj->lowSize)
    {
        int val = heapPop(obj->high, &obj->highSize);
        heapPush(obj->low, &obj->lowSize, -val);
    }
}
double medianFinderFindMedian(MedianFinder* obj)
{
    if(obj->lowSize > obj->highSize)
    {
        return (double)(-obj->low[0]);
    }
    return ((double)(-obj->low[0]) + (double)obj->high[0]) / 2.0;
}
void medianFinderFree(MedianFinder* obj)
{
    free(obj->low);
    free(obj->high);
    free(obj);
}