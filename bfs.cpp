#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int cost[10][10], i, j, k, n, qu[10], front, rare, v, visit[10], visited[10];

int main()
{
    clock_t time_req;
    time_req = clock();
    
    int m;
    cout << "Enter no of vertices: ";
    cin >> n;
    cout << "Enter no of edges: ";
    cin >> m;
    cout << "EDGES \n";
    for (k = 1; k <= m; k++)
    {
        cin >> i >> j;
        cost[i][j] = 1;
    }
    cout << "Enter initial vertex to traverse from: ";
    cin >> v;
    cout << "Visited vertices: ";
    cout << v << " ";
    visited[v] = 1;
    k = 1;
    while (k < n)
    {
        for (j = 1; j <= n; j++)
        {
            if (cost[v][j] != 0 && visited[j] != 1 && visit[j] != 1)
            {
                visit[j] = 1;
                qu[rare++] = j;
            }
        }
        v = qu[front++];
        cout << v << " ";
        k++;
        visit[v] = 0;
        visited[v] = 1;
    }
    
    time_req = clock() - time_req;
    cout << "\nThe time taken is: " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;
    
    int bytes = sizeof(cost) + sizeof(qu) + sizeof(visit) + sizeof(visited);
    cout << "Bytes occupied: " << bytes << endl;

    return 0;
}
