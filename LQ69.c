/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges
times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to
travel from source to target. We will send a signal from a given node k. Return the minimum time it takes for all the n nodes
to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

Example 1:
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

Example 2:
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

Example 3:
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1

Constraints:
1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
*/

#include <stdio.h>
#include <stdlib.h>
int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k)
{
    int INF = 1000000000;
    int* dist = (int*)malloc(sizeof(int)*(n + 1));
    int* done = (int*)calloc(n + 1, sizeof(int));
    int* head = (int*)malloc(sizeof(int)*(n + 1));
    int* next = (int*)malloc(sizeof(int)*(timesSize + 1));
    int* to = (int*)malloc(sizeof(int)*(timesSize + 1));
    int* weight = (int*)malloc(sizeof(int)*(timesSize + 1));
    for(int i=0; i<=n; i++)
    {
        dist[i] = INF;
        head[i] = -1;
    }
    for(int i=0; i<timesSize; i++)
    {
        int u = times[i][0];
        to[i] = times[i][1];
        weight[i] = times[i][2];
        next[i] = head[u];
        head[u] = i;
    }
    dist[k] = 0;
    for(int round=0; round<n; round++)
    {
        int u = -1;
        for(int i=1; i<=n; i++)
        {
            if(done[i] == 0 && (u == -1 || dist[i] < dist[u]))
            {
                u = i;
            }
        }
        if(u == -1 || dist[u] == INF)
        {
            break;
        }
        done[u] = 1;
        for(int e=head[u]; e!=-1; e=next[e])
        {
            int v = to[e];
            if(dist[u] + weight[e] < dist[v])
            {
                dist[v] = dist[u] + weight[e];
            }
        }
    }
    int answer = 0;
    for(int i=1; i<=n; i++)
    {
        if(dist[i] == INF)
        {
            answer = -1;
            break;
        }
        if(dist[i] > answer)
        {
            answer = dist[i];
        }
    }
    free(dist);
    free(done);
    free(head);
    free(next);
    free(to);
    free(weight);
    return answer;
}