/*
You are given an m x n grid where each cell can have one of three values:
0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
*/

#include <stdio.h>
#include <stdlib.h>
int orangesRotting(int** grid, int gridSize, int* gridColSize)
{
    int m = gridSize;
    int n = gridColSize[0];
    int* queue = (int*)malloc(sizeof(int)*m*n);
    int front = 0;
    int rear = 0;
    int fresh = 0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(grid[i][j] == 2)
            {
                queue[rear] = i*n + j;
                rear = rear + 1;
            }
            else if(grid[i][j] == 1)
            {
                fresh = fresh + 1;
            }
        }
    }
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    int minutes = 0;
    while(front < rear && fresh > 0)
    {
        int size = rear - front;
        for(int k=0; k<size; k++)
        {
            int cell = queue[front];
            front = front + 1;
            int r = cell / n;
            int c = cell % n;
            for(int d=0; d<4; d++)
            {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1)
                {
                    grid[nr][nc] = 2;
                    fresh = fresh - 1;
                    queue[rear] = nr*n + nc;
                    rear = rear + 1;
                }
            }
        }
        minutes = minutes + 1;
    }
    free(queue);
    if(fresh > 0)
    {
        return -1;
    }
    return minutes;
}