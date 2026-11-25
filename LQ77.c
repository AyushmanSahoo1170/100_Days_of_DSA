/*
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where
connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly
or indirectly through the network. A critical connection is a connection that, if removed, will make some servers unable to
reach some other server. Return all critical connections in the network in any order.

Example 1:
Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.

Example 2:
Input: n = 2, connections = [[0,1]]
Output: [[0,1]]

Constraints:
2 <= n <= 105
n - 1 <= connections.length <= 105
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.
*/

#include <stdio.h>
#include <stdlib.h>
int** criticalConnections(int n, int** connections, int connectionsSize, int* connectionsColSize, int* returnSize, int** returnColumnSizes)
{
    int m = connectionsSize;
    int* head = (int*)malloc(sizeof(int)*n);
    int* next = (int*)malloc(sizeof(int)*(2*m + 1));
    int* to = (int*)malloc(sizeof(int)*(2*m + 1));
    int* disc = (int*)calloc(n, sizeof(int));
    int* low = (int*)calloc(n, sizeof(int));
    int* iter = (int*)malloc(sizeof(int)*n);
    int* pe = (int*)malloc(sizeof(int)*n);
    int* stack = (int*)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
    {
        head[i] = -1;
    }
    for(int i=0; i<m; i++)
    {
        int a = connections[i][0];
        int b = connections[i][1];
        to[2*i] = b;
        next[2*i] = head[a];
        head[a] = 2*i;
        to[2*i + 1] = a;
        next[2*i + 1] = head[b];
        head[b] = 2*i + 1;
    }
    for(int i=0; i<n; i++)
    {
        iter[i] = head[i];
    }
    int** result = (int**)malloc(sizeof(int*)*n);
    *returnColumnSizes = (int*)malloc(sizeof(int)*n);
    *returnSize = 0;
    int timer = 1;
    int top = 0;
    disc[0] = timer;
    low[0] = timer;
    pe[0] = -1;
    stack[top] = 0;
    top = top + 1;
    while(top > 0)
    {
        int u = stack[top - 1];
        int e = iter[u];
        if(e != -1)
        {
            iter[u] = next[e];
            if(e/2 != pe[u])
            {
                int v = to[e];
                if(disc[v] == 0)
                {
                    timer = timer + 1;
                    disc[v] = timer;
                    low[v] = timer;
                    pe[v] = e/2;
                    stack[top] = v;
                    top = top + 1;
                }
                else if(disc[v] < low[u])
                {
                    low[u] = disc[v];
                }
            }
        }
        else
        {
            top = top - 1;
            if(top > 0)
            {
                int p = stack[top - 1];
                if(low[u] < low[p])
                {
                    low[p] = low[u];
                }
                if(low[u] > disc[p])
                {
                    result[*returnSize] = (int*)malloc(sizeof(int)*2);
                    result[*returnSize][0] = p;
                    result[*returnSize][1] = u;
                    (*returnColumnSizes)[*returnSize] = 2;
                    *returnSize = *returnSize + 1;
                }
            }
        }
    }
    free(head);
    free(next);
    free(to);
    free(disc);
    free(low);
    free(iter);
    free(pe);
    free(stack);
    return result;
}