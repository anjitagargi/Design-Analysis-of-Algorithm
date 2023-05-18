#include<iostream>
#include<bits/stdc++.h>
#include<time.h>

using namespace std;

#define V 5

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
 
    for (int i = 0; i < V; i++)
        if (mstSet[i] == false && key[i] < min)
            min = key[i], min_index = i;

    return min_index;
}

void printMST(int parent[],int graph[V][V])
{
    cout<<"Edge  "<<"  Weight"<<endl;
    for(int i=1;i<V;i++)
    {
        cout<<parent[i]<<" - "<<i<<"    "<<graph[i][parent[i]]<<endl;
    }
}

void prim(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    for(int i=0;i<V;i++)
        key[i]=INT_MAX,mstSet[i]=false;
    
    key[0]=0;
    parent[0]=-1;

    for(int count=0;count<V-1;count++)
    {
        int u=minKey(key,mstSet);
        mstSet[u]=true;
        for(int i=0;i<V;i++)
        {
            if(graph[u][i] && mstSet[i]==false && graph[u][i]<key[i])
                parent[i]=u,key[i]=graph[u][i];
        }
    }

    printMST(parent,graph);
}

int main()
{
    clock_t time_req;
    time_req=clock();
    
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

    prim(graph);
    
    time_req=clock()-time_req;
    cout<<"The time taken is: "<<(float)time_req/CLOCKS_PER_SEC<<" seconds"<<endl;
    cout<<"The bytes occupied is: "<<endl; 
    return 0;
}