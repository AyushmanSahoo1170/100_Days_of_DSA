/*
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|,
where |val| denotes the absolute value of val.
Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any
two points.

Example 1:
Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation: 
We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.

Example 2:
Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18

Constraints:
1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.
*/

#include <stdio.h>
#include <stdlib.h>
int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize)
{
    int n = pointsSize;
    int INF = 2000000000;
    int* minDist = (int*)malloc(sizeof(int)*n);
    int* used = (int*)calloc(n, sizeof(int));
    for(int i=0; i<n; i++)
    {
        minDist[i] = INF;
    }
    minDist[0] = 0;
    int total = 0;
    for(int round=0; round<n; round++)
    {
        int u = -1;
        for(int i=0; i<n; i++)
        {
            if(used[i] == 0 && (u == -1 || minDist[i] < minDist[u]))
            {
                u = i;
            }
        }
        used[u] = 1;
        total = total + minDist[u];
        for(int v=0; v<n; v++)
        {
            if(used[v] == 0)
            {
                int dx = points[u][0] - points[v][0];
                int dy = points[u][1] - points[v][1];
                if(dx < 0)
                {
                    dx = -dx;
                }
                if(dy < 0)
                {
                    dy = -dy;
                }
                int cost = dx + dy;
                if(cost < minDist[v])
                {
                    minDist[v] = cost;
                }
            }
        }
    }
    free(minDist);
    free(used);
    return total;
}