/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array
prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is
impossible.

Constraints:
1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize)
{
    int* indegree = (int*)calloc(numCourses, sizeof(int));
    int* head = (int*)malloc(sizeof(int)*numCourses);
    int* next = (int*)malloc(sizeof(int)*(prerequisitesSize + 1));
    int* to = (int*)malloc(sizeof(int)*(prerequisitesSize + 1));
    for(int i=0; i<numCourses; i++)
    {
        head[i] = -1;
    }
    for(int i=0; i<prerequisitesSize; i++)
    {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        to[i] = a;
        next[i] = head[b];
        head[b] = i;
        indegree[a] = indegree[a] + 1;
    }
    int* queue = (int*)malloc(sizeof(int)*numCourses);
    int front = 0;
    int rear = 0;
    for(int i=0; i<numCourses; i++)
    {
        if(indegree[i] == 0)
        {
            queue[rear] = i;
            rear = rear + 1;
        }
    }
    int done = 0;
    while(front < rear)
    {
        int course = queue[front];
        front = front + 1;
        done = done + 1;
        for(int e=head[course]; e!=-1; e=next[e])
        {
            int nxt = to[e];
            indegree[nxt] = indegree[nxt] - 1;
            if(indegree[nxt] == 0)
            {
                queue[rear] = nxt;
                rear = rear + 1;
            }
        }
    }
    free(indegree);
    free(head);
    free(next);
    free(to);
    free(queue);
    return (done == numCourses);
}