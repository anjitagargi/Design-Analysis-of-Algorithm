#include<iostream>
#include<bits/stdc++.h>
#include<time.h>
#define edge pair<int,int>
using namespace std;
class Graph
{
    private:
    vector <pair<int, edge>> G;//Graph
    vector <pair<int, edge> > T;//Minimum spanning tree
    int* parent;
    int V;//Number of nodes
    public:
    Graph(int V)
    {
        parent=new int [V];
        for(int i=0;i<V;i++)
            parent[i]=i;

        G.clear();
        T.clear();
    }
    void AddEdge(int u,int v,int wu,int wv)//Initialising Graph for Bidirectional graph
    {
        G.push_back(make_pair(wu,edge(u,v)));
        G.push_back(make_pair(wv,edge(v,u)));
    }
    void AddEdge(int u,int v,int w)//Initializing for unidirectional
    {
        G.push_back(make_pair(w,edge(u,v)));
        G.push_back(make_pair(w,edge(v,u)));
    }
    int find_parent(int i)
    {
        if(parent[i]==i)
            return i;
        else 
            return(find_parent(parent[i]));
    }
    void union_set(int u,int v)
    {
        parent[u]=parent[v];
    }
    void kruskal()
    {
        int i,up,vp;
        sort(G.begin(),G.end());
        for(int i=0;i<G.size();i++)
        {
            up=find_parent(G[i].second.first);
            vp=find_parent(G[i].second.second);
            if(up!=vp)
            {
                T.push_back(G[i]);
                union_set(up,vp);
            }
        }
    }
    void print() {
        cout << "Edge :"
            << " Weight" << endl;
        for (int i = 0; i < T.size(); i++) {
            cout << T[i].second.first << " - " << T[i].second.second << " : "
            << T[i].first;
            cout << endl;}
    }
};
int main()
{
    int n,i,x,y,z;
    clock_t time_req;
    time_req=clock();
    cout<<"Enter the no. of nodes: ";
    cin>>n;
    Graph g(n);
    g.AddEdge(0, 1, 4,4);
    g.AddEdge(0, 2, 4,4);
    g.AddEdge(1, 2, 2,2);
    g.AddEdge(2, 3, 3,3);
    g.AddEdge(2, 5, 2,2);
    g.AddEdge(2, 4, 4,4);
    g.AddEdge(3, 4, 3,3);
    g.AddEdge(5, 2, 2,2);
    g.AddEdge(5, 4, 3,3);
    g.kruskal();
    cout<<"The minimum spannng tree is: "<<endl;
    g.print();
    time_req=clock()-time_req;
    cout<<"Time taken is: "<<(float)time_req/CLOCKS_PER_SEC<<"seconds"<<endl;
    
    cout<<"Memory utilised is: "<<(sizeof(g)+5*sizeof(n))<<" bytes";
}